/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include <time.h>
#include <errno.h>
#include <string.h>
#include "freemaster_client.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "external_data_init.h"
#define CALL_RETRY_COUNT 5
#define DEFAULT_STRING "NULL"

CURL *ws_connect = NULL;
lv_obj_t *gg_prompt = NULL;
extern pthread_mutex_t lvgl_mutex;
extern pthread_mutex_t jsonrpc_mutex;
static uint32_t retry_count = 0;

void connect_init()
{
    ws_connect = websocket_connect(freemaster_server);
    if (ws_connect == NULL)
    {
        prompt_display("websocket connect failed.");
        return;
    }
    return;
}

void freemaster_disconnect()
{
    if (ws_connect != NULL)
    {
        websocket_close(ws_connect);
        ws_connect = NULL;
    }
    return;
}

bool equal_to_double_max(double a)
{
    /* set the threshold of double type */
    const double epsilon = 1e-9;
    return fabs(fabs(a) - DBL_MAX) / DBL_MAX < epsilon;
}

// Release the memory occupied by the string array
void free_string_array(char **array, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(array[i]);
    }
    free(array);
}

void freeMasterParse(void *param)
{
    if (strcmp(((readVariableParm *)param)->apiName, "ReadVariable") == 0)
    {
        readVariableParm *user_parm = param;
        char **dataArray = read_variable(user_parm->varArray, user_parm->arrayLen);
        /* use timedlock to avoid dead loop when there is screen transition event*/
        struct timespec timeout = {0, LV_DISP_DEF_REFR_PERIOD * 1000 * 1000};
        int err = pthread_mutex_timedlock(&lvgl_mutex, &timeout);
        if (0 != err)
            return;
        /* display the extern data according to widget type. */
        switch (user_parm->widget_type)
        {
        case GG_LABEL:
        {
            lv_label_set_text(user_parm->parentObj, dataArray[0]);
            break;
        }
        case GG_CHART:
        {
            lv_chart_series_t *childObj = NULL;
            for (int i = 0; i < user_parm->arrayLen; i++)
            {
                childObj = (user_parm->childObjArray)[i];
                lv_chart_set_next_value(user_parm->parentObj, childObj, atoi(dataArray[i]));
            }
            lv_chart_refresh(user_parm->parentObj);
            break;
        }
        case GG_BAR:
        {
            lv_bar_set_value(user_parm->parentObj, atoi(dataArray[0]), LV_ANIM_OFF);
            break;
        }
        case GG_METER:
        {
            lv_meter_indicator_t *childObj = NULL;
            for (int i = 0; i < user_parm->arrayLen; i++)
            {
                childObj = (user_parm->childObjArray)[i];
                lv_meter_set_indicator_value(user_parm->parentObj, childObj, atoi(dataArray[i]));
            }
            break;
        }
        case GG_ARC:
        {
            lv_arc_set_value(user_parm->parentObj, atoi(dataArray[0]));
            break;
        }
        case GG_SLIDER:
        {
            lv_slider_set_value(user_parm->parentObj, atoi(dataArray[0]), LV_ANIM_OFF);
            break;
        }
        case GG_SWITCH:
        {
            if (atoi(dataArray[0]) == 0 && lv_obj_has_state(user_parm->parentObj, LV_STATE_CHECKED))
            {
                lv_obj_clear_state(user_parm->parentObj, LV_STATE_CHECKED);
            }
            if (atoi(dataArray[0]) == 1 && !lv_obj_has_state(user_parm->parentObj, LV_STATE_CHECKED))
            {
                lv_obj_add_state(user_parm->parentObj, LV_STATE_CHECKED);
            }
            break;
        }
        default:
            break;
        }
        free_string_array(dataArray, user_parm->arrayLen);
        pthread_mutex_unlock(&lvgl_mutex);
    }
    return;
}

void prompt_display(char *message)
{
    if (gg_prompt == NULL || !lv_obj_is_valid(gg_prompt))
    {
        gg_prompt = lv_label_create(lv_layer_top()); /* create the prompt label on the top layer */
        lv_label_set_text(gg_prompt, message);
        lv_obj_set_pos(gg_prompt, 0, 0);                                                 /* set the prompt label position */
        lv_obj_set_size(gg_prompt, lv_disp_get_hor_res(NULL), 30);                       /* set the prompt label size */
        lv_label_set_long_mode(gg_prompt, LV_LABEL_LONG_SCROLL);                         /* set the label text long mode */
        lv_color_t red = lv_color_hex(0xff0027); 
        lv_obj_set_style_border_width(gg_prompt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);      /* define the font color as yellow */
        lv_obj_set_style_text_color(gg_prompt, red, LV_PART_MAIN | LV_STATE_DEFAULT);    /* set the label font color */
        lv_obj_set_style_radius(gg_prompt, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    }
}

json_t *callAPI(json_t* params, char *method_name)
{
    static uint32_t id = 1;
    json_error_t error;
    json_t *json_obj = NULL;
    json_t *request_data = NULL;

    /* try to connect*/
    if (ws_connect == NULL)
        connect_init();
    /* still unsuccessful? */
    if (ws_connect == NULL)
        return NULL;

    request_data = json_object();
    pthread_mutex_lock(&jsonrpc_mutex);

    /* format the request params json string */
    json_object_set_new(request_data, "jsonrpc", json_string("2.0"));
    json_object_set_new(request_data, "id", json_integer(id));
    json_object_set_new(request_data, "method", json_string(method_name));
    json_object_set_new(request_data, "params", params);

    /* dynamically increase id for jsonrpc request params*/
    id++;
    if (id == UINT_MAX)
    {
        id = 1;
    }
    pthread_mutex_unlock(&jsonrpc_mutex);

    /* Convert JSON object to string */
    char *param_str = json_dumps(request_data, JSON_INDENT(4));
    /* get the json data from FreeMaster server JSONRPC with websocket.*/
    char *origin_response = websocket_request(ws_connect, param_str);
    if (origin_response == NULL)
    {
        fprintf(stderr, "No data returned from jsonrpc server.\n");
        goto err_ret;
    }

#ifdef DEBUG
    fprintf(stdout, "Decoding json: %s\n", origin_response);
#endif

    json_obj = json_loads(origin_response, 0, &error);
    if (json_obj == NULL)
    {
        fprintf(stderr, "Failed to decode json: %s\n", error.text);
        goto err_ret;
    }

err_ret:
    /* Release the JSON object and its string */
    if(request_data)
        json_decref(request_data);
    if(origin_response)
        free(origin_response);
    if(param_str)
        free(param_str);

    return json_obj;
}

char **read_variable(fm_var *varArray, int arrayLen)
{
    json_t *result_json;
    char **dataArray = (char **)malloc(arrayLen * sizeof(char *));
    if (dataArray == NULL)
    {
        return NULL; // malloc failed.
    }

    for (int i = 0; i < arrayLen; i++)
    {
        char *variable_name = varArray[i].varName;
        json_t *params_arr = json_array();
        json_array_append_new(params_arr, json_string(variable_name));
        result_json = callAPI(params_arr, "ReadVariable");
        /* Automatically release the memory occupied by the object when the reference count becomes 0 */
        json_decref(params_arr);
        if (result_json == NULL)
        {
            dataArray[i] = strdup(DEFAULT_STRING);
            continue;
        }

        int success = 0, retval = 0, errorCode = 0;
        char *id, *dataFormatted, *errorMessage = NULL;
        int data;
        json_error_t error;
        int res = json_unpack_ex(result_json, &error, 0, "{s:s, s:{s:b, s?F, s:{s:b, s?:s}, s?{s:i, s:s}}}",
                                 "id", &id, "result", "success", &success, "data", &data, "xtra", "retval", &retval,
                                 "formatted", &dataFormatted, "error", "code", &errorCode, "msg", &errorMessage);
        if (res == -1 || !success)
        {
            char * dispaly_error = errorMessage ? errorMessage : error.text;
            retry_count += 1;
            fprintf(stderr, "%s\n", dispaly_error);
            /* retry read the variable when the time over the CALL_RETRT_COUNT will alert the error message. */
            if (retry_count >= CALL_RETRY_COUNT)
            {
                prompt_display(dispaly_error);
            }
            /* call the api failed will be set the default string */
            dataArray[i] = strdup(DEFAULT_STRING);
            continue;
        }

        if (success && res != -1)
        {
            if (lv_obj_is_valid(gg_prompt))
            {
                lv_obj_del(gg_prompt);
                gg_prompt = NULL;
                retry_count = 0;
            }
        }
        dataArray[i] = strdup(dataFormatted);
        if (dataArray[i] == NULL)
        {
            // If memory allocation fails, release the allocated memory and return NULL.
            for (int j = 0; j < i; j++)
            {
                free(dataArray[j]);
            }
            free(dataArray);
            return NULL;
        }
        json_decref(result_json);
    }
    return dataArray;
}

void write_variable(char *varName, int value)
{
    json_t *params_arr = json_array();
    json_array_append_new(params_arr, json_string(varName));
    json_array_append_new(params_arr, json_integer(value));
    callAPI(params_arr, "WriteVariable");
    json_decref(params_arr);  /* Automatically release the memory occupied by the object when the reference count becomes 0 */
    return;
}
#endif
