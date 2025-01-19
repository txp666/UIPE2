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



void setup_scr_screen_wifi(lv_ui *ui)
{
    //Write codes screen_wifi
    ui->screen_wifi = lv_obj_create(NULL);
    ui->g_kb_screen_wifi = lv_keyboard_create(ui->screen_wifi);
    lv_obj_add_event_cb(ui->g_kb_screen_wifi, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_screen_wifi, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_screen_wifi, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->screen_wifi, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_wifi, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wifi_ddlist_wifi
    ui->screen_wifi_ddlist_wifi = lv_dropdown_create(ui->screen_wifi);
    lv_dropdown_set_options(ui->screen_wifi_ddlist_wifi, "");
    lv_obj_set_pos(ui->screen_wifi_ddlist_wifi, 140, 19);
    lv_obj_set_size(ui->screen_wifi_ddlist_wifi, 150, 30);

    //Write style for screen_wifi_ddlist_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wifi_ddlist_wifi, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wifi_ddlist_wifi, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0x654f4f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_wifi_ddlist_wifi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wifi_ddlist_wifi, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wifi_ddlist_wifi, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wifi_ddlist_wifi, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_ddlist_wifi, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_ddlist_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wifi_ddlist_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_wifi_ddlist_wifi, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_text_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_wifi_ddlist_wifi, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_wifi_ddlist_wifi, 1, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0x654f4f), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->screen_wifi_ddlist_wifi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(ui->screen_wifi_ddlist_wifi, 8, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_left(ui->screen_wifi_ddlist_wifi, 6, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(ui->screen_wifi_ddlist_wifi, 6, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->screen_wifi_ddlist_wifi, 3, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_ddlist_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_wifi_ddlist_wifi, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_wifi_ddlist_wifi, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_text_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_font(ui->screen_wifi_ddlist_wifi, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_text_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->screen_wifi_ddlist_wifi, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0x654f4f), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_side(ui->screen_wifi_ddlist_wifi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->screen_wifi_ddlist_wifi, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->screen_wifi_ddlist_wifi, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->screen_wifi_ddlist_wifi, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->screen_wifi_ddlist_wifi, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_ddlist_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->screen_wifi_ddlist_wifi, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for screen_wifi_ddlist_wifi, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_text_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->screen_wifi_ddlist_wifi, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->screen_wifi_ddlist_wifi, 1, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_side(ui->screen_wifi_ddlist_wifi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->screen_wifi_ddlist_wifi, 8, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->screen_wifi_ddlist_wifi, 6, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->screen_wifi_ddlist_wifi, 6, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->screen_wifi_ddlist_wifi, 3, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui->screen_wifi_ddlist_wifi, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->screen_wifi_ddlist_wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_ddlist_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->screen_wifi_ddlist_wifi, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style state: LV_STATE_CHECKED for &style_screen_wifi_ddlist_wifi_extra_list_selected_checked
    static lv_style_t style_screen_wifi_ddlist_wifi_extra_list_selected_checked;
    ui_init_style(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked, 2);
    lv_style_set_border_opa(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked, lv_color_hex(0x654f4f));
    lv_style_set_border_side(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_wifi_ddlist_wifi_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_wifi_ddlist_wifi), &style_screen_wifi_ddlist_wifi_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_wifi_ddlist_wifi_extra_list_main_default
    static lv_style_t style_screen_wifi_ddlist_wifi_extra_list_main_default;
    ui_init_style(&style_screen_wifi_ddlist_wifi_extra_list_main_default);

    lv_style_set_max_height(&style_screen_wifi_ddlist_wifi_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_wifi_ddlist_wifi_extra_list_main_default, lv_color_hex(0x000000));
    lv_style_set_text_font(&style_screen_wifi_ddlist_wifi_extra_list_main_default, &lv_font_montserratMedium_14);
    lv_style_set_text_opa(&style_screen_wifi_ddlist_wifi_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_wifi_ddlist_wifi_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_wifi_ddlist_wifi_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_wifi_ddlist_wifi_extra_list_main_default, lv_color_hex(0x654f4f));
    lv_style_set_border_side(&style_screen_wifi_ddlist_wifi_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_wifi_ddlist_wifi_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_wifi_ddlist_wifi_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_wifi_ddlist_wifi_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_wifi_ddlist_wifi_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_wifi_ddlist_wifi), &style_screen_wifi_ddlist_wifi_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_wifi_ddlist_wifi_extra_list_scrollbar_default
    static lv_style_t style_screen_wifi_ddlist_wifi_extra_list_scrollbar_default;
    ui_init_style(&style_screen_wifi_ddlist_wifi_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_wifi_ddlist_wifi_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_wifi_ddlist_wifi_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_wifi_ddlist_wifi_extra_list_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_wifi_ddlist_wifi_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_wifi_ddlist_wifi), &style_screen_wifi_ddlist_wifi_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_wifi_btn_wifi_return
    ui->screen_wifi_btn_wifi_return = lv_btn_create(ui->screen_wifi);
    ui->screen_wifi_btn_wifi_return_label = lv_label_create(ui->screen_wifi_btn_wifi_return);
    lv_label_set_text(ui->screen_wifi_btn_wifi_return_label, "" LV_SYMBOL_LEFT " ");
    lv_label_set_long_mode(ui->screen_wifi_btn_wifi_return_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_wifi_btn_wifi_return_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_wifi_btn_wifi_return, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_wifi_btn_wifi_return_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_wifi_btn_wifi_return, 0, 12);
    lv_obj_set_size(ui->screen_wifi_btn_wifi_return, 21, 215);

    //Write style for screen_wifi_btn_wifi_return, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wifi_btn_wifi_return, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wifi_btn_wifi_return, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_btn_wifi_return, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wifi_btn_wifi_return, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_btn_wifi_return, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wifi_btn_wifi_return, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_wifi_btn_wifi_return, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_wifi_btn_wifi_return, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_wifi_btn_wifi_return, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_wifi_btn_wifi_return, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_wifi_btn_wifi_return, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wifi_btn_wifi_return, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wifi_btn_wifi_return, &lv_font_montserratMedium_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wifi_btn_wifi_return, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wifi_btn_wifi_return, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wifi_ta_wifi_code
    ui->screen_wifi_ta_wifi_code = lv_textarea_create(ui->screen_wifi);
    lv_textarea_set_text(ui->screen_wifi_ta_wifi_code, "");
    lv_textarea_set_placeholder_text(ui->screen_wifi_ta_wifi_code, "");
    lv_textarea_set_password_bullet(ui->screen_wifi_ta_wifi_code, "*");
    lv_textarea_set_password_mode(ui->screen_wifi_ta_wifi_code, false);
    lv_textarea_set_one_line(ui->screen_wifi_ta_wifi_code, true);
    lv_textarea_set_accepted_chars(ui->screen_wifi_ta_wifi_code, "");
    lv_textarea_set_max_length(ui->screen_wifi_ta_wifi_code, 32);
#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
    lv_obj_add_event_cb(ui->screen_wifi_ta_wifi_code, ta_event_cb, LV_EVENT_ALL, ui->g_kb_screen_wifi);
#endif
    lv_obj_set_pos(ui->screen_wifi_ta_wifi_code, 56, 59);
    lv_obj_set_size(ui->screen_wifi_ta_wifi_code, 233, 39);

    //Write style for screen_wifi_ta_wifi_code, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_wifi_ta_wifi_code, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wifi_ta_wifi_code, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wifi_ta_wifi_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_wifi_ta_wifi_code, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wifi_ta_wifi_code, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wifi_ta_wifi_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wifi_ta_wifi_code, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_ta_wifi_code, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wifi_ta_wifi_code, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_wifi_ta_wifi_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_wifi_ta_wifi_code, lv_color_hex(0x6000c7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_wifi_ta_wifi_code, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wifi_ta_wifi_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wifi_ta_wifi_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wifi_ta_wifi_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wifi_ta_wifi_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_ta_wifi_code, 6, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wifi_btn_wifi_connect
    ui->screen_wifi_btn_wifi_connect = lv_btn_create(ui->screen_wifi);
    ui->screen_wifi_btn_wifi_connect_label = lv_label_create(ui->screen_wifi_btn_wifi_connect);
    lv_label_set_text(ui->screen_wifi_btn_wifi_connect_label, " " LV_SYMBOL_GPS " ");
    lv_label_set_long_mode(ui->screen_wifi_btn_wifi_connect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_wifi_btn_wifi_connect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_wifi_btn_wifi_connect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_wifi_btn_wifi_connect_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_wifi_btn_wifi_connect, 56, 118);
    lv_obj_set_size(ui->screen_wifi_btn_wifi_connect, 60, 60);

    //Write style for screen_wifi_btn_wifi_connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wifi_btn_wifi_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wifi_btn_wifi_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_btn_wifi_connect, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wifi_btn_wifi_connect, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_wifi_btn_wifi_connect, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_wifi_btn_wifi_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_wifi_btn_wifi_connect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_wifi_btn_wifi_connect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_wifi_btn_wifi_connect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wifi_btn_wifi_connect, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wifi_btn_wifi_connect, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wifi_btn_wifi_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wifi_btn_wifi_connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wifi_btn_wifi_refresh
    ui->screen_wifi_btn_wifi_refresh = lv_btn_create(ui->screen_wifi);
    ui->screen_wifi_btn_wifi_refresh_label = lv_label_create(ui->screen_wifi_btn_wifi_refresh);
    lv_label_set_text(ui->screen_wifi_btn_wifi_refresh_label, " " LV_SYMBOL_REFRESH " ");
    lv_label_set_long_mode(ui->screen_wifi_btn_wifi_refresh_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_wifi_btn_wifi_refresh_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_wifi_btn_wifi_refresh, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_wifi_btn_wifi_refresh_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_wifi_btn_wifi_refresh, 214, 118);
    lv_obj_set_size(ui->screen_wifi_btn_wifi_refresh, 60, 60);

    //Write style for screen_wifi_btn_wifi_refresh, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wifi_btn_wifi_refresh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wifi_btn_wifi_refresh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_btn_wifi_refresh, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wifi_btn_wifi_refresh, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_wifi_btn_wifi_refresh, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_wifi_btn_wifi_refresh, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_wifi_btn_wifi_refresh, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_wifi_btn_wifi_refresh, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_wifi_btn_wifi_refresh, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wifi_btn_wifi_refresh, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wifi_btn_wifi_refresh, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wifi_btn_wifi_refresh, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wifi_btn_wifi_refresh, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wifi_sw_wifi_swich
    ui->screen_wifi_sw_wifi_swich = lv_switch_create(ui->screen_wifi);
    lv_obj_set_pos(ui->screen_wifi_sw_wifi_swich, 56, 19);
    lv_obj_set_size(ui->screen_wifi_sw_wifi_swich, 60, 30);

    //Write style for screen_wifi_sw_wifi_swich, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wifi_sw_wifi_swich, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wifi_sw_wifi_swich, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_sw_wifi_swich, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wifi_sw_wifi_swich, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_sw_wifi_swich, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wifi_sw_wifi_swich, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_wifi_sw_wifi_swich, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_wifi_sw_wifi_swich, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_wifi_sw_wifi_swich, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_sw_wifi_swich, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_wifi_sw_wifi_swich, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_wifi_sw_wifi_swich, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_wifi_sw_wifi_swich, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_wifi_sw_wifi_swich, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_wifi_sw_wifi_swich, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_wifi_sw_wifi_swich, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_sw_wifi_swich, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_wifi_label_wifi_name
    ui->screen_wifi_label_wifi_name = lv_label_create(ui->screen_wifi);
    lv_label_set_text(ui->screen_wifi_label_wifi_name, "WIFI已连接：AP Mode ：WIFI未连接：");
    lv_label_set_long_mode(ui->screen_wifi_label_wifi_name, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_wifi_label_wifi_name, 55, 188);
    lv_obj_set_size(ui->screen_wifi_label_wifi_name, 232, 21);

    //Write style for screen_wifi_label_wifi_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wifi_label_wifi_name, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wifi_label_wifi_name, &lv_font_SourceHanMonoNormal_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wifi_label_wifi_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_wifi_label_wifi_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wifi_label_wifi_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wifi_label_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_wifi_label_wifi_ip
    ui->screen_wifi_label_wifi_ip = lv_label_create(ui->screen_wifi);
    lv_label_set_text(ui->screen_wifi_label_wifi_ip, "IP:");
    lv_label_set_long_mode(ui->screen_wifi_label_wifi_ip, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_wifi_label_wifi_ip, 55, 216);
    lv_obj_set_size(ui->screen_wifi_label_wifi_ip, 232, 20);

    //Write style for screen_wifi_label_wifi_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_wifi_label_wifi_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_wifi_label_wifi_ip, &lv_font_SourceHanMonoNormal_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_wifi_label_wifi_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_wifi_label_wifi_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_wifi_label_wifi_ip, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_wifi_label_wifi_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_wifi.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_wifi);

    //Init events for screen.
    events_init_screen_wifi(ui);
}
