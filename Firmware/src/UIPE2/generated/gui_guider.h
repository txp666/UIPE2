/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_start;
	bool screen_start_del;
	lv_obj_t *g_kb_screen_start;
	lv_obj_t *screen_start_label_1;
	lv_obj_t *screen_home;
	bool screen_home_del;
	lv_obj_t *g_kb_screen_home;
	lv_obj_t *screen_home_label_screen_home_U;
	lv_obj_t *screen_home_label_screen_home_I;
	lv_obj_t *screen_home_label_screen_home_P;
	lv_obj_t *screen_home_cont_1;
	lv_obj_t *screen_home_label_screen_home_temp;
	lv_obj_t *screen_home_label_screen_home_ene;
	lv_obj_t *screen_home_label_screen_home_time;
	lv_obj_t *screen_home_btn_home_set_u;
	lv_obj_t *screen_home_btn_home_set_u_label;
	lv_obj_t *screen_home_btn_home_clear;
	lv_obj_t *screen_home_btn_home_clear_label;
	lv_obj_t *screen_chart;
	bool screen_chart_del;
	lv_obj_t *g_kb_screen_chart;
	lv_obj_t *screen_chart_chart_1;
	lv_obj_t *screen_chart_label_screen_chart_unit;
	lv_obj_t *screen_chart_label_screen_chart_u;
	lv_obj_t *screen_chart_label_screen_chart_i;
	lv_obj_t *screen_chart_label_screen_chart_p;
	lv_obj_t *screen_chart_btn_screen_chart_play;
	lv_obj_t *screen_chart_btn_screen_chart_play_label;
	lv_obj_t *screen_time;
	bool screen_time_del;
	lv_obj_t *g_kb_screen_time;
	lv_obj_t *screen_time_cont_1;
	lv_obj_t *screen_time_line_1;
	lv_obj_t *screen_time_label_time_hour;
	lv_obj_t *screen_time_label_time_min;
	lv_obj_t *screen_time_label_time_date;
	lv_obj_t *screen_time_animimg_1;
	lv_obj_t *screen_HA;
	bool screen_HA_del;
	lv_obj_t *g_kb_screen_HA;
	lv_obj_t *screen_HA_cont_fan;
	lv_obj_t *screen_HA_sw_fan;
	lv_obj_t *screen_HA_animimg_fan;
	lv_obj_t *screen_HA_label_fan;
	lv_obj_t *screen_HA_cont_light;
	lv_obj_t *screen_HA_label_light;
	lv_obj_t *screen_HA_sw_light;
	lv_obj_t *screen_HA_img_light_on;
	lv_obj_t *screen_HA_img_light_off;
	lv_obj_t *screen_HA_cont_temp;
	lv_obj_t *screen_HA_arc_temp;
	lv_obj_t *screen_HA_label_temp2;
	lv_obj_t *screen_HA_label_temp;
	lv_obj_t *screen_menu;
	bool screen_menu_del;
	lv_obj_t *g_kb_screen_menu;
	lv_obj_t *screen_menu_btn_menu_setting;
	lv_obj_t *screen_menu_btn_menu_setting_label;
	lv_obj_t *screen_menu_btn_menu_home;
	lv_obj_t *screen_menu_btn_menu_home_label;
	lv_obj_t *screen_menu_btn_menu_wifi;
	lv_obj_t *screen_menu_btn_menu_wifi_label;
	lv_obj_t *screen_menu_btn_menu_mqtt;
	lv_obj_t *screen_menu_btn_menu_mqtt_label;
	lv_obj_t *screen_setting;
	bool screen_setting_del;
	lv_obj_t *g_kb_screen_setting;
	lv_obj_t *screen_setting_slider_setting_light;
	lv_obj_t *screen_setting_label_setting_light;
	lv_obj_t *screen_setting_btn_setting_return;
	lv_obj_t *screen_setting_btn_setting_return_label;
	lv_obj_t *screen_pwr;
	bool screen_pwr_del;
	lv_obj_t *g_kb_screen_pwr;
	lv_obj_t *screen_pwr_btn_pwr_5;
	lv_obj_t *screen_pwr_btn_pwr_5_label;
	lv_obj_t *screen_pwr_btn_pwr_9;
	lv_obj_t *screen_pwr_btn_pwr_9_label;
	lv_obj_t *screen_pwr_btn_pwr_12;
	lv_obj_t *screen_pwr_btn_pwr_12_label;
	lv_obj_t *screen_pwr_btn_pwr_15;
	lv_obj_t *screen_pwr_btn_pwr_15_label;
	lv_obj_t *screen_pwr_btn_pwr_20;
	lv_obj_t *screen_pwr_btn_pwr_20_label;
	lv_obj_t *screen_pwr_spinbox_pwr_u;
	lv_obj_t *screen_pwr_spinbox_pwr_u_btn;
	lv_obj_t *screen_pwr_spinbox_pwr_u_btn_minus;
	lv_obj_t *screen_wifi;
	bool screen_wifi_del;
	lv_obj_t *g_kb_screen_wifi;
	lv_obj_t *screen_wifi_ddlist_wifi;
	lv_obj_t *screen_wifi_btn_wifi_return;
	lv_obj_t *screen_wifi_btn_wifi_return_label;
	lv_obj_t *screen_wifi_ta_wifi_code;
	lv_obj_t *screen_wifi_btn_wifi_connect;
	lv_obj_t *screen_wifi_btn_wifi_connect_label;
	lv_obj_t *screen_wifi_btn_wifi_refresh;
	lv_obj_t *screen_wifi_btn_wifi_refresh_label;
	lv_obj_t *screen_wifi_sw_wifi_swich;
	lv_obj_t *screen_wifi_label_wifi_name;
	lv_obj_t *screen_wifi_label_wifi_ip;
	lv_obj_t *screen_mqtt;
	bool screen_mqtt_del;
	lv_obj_t *g_kb_screen_mqtt;
	lv_obj_t *screen_mqtt_btn_mqtt_return;
	lv_obj_t *screen_mqtt_btn_mqtt_return_label;
	lv_obj_t *screen_mqtt_ta_mqtt_ip;
	lv_obj_t *screen_mqtt_label_mqtt_info;
	lv_obj_t *screen_mqtt_ta_mqtt_port;
	lv_obj_t *screen_mqtt_btn_mqtt_connect;
	lv_obj_t *screen_mqtt_btn_mqtt_connect_label;
	lv_obj_t *screen_mqtt_label_1;
	lv_obj_t *screen_mqtt_btn_mqtt_disconnect;
	lv_obj_t *screen_mqtt_btn_mqtt_disconnect_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_screen_start(lv_ui *ui);
void setup_scr_screen_home(lv_ui *ui);
void setup_scr_screen_chart(lv_ui *ui);
void setup_scr_screen_time(lv_ui *ui);
void setup_scr_screen_HA(lv_ui *ui);
void setup_scr_screen_menu(lv_ui *ui);
void setup_scr_screen_setting(lv_ui *ui);
void setup_scr_screen_pwr(lv_ui *ui);
void setup_scr_screen_wifi(lv_ui *ui);
void setup_scr_screen_mqtt(lv_ui *ui);
#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(screen_time_animimg_101);
LV_IMG_DECLARE(screen_time_animimg_102);
LV_IMG_DECLARE(screen_time_animimg_103);
LV_IMG_DECLARE(screen_time_animimg_104);
LV_IMG_DECLARE(screen_time_animimg_105);
LV_IMG_DECLARE(screen_time_animimg_106);
LV_IMG_DECLARE(screen_time_animimg_107);
LV_IMG_DECLARE(screen_time_animimg_108);
LV_IMG_DECLARE(screen_time_animimg_109);
LV_IMG_DECLARE(screen_time_animimg_110);
LV_IMG_DECLARE(screen_time_animimg_111);
LV_IMG_DECLARE(screen_time_animimg_112);
LV_IMG_DECLARE(screen_time_animimg_113);
LV_IMG_DECLARE(screen_time_animimg_114);
LV_IMG_DECLARE(screen_time_animimg_115);
LV_IMG_DECLARE(screen_time_animimg_116);
LV_IMG_DECLARE(screen_time_animimg_117);
LV_IMG_DECLARE(screen_time_animimg_118);
LV_IMG_DECLARE(screen_time_animimg_119);
#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(screen_HA_animimg_fanfan1);
LV_IMG_DECLARE(screen_HA_animimg_fanfan2);
LV_IMG_DECLARE(_light2_alpha_64x64);
LV_IMG_DECLARE(_light1_alpha_64x64);

LV_FONT_DECLARE(lv_font_SourceHanMonoNormal_50)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_11)
LV_FONT_DECLARE(lv_font_SourceHanMonoNormal_40)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_SourceHanMonoNormal_16)
LV_FONT_DECLARE(lv_font_montserratMedium_26)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Acme_Regular_13)
LV_FONT_DECLARE(lv_font_SourceHanMonoNormal_15)
LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_SourceHanMonoNormal_80)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_20)
LV_FONT_DECLARE(lv_font_montserratMedium_50)
LV_FONT_DECLARE(lv_font_montserratMedium_37)
LV_FONT_DECLARE(lv_font_montserratMedium_35)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_18)
LV_FONT_DECLARE(lv_font_montserratMedium_30)
LV_FONT_DECLARE(lv_font_montserratMedium_18)


#ifdef __cplusplus
}
#endif
#endif
