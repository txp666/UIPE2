#include "custom.h"

lv_timer_t *screen_cpu_timer;

static void cpu_timer_cb(lv_timer_t *timer)
{
    float cpu_usage, mem_usage, mem_total, mem_used = 0;
    char buf[64];
#ifdef ARDUINO
    getCpuMem(&cpu_usage, &mem_usage, &mem_total, &mem_used);
    char *date = getDateTime();
#else
    cpu_usage = 10;
    mem_usage = 50;
    mem_total = 64;
    mem_used = 32;
    char *date = "2025-01-17";
#endif

    snprintf(buf, sizeof(buf), "%.2f%%", cpu_usage);
    lv_label_set_text(guider_ui.screen_cpu_label_cpu, buf);
    snprintf(buf, sizeof(buf), "%.2f%%", mem_usage);
    lv_label_set_text(guider_ui.screen_cpu_label_mem, buf);
    snprintf(buf, sizeof(buf), "%.1f/%.1f GB", mem_used, mem_total);
    lv_label_set_text(guider_ui.screen_cpu_label_mem2, buf);
    lv_label_set_text(guider_ui.screen_cpu_label_time, date);
    lv_arc_set_value(guider_ui.screen_cpu_arc_cpu, cpu_usage);
    lv_arc_set_value(guider_ui.screen_cpu_arc_mem, mem_usage);
}

void screen_cpu_load_start()
{
    lv_obj_clear_flag(guider_ui.screen_cpu_arc_cpu, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(guider_ui.screen_cpu_arc_mem, LV_OBJ_FLAG_CLICKABLE);
    screen_cpu_timer = lv_timer_create(cpu_timer_cb, 50, NULL);
}

void screen_cpu_unloaded()
{
    lv_timer_del(screen_cpu_timer);
}