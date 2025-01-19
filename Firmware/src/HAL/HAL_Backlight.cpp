#include "Port/Display.h"
#include "HAL/HAL.h"

// 若定义为 1，则表示背光由高电平点亮；若定义为 0，则表示背光由低电平点亮
#define BACKLIGHT_ACTIVE_HIGH 0

#if BACKLIGHT_ACTIVE_HIGH
#define BACKLIGHT_ON HIGH
#define BACKLIGHT_OFF LOW
#else
#define BACKLIGHT_ON LOW
#define BACKLIGHT_OFF HIGH
#endif

static uint32_t backlightValue = 0;
/**
 * @brief  背光亮度渐变，受lv_anim控制
 * @param  obj:无用
 * @param  brightness:亮度值
 * @retval None
 */
static void Backlight_AnimCallback(void *obj, int32_t brightness)
{
  HAL::Backlight_SetValue(brightness);
}

/**
 * @brief  背光初始化
 * @param  无
 * @retval 无
 */
void HAL::Backlight_Init()
{
  /*PWM初始化，1024级，20KHz频率*/
  ledcSetup(0, 5000, 10);
  ledcAttachPin(CONFIG_SCREEN_BLK_PIN, 0);
  if (BACKLIGHT_ACTIVE_HIGH)
    ledcWrite(0, 0);
  else
    ledcWrite(0, 1024);
}

/**
 * @brief  背光设置，渐变效果
 * @param  target:目标亮度(0~1000 -> 0~100%)
 * @retval 无
 */
void HAL::Backlight_SetGradual(uint32_t target, uint16_t time)
{
  lv_anim_t a;
  lv_anim_init(&a);
  lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)Backlight_AnimCallback);
  lv_anim_set_values(&a, Backlight_GetValue(), target);
  lv_anim_set_time(&a, time);
  lv_anim_set_path_cb(&a, lv_anim_path_ease_out);

  lv_anim_start(&a);
}

/**
 * @brief  获取背光亮度
 * @param  无
 * @retval 当前亮度(0~1000 -> 0~100%)
 */
uint32_t HAL::Backlight_GetValue()
{
  return backlightValue;
}

/**
 * @brief  设置背光亮度
 * @param  val: 亮度(0~1000 -> 0~100%)
 * @retval 无
 */
void HAL::Backlight_SetValue(int32_t val)
{
  val = constrain(val, 0, 1024);
  backlightValue = val;
  val = backlightValue;
  if (BACKLIGHT_ACTIVE_HIGH)
    ledcWrite(0, val);
  else
    ledcWrite(0, 1024 - val);
}

/**
 * @brief  背光强制点亮
 * @param  en: 背光使能
 * @retval 无
 */
void HAL::Backlight_ForceLit(bool en)
{
  pinMode(CONFIG_SCREEN_BLK_PIN, OUTPUT);
  if (en)
    digitalWrite(CONFIG_SCREEN_BLK_PIN, BACKLIGHT_ON);
  else
    digitalWrite(CONFIG_SCREEN_BLK_PIN, BACKLIGHT_OFF);
}

void setBacklight(uint8_t val)
{
  HAL::Backlight_SetValue(val * 10);
}

uint8_t getBacklight()
{
  return HAL::Backlight_GetValue() / 10;
}
