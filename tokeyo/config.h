#pragma once

#define COMBO_STRICT_TIMER
#define COMBO_TERM 30
#define HOLD_ON_OTHER_KEY_PRESS
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350
#define LEADER_NO_TIMEOUT
#define CAPS_WORD_IDLE_TIMEOUT 3000
#define TAPPING_TERM 300
#define QUICK_TAP_TERM 0

#define RGBLIGHT_SLEEP 			// turn off effects when suspended
#define RGBLIGHT_DEFAULT_HUE 135
#define RGBLED_NUM 1
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#define RGBLIGHT_DEFAULT_ON true

// order: static, breathe, rainbow, alternating, twinkle
#define RGBLIGHT_EFFECT_ALTERNATING				// 1 mode
#define RGBLIGHT_EFFECT_BREATHING				// 4 modes
#define RGBLIGHT_EFFECT_RAINBOW_MOOD			// 3 modes
#define RGBLIGHT_EFFECT_TWINKLE					// 6 modes
