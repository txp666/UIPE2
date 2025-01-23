# -*- coding: utf-8 -*-
import sys
import socket
import platform
import psutil
import json
import time
import threading

from zeroconf import ServiceBrowser, Zeroconf

# -------------------------------------------------------------------------
# 配置参数
# -------------------------------------------------------------------------
TARGET_SERVICE_NAME = "uipe"  # ESP32通过mDNS注册的名称里应包含此字符串(忽略大小写)
SERVICE_TYPE = "_ws._tcp.local."  # ESP32注册的服务类型，需与实际一致
ESP32_TCP_PORT = 81  # 你ESP32所监听的TCP端口
SEND_INTERVAL = 3.0  # 间隔(秒)，每隔多久发送一次数据
# -------------------------------------------------------------------------


class Esp32Listener:
    """
    Zeroconf 服务发现事件监听器。扫描到符合条件的ESP32设备后，启动后台线程持续发送信息。
    """

    def __init__(self, zeroconf):
        self.zeroconf = zeroconf
        self.found_devices = set()  # 已发现的设备 IP，防止重复创建线程
        self.lock = threading.Lock()  # 线程安全

    def remove_service(self, zeroconf, service_type, name):
        # 当有服务下线时回调，这里暂不处理
        pass

    def add_service(self, zeroconf, service_type, name):
        """
        当发现新服务时的回调
        """
        info = zeroconf.get_service_info(service_type, name)
        if info:
            # 判断是否包含目标名称(忽略大小写)
            if TARGET_SERVICE_NAME.lower() in name.lower():
                print(f"[+] Found service: {name}")
                self.handle_found_device(info)

    def update_service(self, zeroconf, service_type, name):
        # 当服务信息更新时回调，这里暂不处理
        pass

    def handle_found_device(self, service_info):
        """
        处理发现的设备：解析 IP，若是新设备则启动后台线程循环发送信息
        """
        addresses = service_info.parsed_addresses()
        if not addresses:
            print("[!] 未能解析到 IP 地址")
            return

        ip_addr = addresses[0]
        print(f"    IP: {ip_addr}")

        with self.lock:
            if ip_addr in self.found_devices:
                # 已有线程在发送给该设备，避免重复
                return
            self.found_devices.add(ip_addr)

        # 启动后台线程，循环发送数据
        t = threading.Thread(
            target=self.send_loop, args=(ip_addr, ESP32_TCP_PORT), daemon=True
        )
        t.start()

    def send_loop(self, ip_addr, port):
        """
        后台线程函数：每隔 SEND_INTERVAL 秒，尝试一次TCP发送电脑信息
        """
        print(f"    [Thread] 开始向 {ip_addr}:{port} 循环发送系统信息")
        while True:
            self.send_system_info(ip_addr, port)
            time.sleep(SEND_INTERVAL)

    def send_system_info(self, ip_addr, port):
        """
        封装一次性 TCP 连接 -> 发送 -> 断开 的流程
        """
        data_to_send = self.collect_computer_info()
        json_data = json.dumps(data_to_send)

        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(3)  # 避免长时间阻塞

        try:
            sock.connect((ip_addr, port))
            print(f"[Thread] 已连接 {ip_addr}:{port}, 正在发送数据...")
            sock.sendall(json_data.encode("utf-8"))
            print("[Thread] 发送完成。")
        except Exception as e:
            print(f"[Thread] [!] 连接或发送失败: {e}")
        finally:
            sock.close()

    def collect_computer_info(self):
        """
        获取本机的基本信息：CPU、内存、操作系统等
        """
        info_dict = {}
        try:
            # info_dict["os"] = platform.platform()
            # info_dict["hostname"] = platform.node()
            info_dict["cpu_usage"] = psutil.cpu_percent(interval=0.5)

            mem = psutil.virtual_memory()
            info_dict["mem_total"] = mem.total
            info_dict["mem_used"] = mem.used
            info_dict["mem_percent"] = mem.percent

        except Exception as e:
            info_dict["error"] = str(e)
        return info_dict


def main():
    # 1) 创建 Zeroconf 实例
    zeroconf = Zeroconf()
    listener = Esp32Listener(zeroconf)

    # 2) 启动服务浏览器，扫描 SERVICE_TYPE 指定的所有服务
    browser = ServiceBrowser(zeroconf, SERVICE_TYPE, listener)
    print(">>> 正在扫描局域网中的设备，按 Ctrl+C 退出")

    # 3) 主线程保持循环，可继续扫更多设备
    try:
        while True:
            # 让主线程保持活跃，后台线程会去循环发送
            time.sleep(1.0)
    except KeyboardInterrupt:
        print("\n>>> 用户中断，退出程序")
    finally:
        zeroconf.close()


if __name__ == "__main__":
    main()
