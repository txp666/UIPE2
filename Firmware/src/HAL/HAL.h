#ifndef __HAL_H
#define __HAL_H

#include <stdint.h>
#include <Arduino.h>
#include "App/Configs/Config.h"
#include "CommonMacro.h"
#include "FreeRTOS.h"
#include "menu_config.h"
#include <queue>
#include "UIPE2/custom/custom.h"
#include <FT6336.h>
#include <atomic>
extern QueueHandle_t dataQueue;
extern TaskHandle_t lvglTaskHandle;
struct WiFiCredentials
{
    String ssid;
    String password;
};
namespace HAL
{
    void Init();
    void Update();
    /* iic */
    void IIC_Init(bool startScan);
    void IIC_Task(void *parameter);

    /* NVS */
    void NVS_Init();
    void saveWiFiCredentials(const char *ssid, const char *password);
    void loadWiFiCredentials(char *ssid, char *password, int index);
    int getLastConnectedIndex();
    void saveLastWiFiStatus(bool en);
    bool loadLastWiFiStatus();

    /* Backlight */
    void Backlight_Init();
    uint32_t Backlight_GetValue();
    void Backlight_SetValue(int32_t val);
    void Backlight_SetGradual(uint32_t target, uint16_t time = 500);
    void Backlight_ForceLit(bool en);
    uint32_t Backlight_GetValue();

    /* Buzzer */
    void Buzz_init();
    void Buzz_SetEnable(bool en);
    void Buzz_Tone(uint32_t freq, int32_t duration = 0);

    /* Audio */
    void Audio_Init();
    void Audio_Update();
    bool Audio_PlayMusic(const char *name);

    /* TCP */
    void TCPsetup();
    void TCPTask(void *parameter);
    void wifiScan();
    void powerONtoReadWiFiInfo();

    /* MQTT */
    void getPram(char *buffer, size_t bufferSize);
    void sendMQTT();
    void MQTTTask(void *parameter);

}
uint8_t getBacklight();

#endif
