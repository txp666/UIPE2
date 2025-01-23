#include "custom.h"

lv_timer_t *ha_timer;

static void fan_event_handler(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    if (lv_obj_has_state(guider_ui.screen_HA_sw_fan, LV_STATE_CHECKED))
    {
        lv_animimg_start(guider_ui.screen_HA_animimg_fan);
#ifdef ARDUINO
        turn_fan(true);
#endif
    }
    else
    {
        lv_anim_del(guider_ui.screen_HA_animimg_fan, NULL);
#ifdef ARDUINO
        turn_fan(false);
#endif
    }
}

static void light_event_handler(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    if (lv_obj_has_state(guider_ui.screen_HA_sw_light, LV_STATE_CHECKED))
    {
        lv_obj_add_flag(guider_ui.screen_HA_img_light_off, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.screen_HA_img_light_on, LV_OBJ_FLAG_HIDDEN);
#ifdef ARDUINO
        turn_ligh(true);
#endif
    }
    else
    {
        lv_obj_add_flag(guider_ui.screen_HA_img_light_on, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.screen_HA_img_light_off, LV_OBJ_FLAG_HIDDEN);
#ifdef ARDUINO
        turn_ligh(false);
#endif
    }
}

static void ha_timer_cb()
{
#ifdef ARDUINO
    float temp = getHATemperature();
#else
    float temp = 25;
#endif
    char buffer[32];
    sprintf(buffer, "%.1f°", temp);
    lv_label_set_text(guider_ui.screen_HA_label_temp2, buffer);
    // lv_arc_set_value(guider_ui.screen_HA_arc_temp, round(temp));
}

void screen_ha_load_start()
{
    lv_obj_clear_flag(guider_ui.screen_HA_arc_temp, LV_OBJ_FLAG_CLICKABLE);
    ha_timer = lv_timer_create(ha_timer_cb, 500, NULL);
    lv_obj_add_event_cb(guider_ui.screen_HA_sw_fan, fan_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_HA_sw_light, light_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
}

void screen_ha_unloaded()
{
    lv_timer_del(ha_timer);
}