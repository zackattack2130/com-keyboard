#include QMK_KEYBOARD_H
#include "quantum.h"

/* ------- Readable physical-layout macro (3x7 per half) ------- */
#define LAYOUT_split_3x7(                                              \
/* Left r0 */  L00, L01, L02, L03, L04, L05, L06,                      \
/* Left r1 */  L10, L11, L12, L13, L14, L15, L16,                      \
/* Left r2 */  L20, L21, L22, L23, L24, L25, L26,                      \
/* Right r0 */ R00, R01, R02, R03, R04, R05, R06,                      \
/* Right r1 */ R10, R11, R12, R13, R14, R15, R16,                      \
/* Right r2 */ R20, R21, R22, R23, R24, R25, R26                       \
)                                                                      \
{                                                                       \
    /* Row 0 (left)  */ { L00, L01, L02, L03, L04, L05, L06 },         \
    /* Row 1 (left)  */ { L10, L11, L12, L13, L14, L15, L16 },         \
    /* Row 2 (left)  */ { L20, L21, L22, L23, L24, L25, L26 },         \
    /* Row 3 (right) */ { R00, R01, R02, R03, R04, R05, R06 },         \
    /* Row 4 (right) */ { R10, R11, R12, R13, R14, R15, R16 },         \
    /* Row 5 (right) */ { R20, R21, R22, R23, R24, R25, R26 }          \
}

/* ----------------------- Layers ----------------------- */
enum { _BASE, _FN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ================== BASE (matches your picture) ================== */
[_BASE] = LAYOUT_split_3x7(
  /* Left r0 */ KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,
  /* Left r1 */ KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    MO(_FN),
  /* Left r2 */ KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT,

  /* Right r0 */ KC_PSCR, KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  /* Right r1 */ KC_LGUI, KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  /* Right r2 */ KC_SPC,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT
),

/* ================== FN (matches your picture) ================== */
[_FN] = LAYOUT_split_3x7(
  /* Left r0 */ KC_CAPS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_DEL,
  /* Left r1 */ KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, MO(_FN),
  /* Left r2 */ KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT,

  /* Right r0 */ KC_PSCR, KC_7,   KC_8,    KC_9,    KC_MINS, KC_EQL,  KC_TRNS,
  /* Right r1 */ KC_LGUI, KC_4,   KC_5,    KC_6,    KC_0,    KC_TRNS, KC_TRNS,
  /* Right r2 */ KC_SPC,  KC_1,   KC_2,    KC_3,    KC_MUTE, KC_VOLD, KC_VOLU
)

};

/* ----------------------- Optional OLED ----------------------- */
#ifdef OLED_ENABLE
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_set_cursor(0, 1);
    switch (get_highest_layer(layer_state)) {
      case _BASE: oled_write_ln_P(PSTR("Layer 1"), false); break;
      case _FN:   oled_write_ln_P(PSTR("Layer 2"), false); break;
    }
    oled_set_cursor(1, 1);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
  } else {
    oled_set_cursor(0, 0);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS*") : PSTR("CAPS "), false);
  }
  return false;
}
#endif
