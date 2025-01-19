// menu_config.h
#ifndef MENU_CONFIG_H
#define MENU_CONFIG_H

// 断电不消失的配置
typedef struct
{
    uint8_t slider_Light_value;
} SaveConfig_t;
extern SaveConfig_t saveConfig;

typedef struct
{
    char SSID[20];
    int RSSI;
    int channel;
    char encryptionType[20];
} WiFiNetwork;
#endif // MENU_CONFIG_H
