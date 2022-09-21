/*
  Copyright 2020 Dane Evans

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
// char layer_state_str[24];
enum userspace_layers {
  _COLEMAK = 0,
  _COLEMAKDH,
  _QWERTY,
  _NUM,
  _SYM,
  _COMMAND,
  _NUMPAD,
  _SWITCH,
  _MOVE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // colemak
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
   LT(_NUMPAD,KC_TAB),   KC_Q,          KC_W,          KC_F,          KC_P,          KC_G,                                     LT(_SWITCH,KC_J),    KC_L,          KC_U,          KC_Y,        KC_SCLN,       KC_BSPC,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        KC_LSFT,         KC_A,          KC_R,          KC_S,          KC_T,          KC_D,                                           KC_H,          KC_N,          KC_E,          KC_I,    LT(_SWITCH,KC_O),  KC_QUOT,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        KC_LCTL,         KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,                                           KC_K,          KC_M,        KC_COMM,        KC_DOT,       KC_SLSH,       KC_RSFT,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    KC_LGUI,       MO(_NUM),       KC_SPC,           KC_ENT,       MO(_SYM),      KC_LALT
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),

  // colemak DH
  [_COLEMAKDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
   LT(_NUMPAD,KC_TAB),   KC_Q,          KC_W,          KC_F,          KC_P,          KC_B,                                     LT(_SWITCH,KC_J),    KC_L,          KC_U,          KC_Y,        KC_SCLN,       KC_BSPC,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        KC_LSFT,         KC_A,          KC_R,          KC_S,          KC_T,          KC_G,                                           KC_M,          KC_N,          KC_E,          KC_I,    LT(_SWITCH,KC_O),  KC_QUOT,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        KC_LCTL,         KC_Z,          KC_X,          KC_C,          KC_D,          KC_V,                                           KC_K,          KC_H,        KC_COMM,        KC_DOT,       KC_SLSH,       KC_RSFT,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    KC_LGUI,       MO(_NUM),       KC_SPC,           KC_ENT,       MO(_SYM),      KC_LALT
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),

  // qwerty
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
        _______,         KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,                                           KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,        _______,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,         KC_A,          KC_S,          KC_D,          KC_F,          KC_G,                                           KC_H,          KC_J,          KC_K,          KC_L,   LT(_SWITCH,KC_SCLN),_______,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,         KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,                                           KC_N,          KC_M,        KC_COMM,        KC_DOT,       KC_SLSH,       _______,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    _______,       _______,       _______,          _______,       _______,       _______
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),

  // numbers  - L thumb
  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
         KC_ESC,         KC_1,          KC_2,          KC_3,          KC_4,          KC_5,                                           KC_6,          KC_7,          KC_8,          KC_9,          KC_0,        KC_BSPC,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_WH_U,       KC_PGUP,                                        KC_LEFT,       KC_DOWN,        KC_UP,        KC_RGHT,       XXXXXXX,        KC_DEL,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_WH_D,       KC_PGDN,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    _______,       _______,       _______,          _______,     MO(_COMMAND),    _______
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),

  // symbols  - R thumb
  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
         KC_ESC,       KC_EXLM,        KC_AT,        KC_HASH,        KC_DLR,       KC_PERC,                                        KC_CIRC,       KC_AMPR,       KC_ASTR,       KC_LPRN,       KC_RPRN,       KC_BSPC,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        KC_MINS,        KC_EQL,       KC_LCBR,       KC_RCBR,       KC_PIPE,        KC_GRV,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        _______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        KC_UNDS,       KC_PLUS,       KC_LBRC,       KC_RBRC,       KC_BSLS,       KC_TILD,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    _______,     MO(_COMMAND),    _______,          _______,       _______,       _______
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),

  // commands - both thumbs
  [_COMMAND] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
        XXXXXXX,        KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,                                          KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        RGB_TOG,       RGB_HUI,       RGB_SAI,       RGB_VAI,    DF(_COLEMAKDH), DF(_COLEMAK),                                   C(G(KC_LEFT)),   XXXXXXX,       XXXXXXX,     C(G(KC_RGHT)),   XXXXXXX,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        RGB_MOD,       RGB_HUD,       RGB_SAD,       RGB_VAD,       XXXXXXX,     DF(_QWERTY),                                      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    _______,       _______,       _______,          _______,       _______,       _______
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),

  // numpad
  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_LNUM,                                        KC_CIRC,        KC_P7,         KC_P8,         KC_P9,        KC_PEQL,       KC_BSPC,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        KC_PMNS,        KC_P4,         KC_P5,         KC_P6,        KC_PAST,        KC_DEL,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        KC_PPLS,        KC_P1,         KC_P2,         KC_P3,        KC_PSLS,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                  OSM(MOD_MEH),    XXXXXXX,       _______,          KC_PENT,        KC_P0,        KC_PDOT
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),

  // layer switcher
  [_SWITCH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
        QK_BOOT,     TG(_COLEMAK), TG(_COLEMAKDH), TG(_QWERTY),    TG(_NUM),      TG(_SYM),                                      TG(_COMMAND),  TG(_NUMPAD),   TG(_SWITCH),    TG(_MOVE),      XXXXXXX,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
         EE_CLR,       XXXXXXX,       XXXXXXX,       KC_MUTE,       KC_VOLU,       KC_BRIU,                                        KC_MPRV,       KC_MPLY,       KC_MNXT,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_VOLD,       KC_BRID,                                        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    XXXXXXX,       XXXXXXX,       XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX
                                                              //`--------------------------------------------'  `--------------------------------------------'
  ),

  // amovement
  [_MOVE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------------.                                ,-----------------------------------------------------------------------------------------.
       TG(_MOVE),      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       KC_HOME,        KC_UP,        KC_PGUP,       XXXXXXX,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,       KC_LEFT,       XXXXXXX,       KC_RGHT,       XXXXXXX,        KC_DEL,
  //|--------------+--------------+--------------+--------------+--------------+--------------|                                |--------------+--------------+--------------+--------------+--------------+--------------|
        XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                        XXXXXXX,        KC_END,       KC_DOWN,       KC_PGDN,       XXXXXXX,       XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------------+--------------|  |--------------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                    XXXXXXX,       XXXXXXX,       XXXXXXX,          _______,       XXXXXXX,       XXXXXXX
                                                              //`--------------------------------------------'  `--------------------------------------------'
  )
};

#ifdef RGBLIGHT_ENABLE
  // _COLEMAKDH
  // Light on thumbs and underglow
  const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_RED},
    {27, 7, HSV_RED}
  );

  // _QWERTY
  // Light on thumbs and underglow
  const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_AZURE},
    {27, 7, HSV_AZURE}
  );

  // _NUM
  // Light on thumbs and underglow
  const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_TEAL},
    {27, 7, HSV_TEAL}
  );

  // _SYM
  // Light on thumbs and underglow
  const rgblight_segment_t PROGMEM layer_sym_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_BLUE},
    {27, 7, HSV_BLUE}
  );

  // _COMMAND
  // Light on thumbs and underglow
  const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_PURPLE},
    {27, 7, HSV_PURPLE}
  );

  // _NUMPAD
  // Light on thumbs, underglow and number block
  const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_ORANGE},
    {27, 7, HSV_ORANGE},
    {37, 11, HSV_BLUE}
  );

  // _SWITCH
  // Light up top row and underglow
  const rgblight_segment_t PROGMEM layer_switch_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_GREEN},
    {9, 2, HSV_GREEN},
    {17, 2, HSV_GREEN},
    {23, 1, HSV_GREEN},
    {27, 6, HSV_GREEN},
    {36, 2, HSV_GREEN},
    {44, 2, HSV_GREEN},
    {50, 1, HSV_GREEN}
  );

  // _MOVE
  // Light on thumbs and underglow
  const rgblight_segment_t PROGMEM layer_move_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_PINK},
    {27, 7, HSV_PINK}
  );

  // Now define the array of layers. Later layers take precedence
  const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_colemakdh_lights,
    layer_qwerty_lights,
    layer_num_lights, // Overrides layer 1
    layer_sym_lights,
    layer_command_lights,
    layer_numpad_lights,
    layer_move_lights,
    layer_switch_lights // Overrides other layers
  );

  layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAKDH));
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
  }

  layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(4, layer_state_cmp(state, _COMMAND));
    rgblight_set_layer_state(5, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(6, layer_state_cmp(state, _MOVE));
    rgblight_set_layer_state(7, layer_state_cmp(state, _SWITCH));
    return state;
  }
#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
  // Leds of underglow and thumbs
  const uint8_t underglow_thumbs_leds[] = {0,1,2,3,4,5,27,28,29,30,31,32,6,33};
  // Leds of number block
  const uint8_t number_block_leds[] = {37,38,39,40,41,42,43,44,45,46,47};
  // Leds of top row
  const uint8_t top_row_leds[] = {9,10,17,18,23,36,37,44,45,50};

  void set_color(const uint8_t* leds, uint8_t leds_len, uint8_t h, uint8_t s, uint8_t v) {
    HSV hsv = {h, s, v};
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = 0; i < leds_len; i++) {
      rgb_matrix_set_color(*(leds + i), rgb.r, rgb.g, rgb.b);
    }
  }

  void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(default_layer_state|layer_state)) {
      case _COLEMAKDH:
        set_color(underglow_thumbs_leds, 14, HSV_RED);
        break;
      case _QWERTY:
        set_color(underglow_thumbs_leds, 14, HSV_AZURE);
        break;
      case _NUM:
        set_color(underglow_thumbs_leds, 14, HSV_TEAL);
        break;
      case _SYM:
        set_color(underglow_thumbs_leds, 14, HSV_BLUE);
        break;
      case _COMMAND:
        set_color(underglow_thumbs_leds, 14, HSV_PURPLE);
        break;
      case _NUMPAD:
        set_color(underglow_thumbs_leds, 14, HSV_ORANGE);
        set_color(number_block_leds, 11, HSV_BLUE);
        break;
      case _SWITCH:
        set_color(underglow_thumbs_leds, 12, HSV_GREEN);
        set_color(top_row_leds, 10, HSV_GREEN);
        break;
      case _MOVE:
        set_color(underglow_thumbs_leds, 14, HSV_PINK);
        break;
    }
  }
#endif // RGB_MATRIX_ENABLE

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    rgblight_layers = my_rgb_layers; // Enable the LED layers
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0x00, 0x00, 0x47); // RGB : 208, 208, 208
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  #endif // RGBLIGHT_ENABLE

  #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(0x00, 0x00, 0x47); // RGB : 208, 208, 208
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  #endif // RGB_MATRIX_ENABLE
}

#ifdef OLED_ENABLE
  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
      return OLED_ROTATION_180; // Flips the display 180 degrees if offhand
    }
    return rotation;
  }

  void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(default_layer_state|layer_state)) {
      case _COLEMAK:
        oled_write_ln_P(PSTR("COLEMAK"),false);
        break;
      case _COLEMAKDH:
        oled_write_ln_P(PSTR("COLEMAKDH"),false);
        break;
      case _QWERTY:
        oled_write_ln_P(PSTR("QWERTY"),false);
        break;
      case _NUM:
        oled_write_ln_P(PSTR("Numbers"),false);
        break;
      case _SYM:
        oled_write_ln_P(PSTR("Symbols"),false);
        break;
      case _COMMAND:
        oled_write_ln_P(PSTR("Command"),false);
        break;
      case _NUMPAD:
        oled_write_ln_P(PSTR("Numpad"),false);
        break;
      case _SWITCH:
        oled_write_ln_P(PSTR("Layer Switch"),false);
        break;
      case _MOVE:
        oled_write_ln_P(PSTR("Movement"),false);
        break;
    }
  }

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

  bool oled_task_user(void) {
    if (is_keyboard_master()) {
      oled_render_layer_state();
      oled_render_keylog();
    } else {
      oled_render_logo();
    }
    return false;
  }

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      set_keylog(keycode, record);
    }
    return true;
  }
#endif // OLED_ENABLE
