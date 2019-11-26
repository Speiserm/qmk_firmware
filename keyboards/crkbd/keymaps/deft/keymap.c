/*
 * The Deft layout for the Planck Keyboard
 * Deft Version 1.1
 *
 * A keyboard layout designed for efficiency in programming and transferability between ortholinear boards.
 * Deft is currently supported on the following boards:
 * Planck (12x4)
 * Let's Split (12x4 split)
 * CRKBD (Corne) (Helidox)
 *
 * Coming soon to:
 * Ergodox
 * XD75
 * Collide39
 * Helix
 * HelixPico
 * BFO-9000
 * Sol 2
 * Miuni32
 *
 * The Deft keyboard layout was designed by Michael Speiser. You can find other Deft layouts at my Github:
 * https://github.com/Speiserm
 *
 * A keymap overview and changelog should be available in the repo you got this software from, or at my repo, listed above.
 *
 * For questions, issues, or feedback, feel free to email me at Speiserm@pm.me.
 *
 *
 * Flashing:
 *
 * make crkbd:deft:avrdude
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Follow my cat:
 * https://www.instagram.com/BuchaTheCat/
 *
 */

#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS /* Fix these */
#define XXXXX KC_TRNS
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define RGBTOG  RGB_TOG /* Toggle RGB lighting on/off */
#define RGBMODE RGB_MOD /* Cycle through RGB modes, hold shift to go backwards */
#define HUE_UP RGB_HUI /* Increase hue */
#define HUE_DN RGB_HUD /* Decrease hue */
#define SAT_UP RGB_SAI /* Increase saturation */
#define SAT_DN RGB_SAD /* Decrease saturation */
#define BRT_UP RGB_VAI /* Increase brightness */
#define BRT_DN RGB_VAD /* Decrease brightness */
#define STATIC RGB_M_P /* Static light mode */
#define BREATHE RGB_M_B /* Breathing light mode */
#define RAINBOW RGB_M_R /* Rainbow light mode */
#define SWIRL RGB_M_SW /* Swirl light mode */
#define SNAKE RGB_M_SN /* Snake light mode */
#define KNIGHT RGB_M_K /* Knight rider light mode */
#define XMAS RGB_M_X /* Christmas light mode */
#define GRAD RGB_M_G /* Gradient light mode */
#define TEST RGB_M_T /* RGB test light mode */
#define CYCLE RGBLIGHT_MODE_ALTERNATING /* Cycle through light modes */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Deft
   * ,-----------------------------------------.                ,-----------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |  T   |                |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |Shift |   A  |   S  |   D  |   F  |  G   |                |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | Ctrl |   Z  |   X  |   C  |   V  |  B   |                |   N  |   M  |   ,  |   .  | Copy |  /   |
   * `---------------------------+------+------+------.  ,------+------+------+---------------------------'
   *                             | Alt  |Lower |Enter |  |Space |Raise |Leader|
   *                             `--------------------'  `--------------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_BSPC,\
    KC_LSFT,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_QUOT,\
    KC_LCTL,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,C(KC_C),KC_SLSH,\
                                KC_LALT, LOWER,KC_ENT,   KC_SPC, RAISE, KC_LEAD \
  ),

  /* Lower
   * ,-----------------------------------------.                ,-----------------------------------------.
   * | Del  | Alt1 | Alt2 | Alt3 | Alt4 |  (   |                |   )  |      |  Up  |      |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | Tab  |   `  |   \  |   =  |   -  |  <   |                |   >  | Left | Down | Right|      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | GUI  |      |      |      |      |  [   |                |   ]  |      |      |      |Paste |      |
   * `---------------------------+------+------+------.  ,------+------+------+---------------------------'
   *                             |      |      |Space |  |      |      |      |
   *                             `--------------------'  `--------------------'
   */
  [_LOWER] = LAYOUT( \
    KC_DEL,A(KC_1),A(KC_2),A(KC_3),A(KC_4),S(KC_9),                 S(KC_0),XXXXX,KC_UP,XXXXX,XXXXX,XXXXX,\
    KC_TAB,KC_GRV,KC_BSLS,KC_EQL,KC_MINS,S(KC_COMM),              S(KC_DOT),KC_LEFT,KC_DOWN,KC_RIGHT,XXXXX,XXXXX,\
    KC_LGUI,XXXXX, XXXXX, XXXXX, XXXXX, KC_LBRC,                 KC_RBRC, XXXXX, XXXXX,XXXXX, C(KC_P), XXXXX,\
                                  XXXXX, XXXXX, KC_SPC,      XXXXX, XXXXX, XXXXX \
  ),

  /* Raise
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      |   1  |   2  |   3  |   4  |  5   |                |   6  |  7   |  8   |  9   |  0   |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      | F11  | F12  | F13  | F14  | F15  |                | F16  | F17  | F18  | F19  | Cut  |      |
   * `---------------------------+------+------+------.  ,------+------+------+---------------------------'
   *                             |      |      |      |  |Enter |      |      |
   *                             `--------------------'  `--------------------'
   */
  [_RAISE] = LAYOUT( \
      XXXXX,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,  KC_8,  KC_9,   KC_0, XXXXX,\
      XXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, XXXXX,\
      XXXXX,KC_F11,KC_F12,KC_F13,KC_F14,KC_F15,                 KC_F16,KC_F17,KC_F18,KC_F19,C(KC_X), XXXXX,\
                                  XXXXX, XXXXX, XXXXX,    KC_ENT, XXXXX, XXXXX \
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |RGBTOG|RGBMOD| CYCLE|      |      |      |                |      |      |      |      |      |RESET|
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |HUE_UP|SAT_UP|BRT_UP|      |      |      |                |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |HUE_DN|SAT_DN|BRT_DN|      |      |      |                |      |      |      |      |      |      |
   * `---------------------------+------+------+------.  ,------+------+------+---------------------------'
   *                             |      |      |      |  |      |      |      |
   *                             `--------------------'  `--------------------'
   */
  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     RGBTOG, RGBMODE,CYCLE,RGBRST, XXXXX, XXXXX,               XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, RESET,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     HUE_UP,SAT_UP,BRT_UP, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     HUE_DN,SAT_DN,BRT_DN, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
