#ifndef __CONFIG_H
#define __CONFIG_H

/*=========================
   Application configuration
 *=========================*/
#define lvglTaskPri configMAX_PRIORITIES - 1
#define IICtaskPri configMAX_PRIORITIES - 2
#define TCPTaskPri configMAX_PRIORITIES - 3

/*=========================
   Hardware Configuration
 *=========================*/

/* IIC */
#define CONFIG_IIC_SDA 48
#define CONFIG_IIC_SCL 47
#define FUSB302_INT_PIN 41

/* Screen */
#define CONFIG_SCREEN_BLK_PIN 16

#define CONFIG_SCREEN_HOR_RES 320
#define CONFIG_SCREEN_VER_RES 240
#define CONFIG_SCREEN_BUFFER_SIZE (CONFIG_SCREEN_HOR_RES * CONFIG_SCREEN_VER_RES)

/* Debug USART */
#define CONFIG_DEBUG_SERIAL Serial

/* Buzzer */
#define CONFIG_BUZZ_PIN 42
#define CONFIG_BUZZ_CHANNEL 2
#define CONFIG_SOUND_ENABLE_DEFAULT true

/* touch */
#define FT6336_INT 8
#define FT6336_SDA 18
#define FT6336_SCL 17

/* out */
#define CONFIG_OUT_PIN 15

#endif
