#include "custom.h"

static lv_obj_t *chart_chart;

static lv_coord_t ui_Chart_series_1_array[101] = {0, 10, 20, 4, 80, 10, 40, 20, 10, 0};
static lv_coord_t ui_Chart_series_2_array[101] = {0, 10, 20, 4, 80, 10, 40, 20, 10, 0};
lv_chart_series_t *ui_Chart_series_1;
lv_chart_series_t *ui_Chart_series_2;
int ui_Chart_series_1_array_max;
int ui_Chart_series_2_array_max;

lv_timer_t *screen_chart_timer;

int ranges[] = {1, 5, 10, 20, 50, 100, 150, 200, 300, 500, 1000, 1500, 2000, 2500, 3000};
int size = sizeof(ranges) / sizeof(ranges[0]);
static bool playStatus = true;

int get_max_num(lv_coord_t *ui_array)
{
    int max_num = 0;
    for (size_t i = 0; i < 100; i++)
        if (max_num < ui_array[i])
            max_num = ui_array[i];

    return max_num;
}

void ui_Chart_update(int current, int voltage)
{
    for (char i = 0; i < 100; i++)
    {
        ui_Chart_series_1_array[i] = ui_Chart_series_1_array[i + 1];
        ui_Chart_series_2_array[i] = ui_Chart_series_2_array[i + 1];
    }
    if (current > 1000)
    {
        ui_Chart_series_1_array[100] = current / 1000;
        ui_Chart_series_2_array[100] = voltage;
        lv_label_set_text(guider_ui.screen_chart_label_screen_chart_unit, "mA");
    }
    else
    {
        ui_Chart_series_1_array[100] = current;
        ui_Chart_series_2_array[100] = voltage;
        lv_label_set_text(guider_ui.screen_chart_label_screen_chart_unit, "μA");
    }

    ui_Chart_series_1_array_max = get_max_num(ui_Chart_series_1_array);

    for (int i = 0; i < size; i++)
    {
        if (ui_Chart_series_1_array_max < ranges[i])
        {
            lv_chart_set_range(chart_chart, LV_CHART_AXIS_PRIMARY_Y, 0, ranges[i]);
            break;
        }
    }

    ui_Chart_series_2_array_max = get_max_num(ui_Chart_series_2_array);

    if (ui_Chart_series_2_array_max < 10)
        lv_chart_set_range(chart_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 9);
    else if (ui_Chart_series_2_array_max < 16)
        lv_chart_set_range(chart_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 15);
    else
        lv_chart_set_range(chart_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 20);

    lv_chart_set_ext_y_array(chart_chart, ui_Chart_series_1, ui_Chart_series_1_array);
    lv_chart_set_ext_y_array(chart_chart, ui_Chart_series_2, ui_Chart_series_2_array);
}

void create_chart()
{
    chart_chart = guider_ui.screen_chart_chart_1;

    ui_Chart_series_1 = lv_chart_add_series(chart_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    ui_Chart_series_2 = lv_chart_add_series(chart_chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_SECONDARY_Y);

    lv_chart_set_point_count(chart_chart, 100);
}

static void screen_chart_timer_cb(lv_timer_t *timer)
{
#ifdef ARDUINO
    float u, i, p;
    getUIP(&u, &i, &p);
#else
    // 随机数
    float u = rand() % 25;
    float i = rand() % 100;
    float p = u * i;
#endif

    ui_Chart_update(round(i), round(u));

    char buf[32];

    /* ------------------ 电压显示 (单位: V) ------------------ */
    // 若电压 >= 10V，仅显示到小数点后2位；否则显示到3位。
    if (u >= 10.0f)
    {
        snprintf(buf, sizeof(buf), "%.2fV", u);
    }
    else
    {
        snprintf(buf, sizeof(buf), "%.3fV", u);
    }
    lv_label_set_text(guider_ui.screen_chart_label_screen_chart_u, buf);

    /* ------------------ 电流显示 (单位: μA -> mA/A) ------------------ */
    // 转换规则：
    //  - i >= 1,000,000 (即 >=1A)        -> 显示为 A
    //  - i >= 1,000   (即 >=1mA)        -> 显示为 mA
    //  - 否则                          -> 显示为 μA
    if (i >= 1e6f)
    {
        // 大于等于 1A
        snprintf(buf, sizeof(buf), "%.3fA", i / 1e6f);
    }
    else if (i >= 1e3f)
    {
        // 大于等于 1mA
        // 若大于等于 100mA，则显示到小数点后1位；否则小数点后2位
        if (i >= 100e3f)
        {
            snprintf(buf, sizeof(buf), "%.1fmA", i / 1e3f);
        }
        else
        {
            snprintf(buf, sizeof(buf), "%.2fmA", i / 1e3f);
        }
    }
    else
    {
        // 小于 1mA
        snprintf(buf, sizeof(buf), "%.0fμA", i);
    }
    lv_label_set_text(guider_ui.screen_chart_label_screen_chart_i, buf);

    /* ------------------ 功率显示 (单位: μW -> mW/W) ------------------ */
    // 转换规则：
    //  - p >= 1,000,000 (即 >=1W)      -> 显示为 W
    //  - p >= 1,000   (即 >=1mW)      -> 显示为 mW
    //  - 否则                         -> 显示为 μW
    if (p >= 1e6f)
    {
        snprintf(buf, sizeof(buf), "%.3fW", p / 1e6f);
    }
    else if (p >= 1e3f)
    {
        snprintf(buf, sizeof(buf), "%.1fmW", p / 1e3f);
    }
    else
    {
        snprintf(buf, sizeof(buf), "%.0fμW", p);
    }
    lv_label_set_text(guider_ui.screen_chart_label_screen_chart_p, buf);
}

static void chart_play_cb(lv_event_t *e)
{
    if (playStatus)
    {
        lv_timer_pause(screen_chart_timer);
        lv_label_set_text(guider_ui.screen_chart_btn_screen_chart_play_label, LV_SYMBOL_PLAY);
    }
    else
    {
        lv_timer_resume(screen_chart_timer);
        lv_label_set_text(guider_ui.screen_chart_btn_screen_chart_play_label, LV_SYMBOL_STOP);
    }
    playStatus = !playStatus;
}

void screen_chart_loade_start()
{
    create_chart();
    screen_chart_timer = lv_timer_create(screen_chart_timer_cb, 100, NULL);
    lv_label_set_text(guider_ui.screen_chart_btn_screen_chart_play_label, LV_SYMBOL_STOP);
    lv_obj_add_event_cb(guider_ui.screen_chart_btn_screen_chart_play, chart_play_cb, LV_EVENT_CLICKED, NULL);
}

void screen_chart_unloaded()
{
    lv_obj_del(chart_chart);
    lv_timer_del(screen_chart_timer);
}