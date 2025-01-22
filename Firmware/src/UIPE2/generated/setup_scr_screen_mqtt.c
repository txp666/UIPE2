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



void setup_scr_screen_mqtt(lv_ui *ui)
{
    //Write codes screen_mqtt
    ui->screen_mqtt = lv_obj_create(NULL);
    ui->g_kb_screen_mqtt = lv_keyboard_create(ui->screen_mqtt);
    lv_obj_add_event_cb(ui->g_kb_screen_mqtt, kb_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui->g_kb_screen_mqtt, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui->g_kb_screen_mqtt, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_size(ui->screen_mqtt, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_mqtt, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_mqtt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mqtt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mqtt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mqtt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mqtt_btn_mqtt_return
    ui->screen_mqtt_btn_mqtt_return = lv_btn_create(ui->screen_mqtt);
    ui->screen_mqtt_btn_mqtt_return_label = lv_label_create(ui->screen_mqtt_btn_mqtt_return);
    lv_label_set_text(ui->screen_mqtt_btn_mqtt_return_label, "" LV_SYMBOL_LEFT " ");
    lv_label_set_long_mode(ui->screen_mqtt_btn_mqtt_return_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_mqtt_btn_mqtt_return_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_mqtt_btn_mqtt_return, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_mqtt_btn_mqtt_return_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_mqtt_btn_mqtt_return, 0, 12);
    lv_obj_set_size(ui->screen_mqtt_btn_mqtt_return, 21, 215);

    //Write style for screen_mqtt_btn_mqtt_return, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mqtt_btn_mqtt_return, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mqtt_btn_mqtt_return, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mqtt_btn_mqtt_return, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_mqtt_btn_mqtt_return, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mqtt_btn_mqtt_return, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mqtt_btn_mqtt_return, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_mqtt_btn_mqtt_return, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_mqtt_btn_mqtt_return, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_mqtt_btn_mqtt_return, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_mqtt_btn_mqtt_return, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_mqtt_btn_mqtt_return, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mqtt_btn_mqtt_return, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mqtt_btn_mqtt_return, &lv_font_montserratMedium_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mqtt_btn_mqtt_return, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mqtt_btn_mqtt_return, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mqtt_ta_mqtt_ip
    ui->screen_mqtt_ta_mqtt_ip = lv_textarea_create(ui->screen_mqtt);
    lv_textarea_set_text(ui->screen_mqtt_ta_mqtt_ip, "192.168.1.1");
    lv_textarea_set_placeholder_text(ui->screen_mqtt_ta_mqtt_ip, "");
    lv_textarea_set_password_bullet(ui->screen_mqtt_ta_mqtt_ip, "*");
    lv_textarea_set_password_mode(ui->screen_mqtt_ta_mqtt_ip, false);
    lv_textarea_set_one_line(ui->screen_mqtt_ta_mqtt_ip, true);
    lv_textarea_set_accepted_chars(ui->screen_mqtt_ta_mqtt_ip, "");
    lv_textarea_set_max_length(ui->screen_mqtt_ta_mqtt_ip, 32);
#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
    lv_obj_add_event_cb(ui->screen_mqtt_ta_mqtt_ip, ta_event_cb, LV_EVENT_ALL, ui->g_kb_screen_mqtt);
#endif
    lv_obj_set_pos(ui->screen_mqtt_ta_mqtt_ip, 55, 34);
    lv_obj_set_size(ui->screen_mqtt_ta_mqtt_ip, 148, 37);

    //Write style for screen_mqtt_ta_mqtt_ip, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_mqtt_ta_mqtt_ip, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mqtt_ta_mqtt_ip, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mqtt_ta_mqtt_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mqtt_ta_mqtt_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mqtt_ta_mqtt_ip, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mqtt_ta_mqtt_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mqtt_ta_mqtt_ip, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mqtt_ta_mqtt_ip, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_mqtt_ta_mqtt_ip, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_mqtt_ta_mqtt_ip, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_mqtt_ta_mqtt_ip, lv_color_hex(0x6000c7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_mqtt_ta_mqtt_ip, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mqtt_ta_mqtt_ip, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mqtt_ta_mqtt_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mqtt_ta_mqtt_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mqtt_ta_mqtt_ip, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mqtt_ta_mqtt_ip, 6, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mqtt_label_mqtt_info
    ui->screen_mqtt_label_mqtt_info = lv_label_create(ui->screen_mqtt);
    lv_label_set_text(ui->screen_mqtt_label_mqtt_info, "");
    lv_label_set_long_mode(ui->screen_mqtt_label_mqtt_info, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_mqtt_label_mqtt_info, 55, 206);
    lv_obj_set_size(ui->screen_mqtt_label_mqtt_info, 232, 20);

    //Write style for screen_mqtt_label_mqtt_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mqtt_label_mqtt_info, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mqtt_label_mqtt_info, &lv_font_SourceHanMonoNormal_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mqtt_label_mqtt_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mqtt_label_mqtt_info, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mqtt_label_mqtt_info, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mqtt_label_mqtt_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mqtt_ta_mqtt_port
    ui->screen_mqtt_ta_mqtt_port = lv_textarea_create(ui->screen_mqtt);
    lv_textarea_set_text(ui->screen_mqtt_ta_mqtt_port, "1883");
    lv_textarea_set_placeholder_text(ui->screen_mqtt_ta_mqtt_port, "");
    lv_textarea_set_password_bullet(ui->screen_mqtt_ta_mqtt_port, "*");
    lv_textarea_set_password_mode(ui->screen_mqtt_ta_mqtt_port, false);
    lv_textarea_set_one_line(ui->screen_mqtt_ta_mqtt_port, true);
    lv_textarea_set_accepted_chars(ui->screen_mqtt_ta_mqtt_port, "");
    lv_textarea_set_max_length(ui->screen_mqtt_ta_mqtt_port, 32);
#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
    lv_obj_add_event_cb(ui->screen_mqtt_ta_mqtt_port, ta_event_cb, LV_EVENT_ALL, ui->g_kb_screen_mqtt);
#endif
    lv_obj_set_pos(ui->screen_mqtt_ta_mqtt_port, 225, 34);
    lv_obj_set_size(ui->screen_mqtt_ta_mqtt_port, 78, 37);

    //Write style for screen_mqtt_ta_mqtt_port, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_mqtt_ta_mqtt_port, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mqtt_ta_mqtt_port, &lv_font_SourceHanSerifSC_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mqtt_ta_mqtt_port, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mqtt_ta_mqtt_port, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mqtt_ta_mqtt_port, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mqtt_ta_mqtt_port, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mqtt_ta_mqtt_port, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mqtt_ta_mqtt_port, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_mqtt_ta_mqtt_port, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_mqtt_ta_mqtt_port, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_mqtt_ta_mqtt_port, lv_color_hex(0x6000c7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_mqtt_ta_mqtt_port, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mqtt_ta_mqtt_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mqtt_ta_mqtt_port, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mqtt_ta_mqtt_port, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mqtt_ta_mqtt_port, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mqtt_ta_mqtt_port, 6, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mqtt_btn_mqtt_connect
    ui->screen_mqtt_btn_mqtt_connect = lv_btn_create(ui->screen_mqtt);
    ui->screen_mqtt_btn_mqtt_connect_label = lv_label_create(ui->screen_mqtt_btn_mqtt_connect);
    lv_label_set_text(ui->screen_mqtt_btn_mqtt_connect_label, "" LV_SYMBOL_GPS " ");
    lv_label_set_long_mode(ui->screen_mqtt_btn_mqtt_connect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_mqtt_btn_mqtt_connect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_mqtt_btn_mqtt_connect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_mqtt_btn_mqtt_connect_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_mqtt_btn_mqtt_connect, 58, 88);
    lv_obj_set_size(ui->screen_mqtt_btn_mqtt_connect, 86, 40);

    //Write style for screen_mqtt_btn_mqtt_connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mqtt_btn_mqtt_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_mqtt_btn_mqtt_connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mqtt_btn_mqtt_connect, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mqtt_btn_mqtt_connect, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_mqtt_btn_mqtt_connect, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_mqtt_btn_mqtt_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_mqtt_btn_mqtt_connect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_mqtt_btn_mqtt_connect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_mqtt_btn_mqtt_connect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mqtt_btn_mqtt_connect, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mqtt_btn_mqtt_connect, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mqtt_btn_mqtt_connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mqtt_btn_mqtt_connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mqtt_label_1
    ui->screen_mqtt_label_1 = lv_label_create(ui->screen_mqtt);
    lv_label_set_text(ui->screen_mqtt_label_1, "MQTT:");
    lv_label_set_long_mode(ui->screen_mqtt_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_mqtt_label_1, 58, 8);
    lv_obj_set_size(ui->screen_mqtt_label_1, 69, 20);

    //Write style for screen_mqtt_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mqtt_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mqtt_label_1, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mqtt_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mqtt_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mqtt_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mqtt_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mqtt_btn_mqtt_disconnect
    ui->screen_mqtt_btn_mqtt_disconnect = lv_btn_create(ui->screen_mqtt);
    ui->screen_mqtt_btn_mqtt_disconnect_label = lv_label_create(ui->screen_mqtt_btn_mqtt_disconnect);
    lv_label_set_text(ui->screen_mqtt_btn_mqtt_disconnect_label, "" LV_SYMBOL_CLOSE " ");
    lv_label_set_long_mode(ui->screen_mqtt_btn_mqtt_disconnect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_mqtt_btn_mqtt_disconnect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_mqtt_btn_mqtt_disconnect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_mqtt_btn_mqtt_disconnect_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_mqtt_btn_mqtt_disconnect, 194, 88);
    lv_obj_set_size(ui->screen_mqtt_btn_mqtt_disconnect, 86, 40);

    //Write style for screen_mqtt_btn_mqtt_disconnect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mqtt_btn_mqtt_disconnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_mqtt_btn_mqtt_disconnect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mqtt_btn_mqtt_disconnect, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mqtt_btn_mqtt_disconnect, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_mqtt_btn_mqtt_disconnect, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_mqtt_btn_mqtt_disconnect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_mqtt_btn_mqtt_disconnect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->screen_mqtt_btn_mqtt_disconnect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->screen_mqtt_btn_mqtt_disconnect, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mqtt_btn_mqtt_disconnect, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mqtt_btn_mqtt_disconnect, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mqtt_btn_mqtt_disconnect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mqtt_btn_mqtt_disconnect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_mqtt.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_mqtt);

    //Init events for screen.
    events_init_screen_mqtt(ui);
}
