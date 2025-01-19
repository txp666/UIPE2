#include "custom.h"

lv_timer_t *screen_wifi_timer;

static bool isSTAmode = false;

/* wifi连接按钮按下 */
void connectBtnClicked()
{
#ifdef ARDUINO
    char ssid[20];
    char password[30];
    lv_dropdown_get_selected_str(guider_ui.screen_wifi_ddlist_wifi, ssid, sizeof(ssid));
    strncpy(password, lv_textarea_get_text(guider_ui.screen_wifi_ta_wifi_code), sizeof(password) - 1);
    startConnect(ssid, password);
#endif
}

/* wifi开关切换 */
void wifiSwitchChanged()
{
#ifdef ARDUINO
    isSTAmode = lv_obj_has_state(guider_ui.screen_wifi_sw_wifi_swich, LV_STATE_CHECKED);
    if (!isSTAmode)
        lv_dropdown_clear_options(guider_ui.screen_wifi_ddlist_wifi);
    enableWiFi(isSTAmode);
#endif
}

// 更新WiFi下拉列表
void update_wifi_dropdown()
{
#ifdef ARDUINO
    lv_dropdown_clear_options(guider_ui.screen_wifi_ddlist_wifi);
    int count;
    const char **wifiNames = getWiFiNames(&count);
    for (int i = 0; i < count; ++i)
    {
        lv_dropdown_add_option(guider_ui.screen_wifi_ddlist_wifi, wifiNames[i], LV_DROPDOWN_POS_LAST);
    }
#endif
}

/* 刷新wifi页面 */
void refreshWiFi()
{
    char buf[32];
#ifdef ARDUINO
    if (getScanFlag() && isSTAmode)
        update_wifi_dropdown();
    uint8_t status = getWifiStatus();
    if (status == 2)
    {
        snprintf(buf, sizeof(buf), "AP Mode:%s", getWiFiName());
        lv_label_set_text(guider_ui.screen_wifi_label_wifi_name, buf);
        snprintf(buf, sizeof(buf), "IP:%s", getIPAddress());
        lv_label_set_text(guider_ui.screen_wifi_label_wifi_ip, buf);
        return;
    }
    else if (status == 1)
    {
        snprintf(buf, sizeof(buf), "WIFI已连接:%s", getWiFiName());
        lv_label_set_text(guider_ui.screen_wifi_label_wifi_name, buf);
        snprintf(buf, sizeof(buf), "IP:%s", getIPAddress());
        lv_label_set_text(guider_ui.screen_wifi_label_wifi_ip, buf);
    }
    else if (status == 0)
    {
        snprintf(buf, sizeof(buf), "WIFI未连接:%s", getWiFiName());
        lv_label_set_text(guider_ui.screen_wifi_label_wifi_name, buf);
        snprintf(buf, sizeof(buf), " ");
        lv_label_set_text(guider_ui.screen_wifi_label_wifi_ip, buf);
    }

#endif
}

/* 刷新按钮点击 */
static void wifi_refresh_cb(lv_event_t *e)
{
#ifdef ARDUINO
    startScan();
#endif
}

void screen_wifi_load_start()
{
#ifdef ARDUINO
    uint8_t status = getWifiStatus();
    if (status == 2)
        isSTAmode = false;
    else
        isSTAmode = true;
#endif
    lv_obj_add_state(guider_ui.screen_wifi_sw_wifi_swich, isSTAmode ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    refreshWiFi();
    screen_wifi_timer = lv_timer_create(refreshWiFi, 2000, NULL);
    lv_obj_add_event_cb(guider_ui.screen_wifi_btn_wifi_refresh, wifi_refresh_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_wifi_btn_wifi_connect, connectBtnClicked, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_wifi_sw_wifi_swich, wifiSwitchChanged, LV_EVENT_VALUE_CHANGED, NULL);
}

void screen_wifi_unloaded()
{
    lv_timer_del(screen_wifi_timer);
}
