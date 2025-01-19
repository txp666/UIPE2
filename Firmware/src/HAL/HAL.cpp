#include "HAL/HAL.h"
#include "App/Configs/Version.h"
#define DISP_HOR_RES CONFIG_SCREEN_HOR_RES
#define DISP_VER_RES CONFIG_SCREEN_VER_RES
#define DISP_BUF_SIZE CONFIG_SCREEN_BUFFER_SIZE
extern lv_color_t *lv_disp_buf_p;

void HAL::Init()
{
    // delay(2000);
    Serial.begin(115200);
    Serial.println(VERSION_FIRMWARE_NAME);
    Serial.printf("Version: %.1f\n", VERSION_SOFTWARE);
    Serial.println("Author: " VERSION_AUTHOR_NAME);
    HAL::NVS_Init();

    // Move the malloc process to Init() to make sure that the largest heap can be used for this buffer.
    lv_disp_buf_p = static_cast<lv_color_t *>(malloc(DISP_BUF_SIZE * sizeof(lv_color_t)));
    if (lv_disp_buf_p == nullptr)
        LV_LOG_WARN("lv_port_disp_init malloc failed!\n");
    HAL::Backlight_Init();
    pinMode(CONFIG_OUT_PIN, OUTPUT);
    digitalWrite(CONFIG_OUT_PIN, HIGH);
    HAL::Buzz_init();
    HAL::Audio_Init();
    HAL::IIC_Init(true);
    HAL::TCPsetup();
    HAL::Audio_PlayMusic("Startup");
}

void HAL::Update()
{
    HAL::Audio_Update();
}
