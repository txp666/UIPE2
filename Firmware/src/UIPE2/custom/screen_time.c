#include "custom.h"

lv_timer_t *screen_time_timer;

void update_time()
{
    char buf[32];
#ifdef ARDUINO
    int hour = getHour();
    int minute = getMinute();
    // 获取日期
    char *date = getDate();

#else
    // 随机数
    int hour = rand() % 24;
    int minute = rand() % 60;
    char *date = "2025-01-17";
#endif

    lv_snprintf(buf, sizeof(buf), "%02d", hour);
    lv_label_set_text(guider_ui.screen_time_label_time_hour, buf);
    lv_snprintf(buf, sizeof(buf), "%02d", minute);
    lv_label_set_text(guider_ui.screen_time_label_time_min, buf);
    lv_label_set_text(guider_ui.screen_time_label_time_date, date);
}
static void screen_time_timer_cb(lv_timer_t *timer)
{
    update_time();
}

void screen_time_load_start()
{
    update_time();
    screen_time_timer = lv_timer_create(screen_time_timer_cb, 200, NULL);
}

void screen_time_unloaded()
{
    if (screen_time_timer != NULL)
    {
        lv_timer_del(screen_time_timer);
        screen_time_timer = NULL;
    }
}