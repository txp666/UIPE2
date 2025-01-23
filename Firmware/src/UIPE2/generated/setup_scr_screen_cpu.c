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



void setup_scr_screen_cpu(lv_ui *ui)
{
    //Write codes screen_cpu
    ui->screen_cpu = lv_obj_create(NULL);
    ui->g_kb_screen_cpu = lv_keyboard_create(ui->screen_cpu);
    lv_obj_add_event_cb(ui->g_kb_screen_cpu, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_screen_cpu, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_screen_cpu, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->screen_cpu, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_cpu, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_cont_cpu
    ui->screen_cpu_cont_cpu = lv_obj_create(ui->screen_cpu);
    lv_obj_set_pos(ui->screen_cpu_cont_cpu, 20, 43);
    lv_obj_set_size(ui->screen_cpu_cont_cpu, 125, 173);
    lv_obj_set_scrollbar_mode(ui->screen_cpu_cont_cpu, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cpu_cont_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_cont_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu_cont_cpu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu_cont_cpu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_cont_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_label_cpu2
    ui->screen_cpu_label_cpu2 = lv_label_create(ui->screen_cpu_cont_cpu);
    lv_label_set_text(ui->screen_cpu_label_cpu2, "cpu:");
    lv_label_set_long_mode(ui->screen_cpu_label_cpu2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_cpu_label_cpu2, 26, 113);
    lv_obj_set_size(ui->screen_cpu_label_cpu2, 71, 32);

    //Write style for screen_cpu_label_cpu2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu_label_cpu2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu_label_cpu2, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu_label_cpu2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cpu_label_cpu2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_cpu_label_cpu2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_label_cpu2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_label_cpu
    ui->screen_cpu_label_cpu = lv_label_create(ui->screen_cpu_cont_cpu);
    lv_label_set_text(ui->screen_cpu_label_cpu, "30%");
    lv_label_set_long_mode(ui->screen_cpu_label_cpu, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_cpu_label_cpu, 20, 46);
    lv_obj_set_size(ui->screen_cpu_label_cpu, 82, 32);

    //Write style for screen_cpu_label_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu_label_cpu, lv_color_hex(0x017d2e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu_label_cpu, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu_label_cpu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cpu_label_cpu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_cpu_label_cpu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_label_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_arc_cpu
    ui->screen_cpu_arc_cpu = lv_arc_create(ui->screen_cpu_cont_cpu);
    lv_arc_set_mode(ui->screen_cpu_arc_cpu, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_cpu_arc_cpu, 0, 100);
    lv_arc_set_bg_angles(ui->screen_cpu_arc_cpu, 135, 45);
    lv_arc_set_value(ui->screen_cpu_arc_cpu, 30);
    lv_arc_set_rotation(ui->screen_cpu_arc_cpu, 0);
    lv_obj_set_pos(ui->screen_cpu_arc_cpu, 0, 0);
    lv_obj_set_size(ui->screen_cpu_arc_cpu, 120, 120);

    //Write style for screen_cpu_arc_cpu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_cpu_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cpu_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_cpu_arc_cpu, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_cpu_arc_cpu, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_cpu_arc_cpu, lv_color_hex(0x010109), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_arc_cpu, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_arc_cpu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cpu_arc_cpu, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_cpu_arc_cpu, 4, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_cpu_arc_cpu, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_cpu_arc_cpu, lv_color_hex(0x017d2e), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_cpu_arc_cpu, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_cpu_arc_cpu, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu_arc_cpu, lv_color_hex(0x017d2e), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu_arc_cpu, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_cpu_arc_cpu, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_cpu_cont_mem
    ui->screen_cpu_cont_mem = lv_obj_create(ui->screen_cpu);
    lv_obj_set_pos(ui->screen_cpu_cont_mem, 185, 43);
    lv_obj_set_size(ui->screen_cpu_cont_mem, 125, 173);
    lv_obj_set_scrollbar_mode(ui->screen_cpu_cont_mem, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cpu_cont_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_cont_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu_cont_mem, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu_cont_mem, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_cont_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_label_mem3
    ui->screen_cpu_label_mem3 = lv_label_create(ui->screen_cpu_cont_mem);
    lv_label_set_text(ui->screen_cpu_label_mem3, "mem:");
    lv_label_set_long_mode(ui->screen_cpu_label_mem3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_cpu_label_mem3, 28, 113);
    lv_obj_set_size(ui->screen_cpu_label_mem3, 71, 32);

    //Write style for screen_cpu_label_mem3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu_label_mem3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu_label_mem3, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu_label_mem3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cpu_label_mem3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_cpu_label_mem3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_label_mem3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_label_mem
    ui->screen_cpu_label_mem = lv_label_create(ui->screen_cpu_cont_mem);
    lv_label_set_text(ui->screen_cpu_label_mem, "30%");
    lv_label_set_long_mode(ui->screen_cpu_label_mem, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_cpu_label_mem, 12, 50);
    lv_obj_set_size(ui->screen_cpu_label_mem, 100, 32);

    //Write style for screen_cpu_label_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu_label_mem, lv_color_hex(0x3700ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu_label_mem, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu_label_mem, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cpu_label_mem, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_cpu_label_mem, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_label_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_arc_mem
    ui->screen_cpu_arc_mem = lv_arc_create(ui->screen_cpu_cont_mem);
    lv_arc_set_mode(ui->screen_cpu_arc_mem, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_cpu_arc_mem, 0, 100);
    lv_arc_set_bg_angles(ui->screen_cpu_arc_mem, 135, 45);
    lv_arc_set_value(ui->screen_cpu_arc_mem, 30);
    lv_arc_set_rotation(ui->screen_cpu_arc_mem, 0);
    lv_obj_set_pos(ui->screen_cpu_arc_mem, 0, 0);
    lv_obj_set_size(ui->screen_cpu_arc_mem, 120, 120);

    //Write style for screen_cpu_arc_mem, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_cpu_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cpu_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_cpu_arc_mem, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_cpu_arc_mem, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_cpu_arc_mem, lv_color_hex(0x010109), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_arc_mem, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_arc_mem, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cpu_arc_mem, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_cpu_arc_mem, 4, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_cpu_arc_mem, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_cpu_arc_mem, lv_color_hex(0x3700ff), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_cpu_arc_mem, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_cpu_arc_mem, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu_arc_mem, lv_color_hex(0x3700ff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu_arc_mem, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_cpu_arc_mem, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_cpu_label_mem2
    ui->screen_cpu_label_mem2 = lv_label_create(ui->screen_cpu_cont_mem);
    lv_label_set_text(ui->screen_cpu_label_mem2, "32/64GB");
    lv_label_set_long_mode(ui->screen_cpu_label_mem2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_cpu_label_mem2, 8, 70);
    lv_obj_set_size(ui->screen_cpu_label_mem2, 106, 32);

    //Write style for screen_cpu_label_mem2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu_label_mem2, lv_color_hex(0x3700ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu_label_mem2, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu_label_mem2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cpu_label_mem2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_cpu_label_mem2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_label_mem2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_label_time
    ui->screen_cpu_label_time = lv_label_create(ui->screen_cpu);
    lv_label_set_text(ui->screen_cpu_label_time, "星期日一二三四五六七八九十月");
    lv_label_set_long_mode(ui->screen_cpu_label_time, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_cpu_label_time, 74, 206);
    lv_obj_set_size(ui->screen_cpu_label_time, 171, 27);

    //Write style for screen_cpu_label_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu_label_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu_label_time, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu_label_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cpu_label_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_cpu_label_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_cpu.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_cpu);

    //Init events for screen.
    events_init_screen_cpu(ui);
}
