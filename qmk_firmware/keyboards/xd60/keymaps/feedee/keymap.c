#include QMK_KEYBOARD_H

// Layer ID
#define _BASE  0
#define _FN1   1
#define _FN2   2  // Caplock layer
#define _RGB   3  // RGB layer]
#define _RESET 4

// Macro ID
#define M_WIN   1  // switch to Windows unicode
#define M_LIN 2  // switch to Linux unicode
#define M_OSX   3  // switch to OSX unicode

#define _K_TILD LSFT(KC_GRV)  // ~

// unicodes
#define _I_CIRC UC(0x00EE)  // î
#define _O_CIRC UC(0x00F4)  // ô
#define _A_CIRC UC(0x00E2)  // â
#define _U_CIRC UC(0x00FB)  // û
#define _U_GRAV UC(0x00F9)  // ù
#define _A_GRAV UC(0x00E0)  // à
#define _A_TREM UC(0x00E4)  // ä
#define _E_GRAV UC(0x00E8)  // è
#define _E_AIGU UC(0x00E9)  // é
#define _E_CIRC UC(0x00EA)  // ê
#define _E_TREM UC(0x00EB)  // ë

#define _INSSPC UC(0x00A0)  // insecable space
#define _C_CEDI UC(0x00E7)  // ç
#define _ELLIPS UC(0x2026)  // …
#define _DEGREE UC(0x00B0)  // °
#define _APOPUN UC(0x2019)  // ’ Punctuation apostrophe
#define _LQUOTM UC(0x00AB)  // «
#define _RQUOTM UC(0x00BB)  // »
#define _LQUOTA UC(0x201C)  // “
#define _RQUOTA UC(0x201D)  // ”
#define _OE_LIG UC(0x0153)  // œ
#define _EUROSI UC(0x20AC)  // €
#define _POUND  UC(0x00A3)  // £

//Tap Dance Declarations
/*enum {
  TD_PRN = 0  // ()
};*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 * ,--------------------------------------------------------------------.
 * | ESC   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -  | =  |   Bksp   |
 * |--------------------------------------------------------------------|
 * |  Tab    | Q | W | E | R | T | Y | U | I | O | P | [  | ]  |   \    |
 * |--------------------------------------------------------------------|
 * |   FN2     | A | S | D | F | G | H | J | K | L | ; | ' |   Enter    |
 * |--------------------------------------------------------------------|
 * | LShft       | Z | X | C | V | B | N | M | , | . | / |    RShft     |
 * |--------------------------------------------------------------------|
 * | LCtrl | LGui | LAlt |      Space       | FN1 | RAlt | Menu | LCtrl |
 * `--------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_60_ansi(
 KC_ESC,   KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC, \
 KC_TAB,   KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, \
 MO(_FN2), KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT, \
 KC_LSFT,  KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N,   KC_M, KC_COMM, KC_DOT,   KC_SLSH,                     KC_RSFT, \
 KC_LCTL,  KC_LGUI, KC_LALT,                   KC_SPC,                          MO(_FN1), KC_RALT,  KC_APP,  KC_RCTL),


/* FN 1
 * ,-----------------------------------------------------------------------------------.
 * | `  | F1 | F2 | F3 | F4 | F5 | F6 |  F7  | F8  | F9  | F10  | F11 | F12 |   Ins    |
 * |-----------------------------------------------------------------------------------|
 * | Caps | !  | @  | #  | &  | *  |    | Home |  ↑  | End | PgUp |     |     |        |
 * |-----------------------------------------------------------------------------------|
 * |        | $  | -  | -  | _  | =  |    |  ←   |  ↓  |  →  | PgDn |     |            |
 * |-----------------------------------------------------------------------------------|
 * |           | %  | ~  |    | ^  |    |    |  [   |  ]  |     |      |     RGB       |
 * |-----------------------------------------------------------------------------------|
 * |      |     |     |             Delete             |       |       |       | RESET |
 * `-----------------------------------------------------------------------------------'
 */
[_FN1] = LAYOUT_60_ansi(
 KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, \
 KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_AMPR, KC_ASTR, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, \
 _______, KC_DLR,  KC_MINS, KC_PLUS, KC_UNDS, KC_EQL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,          _______, \
 _______, KC_PERC, _K_TILD, _______, KC_CIRC, _______, _______, KC_LBRC, KC_RBRC, _______, _______,                   TO(_RGB), \
 _______, _______, _______,                            KC_DELT,                            _______, _______, _______, TO(_RESET)),


/* FN 2 (Caplock)
 * ,--------------------------------------------------------------------------.
 * |   | Lin | Win | OSX |    |    |    |     |     |Mute|Vol-|Vol+|         |
 * |---------------------------------------------------------------------------|
 * |     |   | … | ’ | â  | à  | î  |  (  |  )   |     |Print|     |    |
 * |---------------------------------------------------------------------------|
 * |       | € | ë | é | ê  | è  | ô  |  [  |  ]  |  “  |  ”  |     |    |
 * |---------------------------------------------------------------------------|
 * |        | £ | ç | œ | û  | ù  | «  |  »  |  {  |  }   |    |     |    |
 * |---------------------------------------------------------------------------|
 * |      |     |      |         insec space           |     |     |     |     |
 * `-------------------------------------------------------------------'
 */
[_FN2] = LAYOUT_60_ansi(
 _______, M(M_LIN), M(M_WIN), M(M_OSX), _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, \
 _______, _______,  _ELLIPS,  _APOPUN,  _A_CIRC, _A_GRAV, _I_CIRC, KC_LPRN, KC_RPRN, _______, KC_PSCR, _______, _______, _______, \
 _______, _EUROSI,  _E_TREM,  _E_AIGU,  _E_CIRC, _E_GRAV, _O_CIRC, KC_LBRC, KC_RBRC, _LQUOTA, _RQUOTA, _______,          _______, \
 _______, _POUND,   _C_CEDI,  _OE_LIG,  _U_CIRC, _U_GRAV, _LQUOTM, _RQUOTM, KC_LCBR, KC_RCBR, _______,                   _______, \
 _______, _______,  _______,                              _INSSPC,                            _______, _______, _______, _______),


/* RGB
 * ,------------------------------------------------------------------------------------------.
 * |   |Plain|Breath|Rainb|Swirl|Snake|Knight|Xmas |Grade| Test |     |     |     |           |
 * |------------------------------------------------------------------------------------------|
 * |       |      |     |     |     |     |     | Hue+ | Val+ | Sat+ |     |     |     |      |
 * |------------------------------------------------------------------------------------------|
 * |        |      |     |<Mode|Mode>|     |     | Hue- | Val- | Sat- |      |     |          |
 * |------------------------------------------------------------------------------------------|
 * |           |     |     |     |     |     |     |      |      |      |      |              |
 * |------------------------------------------------------------------------------------------|
 * |      |      |      |              Toogle RGB                 |      |      |      |      |
 * `------------------------------------------------------------------------------------------'
 */
[_RGB] = LAYOUT_60_ansi(
 TO(_BASE), RGB_M_P, RGB_M_B, RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, RGB_HUI, RGB_VAI, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 XXXXXXX,   XXXXXXX, XXXXXXX, RGB_RMOD, RGB_MOD,  XXXXXXX,  XXXXXXX, RGB_HUD, RGB_VAD, RGB_SAD, XXXXXXX, XXXXXXX,          XXXXXXX, \
 XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, \
 XXXXXXX,   XXXXXXX, XXXXXXX,                               RGB_TOG,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

// Reset
[_RESET] = LAYOUT_60_ansi(
 TO(_BASE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, \
 XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, \
 RESET,     XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

};

/*enum {
  NO_TAP = 0,
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

int cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted) {
      //if (!state->pressed) return SINGLE_TAP;
      //else return SINGLE_HOLD;
      return SINGLE_HOLD;
    }
    else {
      if (!state->pressed) return SINGLE_TAP;
      else return SINGLE_HOLD;
    }
  }
  return NO_TAP;
}

typedef struct {
  bool is_press_action;
  int state;
} xtap;

static xtap tab_state = {
  .is_press_action = true,
  .state = 0
};

void prn_finished(qk_tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
    case SINGLE_TAP: register_code(KC_LSFT); register_code(KC_9); unregister_code(KC_9); unregister_code(KC_LSFT); break;  // (
    case SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_0); unregister_code(KC_0); unregister_code(KC_LSFT); break;  // )
  }
}

void prn_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
    case SINGLE_TAP: unregister_code(KC_9); unregister_code(KC_LSFT); break;
    case DOUBLE_HOLD: unregister_code(KC_0); unregister_code(KC_LSFT); break;
  }
  tab_state.state = 0;
}*/

/*void prn_finished1(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("(");
    reset_tap_dance (state);
  }
  else { // 2
    SEND_STRING(")");
    reset_tap_dance (state);
  }
}*/

// Tap dance
/*qk_tap_dance_action_t tap_dance_actions[] = {
  //[TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [TD_PRN] = ACTION_TAP_DANCE_FN(prn_finished1),
};*/

// Loop
/*void matrix_scan_user(void) {
  // Empty
};*/

void matrix_init_user()
{
    // boot in Linux unicode mode by default
    set_unicode_input_mode(UC_LNX);
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
    case M_WIN:
        set_unicode_input_mode(UC_WIN);
        break;
    case M_LIN:
        set_unicode_input_mode(UC_LNX);
        break;
    case M_OSX:
        set_unicode_input_mode(UC_OSX);
        break;
    }
    return MACRO_NONE;
};
