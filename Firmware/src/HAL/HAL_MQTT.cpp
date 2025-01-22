#include "HAL/HAL.h"
#include "PubSubClient.h"
#include "WiFi.h"
#include "ArduinoJson.h"

char MQTT_SERVER[16] = "192.168.3.21";
static int MQTT_PORT = 1883;
const char *TOPIC = "UIPE2";
static bool mqttConnected = false;

WiFiClient espClient;
PubSubClient MQTTClient(espClient);
TaskHandle_t MQTTTaskHandle;
JsonDocument doc;
JsonDocument docRec;

long lastMsg = 0;
int value = 0;
unsigned long lastReconnectAttempt = 0;

static float temperature = 0;

String getUniqueID()
{
    uint8_t baseMac[6];
    esp_read_mac(baseMac, ESP_MAC_WIFI_STA);
    char baseMacChr[18] = {0};
    sprintf(baseMacChr, "%02X:%02X:%02X:%02X:%02X:%02X",
            baseMac[0], baseMac[1], baseMac[2], baseMac[3], baseMac[4], baseMac[5]);
    return String("UIPE2") + String(baseMacChr);
}

void attemptReconnect()
{
    String clientId = getUniqueID();
    const char *clientIdChar = clientId.c_str();
    if (MQTTClient.connect(clientIdChar))
    {
        Serial.println("connected");
        MQTTClient.subscribe(TOPIC);
    }
    else
    {
        Serial.print("failed, rc=");
        Serial.print(MQTTClient.state());
        Serial.println(" try again in 5 seconds");
    }
}

void reconnect()
{
    if (!MQTTClient.connected())
    {
        unsigned long now = millis();
        if (now - lastReconnectAttempt > 5000)
        {
            lastReconnectAttempt = now;
            attemptReconnect();
        }
    }
}

void callback(char *topic, byte *payload, unsigned int length)
{
    // Serial.print("Message arrived [");
    // Serial.print(topic);
    // Serial.print("] ");
    // for (int i = 0; i < length; i++)
    // {
    //     Serial.print((char)payload[i]);
    // }
    DeserializationError error = deserializeJson(docRec, payload);
    temperature = docRec["temperature"];
}

void HAL::sendMQTT()
{
    char buffer[256];
    MQTTClient.publish("UIPE2", buffer);
}

void HAL::MQTTTask(void *parameter)
{
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Waiting for WiFi to connect...");
        vTaskDelay(1000); // 等待1秒
    }
    Serial.println("WiFi connected. Setting MQTT server and callback.");
    MQTTClient.setServer(MQTT_SERVER, MQTT_PORT);
    MQTTClient.setCallback(callback);
    lastReconnectAttempt = 0;
    while (1)
    {
        if (!MQTTClient.connected())
        {
            mqttConnected = false;
            reconnect();
        }
        if (MQTTClient.connected())
        {
            mqttConnected = true;
            sendMQTT();
            MQTTClient.loop();
        }
        vTaskDelay(50);
    }
}

void startMqtt()
{
    if (MQTTTaskHandle == NULL)
    {
        xTaskCreate(HAL::MQTTTask, "MQTT Task", 4 * 1024, NULL, MQTTTaskPri, &MQTTTaskHandle);
    }
}

void stopMqtt()
{
    if (MQTTClient.connected())
        MQTTClient.disconnect();
    mqttConnected = false;
    if (MQTTTaskHandle != NULL)
    {
        vTaskDelete(MQTTTaskHandle);
        MQTTTaskHandle = NULL;
    }
}

bool getMqttConnected()
{
    return mqttConnected;
}

const char *getMqttServer()
{
    return MQTT_SERVER;
}

bool validateIPAddress(const char *ip)
{
    int num, dots = 0;
    char *ptr;
    char ipCopy[16];
    strncpy(ipCopy, ip, sizeof(ipCopy) - 1);
    ipCopy[sizeof(ipCopy) - 1] = '\0';

    if (ip == NULL)
    {
        return false;
    }

    ptr = strtok(ipCopy, ".");
    if (ptr == NULL)
    {
        return false;
    }

    while (ptr)
    {
        if (!isdigit(*ptr))
        {
            return false;
        }

        num = atoi(ptr);
        if (num >= 0 && num <= 255)
        {
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
            {
                dots++;
            }
        }
        else
        {
            return false;
        }
    }

    return (dots == 3);
}

void setMqttServer(const char *server)
{
    if (validateIPAddress(server))
    {
        strncpy(MQTT_SERVER, server, sizeof(MQTT_SERVER) - 1);
        MQTT_SERVER[sizeof(MQTT_SERVER) - 1] = '\0'; // 确保字符串以null结尾
        Serial.print("MQTT_SERVER: ");
        Serial.println(MQTT_SERVER);
    }
    else
    {
        Serial.println("Invalid IP address.");
    }
}

/* 获取端口号 */
int getMqttPort()
{
    return MQTT_PORT;
}

/* 设置端口 */
void setMqttPort(int port)
{
    MQTT_PORT = port;
    Serial.print("MQTT_PORT:");
    Serial.println(MQTT_PORT);
}

/* ---------自定义设备控制指令 ----------*/
void turn_ligh(bool on)
{
    char buffer[256];
    if (on)
        doc["light"] = "on";
    else
        doc["light"] = "off";
    serializeJson(doc, buffer, sizeof(buffer));
    MQTTClient.publish("light", buffer);
}

void turn_fan(bool on)
{
    char buffer[256];
    if (on)
        doc["fan"] = "on";
    else
        doc["fan"] = "off";
    serializeJson(doc, buffer, sizeof(buffer));
    MQTTClient.publish("fan", buffer);
}

float getHATemperature()
{
    return temperature;
}