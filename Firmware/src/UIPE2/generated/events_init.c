/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_start_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_start_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 1400, false, true);
        break;
    }
    case LV_EVENT_SCREEN_LOAD_START:
    {
        ui_animation(guider_ui.screen_start_label_1, 1000, 0, lv_obj_get_x(guider_ui.screen_start_label_1), 71, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_start (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_start, screen_start_event_handler, LV_EVENT_ALL, ui);
}

static void screen_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_home_loade_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_home_unloaded();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chart, guider_ui.screen_chart_del, &guider_ui.screen_home_del, setup_scr_screen_chart, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_home_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_cpu, guider_ui.screen_cpu_del, &guider_ui.screen_home_del, setup_scr_screen_cpu, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_home (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_home, screen_home_event_handler, LV_EVENT_ALL, ui);
}

static void screen_chart_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_chart_loade_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_chart_unloaded();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_chart_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_time, guider_ui.screen_time_del, &guider_ui.screen_chart_del, setup_scr_screen_time, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_chart_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_chart (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_chart, screen_chart_event_handler, LV_EVENT_ALL, ui);
}

static void screen_time_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_time_load_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_time_unloaded();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_HA, guider_ui.screen_HA_del, &guider_ui.screen_time_del, setup_scr_screen_HA, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chart, guider_ui.screen_chart_del, &guider_ui.screen_time_del, setup_scr_screen_chart, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_time_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_time (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_time, screen_time_event_handler, LV_EVENT_ALL, ui);
}

static void screen_HA_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_ha_load_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_ha_unloaded();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_cpu, guider_ui.screen_cpu_del, &guider_ui.screen_HA_del, setup_scr_screen_cpu, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_time, guider_ui.screen_time_del, &guider_ui.screen_HA_del, setup_scr_screen_time, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_HA_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_HA (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_HA, screen_HA_event_handler, LV_EVENT_ALL, ui);
}

static void screen_menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_menu_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_menu_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_menu_btn_menu_setting_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_setting, guider_ui.screen_setting_del, &guider_ui.screen_menu_del, setup_scr_screen_setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void screen_menu_btn_menu_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_menu_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void screen_menu_btn_menu_wifi_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_wifi, guider_ui.screen_wifi_del, &guider_ui.screen_menu_del, setup_scr_screen_wifi, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void screen_menu_btn_menu_mqtt_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_mqtt, guider_ui.screen_mqtt_del, &guider_ui.screen_menu_del, setup_scr_screen_mqtt, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_menu (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_menu, screen_menu_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_menu_btn_menu_setting, screen_menu_btn_menu_setting_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_menu_btn_menu_home, screen_menu_btn_menu_home_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_menu_btn_menu_wifi, screen_menu_btn_menu_wifi_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_menu_btn_menu_mqtt, screen_menu_btn_menu_mqtt_event_handler, LV_EVENT_ALL, ui);
}

static void screen_setting_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_setting_loade_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_setting_unloaded();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_setting_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_setting_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_setting_btn_setting_return_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_setting_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_setting (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_setting, screen_setting_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_setting_btn_setting_return, screen_setting_btn_setting_return_event_handler, LV_EVENT_ALL, ui);
}

static void screen_pwr_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_pwr_load_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_pwr_unloaded();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chart, guider_ui.screen_chart_del, &guider_ui.screen_pwr_del, setup_scr_screen_chart, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_pwr_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_pwr (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_pwr, screen_pwr_event_handler, LV_EVENT_ALL, ui);
}

static void screen_wifi_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_wifi_load_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_wifi_unloaded();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_wifi_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_wifi_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_wifi_btn_wifi_return_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_wifi_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_wifi (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_wifi, screen_wifi_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_wifi_btn_wifi_return, screen_wifi_btn_wifi_return_event_handler, LV_EVENT_ALL, ui);
}

static void screen_mqtt_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_mqtt_load_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_mqtt_unloaded();
        break;
    }
    default:
        break;
    }
}

static void screen_mqtt_btn_mqtt_return_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_menu, guider_ui.screen_menu_del, &guider_ui.screen_mqtt_del, setup_scr_screen_menu, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_mqtt (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_mqtt, screen_mqtt_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_mqtt_btn_mqtt_return, screen_mqtt_btn_mqtt_return_event_handler, LV_EVENT_ALL, ui);
}

static void screen_cpu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        screen_cpu_load_start();
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        screen_cpu_unloaded();
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_cpu_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_HA, guider_ui.screen_HA_del, &guider_ui.screen_cpu_del, setup_scr_screen_HA, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_cpu (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_cpu, screen_cpu_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
