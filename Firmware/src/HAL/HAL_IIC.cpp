#include "HAL/HAL.h"

#include "INA228.h"
#include <PD_UFP.h>

PD_UFP_c PD_UFP;
INA228 INA(0x40);

static float voltage, current, power, temp;
static double energy_uAh;
static uint8_t pps_status;

void HAL::IIC_Task(void *parameter)
{
    while (1)
    {
        PD_UFP.run();
        if (PD_UFP.is_PPS_ready())
        {
            // Serial.write("PPS trigger succcess\n");
            pps_status = 1;
        }
        else if (PD_UFP.is_power_ready())
        {
            // Serial.write("Fail to trigger PPS\n");
            pps_status = 0;
        }
        else
        {
            // Serial.write("No PD supply available\n");
            pps_status = 2;
        }

        __IntervalExecute(temp = INA.getTemperature(), 1000);
        __IntervalExecute(voltage = INA.getBusVoltage();
                          current = INA.getMicroAmpere();
                          power = INA.getMicroWatt();
                          energy_uAh += current * (0.02 / 3600.0), 20);
        vTaskDelay(2);
    }
}

void HAL::IIC_Init(bool startScan)
{
    Wire.begin(CONFIG_IIC_SDA, CONFIG_IIC_SCL);

    if (startScan)
    {
        uint8_t error, address;
        int nDevices;

        Serial.println("I2C: device scanning...");

        nDevices = 0;
        for (address = 1; address < 127; address++)
        {
            // The i2c_scanner uses the return value of
            // the Write.endTransmisstion to see if
            // a device did acknowledge to the address.
            Wire.beginTransmission(address);
            error = Wire.endTransmission();

            if (error == 0)
            {
                Serial.print("I2C: device found at address 0x");
                if (address < 16)
                    Serial.print("0");
                Serial.print(address, HEX);
                Serial.println(" !");

                nDevices++;
            }
            else if (error == 4)
            {
                Serial.print("I2C: unknow error at address 0x");
                if (address < 16)
                    Serial.print("0");
                Serial.println(address, HEX);
            }
        }
        Serial.printf("I2C: %d devices was found\r\n", nDevices);
    }

    if (!INA.begin())
    {
        Serial.println("INA device not found");
        while (1)
            ;
    }

    INA.setMaxCurrentShunt(10, 0.01);
    // PD_UFP.init_PPS(FUSB302_INT_PIN, PPS_V(5), PPS_A(0), PD_POWER_OPTION_MAX_20V);
    PD_UFP.init(FUSB302_INT_PIN, PD_POWER_OPTION_MAX_20V);
    PD_UFP.set_power_option(PD_POWER_OPTION_MAX_5V);

    xTaskCreatePinnedToCore(IIC_Task, "IIC_Task", 1024 * 2, NULL, IICtaskPri, NULL, 1);
}

/* 返回 U I P / V μA μW */
void getUIP(float *u, float *i, float *p)
{
    current < 0 ? current = 0 : current = current;
    power < 0 ? power = 0 : power = power;

    // 最后再通过指针传给外部
    *u = voltage;
    *i = current;
    *p = power;
}

float getTemperature()
{
    return temp;
}

double getEnergy()
{
    return energy_uAh;
}

void clearEnergy()
{
    energy_uAh = 0;
}

void setPwrMode(uint8_t mode)
{
    PD_UFP.set_power_option((PD_power_option_t)mode);
}

void setPwrPPS(float PPS_voltage, float PPS_current)
{

    PD_UFP.set_PPS(PPS_V(PPS_voltage), PPS_A(PPS_current));
}
