/*
  Copyright 2022 Leonardo Diaz (Lezaid)

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

// CRKBD

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum crkbd_layers {
  _DVORAK,
  _SYM,
  _NAV,
  _NUMP,
  _ADJ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
    LT(_NUMP,KC_TAB),  ES_QUOT,       ES_COMM,        ES_DOT,         ES_P,          ES_Y,                                           ES_F,          ES_G,          ES_C,          ES_R,          ES_L,        KC_BSPC,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
     LCTL_T(KC_ESC),     ES_A,          ES_O,          ES_E,          ES_U,          ES_I,                                           ES_D,          ES_H,          ES_T,          ES_N,          ES_S,        ES_MINS,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
    LSFT_T(KC_CAPS),   ES_SCLN,         ES_Q,          ES_J,          ES_K,          ES_X,                                           ES_B,          ES_M,          ES_W,          ES_V,          ES_Z,     RSFT_T(KC_ENT),
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    KC_LGUI,       MO(_NAV),  LT(_SYM,KC_SPC),  LT(_SYM,KC_SPC),   MO(_NAV),      KC_LALT
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),
  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
        ES_MORD,       ES_DQUO,       ES_LABK,       ES_RABK,       ES_ACUT,        ES_GRV,                                        ES_SLSH,       ES_BSLS,       ES_LPRN,       ES_RPRN,       ES_CIRC,       _______,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,        ES_AT,       ES_IQUE,       ES_QUES,        ES_HASH,        ES_DLR,                                        ES_PIPE,       ES_AMPR,       ES_LCBR,       ES_RCBR,       ES_PLUS,       ES_UNDS,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        KC_LSFT,       ES_COLN,       ES_IEXL,       ES_EXLM,       ES_PERC,        ES_NOT,                                        ES_TILD,        ES_EQL,       ES_LBRC,       ES_RBRC,       ES_ASTR,       _______,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    _______,       MO(_ADJ),      _______,          _______,       MO(_ADJ),      _______
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),
  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
         KC_TAB,       G(KC_1),       G(KC_2),       G(KC_3),       G(KC_4),       G(KC_5),                                        G(KC_6),       G(KC_7),       G(KC_8),       G(KC_9),       G(KC_0),       _______,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,       C(ES_A),       C(ES_Y),       XXXXXXX,       XXXXXXX,       KC_WH_U,                                        KC_LEFT,       KC_DOWN,        KC_UP,        KC_RGHT,       XXXXXXX,       KC_PSCR,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        KC_LSFT,       C(ES_Z),       C(ES_X),       C(ES_C),       C(ES_V),       KC_WH_D,                                        KC_HOME,       KC_PGDN,       KC_PGUP,        KC_END,       XXXXXXX,       _______,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    _______,       _______,   LT(_ADJ,KC_SPC),  LT(_ADJ,KC_SPC),   _______,       _______
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),
  [_NUMP] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,        KC_NUM,                                        KC_PSLS,        KC_P7,         KC_P8,         KC_P9,        ES_CIRC,       KC_BSPC,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        KC_PDOT,        KC_P4,         KC_P5,         KC_P6,        KC_PPLS,       KC_PMNS,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                         KC_P0,         KC_P1,         KC_P2,         KC_P3,        KC_PAST,       KC_PENT,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    _______,       _______,        KC_SPC,           KC_SPC,       _______,       _______
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),
  [_ADJ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
        XXXXXXX,        KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,                                          KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,       RGB_TOG,       RGB_HUI,       RGB_SAI,       RGB_VAI,       XXXXXXX,                                        XXXXXXX,       KC_VOLD,       KC_MUTE,       KC_VOLU,       KC_BRIU,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        XXXXXXX,       RGB_MOD,       RGB_HUD,       RGB_SAD,       RGB_VAD,       XXXXXXX,                                        XXXXXXX,       KC_MPRV,       KC_MPLY,       KC_MNXT,       KC_BRID,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    _______,       _______,       XXXXXXX,          XXXXXXX,       _______,       _______
                                                              //`--------------------------------------------'  `--------------------------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE
  #define HSV_DEFAULT    0x00, 0x14, 0x46 // RGB(70, 64, 64)

  const uint8_t top_lcorner_leds[] = {24}; // Leds of top left corner
  const uint8_t thumbs_leds[] = {13,40}; // Leds of thumbs
  const uint8_t space_bar_leds[] = {6,33}; // Leds of space bar
  const uint8_t underglow_leds[] = {0,1,2,3,4,5,27,28,29,30,31,32}; // Leds of underglow
  const uint8_t number_row_leds[] = {9,10,17,18,23,36,37,44,45,50}; // Leds of number row

  void set_leds_color(const uint8_t* leds, uint8_t leds_len, RGB rgb) {
    for (uint8_t i = 0; i < leds_len; i++) {
      rgb_matrix_set_color(*(leds + i), rgb.r, rgb.g, rgb.b);
    }
  }

  void set_leds_capped_color(const uint8_t* leds, uint8_t leds_len, uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = {h, s, v};
    if (hsv.v > rgb_matrix_get_val()) {
      hsv.v = rgb_matrix_get_val();
    }

    set_leds_color(leds, leds_len, hsv_to_rgb(hsv));
  }

  void set_leds_modified_color(const uint8_t* leds, uint8_t leds_len, uint8_t h, uint8_t s, uint8_t v, uint8_t new_v) {
    HSV hsv = {h, s, v};
    hsv.v = new_v;

    set_leds_color(leds, leds_len, hsv_to_rgb(hsv));
  }

  void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(default_layer_state|layer_state)) {
      case _DVORAK:
        set_leds_modified_color(underglow_leds, sizeof(underglow_leds), HSV_DEFAULT,200);
        set_leds_capped_color(top_lcorner_leds, sizeof(top_lcorner_leds), HSV_BLUE);
        set_leds_capped_color(thumbs_leds, sizeof(thumbs_leds), HSV_PURPLE);
        set_leds_capped_color(space_bar_leds, sizeof(space_bar_leds), HSV_CYAN);
        break;
      case _SYM:
        set_leds_modified_color(underglow_leds, sizeof(underglow_leds), HSV_CYAN,200);
        set_leds_capped_color(thumbs_leds, sizeof(thumbs_leds), HSV_PINK);
        break;
      case _NAV:
        set_leds_modified_color(underglow_leds, sizeof(underglow_leds), HSV_PURPLE,200);
        set_leds_capped_color(space_bar_leds, sizeof(space_bar_leds), HSV_PINK);
        break;
      case _NUMP:
        set_leds_modified_color(underglow_leds, sizeof(underglow_leds), HSV_BLUE,200);
        break;
      case _ADJ:
        set_leds_modified_color(underglow_leds, sizeof(underglow_leds), HSV_PINK,200);
        set_leds_capped_color(number_row_leds, sizeof(number_row_leds), HSV_CORAL);
        break;
    }
  }
#endif // RGB_MATRIX_ENABLE

#ifdef OLED_ENABLE
  static const char PROGMEM blank_char[] = {0x5F, 0};

  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
  }

  void render_layer_state(void) {
    static const char PROGMEM topO_layer[]              = {0x5F, 0x04, 0x05, 0x06, 0x5F, 0};
    static const char PROGMEM botO_layer[]              = {0x5F, 0x41, 0x42, 0x43, 0x5F, 0};
    static const char PROGMEM midX_layer[]              = {0x5F, 0x4E, 0x4F, 0x50, 0x5F, 0};
    static const char PROGMEM midXe_layer[]             = {0x5F, 0x51, 0x52, 0x53, 0x5F, 0};
    static const char PROGMEM topX_midO_layer[]         = {0x5F, 0x01, 0x02, 0x03, 0x5F, 0x5F, 0x21, 0x22, 0x23, 0x5F, 0};
    static const char PROGMEM midO_botX_layer[]         = {0x5F, 0x24, 0x25, 0x26, 0x5F, 0x5F, 0x44, 0x45, 0x46, 0x5F, 0};
    static const char PROGMEM topXe_midXe_botXe_layer[] = {0x5F, 0x07, 0x08, 0x09, 0x5F, 0x5F, 0x27, 0x28, 0x29, 0x5F, 0x5F, 0x47, 0x48, 0x49, 0x5F, 0};
    
    switch (get_highest_layer(default_layer_state|layer_state)) {  
      case _SYM:
        oled_write_P(topX_midO_layer, false);
        oled_write_P(botO_layer, false);
        break;
      case _NAV:
        oled_write_P(topO_layer, false);
        oled_write_P(midO_botX_layer, false);
        break;
      case _NUMP:
        oled_write_P(topO_layer, false);
        oled_write_P(midXe_layer, false);
        oled_write_P(botO_layer, false);
        break;
      case _ADJ:
        oled_write_P(topXe_midXe_botXe_layer, false);
        break;
      default :
        oled_write_P(topO_layer, false);
        oled_write_P(midX_layer, false);
        oled_write_P(botO_layer, false);
    }
  }

  void render_indicator_status(void) {
    static const char PROGMEM cap_lock[][2][3] = {
      {{0x5F, 0x5F, 0}, {0x5F, 0x5F, 0}},
      {{0x2A, 0x2B, 0}, {0x4A, 0x4B, 0}}
    };
    static const char PROGMEM num_lock[][2][3] = {
      {{0x5F, 0x5F, 0}, {0x5F, 0x5F, 0}},
      {{0x2C, 0x2D, 0}, {0x4C, 0x4D, 0}}
    };
    static const char PROGMEM separator_lock[][2][2] = {
      {{0x5F, 0}, {0x5F, 0}},
      {{0x56, 0}, {0x57, 0}},
      {{0x58, 0}, {0x59, 0}},
      {{0x0B, 0}, {0x0C, 0}}
    };

    led_t led_state = host_keyboard_led_state();

    uint8_t left = 0;
    uint8_t mid = 0;
    uint8_t right = 0;

    if (led_state.caps_lock) {
      left = 1;
      mid = 1;
    }
    if (led_state.num_lock) {
      right = 1;
      mid = 2;
    }
    if (led_state.caps_lock && led_state.num_lock) {
      mid = 3;
    }

    for (uint8_t i = 0; i < 2; i++) {
      oled_write_P(cap_lock[left][i], false);
      oled_write_P(separator_lock[mid][i], false);
      oled_write_P(num_lock[right][i], false);
    }
  }

  void _render_mod_row(const uint8_t modifiers, uint8_t left_mod, uint8_t right_mod, const char (*left_data)[2][3], const char (*right_data)[2][3]) {
    static const char PROGMEM separator_data[][2][2] = {
      {{0x1E, 0}, {0x3E, 0}},
      {{0x1F, 0}, {0x3F, 0}},
      {{0x20, 0}, {0x40, 0}},
      {{0x54, 0}, {0x55, 0}}
    };

    uint8_t left = 0;
    uint8_t mid = 0;
    uint8_t right = 0;

    if (modifiers & left_mod) {
      left = 1;
      mid = 1;
    }
    if (modifiers & right_mod) {
      right = 1;
      mid = 2;
    }
    if ((modifiers & left_mod) && (modifiers & right_mod)) {
      mid = 3;
    }

    for (uint8_t i = 0; i < 2; i++) {
      oled_write_P(left_data[left][i], false);
      oled_write_P(separator_data[mid][i], false);
      oled_write_P(right_data[right][i], false);
    }
  }

  void render_mod_status(void) {
    const uint8_t modifiers = get_mods();
    if (!modifiers) {
      for (uint8_t i = 0; i < 20; i++) {
        oled_write_P(blank_char, false);
      }
      return;
    }

    static const char PROGMEM ctrl[][2][3] = {
      {{0x12, 0x13, 0}, {0x32, 0x33, 0}},
      {{0x1A, 0x1B, 0}, {0x3A, 0x3B, 0}}
    };
    static const char PROGMEM shift[][2][3] = {
      {{0x14, 0x15, 0}, {0x34, 0x35, 0}},
      {{0x1C, 0x1D, 0}, {0x3C, 0x3D, 0}}
    };
    static const char PROGMEM gui[][2][3] = {
      {{0x0E, 0x0F, 0}, {0x2E, 0x2F, 0}},
      {{0x16, 0x17, 0}, {0x36, 0x37, 0}}
    };
    static const char PROGMEM alt[][2][3] = {
      {{0x10, 0x11, 0}, {0x30, 0x31, 0}},
      {{0x18, 0x19, 0}, {0x38, 0x39, 0}}
    };

    _render_mod_row(modifiers, MOD_MASK_CTRL, MOD_MASK_SHIFT, ctrl, shift);
    _render_mod_row(modifiers, MOD_MASK_GUI, MOD_MASK_ALT, gui, alt);
  }


/*
  char keylog_str[] = "\0x , k      :  ";
  const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
  };
  void set_keylog(uint16_t keycode, keyrecord_t *record) {
    if ((QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX) || (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX)) {
      keycode = keycode & 0xFF;
    }

    *(keylog_str + 0) = '0' + record->event.key.row;
    *(keylog_str + 2) = '0' + record->event.key.col;
    const char* buff = get_u16_str(keycode, ' ');
    for (uint8_t i = 0,x = 0; i < 5; ++i) {
      uint8_t idx = *(buff + i) == ' '? 10 - i : 6 + x++;
      *(keylog_str + idx) = *(buff + i);
    }
    if (keycode < 60) {
      *(keylog_str + 14) = code_to_name[keycode];
      *(keylog_str + 12) = ':';
    } else {
      *(keylog_str + 14) = ' ';
      *(keylog_str + 12) = ' ';
    }
  }

  void oled_render_keylog(void) {
    oled_write(keylog_str, false);
  }

  void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
    oled_write_P(crkbd_logo, false);
  }
*/
  bool oled_task_user(void) {
    if (is_keyboard_left()) {
      // oled_render_layer_state();
      // oled_render_keylog();
    } else {
      render_indicator_status();
      oled_set_cursor(0, 6);
      render_layer_state();
      oled_set_cursor(0, 11);
      render_mod_status();
    }
    return false;
  }
#endif // OLED_ENABLE

void keyboard_post_init_user(void) {
  #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_sethsv_noeeprom(HSV_DEFAULT);
  #endif // RGB_MATRIX_ENABLE
}

bool process_maskmap_key(keyrecord_t *record, uint16_t mod_mask, uint16_t keycode, bool *registered) {
  uint8_t mod_state = get_mods();
  if (mod_state & mod_mask || *registered) {
    del_mods(mod_mask);
    if (record->event.pressed) {
      register_code16(keycode);
      *registered = true;
    } else {
      unregister_code16(keycode);
      *registered = false;
    }
    set_mods(mod_state);
    return false;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_BSPC: {
      static bool delkey_registered;
      return process_maskmap_key(record, MOD_MASK_SHIFT, KC_DEL, &delkey_registered);
    }
    case ES_N: {
      static bool ntilkey_registered;
      return process_maskmap_key(record, MOD_MASK_ALT, ES_NTIL, &ntilkey_registered);
    }
  }
  return true;
}