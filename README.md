# STM32 学习工程合集

个人 STM32 入门学习代码，主控为 **STM32F103C8T6**（72 MHz，64 KB Flash / 20 KB SRAM），使用 **Keil MDK5** 开发。

## 目录结构

| 目录 | 内容 | 说明 |
|---|---|---|
| `程序/` | 标准库练习工程 | 基于 STM32 标准外设库（StdPeriph），每个工程自带完整的 `Library`、`Start`、`System` |
| `stdmo/` | 标准库空白工程模板 | 新建练习时复制此目录即可 |
| `cubemxtest/` | CubeMX 生成的 HAL 工程 | STM32CubeMX + HAL 库，`MDK-ARM` 目录下有 Keil 工程文件 |
| `工程所需文件/` | 可复用模块 | OLED、Key、LED、Delay 驱动模块，以及标准库启动文件与建工程说明 |

### 程序/ 下的练习

| 工程 | 内容 |
|---|---|
| `4-1 OLED显示屏` | SPI 软件模拟时序驱动 0.96" OLED，含字库 `OLED_Font.h` |
| `5-2 旋转编码器` | EXTI 中断 + 编码器旋钮计数 |
| `5-2 红外传感` | 红外对管 / 传感器输入检测 |
| `test` | 实验用零散测试 |

## 环境与编译

1. 安装 Keil MDK5 与 **STM32F1xx Device Pack**（Keil.STM32F1xx_DFP）
2. 打开各工程目录下的 `Project.uvprojx`（CubeMX 工程在 `MDK-ARM/` 下）
3. `F7` 编译，`F8` 下载（默认 ST-Link / CMSIS-DAP）

标准库工程的目录约定：

```
Start/    启动文件 + 内核寄存器定义
Library/  STM32 标准外设库源码
System/   SysTick 延时等系统函数
Hardware/ 外设驱动模块（LED、Key、OLED …）
User/     main.c 与中断服务函数
```

## 模块用法

`工程所需文件/` 里的模块按「.c 加入工程分组、.h 提供接口」的方式使用，例如 OLED：

```c
#include "OLED.h"

OLED_Init();
OLED_ShowString(1, 1, "Hello");
```

具体建工程步骤见 `工程所需文件/基本头文件/创建新项目.txt`。

## 说明

- 仓库不含 Keil / CubeMX 安装文件，也不含 `Objects/`、`Listings/` 等编译产物（见 `.gitignore`）
- `cubemxtest/` 内的 CMSIS-DSP 预编译库（`Drivers/CMSIS/Lib/`）体积较大，属于 CubeMX 自动生成，保留以保证工程可编译
- 学习路线参考江协科技 STM32 教程，工程命名与其编号一致
