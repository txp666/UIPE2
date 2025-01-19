#include "custom.h"

lv_timer_t *screen_home_timer;
lv_timer_t *screen_home_timer_1s;

static uint32_t time = 0;

/**
 * @brief 该定时器回调函数每200ms执行一次，获取/更新电压、电流、功率并刷新UI显示。
 */
static void screen_home_timer_cb(lv_timer_t *timer)
{
    float u, i, p;
#ifdef ARDUINO
    getUIP(&u, &i, &p);
#else
    // 随机数
    u = rand() % 25;
    i = rand() % 1000;
    p = u * i;
#endif

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
    lv_label_set_text(guider_ui.screen_home_label_screen_home_U, buf);

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
    lv_label_set_text(guider_ui.screen_home_label_screen_home_I, buf);

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
    lv_label_set_text(guider_ui.screen_home_label_screen_home_P, buf);
}

static void screen_home_timer_1s_cb(lv_timer_t *timer)
{
    char buf[32];
    time++;
    // 更新时间
    snprintf(buf, sizeof(buf), "%02d:%02d:%02d", time / 3600, (time % 3600) / 60, time % 60);
    lv_label_set_text(guider_ui.screen_home_label_screen_home_time, buf);
// 更新温度
#ifdef ARDUINO
    float temp = getTemperature();
#else
    // 随机数
    float temp = rand() % 25;
#endif
    snprintf(buf, sizeof(buf), "%.1f°C", temp);
    lv_label_set_text(guider_ui.screen_home_label_screen_home_temp, buf);
// energy
#ifdef ARDUINO
    double energy = getEnergy();
#else
    double energy = rand() % 1000;
#endif
    if (energy < 1000)
    {
        if (energy < 10)
            snprintf(buf, sizeof(buf), "%.3fμAh", energy);
        else if (energy < 100)
            snprintf(buf, sizeof(buf), "%.2fμAh", energy);
        else
            snprintf(buf, sizeof(buf), "%.1fμAh", energy);
    }
    else if (energy >= 1000 * 1000)
    {
        if (energy < 1000 * 1000 * 10)
            snprintf(buf, sizeof(buf), "%.3fAh", energy / 1000.0 / 1000.0);
        else if (energy < 1000 * 1000 * 100)
            snprintf(buf, sizeof(buf), "%.2fAh", energy / 1000.0 / 1000.0);
        else
            snprintf(buf, sizeof(buf), "%.1fAh", energy / 1000.0 / 1000.0);
    }
    else
    {
        if (energy < 1000 * 10)
            snprintf(buf, sizeof(buf), "%.3fmAh", energy / 1000.0);
        else if (energy < 1000 * 100)
            snprintf(buf, sizeof(buf), "%.2fmAh", energy / 1000.0);
        else
            snprintf(buf, sizeof(buf), "%.1fmAh", energy / 1000.0);
    }
    lv_label_set_text(guider_ui.screen_home_label_screen_home_ene, buf);
}

static void energy_zero_event_cb(lv_event_t *e)
{
    time = 0;
#ifdef ARDUINO
    clearEnergy();
#endif
}

static void change_u_cb(lv_event_t *e)
{
    static uint8_t currentVoltage_type = 0;
    currentVoltage_type = (currentVoltage_type + 1) % 5;
#ifdef ARDUINO
    setPwrMode(currentVoltage_type);
#endif
}

void screen_home_loade_start()
{
    // 创建一个 200ms 刷新一次的定时器，用于更新UI
    screen_home_timer = lv_timer_create(screen_home_timer_cb, 200, NULL);
    // 创建一个 1s 刷新一次的定时器，用于更新时间和温度
    screen_home_timer_1s = lv_timer_create(screen_home_timer_1s_cb, 1000, NULL);
    // 按钮回调
    lv_obj_add_event_cb(guider_ui.screen_home_btn_home_clear, energy_zero_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(guider_ui.screen_home_btn_home_set_u, change_u_cb, LV_EVENT_CLICKED, NULL);
}

void screen_home_unloaded()
{
    if (screen_home_timer != NULL)
    {
        lv_timer_del(screen_home_timer);
        screen_home_timer = NULL;
    }
    if (screen_home_timer_1s != NULL)
    {
        lv_timer_del(screen_home_timer_1s);
        screen_home_timer_1s = NULL;
    }
}