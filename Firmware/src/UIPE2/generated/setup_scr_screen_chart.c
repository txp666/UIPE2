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



void setup_scr_screen_chart(lv_ui *ui)
{
    //Write codes screen_chart
    ui->screen_chart = lv_obj_create(NULL);
    ui->g_kb_screen_chart = lv_keyboard_create(ui->screen_chart);
    lv_obj_add_event_cb(ui->g_kb_screen_chart, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_screen_chart, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_screen_chart, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->screen_chart, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_chart, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_chart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_chart_chart_1
    ui->screen_chart_chart_1 = lv_chart_create(ui->screen_chart);
    lv_chart_set_type(ui->screen_chart_chart_1, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->screen_chart_chart_1, 5, 10);
    lv_chart_set_point_count(ui->screen_chart_chart_1, 5);
    lv_chart_set_range(ui->screen_chart_chart_1, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    lv_chart_set_axis_tick(ui->screen_chart_chart_1, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 4, true, 40);
    lv_chart_set_range(ui->screen_chart_chart_1, LV_CHART_AXIS_SECONDARY_Y, 0, 20);
    lv_chart_set_axis_tick(ui->screen_chart_chart_1, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 4, true, 40);
    lv_chart_set_zoom_x(ui->screen_chart_chart_1, 256);
    lv_chart_set_zoom_y(ui->screen_chart_chart_1, 256);
    lv_obj_set_style_size(ui->screen_chart_chart_1, 0, LV_PART_INDICATOR);
    lv_obj_set_pos(ui->screen_chart_chart_1, 42, 39);
    lv_obj_set_size(ui->screen_chart_chart_1, 240, 200);
    lv_obj_set_scrollbar_mode(ui->screen_chart_chart_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_chart_chart_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_chart_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_chart_chart_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_chart_chart_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_chart_chart_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_chart_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_chart_chart_1, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_chart_chart_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_chart_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_chart_chart_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_chart_chart_1, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_chart_chart_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_chart_chart_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_chart_chart_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_chart_chart_1, lv_color_hex(0x151212), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_chart_chart_1, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_chart_chart_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_chart_chart_1, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_chart_chart_1, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_chart_chart_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write codes screen_chart_label_screen_chart_unit
    ui->screen_chart_label_screen_chart_unit = lv_label_create(ui->screen_chart);
    lv_label_set_text(ui->screen_chart_label_screen_chart_unit, "μmA");
    lv_label_set_long_mode(ui->screen_chart_label_screen_chart_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_chart_label_screen_chart_unit, 0, 32);
    lv_obj_set_size(ui->screen_chart_label_screen_chart_unit, 42, 20);

    //Write style for screen_chart_label_screen_chart_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_chart_label_screen_chart_unit, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_chart_label_screen_chart_unit, &lv_font_Acme_Regular_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_chart_label_screen_chart_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_chart_label_screen_chart_unit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_chart_label_screen_chart_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_chart_label_screen_chart_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_chart_label_screen_chart_u
    ui->screen_chart_label_screen_chart_u = lv_label_create(ui->screen_chart);
    lv_label_set_text(ui->screen_chart_label_screen_chart_u, "52.160V");
    lv_label_set_long_mode(ui->screen_chart_label_screen_chart_u, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_chart_label_screen_chart_u, 61, 2);
    lv_obj_set_size(ui->screen_chart_label_screen_chart_u, 80, 30);

    //Write style for screen_chart_label_screen_chart_u, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_chart_label_screen_chart_u, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_chart_label_screen_chart_u, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_chart_label_screen_chart_u, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_chart_label_screen_chart_u, &lv_font_SourceHanMonoNormal_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_chart_label_screen_chart_u, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_chart_label_screen_chart_u, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_chart_label_screen_chart_u, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_chart_label_screen_chart_u, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_chart_label_screen_chart_u, 180, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_chart_label_screen_chart_u, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_chart_label_screen_chart_u, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_chart_label_screen_chart_u, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_chart_label_screen_chart_u, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_chart_label_screen_chart_u, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_chart_label_screen_chart_u, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_chart_label_screen_chart_u, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_chart_label_screen_chart_i
    ui->screen_chart_label_screen_chart_i = lv_label_create(ui->screen_chart);
    lv_label_set_text(ui->screen_chart_label_screen_chart_i, "12.1mA");
    lv_label_set_long_mode(ui->screen_chart_label_screen_chart_i, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_chart_label_screen_chart_i, 148, 2);
    lv_obj_set_size(ui->screen_chart_label_screen_chart_i, 80, 30);

    //Write style for screen_chart_label_screen_chart_i, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_chart_label_screen_chart_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_chart_label_screen_chart_i, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_chart_label_screen_chart_i, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_chart_label_screen_chart_i, &lv_font_SourceHanMonoNormal_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_chart_label_screen_chart_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_chart_label_screen_chart_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_chart_label_screen_chart_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_chart_label_screen_chart_i, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_chart_label_screen_chart_i, 180, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_chart_label_screen_chart_i, lv_color_hex(0x00d2ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_chart_label_screen_chart_i, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_chart_label_screen_chart_i, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_chart_label_screen_chart_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_chart_label_screen_chart_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_chart_label_screen_chart_i, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_chart_label_screen_chart_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_chart_label_screen_chart_p
    ui->screen_chart_label_screen_chart_p = lv_label_create(ui->screen_chart);
    lv_label_set_text(ui->screen_chart_label_screen_chart_p, "22.56μW");
    lv_label_set_long_mode(ui->screen_chart_label_screen_chart_p, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_chart_label_screen_chart_p, 235, 2);
    lv_obj_set_size(ui->screen_chart_label_screen_chart_p, 80, 30);

    //Write style for screen_chart_label_screen_chart_p, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_chart_label_screen_chart_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_chart_label_screen_chart_p, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_chart_label_screen_chart_p, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_chart_label_screen_chart_p, &lv_font_SourceHanMonoNormal_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_chart_label_screen_chart_p, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_chart_label_screen_chart_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_chart_label_screen_chart_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_chart_label_screen_chart_p, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_chart_label_screen_chart_p, 163, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_chart_label_screen_chart_p, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_chart_label_screen_chart_p, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_chart_label_screen_chart_p, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_chart_label_screen_chart_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_chart_label_screen_chart_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_chart_label_screen_chart_p, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_chart_label_screen_chart_p, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_chart_btn_screen_chart_play
    ui->screen_chart_btn_screen_chart_play = lv_btn_create(ui->screen_chart);
    ui->screen_chart_btn_screen_chart_play_label = lv_label_create(ui->screen_chart_btn_screen_chart_play);
    lv_label_set_text(ui->screen_chart_btn_screen_chart_play_label, "" LV_SYMBOL_PLAY " " LV_SYMBOL_STOP " ");
    lv_label_set_long_mode(ui->screen_chart_btn_screen_chart_play_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_chart_btn_screen_chart_play_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_chart_btn_screen_chart_play, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_chart_btn_screen_chart_play_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_chart_btn_screen_chart_play, 4, 2);
    lv_obj_set_size(ui->screen_chart_btn_screen_chart_play, 50, 30);

    //Write style for screen_chart_btn_screen_chart_play, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_chart_btn_screen_chart_play, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_chart_btn_screen_chart_play, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_chart_btn_screen_chart_play, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_chart_btn_screen_chart_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_chart_btn_screen_chart_play, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_chart_btn_screen_chart_play, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_chart_btn_screen_chart_play, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_chart_btn_screen_chart_play, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_chart_btn_screen_chart_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_chart_btn_screen_chart_play, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_chart_btn_screen_chart_play, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_chart_btn_screen_chart_play, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_chart_btn_screen_chart_play, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_chart_btn_screen_chart_play, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_chart_btn_screen_chart_play, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_chart.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_chart);

    //Init events for screen.
    events_init_screen_chart(ui);
}
