#include "custom.h"

static void btn_event_cb(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target(e);
#ifdef ARDUINO
    if (btn == guider_ui.screen_pwr_btn_pwr_5)
    {
        setPwrMode(0);
    }
    else if (btn == guider_ui.screen_pwr_btn_pwr_9)
    {
        setPwrMode(1);
    }
    else if (btn == guider_ui.screen_pwr_btn_pwr_12)
    {
        setPwrMode(2);
    }
    else if (btn == guider_ui.screen_pwr_btn_pwr_15)
    {
        setPwrMode(3);
    }
    else if (btn == guider_ui.screen_pwr_btn_pwr_20)
    {
        setPwrMode(4);
    }
#endif
}

static void spinbox_event_cb(lv_event_t *e)
{
    lv_obj_t *spinbox = lv_event_get_target(e);
    if (spinbox == guider_ui.screen_pwr_spinbox_pwr_u)
    {
        int32_t u = lv_spinbox_get_value(guider_ui.screen_pwr_spinbox_pwr_u);
#ifdef ARDUINO
        setPwrPPS(u / 100.0, 0);
#endif
    }
}

void screen_pwr_load_start()
{
    lv_obj_add_event_cb(guider_ui.screen_pwr_btn_pwr_5, btn_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_pwr_btn_pwr_9, btn_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_pwr_btn_pwr_12, btn_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_pwr_btn_pwr_15, btn_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_pwr_btn_pwr_20, btn_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_pwr_spinbox_pwr_u, spinbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_spinbox_set_range(guider_ui.screen_pwr_spinbox_pwr_u, 50, 2000);
}

void screen_pwr_unloaded()
{
}