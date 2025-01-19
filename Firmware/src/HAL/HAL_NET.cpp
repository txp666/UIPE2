#include <WiFi.h>
#include <ESPmDNS.h>
#include "HAL/HAL.h"
#include "ArduinoJson.h"
#include "App/Configs/Version.h"
#include "custom.h"
#include <ESP32Time.h>
#include <time.h>
#include <map>
#include <string>

// ========== NTP 配置 ==========
// 设置 NTP 服务器以及时区
const char *ntpServer = "pool.ntp.org"; // 或者 cn.pool.ntp.org
const long gmtOffset_sec = 8 * 3600;    // 东八区，GMT+8，秒为单位
const int daylightOffset_sec = 0;       // 无夏令时

// ========== ESP32Time 对象 ==========
ESP32Time rtc;
#define MAX_NETWORKS 10

// ========== wifi 配置 ==========
static char ssid[33];     // 最大 SSID 长度为 32 个字符
static char password[65]; // 最大密码长度为 64 个字符
static char APssid[33];
static char ipAddress[16];
static bool connectFlag = false;
static bool isAPMode = true;
static int connectionAttempts = 0;
static bool scanFlag = false;
static bool isScanDone = false;
int networkCount = 0;

StaticJsonDocument<512> docTCPRec;
TaskHandle_t TCPTaskHandle;
WiFiServer tcpServer(81);
WiFiClient client;
WiFiNetwork networks[MAX_NETWORKS];

// 函数声明
bool connectToWiFi();
void handleClientData();
void enableAPMode(bool enable);
void handleWiFiSettings(const JsonDocument &doc);
void processDataTransmission();
void startServerAndMDNS();
void stopServerAndMDNS();
void time_setup();

void HAL::TCPsetup()
{
    strncpy(APssid, VERSION_FIRMWARE_NAME, sizeof(APssid) - 1);
    APssid[sizeof(APssid) - 1] = '\0';
    isAPMode = HAL::loadLastWiFiStatus();
    enableAPMode(isAPMode);
    xTaskCreate(TCPTask, "TCP Task", 4 * 1024, NULL, TCPTaskPri, &TCPTaskHandle);
}

/**
 * @brief 启动服务器和 MDNS 服务
 *
 * 初始化 MDNS 服务并启动 TCP 服务器。
 */
void startServerAndMDNS()
{
    if (!MDNS.begin(VERSION_FIRMWARE_NAME))
    {
        Serial.println("设置 MDNS 响应器出错！");
        return;
    }
    MDNS.addService("ws", "tcp", 81);
    tcpServer.begin();
    Serial.println("服务器和 MDNS 已启动。");
}

/**
 * @brief 停止服务器和 MDNS 服务
 *
 * 停止 MDNS 服务并关闭 TCP 服务器。
 */
void stopServerAndMDNS()
{
    MDNS.end();
    tcpServer.stop();
    Serial.println("服务器和 MDNS 已停止。");
}

/**
 * @brief 启用或禁用 AP 模式
 *
 * 根据参数启用或禁用 WiFi AP 模式，并配置网络设置。
 *
 * @param enable 是否启用 AP 模式
 */
void enableAPMode(bool enable)
{
    if (enable)
    {
        WiFi.mode(WIFI_AP);
        WiFi.softAP(APssid, "12345678");
        IPAddress localIP(192, 168, 1, 1);
        IPAddress gateway(192, 168, 1, 1);
        IPAddress subnet(255, 255, 255, 0);
        WiFi.softAPConfig(localIP, gateway, subnet);
        snprintf(ipAddress, sizeof(ipAddress), "%d.%d.%d.%d", localIP[0], localIP[1], localIP[2], localIP[3]);
        Serial.println("热点模式已启动，IP: 192.168.1.1");
        startServerAndMDNS();
    }
    else
    {
        stopServerAndMDNS();
        WiFi.softAPdisconnect(true);
        WiFi.mode(WIFI_STA);
        Serial.println("热点模式已关闭。");
        startScan();
    }
}

/**
 * @brief 连接到 WiFi 网络
 *
 * 尝试连接到指定的 WiFi 网络，若成功则启动服务器和 MDNS 服务。
 *
 * @return 是否连接成功
 */
bool connectToWiFi()
{
    stopServerAndMDNS();
    WiFi.softAPdisconnect(true);
    WiFi.mode(WIFI_STA);

    Serial.print("正在连接到 ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    unsigned long startTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startTime < 4000)
    {
        delay(500);
        Serial.println("等待连接...");
    }

    if (WiFi.status() != WL_CONNECTED)
    {
        connectionAttempts++;
        Serial.printf("WiFi 连接失败。尝试次数 %d/5。\n", connectionAttempts);
        return false;
    }
    else
    {
        connectionAttempts = 0;
        Serial.println("WiFi 已连接。");
        IPAddress localIP = WiFi.localIP();
        snprintf(ipAddress, sizeof(ipAddress), "%d.%d.%d.%d", localIP[0], localIP[1], localIP[2], localIP[3]);
        startServerAndMDNS();
        // WiFi 连接成功后，获取一次网络时间
        time_setup();
        return true;
    }
}

/**
 * @brief TCP 通信任务
 *
 * 处理 WiFi 连接、客户端连接和数据通信。
 *
 * @param parameter 任务参数
 */
void HAL::TCPTask(void *parameter)
{
    HAL::powerONtoReadWiFiInfo();

    while (1)
    {
        if (!isAPMode && WiFi.status() != WL_CONNECTED)
        {
            if (connectFlag || connectionAttempts > 0)
            {
                if (connectToWiFi())
                {
                    HAL::saveWiFiCredentials(ssid, password);
                    connectionAttempts = 0;
                }
                else if (connectionAttempts >= 10)
                {
                    Serial.println("尝试 10 次连接失败。切换到 AP 模式。");
                    isAPMode = true;
                    HAL::saveLastWiFiStatus(isAPMode);
                    enableAPMode(true);
                    connectionAttempts = 0;
                }
            }
            else
            {
                // 定期尝试重新连接
                static unsigned long lastAttemptTime = 0;
                if (millis() - lastAttemptTime > 3000)
                {
                    lastAttemptTime = millis();
                    connectFlag = true;
                }
            }
        }

        if (isAPMode || WiFi.status() == WL_CONNECTED)
        {
            // 处理客户端连接
            if (tcpServer.hasClient())
            {
                if (!client || !client.connected())
                {
                    if (client)
                        client.stop();

                    client = tcpServer.available();
                    Serial.println("新客户端已连接");
                    client.printf("{\"Version\":\"%.1f\"}\n", VERSION_SOFTWARE);
                }
            }

            if (client && client.connected())
            {
                handleClientData();
                __IntervalExecute(processDataTransmission(), 20);
            }
        }
        if (!isAPMode)
        {
            // Handle WiFi scanning
            if (scanFlag)
            {
                HAL::wifiScan();
                scanFlag = false;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

/**
 * @brief 处理客户端数据
 *
 * 从客户端接收数据并进行处理，包括命令解析和参数设置。
 */
void handleClientData()
{
    if (client && client.connected())
    {
        while (client.available())
        {
            String data = client.readStringUntil('\n');
            Serial.printf("接收到数据: %s\n", data.c_str());

            DeserializationError error = deserializeJson(docTCPRec, data);
            if (!error)
            {
                if (docTCPRec.containsKey("ZC"))
                {
                }
            }
            else
            {
                Serial.println("JSON 解析失败");
            }
        }
    }
}

/**
 * @brief 处理 WiFi 设置
 *
 * 根据接收到的 JSON 文档，设置 WiFi 模式和凭据。
 *
 * @param doc JSON 文档
 */
void handleWiFiSettings(const JsonDocument &doc)
{
    if (doc.containsKey("WiFiMode"))
    {
        String mode = doc["WiFiMode"].as<String>();
        if (mode == "AP")
        {
            isAPMode = true;
            WiFi.disconnect(true);
            enableAPMode(true);
            Serial.println("切换到 AP 模式。");
        }
        else if (mode == "STA")
        {
            isAPMode = false;
            connectFlag = true;
            Serial.println("切换到 STA 模式。");
        }
        HAL::saveLastWiFiStatus(isAPMode);
    }

    if (doc.containsKey("SSID") && doc.containsKey("Password"))
    {
        const char *newSSID = doc["SSID"];
        const char *newPassword = doc["Password"];

        if (strlen(newSSID) == 0 || strlen(newPassword) == 0)
        {
            // 如果接收到的 SSID 或密码为空，则从 NVS 中读取上次的名称和密码
            int lastConnectedIndex = HAL::getLastConnectedIndex();
            HAL::loadWiFiCredentials(ssid, password, lastConnectedIndex);
            Serial.println("接收到空的 SSID 或密码，使用上次的 WiFi 凭据。");
        }
        else
        {
            // 保存新的 WiFi 凭据
            strncpy(ssid, newSSID, sizeof(ssid) - 1);
            ssid[sizeof(ssid) - 1] = '\0';
            strncpy(password, newPassword, sizeof(password) - 1);
            password[sizeof(password) - 1] = '\0';
            HAL::saveWiFiCredentials(ssid, password);
            Serial.printf("新 WiFi 设置: SSID=%s\n", ssid);
            connectFlag = true;
        }
    }
}

/**
 * @brief 处理数据传输
 *
 * 将参数数据发送给客户端。
 */
void processDataTransmission()
{
    char buffer[200];
    client.println(buffer);
}

/**
 * @brief 读取 WiFi 信息并尝试连接
 *
 * 在设备启动时，读取上次保存的 WiFi 信息并尝试连接。
 */
void HAL::powerONtoReadWiFiInfo()
{
    if (isAPMode)
        return;

    int lastConnectedIndex = HAL::getLastConnectedIndex();
    HAL::loadWiFiCredentials(ssid, password, lastConnectedIndex);
    if (connectToWiFi())
    {
        Serial.println("使用上次的凭据连接到 WiFi。");
    }
    else
    {
        if (lastConnectedIndex > 0)
        {
            Serial.println("使用上次凭据连接失败，尝试其他保存的凭据...");
            for (int i = 0; i < lastConnectedIndex; i++)
            {
                HAL::loadWiFiCredentials(ssid, password, i);
                if (connectToWiFi())
                {
                    Serial.println("使用保存的凭据连接到 WiFi。");
                    break;
                }
            }
        }
        else
        {
            Serial.println("未找到保存的凭据，启动 AP 模式...");
            isAPMode = true;
            enableAPMode(true);
        }
    }
}

String getEncryptionType(wifi_auth_mode_t encryptionType);

/**
 * 扫描WiFi网络
 *
 * 扫描附近的WiFi网络，并将扫描到的网络信息存储在全局变量中。
 * 如果扫描成功，将设置isScanDone为true，否则为false。
 * 如果没有扫描到任何网络，将打印"No networks found"。
 * 如果扫描到网络，将将网络信息存储在networks数组中。
 */
void HAL::wifiScan()
{
    Serial.println("开始扫描...");
    isScanDone = false;
    int n = WiFi.scanNetworks();
    Serial.println("扫描完成");
    isScanDone = true;
    if (n == 0)
    {
        Serial.println("未找到任何网络");
    }
    else
    {
        networkCount = (n > MAX_NETWORKS) ? MAX_NETWORKS : n;
        for (int i = 0; i < networkCount; ++i)
        {
            strncpy(networks[i].SSID, WiFi.SSID(i).c_str(), sizeof(networks[i].SSID) - 1);
            networks[i].RSSI = WiFi.RSSI(i);
            networks[i].channel = WiFi.channel(i);
            strcpy(networks[i].encryptionType, getEncryptionType(WiFi.encryptionType(i)).c_str());
        }
    }
    WiFi.scanDelete();
}

/**
 * 获取WiFi连接状态
 *
 * @return 如果WiFi已连接，则返回true；否则返回false。
 */
uint8_t getWifiStatus()
{
    if (isAPMode)
    {
        return 2;
    }
    else if (WiFi.status() == WL_CONNECTED)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
 *获取IP地址
 */
char *getIPAddress()
{
    return ipAddress;
}

/**
 * 获取WiFi名称列表
 *
 * 返回扫描到的WiFi网络名称列表，并通过指针传递数组长度。
 *
 * @param outCount 用于存储WiFi网络名称列表的数组长度
 * @return const char** 扫描到的WiFi网络名称列表
 */
const char **getWiFiNames(int *outCount)
{
    static const char *wifiNames[MAX_NETWORKS];
    for (int i = 0; i < networkCount; ++i)
    {
        wifiNames[i] = networks[i].SSID;
    }
    *outCount = networkCount; // 通过指针传递数组长度
    return wifiNames;
}

/* 是否打开wifi  sta*/
void enableWiFi(bool en)
{
    isAPMode = !en;
    if (isAPMode)
    {
        WiFi.disconnect(true);
        enableAPMode(true);
    }
    else
    {
        connectFlag = true;
    }
    HAL::saveLastWiFiStatus(isAPMode);
}

/* 当前连接WiFi名称 */
char *getWiFiName()
{
    if (!isAPMode)
        return ssid;
    else
        return APssid;
}

/* 开始扫描wifi */
void startScan()
{
    scanFlag = true;
}

/**
 * 开始连接到WiFi网络
 *
 * @param newssid 新的WiFi网络名称
 * @param newpassword 新的WiFi网络密码
 */
void startConnect(char *newssid, char *newpassword)
{
    connectFlag = true;
    strncpy(ssid, newssid, sizeof(ssid));
    strncpy(password, newpassword, sizeof(password));
}

/* 获取扫描状态 */
bool getScanFlag()
{
    return isScanDone;
}

/**
 * 获取WiFi加密类型
 *
 * 根据给定的WiFi加密类型，返回对应的字符串表示。
 *
 * @param encryptionType WiFi加密类型
 * @return String WiFi加密类型的字符串表示
 */
String getEncryptionType(wifi_auth_mode_t encryptionType)
{
    switch (encryptionType)
    {
    case WIFI_AUTH_OPEN:
        return "开放";
    case WIFI_AUTH_WEP:
        return "WEP";
    case WIFI_AUTH_WPA_PSK:
        return "WPA";
    case WIFI_AUTH_WPA2_PSK:
        return "WPA2";
    case WIFI_AUTH_WPA_WPA2_PSK:
        return "WPA/WPA2";
    case WIFI_AUTH_WPA2_ENTERPRISE:
        return "Enterprise";
    case WIFI_AUTH_WPA3_PSK:
        return "WPA3";
    case WIFI_AUTH_WPA2_WPA3_PSK:
        return "WPA2/WPA3";
    default:
        return "Unknown";
    }
}

// ========== 获取网络时间并设置到 ESP32Time ==========
void time_setup()
{
    // 配置时间（时区、夏令时偏移、NTP 服务器）
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    // 获取当前时间
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("无法从网络获取时间。");
        return;
    }
    // 使用 rtc.setTimeStruct() 将系统时间设置到 ESP32Time
    rtc.setTimeStruct(timeinfo);

    // 输出当前时间
    Serial.print("NTP 同步成功，当前时间为: ");
    Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));
}

int getHour()
{
    return rtc.getHour(true);
}

int getMinute()
{
    return rtc.getMinute();
}

char *getDate()
{
    static char buf[64];
    std::string date = rtc.getDate(false).c_str(); // 获取日期字符串

    // 定义英文到中文的映射
    std::map<std::string, std::string> weekDays = {
        {"Sun", "星期日"}, {"Mon", "星期一"}, {"Tue", "星期二"}, {"Wed", "星期三"}, {"Thu", "星期四"}, {"Fri", "星期五"}, {"Sat", "星期六"}};

    std::map<std::string, std::string> months = {
        {"Jan", "一月"}, {"Feb", "二月"}, {"Mar", "三月"}, {"Apr", "四月"}, {"May", "五月"}, {"Jun", "六月"}, {"Jul", "七月"}, {"Aug", "八月"}, {"Sep", "九月"}, {"Oct", "十月"}, {"Nov", "十一月"}, {"Dec", "十二月"}};

    // 解析日期字符串
    std::string weekDay = date.substr(0, 3);
    std::string month = date.substr(5, 3);
    std::string day = date.substr(9, 2);
    std::string year = date.substr(12, 4);

    // 构建中文日期字符串
    snprintf(buf, sizeof(buf), "%s %s日 %s ",
             months[month].c_str(),
             day.c_str(),
             weekDays[weekDay].c_str());

    return buf;
}