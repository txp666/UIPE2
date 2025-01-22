#include "custom.h"

lv_timer_t *mqtt_timer;

static void mqtt_connect_event_cb()
{
#ifdef ARDUINO
    stopMqtt();
    setMqttServer(lv_textarea_get_text(guider_ui.screen_mqtt_ta_mqtt_ip));
    setMqttPort(atoi(lv_textarea_get_text(guider_ui.screen_mqtt_ta_mqtt_port)));
    startMqtt();
#endif
}

static void mqtt_disconnect_event_cb()
{
#ifdef ARDUINO
    stopMqtt();
#endif
}

static void mqtt_timer_cb(lv_timer_t *timer)
{
#ifdef ARDUINO
    if (getMqttConnected())
        lv_label_set_text(guider_ui.screen_mqtt_label_mqtt_info, "mqtt connected");
    else
        lv_label_set_text(guider_ui.screen_mqtt_label_mqtt_info, "mqtt disconnected");
    if (getWifiStatus() == 0)
        lv_label_set_text(guider_ui.screen_mqtt_label_mqtt_info, "wifi err");

#endif
}

void screen_mqtt_load_start()
{
    mqtt_timer = lv_timer_create(mqtt_timer_cb, 500, NULL);
#ifdef ARDUINO

    lv_textarea_set_text(guider_ui.screen_mqtt_ta_mqtt_ip, getMqttServer());
    char port_str[6]; // 假设端口号最大为65535
    sprintf(port_str, "%d", getMqttPort());
    lv_textarea_set_text(guider_ui.screen_mqtt_ta_mqtt_port, port_str);

    lv_obj_add_event_cb(guider_ui.screen_mqtt_btn_mqtt_connect, mqtt_connect_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_mqtt_btn_mqtt_disconnect, mqtt_disconnect_event_cb, LV_EVENT_CLICKED, NULL);

#endif
}

void screen_mqtt_unloaded()
{
    lv_timer_del(mqtt_timer);
}
