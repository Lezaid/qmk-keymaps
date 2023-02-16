/*
  This is the c configuration file for the keymap

  Copyright 2012 Jun Wako <wakojun@gmail.com>
  Copyright 2015 Jack Humbert
  Copyright 2021 Dane Evans

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_MATRIX_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_TERM 190

#if defined(OLED_ENABLE) || defined(RGB_MATRIX_ENABLE)
  #define SPLIT_LAYER_STATE_ENABLE
#endif

#ifdef OLED_ENABLE
  #define SPLIT_LED_STATE_ENABLE
  #define SPLIT_MODS_ENABLE
  #define SPLIT_WPM_ENABLE
  #define SPLIT_OLED_ENABLE

  #define OLED_FONT_END 95
  #define OLED_TIMEOUT 150000
  #define OLED_BRIGHTNESS 230
  #define OLED_FADE_OUT
  #define OLED_FADE_OUT_INTERVAL 15

  #define OLED_FONT_H "keyboards/crkbd/keymaps/lezaid/glcdfont.c"
#endif

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_KEYPRESSES 
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS

  #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5
  #define RGB_MATRIX_LED_FLUSH_LIMIT 16 
  #define RGB_DISABLE_WHEN_USB_SUSPENDED

  #undef ENABLE_RGB_MATRIX_ALPHAS_MODS
  #undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #undef ENABLE_RGB_MATRIX_BREATHING
  #undef ENABLE_RGB_MATRIX_BAND_SAT
  #undef ENABLE_RGB_MATRIX_BAND_VAL
  #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #undef ENABLE_RGB_MATRIX_CYCLE_ALL
  #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
  #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  #undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  #undef ENABLE_RGB_MATRIX_DUAL_BEACON
  #undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
  #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #undef ENABLE_RGB_MATRIX_RAINDROPS
  #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  #undef ENABLE_RGB_MATRIX_HUE_BREATHING
  #undef ENABLE_RGB_MATRIX_HUE_PENDULUM
  #undef ENABLE_RGB_MATRIX_HUE_WAVE
  #undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
  #undef ENABLE_RGB_MATRIX_PIXEL_FLOW
  #undef ENABLE_RGB_MATRIX_PIXEL_RAIN
  
  // #ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
  #undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
  // #endif
  
  // #if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES)
  #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  #undef ENABLE_RGB_MATRIX_SPLASH
  #define ENABLE_RGB_MATRIX_MULTISPLASH
  #undef ENABLE_RGB_MATRIX_SOLID_SPLASH
  #undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
  // #endif

  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 130
  #define RGB_MATRIX_HUE_STEP 8
  #define RGB_MATRIX_SAT_STEP 8
  #define RGB_MATRIX_VAL_STEP 8
#endif

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
