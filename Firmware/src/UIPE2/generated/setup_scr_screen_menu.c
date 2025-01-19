/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_menu(lv_ui *ui)
{
    //Write codes screen_menu
    ui->screen_menu = lv_obj_create(NULL);
    ui->g_kb_screen_menu = lv_keyboard_create(ui->screen_menu);
    lv_obj_add_event_cb(ui->g_kb_screen_menu, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_screen_menu, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_screen_menu, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->screen_menu, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_menu, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_btn_menu_setting
    ui->screen_menu_btn_menu_setting = lv_btn_create(ui->screen_menu);
    ui->screen_menu_btn_menu_setting_label = lv_label_create(ui->screen_menu_btn_menu_setting);
    lv_label_set_text(ui->screen_menu_btn_menu_setting_label, " " LV_SYMBOL_SETTINGS " ");
    lv_label_set_long_mode(ui->screen_menu_btn_menu_setting_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_btn_menu_setting_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_btn_menu_setting, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_menu_btn_menu_setting_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_menu_btn_menu_setting, 36, 19);
    lv_obj_set_size(ui->screen_menu_btn_menu_setting, 100, 100);

    //Write style for screen_menu_btn_menu_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_menu_btn_menu_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_menu_btn_menu_setting, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_menu_btn_menu_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_menu_btn_menu_setting, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_menu_btn_menu_setting, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_btn_menu_setting, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_btn_menu_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_btn_menu_setting, lv_color_hex(0x12548b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_btn_menu_setting, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_btn_menu_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_btn_menu_setting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_btn_menu_home
    ui->screen_menu_btn_menu_home = lv_btn_create(ui->screen_menu);
    ui->screen_menu_btn_menu_home_label = lv_label_create(ui->screen_menu_btn_menu_home);
    lv_label_set_text(ui->screen_menu_btn_menu_home_label, " " LV_SYMBOL_HOME " ");
    lv_label_set_long_mode(ui->screen_menu_btn_menu_home_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_btn_menu_home_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_btn_menu_home, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_menu_btn_menu_home_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_menu_btn_menu_home, 36, 130);
    lv_obj_set_size(ui->screen_menu_btn_menu_home, 100, 100);

    //Write style for screen_menu_btn_menu_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_menu_btn_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_menu_btn_menu_home, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_menu_btn_menu_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_menu_btn_menu_home, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_menu_btn_menu_home, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_btn_menu_home, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_btn_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_btn_menu_home, lv_color_hex(0x12548b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_btn_menu_home, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_btn_menu_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_btn_menu_home, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_btn_menu_wifi
    ui->screen_menu_btn_menu_wifi = lv_btn_create(ui->screen_menu);
    ui->screen_menu_btn_menu_wifi_label = lv_label_create(ui->screen_menu_btn_menu_wifi);
    lv_label_set_text(ui->screen_menu_btn_menu_wifi_label, " " LV_SYMBOL_WIFI " ");
    lv_label_set_long_mode(ui->screen_menu_btn_menu_wifi_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_menu_btn_menu_wifi_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_menu_btn_menu_wifi, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_menu_btn_menu_wifi_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_menu_btn_menu_wifi, 186, 19);
    lv_obj_set_size(ui->screen_menu_btn_menu_wifi, 100, 100);

    //Write style for screen_menu_btn_menu_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_menu_btn_menu_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_menu_btn_menu_wifi, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_menu_btn_menu_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_menu_btn_menu_wifi, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_menu_btn_menu_wifi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_btn_menu_wifi, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_btn_menu_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_menu_btn_menu_wifi, lv_color_hex(0x12548b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_menu_btn_menu_wifi, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_menu_btn_menu_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_menu_btn_menu_wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_menu.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_menu);

    //Init events for screen.
    events_init_screen_menu(ui);
}
