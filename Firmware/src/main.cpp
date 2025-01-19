#include <Arduino.h>
#include "HAL/HAL.h"
#include "Port/Display.h"

#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "menu_config.h"

lv_ui guider_ui;
TaskHandle_t lvglTaskHandle = NULL;

SaveConfig_t saveConfig;
void lvglTask(void *pvParameters)
{
    while (1)
    {
        // 处理LVGL任务
        lv_task_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}
void setup()
{
    HAL::Init();
    Port_Init();
    setup_ui(&guider_ui);
    xTaskCreatePinnedToCore(
        lvglTask,        /* 任务函数 */
        "LvglTask",      /* 任务名称 */
        1024 * 4,        /* 栈大小 */
        NULL,            /* 任务参数 */
        lvglTaskPri,     /* 优先级 */
        &lvglTaskHandle, /* 任务句柄 */
        APP_CPU_NUM);    /* CPU核心 */
}

void loop()
{
    HAL::Update();

    vTaskDelay(pdMS_TO_TICKS(20));
}
