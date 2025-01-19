#include "custom.h"

static void slider_event_cb(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target(e);
// 设置背光亮度
#ifdef ARDUINO
    setBacklight(lv_slider_get_value(slider));
#endif
}

void screen_setting_loade_start()
{
#ifdef ARDUINO
    uint8_t backlight = getBacklight();
#else
    uint8_t backlight = 50;
#endif
    lv_slider_set_value(guider_ui.screen_setting_slider_setting_light, backlight, LV_ANIM_OFF);
    lv_obj_add_event_cb(guider_ui.screen_setting_slider_setting_light, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

void screen_setting_unloaded()
{
#ifdef ARDUINO
    savetoStorage();
#endif
}
