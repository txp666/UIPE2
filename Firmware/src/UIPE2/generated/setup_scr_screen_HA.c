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



void setup_scr_screen_HA(lv_ui *ui)
{
    //Write codes screen_HA
    ui->screen_HA = lv_obj_create(NULL);
    ui->g_kb_screen_HA = lv_keyboard_create(ui->screen_HA);
    lv_obj_add_event_cb(ui->g_kb_screen_HA, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_screen_HA, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_screen_HA, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->screen_HA, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_HA, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_HA, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_HA, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_cont_fan
    ui->screen_HA_cont_fan = lv_obj_create(ui->screen_HA);
    lv_obj_set_pos(ui->screen_HA_cont_fan, 4, 49);
    lv_obj_set_size(ui->screen_HA_cont_fan, 100, 157);
    lv_obj_set_scrollbar_mode(ui->screen_HA_cont_fan, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_HA_cont_fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_HA_cont_fan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_HA_cont_fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_HA_cont_fan, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_HA_cont_fan, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_cont_fan, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_HA_cont_fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA_cont_fan, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_cont_fan, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_HA_cont_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_HA_cont_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_HA_cont_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_HA_cont_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_cont_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_sw_fan
    ui->screen_HA_sw_fan = lv_switch_create(ui->screen_HA_cont_fan);
    lv_obj_set_pos(ui->screen_HA_sw_fan, 35, 118);
    lv_obj_set_size(ui->screen_HA_sw_fan, 61, 30);

    //Write style for screen_HA_sw_fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_HA_sw_fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA_sw_fan, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_sw_fan, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_HA_sw_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_sw_fan, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_sw_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_HA_sw_fan, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_HA_sw_fan, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_HA_sw_fan, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_sw_fan, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_HA_sw_fan, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_HA_sw_fan, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_HA_sw_fan, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA_sw_fan, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_sw_fan, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_HA_sw_fan, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_sw_fan, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_HA_animimg_fan
    ui->screen_HA_animimg_fan = lv_animimg_create(ui->screen_HA_cont_fan);
    lv_animimg_set_src(ui->screen_HA_animimg_fan, (const void **) screen_HA_animimg_fan_imgs, 2, false);
    lv_animimg_set_duration(ui->screen_HA_animimg_fan, 100*2);
    lv_animimg_set_repeat_count(ui->screen_HA_animimg_fan, LV_ANIM_REPEAT_INFINITE);
    lv_img_set_src(ui->screen_HA_animimg_fan, screen_HA_animimg_fan_imgs[0]);
    lv_obj_set_pos(ui->screen_HA_animimg_fan, 17, 34);
    lv_obj_set_size(ui->screen_HA_animimg_fan, 64, 64);

    //Write codes screen_HA_label_fan
    ui->screen_HA_label_fan = lv_label_create(ui->screen_HA_cont_fan);
    lv_label_set_text(ui->screen_HA_label_fan, "风扇");
    lv_label_set_long_mode(ui->screen_HA_label_fan, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_HA_label_fan, 21, 5);
    lv_obj_set_size(ui->screen_HA_label_fan, 55, 23);

    //Write style for screen_HA_label_fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_HA_label_fan, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_HA_label_fan, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_HA_label_fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_HA_label_fan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_HA_label_fan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_label_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_cont_light
    ui->screen_HA_cont_light = lv_obj_create(ui->screen_HA);
    lv_obj_set_pos(ui->screen_HA_cont_light, 110, 49);
    lv_obj_set_size(ui->screen_HA_cont_light, 100, 157);
    lv_obj_set_scrollbar_mode(ui->screen_HA_cont_light, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_HA_cont_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_HA_cont_light, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_HA_cont_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_HA_cont_light, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_HA_cont_light, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_cont_light, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_HA_cont_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA_cont_light, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_cont_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_HA_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_HA_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_HA_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_HA_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_label_light
    ui->screen_HA_label_light = lv_label_create(ui->screen_HA_cont_light);
    lv_label_set_text(ui->screen_HA_label_light, "台灯");
    lv_label_set_long_mode(ui->screen_HA_label_light, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_HA_label_light, 21, 5);
    lv_obj_set_size(ui->screen_HA_label_light, 55, 23);

    //Write style for screen_HA_label_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_HA_label_light, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_HA_label_light, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_HA_label_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_HA_label_light, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_HA_label_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_sw_light
    ui->screen_HA_sw_light = lv_switch_create(ui->screen_HA_cont_light);
    lv_obj_set_pos(ui->screen_HA_sw_light, 35, 118);
    lv_obj_set_size(ui->screen_HA_sw_light, 61, 30);

    //Write style for screen_HA_sw_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_HA_sw_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA_sw_light, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_sw_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_HA_sw_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_sw_light, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_sw_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_HA_sw_light, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_HA_sw_light, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_HA_sw_light, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_sw_light, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_HA_sw_light, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_HA_sw_light, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_HA_sw_light, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA_sw_light, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_sw_light, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_HA_sw_light, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_sw_light, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_HA_img_light_on
    ui->screen_HA_img_light_on = lv_img_create(ui->screen_HA_cont_light);
    lv_obj_add_flag(ui->screen_HA_img_light_on, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_HA_img_light_on, &_light2_alpha_64x64);
    lv_img_set_pivot(ui->screen_HA_img_light_on, 50,50);
    lv_img_set_angle(ui->screen_HA_img_light_on, 0);
    lv_obj_set_pos(ui->screen_HA_img_light_on, 17, 34);
    lv_obj_set_size(ui->screen_HA_img_light_on, 64, 64);
    lv_obj_add_flag(ui->screen_HA_img_light_on, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_HA_img_light_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_HA_img_light_on, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_HA_img_light_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_img_light_on, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_HA_img_light_on, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_img_light_off
    ui->screen_HA_img_light_off = lv_img_create(ui->screen_HA_cont_light);
    lv_obj_add_flag(ui->screen_HA_img_light_off, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_HA_img_light_off, &_light1_alpha_64x64);
    lv_img_set_pivot(ui->screen_HA_img_light_off, 50,50);
    lv_img_set_angle(ui->screen_HA_img_light_off, 0);
    lv_obj_set_pos(ui->screen_HA_img_light_off, 17, 34);
    lv_obj_set_size(ui->screen_HA_img_light_off, 64, 64);

    //Write style for screen_HA_img_light_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_HA_img_light_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_HA_img_light_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_img_light_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_HA_img_light_off, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_cont_temp
    ui->screen_HA_cont_temp = lv_obj_create(ui->screen_HA);
    lv_obj_set_pos(ui->screen_HA_cont_temp, 216, 49);
    lv_obj_set_size(ui->screen_HA_cont_temp, 100, 157);
    lv_obj_set_scrollbar_mode(ui->screen_HA_cont_temp, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_HA_cont_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_HA_cont_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_HA_cont_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_HA_cont_temp, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_HA_cont_temp, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_cont_temp, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_HA_cont_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA_cont_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_cont_temp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_HA_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_HA_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_HA_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_HA_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_arc_temp
    ui->screen_HA_arc_temp = lv_arc_create(ui->screen_HA_cont_temp);
    lv_arc_set_mode(ui->screen_HA_arc_temp, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_HA_arc_temp, 0, 80);
    lv_arc_set_bg_angles(ui->screen_HA_arc_temp, 180, 0);
    lv_arc_set_value(ui->screen_HA_arc_temp, 25);
    lv_arc_set_rotation(ui->screen_HA_arc_temp, 0);
    lv_obj_set_style_arc_rounded(ui->screen_HA_arc_temp, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_HA_arc_temp, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_HA_arc_temp, 7, 30);
    lv_obj_set_size(ui->screen_HA_arc_temp, 80, 111);

    //Write style for screen_HA_arc_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_HA_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_HA_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_HA_arc_temp, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_HA_arc_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_HA_arc_temp, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_HA_arc_temp, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_HA_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_HA_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_HA_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_HA_arc_temp, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_HA_arc_temp, 7, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_HA_arc_temp, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_HA_arc_temp, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_HA_arc_temp, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_HA_arc_temp, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_HA_arc_temp, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_HA_arc_temp, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_HA_arc_temp, 2, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_HA_label_temp2
    ui->screen_HA_label_temp2 = lv_label_create(ui->screen_HA_cont_temp);
    lv_label_set_text(ui->screen_HA_label_temp2, "25°");
    lv_label_set_long_mode(ui->screen_HA_label_temp2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_HA_label_temp2, 24, 75);
    lv_obj_set_size(ui->screen_HA_label_temp2, 55, 31);

    //Write style for screen_HA_label_temp2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_HA_label_temp2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_HA_label_temp2, &lv_font_SourceHanSerifSC_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_HA_label_temp2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_HA_label_temp2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_HA_label_temp2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_label_temp2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_HA_label_temp
    ui->screen_HA_label_temp = lv_label_create(ui->screen_HA_cont_temp);
    lv_label_set_text(ui->screen_HA_label_temp, "温度");
    lv_label_set_long_mode(ui->screen_HA_label_temp, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_HA_label_temp, 21, 5);
    lv_obj_set_size(ui->screen_HA_label_temp, 55, 23);

    //Write style for screen_HA_label_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_HA_label_temp, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_HA_label_temp, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_HA_label_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_HA_label_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_HA_label_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_HA_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_HA.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_HA);

    //Init events for screen.
    events_init_screen_HA(ui);
}
