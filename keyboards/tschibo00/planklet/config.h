#pragma once

//#define DRIVER_COUNT 1
#define LED_DRIVER_ADDR_1 0x74
#define LED_DRIVER_COUNT 1
#define I2C1_SDA_PIN 	GP6
#define I2C1_SCL_PIN 	GP7
#define LED_DISABLE_WHEN_USB_SUSPENDED
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended

#define COMBO_STRICT_TIMER
#define COMBO_TERM 30

#define RGBLED_NUM 1                     // The number of LEDs connected

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
