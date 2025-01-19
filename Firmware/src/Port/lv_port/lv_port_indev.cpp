/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include "HAL/HAL.h"
#include <FT6336.h>
FT6336U touch_6336(FT6336_SDA, FT6336_SCL, FT6336_INT, &Wire1); // Wire是0号总线，引脚号根据实际连线修改

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    if (touch_6336.available())
    {
        data->state = LV_INDEV_STATE_PR;
        data->point.y = CONFIG_SCREEN_VER_RES - 1 - touch_6336.touchPoint.tp[0].x;
        data->point.x = touch_6336.touchPoint.tp[0].y;
        // data->point.y = touch_6336.touchPoint.tp[0].y;
        // data->point.x = touch_6336.touchPoint.tp[0].x;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
}
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
/*
static void encoder_init(void);
static void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data); */

/**********************
 *  STATIC VARIABLES
 **********************/

/* static lv_indev_t *encoder_indev; */
static lv_indev_t *touch_indev;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
/* static lv_indev_drv_t indev_drv; */
static lv_indev_drv_t touch_drv;
void lv_port_indev_init(void)
{

    /*------------------
     * Encoder
     * -----------------*/

    /*Initialize your encoder if you have*/
    // encoder_init();
    touch_6336.begin();
    /*Initialize the (dummy) input device driver*/
    lv_indev_drv_init(&touch_drv);
    touch_drv.type = LV_INDEV_TYPE_POINTER;
    touch_drv.read_cb = my_touchpad_read;
    touch_indev = lv_indev_drv_register(&touch_drv);
    /*Register a encoder input device*/
    /*     lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_ENCODER;
        indev_drv.read_cb = encoder_read;
        encoder_indev = lv_indev_drv_register(&indev_drv); */

    /* Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     * add objects to the group with `lv_group_add_obj(group, obj)`
     * and assign this input device to group to navigate in it:
     * `lv_indev_set_group(indev_encoder, group);` */
    lv_group_t *group = lv_group_create();
    // lv_indev_set_group(encoder_indev, group);
    lv_indev_set_group(touch_indev, group);
    lv_group_set_default(group);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Encoder
 * -----------------*/

/* Initialize your keypad */
static void encoder_init(void)
{
    /*Do it in Init*/
}

/* Will be called by the library to read the encoder */
/* static void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    data->enc_diff = HAL::Encoder_GetDiff();
    data->state = HAL::Encoder_GetIsPush() ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
} */

#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif
