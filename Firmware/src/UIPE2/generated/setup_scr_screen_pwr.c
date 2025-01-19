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



void setup_scr_screen_pwr(lv_ui *ui)
{
    //Write codes screen_pwr
    ui->screen_pwr = lv_obj_create(NULL);
    ui->g_kb_screen_pwr = lv_keyboard_create(ui->screen_pwr);
    lv_obj_add_event_cb(ui->g_kb_screen_pwr, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_screen_pwr, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_screen_pwr, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->screen_pwr, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_pwr, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_pwr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_pwr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_pwr, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_pwr, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_pwr_btn_pwr_5
    ui->screen_pwr_btn_pwr_5 = lv_btn_create(ui->screen_pwr);
    ui->screen_pwr_btn_pwr_5_label = lv_label_create(ui->screen_pwr_btn_pwr_5);
    lv_label_set_text(ui->screen_pwr_btn_pwr_5_label, "5V");
    lv_label_set_long_mode(ui->screen_pwr_btn_pwr_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_pwr_btn_pwr_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_pwr_btn_pwr_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_pwr_btn_pwr_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_pwr_btn_pwr_5, 21, 56);
    lv_obj_set_size(ui->screen_pwr_btn_pwr_5, 80, 50);

    //Write style for screen_pwr_btn_pwr_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_pwr_btn_pwr_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_pwr_btn_pwr_5, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_pwr_btn_pwr_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_pwr_btn_pwr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_pwr_btn_pwr_5, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_pwr_btn_pwr_5, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_pwr_btn_pwr_5, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_pwr_btn_pwr_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_pwr_btn_pwr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_pwr_btn_pwr_5, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_pwr_btn_pwr_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_pwr_btn_pwr_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_pwr_btn_pwr_5, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_pwr_btn_pwr_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_pwr_btn_pwr_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_pwr_btn_pwr_9
    ui->screen_pwr_btn_pwr_9 = lv_btn_create(ui->screen_pwr);
    ui->screen_pwr_btn_pwr_9_label = lv_label_create(ui->screen_pwr_btn_pwr_9);
    lv_label_set_text(ui->screen_pwr_btn_pwr_9_label, "9V");
    lv_label_set_long_mode(ui->screen_pwr_btn_pwr_9_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_pwr_btn_pwr_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_pwr_btn_pwr_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_pwr_btn_pwr_9_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_pwr_btn_pwr_9, 122, 56);
    lv_obj_set_size(ui->screen_pwr_btn_pwr_9, 80, 50);

    //Write style for screen_pwr_btn_pwr_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_pwr_btn_pwr_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_pwr_btn_pwr_9, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_pwr_btn_pwr_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_pwr_btn_pwr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_pwr_btn_pwr_9, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_pwr_btn_pwr_9, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_pwr_btn_pwr_9, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_pwr_btn_pwr_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_pwr_btn_pwr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_pwr_btn_pwr_9, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_pwr_btn_pwr_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_pwr_btn_pwr_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_pwr_btn_pwr_9, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_pwr_btn_pwr_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_pwr_btn_pwr_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_pwr_btn_pwr_12
    ui->screen_pwr_btn_pwr_12 = lv_btn_create(ui->screen_pwr);
    ui->screen_pwr_btn_pwr_12_label = lv_label_create(ui->screen_pwr_btn_pwr_12);
    lv_label_set_text(ui->screen_pwr_btn_pwr_12_label, "12V");
    lv_label_set_long_mode(ui->screen_pwr_btn_pwr_12_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_pwr_btn_pwr_12_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_pwr_btn_pwr_12, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_pwr_btn_pwr_12_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_pwr_btn_pwr_12, 223, 56);
    lv_obj_set_size(ui->screen_pwr_btn_pwr_12, 80, 50);

    //Write style for screen_pwr_btn_pwr_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_pwr_btn_pwr_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_pwr_btn_pwr_12, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_pwr_btn_pwr_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_pwr_btn_pwr_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_pwr_btn_pwr_12, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_pwr_btn_pwr_12, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_pwr_btn_pwr_12, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_pwr_btn_pwr_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_pwr_btn_pwr_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_pwr_btn_pwr_12, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_pwr_btn_pwr_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_pwr_btn_pwr_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_pwr_btn_pwr_12, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_pwr_btn_pwr_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_pwr_btn_pwr_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_pwr_btn_pwr_15
    ui->screen_pwr_btn_pwr_15 = lv_btn_create(ui->screen_pwr);
    ui->screen_pwr_btn_pwr_15_label = lv_label_create(ui->screen_pwr_btn_pwr_15);
    lv_label_set_text(ui->screen_pwr_btn_pwr_15_label, "15V");
    lv_label_set_long_mode(ui->screen_pwr_btn_pwr_15_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_pwr_btn_pwr_15_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_pwr_btn_pwr_15, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_pwr_btn_pwr_15_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_pwr_btn_pwr_15, 21, 133);
    lv_obj_set_size(ui->screen_pwr_btn_pwr_15, 80, 50);

    //Write style for screen_pwr_btn_pwr_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_pwr_btn_pwr_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_pwr_btn_pwr_15, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_pwr_btn_pwr_15, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_pwr_btn_pwr_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_pwr_btn_pwr_15, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_pwr_btn_pwr_15, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_pwr_btn_pwr_15, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_pwr_btn_pwr_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_pwr_btn_pwr_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_pwr_btn_pwr_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_pwr_btn_pwr_15, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_pwr_btn_pwr_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_pwr_btn_pwr_15, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_pwr_btn_pwr_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_pwr_btn_pwr_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_pwr_btn_pwr_20
    ui->screen_pwr_btn_pwr_20 = lv_btn_create(ui->screen_pwr);
    ui->screen_pwr_btn_pwr_20_label = lv_label_create(ui->screen_pwr_btn_pwr_20);
    lv_label_set_text(ui->screen_pwr_btn_pwr_20_label, "20V");
    lv_label_set_long_mode(ui->screen_pwr_btn_pwr_20_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_pwr_btn_pwr_20_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_pwr_btn_pwr_20, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_pwr_btn_pwr_20_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_pwr_btn_pwr_20, 125, 133);
    lv_obj_set_size(ui->screen_pwr_btn_pwr_20, 80, 50);

    //Write style for screen_pwr_btn_pwr_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_pwr_btn_pwr_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_pwr_btn_pwr_20, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_pwr_btn_pwr_20, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_pwr_btn_pwr_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_pwr_btn_pwr_20, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_pwr_btn_pwr_20, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_pwr_btn_pwr_20, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_pwr_btn_pwr_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_pwr_btn_pwr_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_pwr_btn_pwr_20, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_pwr_btn_pwr_20, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_pwr_btn_pwr_20, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_pwr_btn_pwr_20, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_pwr_btn_pwr_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_pwr_btn_pwr_20, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_pwr_spinbox_pwr_u
    ui->screen_pwr_spinbox_pwr_u = lv_spinbox_create(ui->screen_pwr);
    lv_obj_set_pos(ui->screen_pwr_spinbox_pwr_u, 54, 14);
    lv_obj_set_width(ui->screen_pwr_spinbox_pwr_u, 213);
    lv_obj_set_height(ui->screen_pwr_spinbox_pwr_u, 39);
    lv_spinbox_set_digit_format(ui->screen_pwr_spinbox_pwr_u, 4, 2);
    lv_spinbox_set_range(ui->screen_pwr_spinbox_pwr_u, -9999, 9999);
    lv_coord_t screen_pwr_spinbox_pwr_u_h = lv_obj_get_height(ui->screen_pwr_spinbox_pwr_u);
    ui->screen_pwr_spinbox_pwr_u_btn = lv_btn_create(ui->screen_pwr);
    lv_obj_set_size(ui->screen_pwr_spinbox_pwr_u_btn, screen_pwr_spinbox_pwr_u_h, screen_pwr_spinbox_pwr_u_h);
    lv_obj_align_to(ui->screen_pwr_spinbox_pwr_u_btn, ui->screen_pwr_spinbox_pwr_u, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_img_src(ui->screen_pwr_spinbox_pwr_u_btn, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->screen_pwr_spinbox_pwr_u_btn, lv_screen_pwr_spinbox_pwr_u_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->screen_pwr_spinbox_pwr_u_btn_minus = lv_btn_create(ui->screen_pwr);
    lv_obj_set_size(ui->screen_pwr_spinbox_pwr_u_btn_minus, screen_pwr_spinbox_pwr_u_h, screen_pwr_spinbox_pwr_u_h);
    lv_obj_align_to(ui->screen_pwr_spinbox_pwr_u_btn_minus, ui->screen_pwr_spinbox_pwr_u, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_img_src(ui->screen_pwr_spinbox_pwr_u_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->screen_pwr_spinbox_pwr_u_btn_minus, lv_screen_pwr_spinbox_pwr_u_decrement_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->screen_pwr_spinbox_pwr_u_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_pwr_spinbox_pwr_u_btn_minus, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_pos(ui->screen_pwr_spinbox_pwr_u, 54, 14);
    lv_obj_add_flag(ui->screen_pwr_spinbox_pwr_u, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_pwr_spinbox_pwr_u, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_pwr_spinbox_pwr_u, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_pwr_spinbox_pwr_u, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_pwr_spinbox_pwr_u, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_pwr_spinbox_pwr_u, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_pwr_spinbox_pwr_u, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_pwr_spinbox_pwr_u, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_pwr_spinbox_pwr_u, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_pwr_spinbox_pwr_u, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_pwr_spinbox_pwr_u, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_pwr_spinbox_pwr_u, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_pwr_spinbox_pwr_u, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_pwr_spinbox_pwr_u, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_pwr_spinbox_pwr_u, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_pwr_spinbox_pwr_u, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_pwr_spinbox_pwr_u, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_pwr_spinbox_pwr_u, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_pwr_spinbox_pwr_u, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_pwr_spinbox_pwr_u, &lv_font_montserratMedium_20, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_pwr_spinbox_pwr_u, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_pwr_spinbox_pwr_u, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_pwr_spinbox_pwr_u, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_pwr_spinbox_pwr_u, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_pwr_spinbox_pwr_u_extra_btns_main_default
    static lv_style_t style_screen_pwr_spinbox_pwr_u_extra_btns_main_default;
    ui_init_style(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default);

    lv_style_set_text_color(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, lv_color_hex(0x000000));
    lv_style_set_text_font(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, 0);
    lv_style_set_border_width(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, 2);
    lv_style_set_border_opa(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, 255);
    lv_style_set_border_color(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_border_side(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_pwr_spinbox_pwr_u_btn, &style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_pwr_spinbox_pwr_u_btn_minus, &style_screen_pwr_spinbox_pwr_u_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_pwr.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_pwr);

    //Init events for screen.
    events_init_screen_pwr(ui);
}
