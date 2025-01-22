/*
 * Copyright 2023 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus

extern "C"
{
#endif

#include "gui_guider.h"
#ifdef ARDUINO
#define lv_animimg_set_src(obj, dsc, img_num, auto_play) lv_animimg_set_src(obj, dsc, img_num)
#endif
    void custom_init(lv_ui *ui);
    void getUIP(float *u, float *i, float *p);
    float getTemperature();
    double getEnergy();
    void clearEnergy();
    void screen_home_loade_start();
    void screen_home_unloaded();

    void screen_chart_loade_start();
    void screen_chart_unloaded();

    void setBacklight(uint8_t val);
    uint8_t getBacklight();
    void screen_setting_loade_start();
    void screen_setting_unloaded();
    void savetoStorage();

    void screen_pwr_load_start();
    void setPwrMode(uint8_t mode);
    void setPwrPPS(float PPS_voltage, float PPS_current);
    void screen_pwr_unloaded();

    void connectBtnClicked();
    void wifiSwitchChanged();
    void screen_wifi_load_start();
    void screen_wifi_unloaded();
    const char **getWiFiNames(int *outCount);
    void enableAPMode(bool enable);
    uint8_t getWifiStatus();
    char *getIPAddress();
    void startScan();
    void enableWiFi(bool en);
    bool getScanFlag();
    void startConnect(char *newssid, char *newpassword);
    char *getWiFiName();

    int getHour();
    int getMinute();
    void screen_time_load_start();
    void screen_time_unloaded();
    char *getDate();

    void screen_ha_load_start();
    void screen_ha_unloaded();

    /* mqtt */
    void screen_mqtt_load_start();
    void screen_mqtt_unloaded();
    void startMqtt();
    void stopMqtt();
    void setMqttServer(const char *server);
    bool getMqttConnected();
    const char *getMqttServer();
    int getMqttPort();
    void setMqttPort(int port);
    void turn_ligh(bool on);
    void turn_fan(bool on);
    float getHATemperature();

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
