#include "HAL/HAL.h"
#include <Preferences.h>
Preferences preferences;
#define SSID_SIZE 20
#define PASSWORD_SIZE 30
char keySSID[SSID_SIZE], keyPassword[PASSWORD_SIZE];
static bool saveStorage = 0;

void HAL::NVS_Init()
{
    preferences.begin("storage", false);                                                       // 非易失性存储命名空间"storage"
    size_t saveConfigRead = preferences.getBytes("config", &saveConfig, sizeof(SaveConfig_t)); // 试图从Preferences中获取数据
    if (saveConfigRead != sizeof(SaveConfig_t))                                                // 如果读取的字节数与结构体大小不同，说明在Preferences中找不到数据
    {
        // 未在Preferences中找到数据，使用默认值填充你的结构体
        saveConfig.slider_Light_value = 70;
        preferences.putBytes("config", &saveConfig, sizeof(SaveConfig_t)); // 将默认值保存到Preferences
    }
    preferences.end(); // 关闭Preferences
}

void savetoStorage()
{
    saveConfig.slider_Light_value = getBacklight();
    preferences.begin("storage", false);
    preferences.putBytes("config", &saveConfig, sizeof(SaveConfig_t));
    preferences.end();
    // Serial.println("Saved to storage");
}

#define MAX_WIFI_CONFIGS 10

void HAL::saveWiFiCredentials(const char *ssid, const char *password)
{
    preferences.begin("WiFiCreds", false); // 开启Preferences

    int index = preferences.getInt("index", 0); // 获取当前索引，默认为0

    // 检查SSID是否已经存在
    bool exists = false;
    for (int i = 0; i < index; i++)
    {
        sprintf(keySSID, "ssid%d", i);
        String storedSSID = preferences.getString(keySSID, "");
        if (storedSSID.equals(ssid))
        {
            exists = true;
            Serial.println("SSID already exists, not saving again.");
            break;
        }
    }

    if (exists)
    {
        preferences.end(); // 如果SSID已存在，则关闭Preferences并退出
        return;
    }

    if (index >= MAX_WIFI_CONFIGS)
    {
        // 清空所有配置并重置索引
        Serial.println("Maximum number of WiFi configs reached, clearing all saved configs.");
        preferences.clear();
        index = 0; // 重置索引
    }

    // 保存新的WiFi凭证
    sprintf(keySSID, "ssid%d", index);
    sprintf(keyPassword, "password%d", index);
    preferences.putString(keySSID, ssid);
    preferences.putString(keyPassword, password);
    preferences.putInt("index", index + 1); // 更新索引

    Serial.println("New WiFi credentials saved.");
    preferences.end(); // 关闭Preferences
}

void HAL::loadWiFiCredentials(char *ssid, char *password, int index)
{
    if (index < 0 || index >= MAX_WIFI_CONFIGS)
        return;

    preferences.begin("WiFiCreds", true);

    char key[30];
    sprintf(key, "ssid%d", index);
    String readSSID = preferences.getString(key, "");
    sprintf(key, "password%d", index);
    String readPassword = preferences.getString(key, "");

    // 确保字符串不会超过预定义数组长度
    strncpy(ssid, readSSID.c_str(), SSID_SIZE - 1);
    ssid[SSID_SIZE - 1] = '\0';
    strncpy(password, readPassword.c_str(), PASSWORD_SIZE - 1);
    password[PASSWORD_SIZE - 1] = '\0';

    preferences.end();
    Serial.printf("Loaded WiFi credentials: %s, %s\n", ssid, password);
}

int HAL::getLastConnectedIndex()
{
    preferences.begin("WiFiCreds", true);
    int lastConnectedIndex = preferences.getInt("lastConnectedIndex", 0);
    preferences.end();
    return lastConnectedIndex;
}

void HAL::saveLastWiFiStatus(bool en)
{
    preferences.begin("WiFiCreds", false);
    preferences.putBool("lastWiFiStatus", en);
    preferences.end();
}

bool HAL::loadLastWiFiStatus()
{
    preferences.begin("WiFiCreds", true);
    bool lastWiFiStatus = preferences.getBool("lastWiFiStatus", true);
    preferences.end();
    return lastWiFiStatus;
}

void clearStorage()
{
    // 清空存储
    preferences.begin("storage", false);
    saveConfig.slider_Light_value = 70;
    preferences.putBytes("config", &saveConfig, sizeof(SaveConfig_t)); // 将默认值保存到Preferences
    preferences.end();
    preferences.begin("WiFiCreds", false);
    preferences.clear();
    preferences.end();

    // 重启
    esp_restart();
}
