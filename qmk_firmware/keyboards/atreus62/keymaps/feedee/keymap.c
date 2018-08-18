// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEF   0
#define _FN1   1
#define _FN2   2
#define _FN3   3
#define _FN4   4
#define _RESET 5


// Macro ID numbers
#define M_WIN   1
#define M_LINUX 2
#define M_OSX   3

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

// Fillers to make layering more clear
#define _______ KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,---------------------------------------.             .---------------------------------------.
 * |   `    |  1   |  2  |  3  |  4  |  5  |             |  6   |  7  |  8  |  9  |  0  |  ins   |
 * |--------+------+-----+-----+-----+-----|             |------+-----+-----+-----+-----+--------|
 * |  Tab   |  Q   |  W  |  E  |  R  |  T  |             |  Y   |  U  |  I  |  O  |  P  |   \    |
 * |--------+------+-----+-----+-----+-----|             |------+-----+-----+-----+-----+--------|
 * |  Fn3   |  A   |  S  |  D  |  F  |  G  |             |  H   |  J  |  K  |  L  |  ;  |   '    |
 * |--------+------+-----+-----+-----+-----|-----. .-----|------+-----+-----+-----+-----+--------|
 * | LShift |  Z   |  X  |  C  |  V  |  B  |     | |     |  N   |  M  |  ,  |  .  |  /  | RShift |
 * |--------+------+-----+-----+-----+-----| Fn2 | | Ent |------+-----+-----+-----+-----+--------|
 * | LCtrl  | LGui |  _  | Alt | Spc | Del |     | |     | Bksp | Fn1 |  -  |  =  | Fn4 |  Esc   |
 * `---------------------------------------------' '---------------------------------------------'
 */
[_DEF] = {
{ KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,     _______,   KC_6,    KC_7,     KC_8,    KC_9,   KC_0,     KC_INS  },
{ KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     _______,   KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,     KC_BSLS },
{ MO(_FN3), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     _______,   KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN,  KC_QUOT },
{ KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,     TG(_FN2),  KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT },
{ KC_LCTL,  KC_LGUI, KC_UNDS, KC_LALT, KC_SPC, KC_DELT,  KC_ENT,    KC_BSPC, MO(_FN1), KC_MINS, KC_EQL, MO(_FN4), KC_ESC  }
},

/* FN 1 (right)
 * ,-----------------------------.       .--------------------------------------.
 * | F1 | F2 | F3 | F4 | F5 | F6 |       |  F7  |  F8  | F9 | F10 | F11  | F12  |
 * |----+----+----+----+----+----|       |------+------+----+-----+------+------|
 * | `  | !  | @  | #  | &  | [  |       |   ]  | Home | ↑  | End | Bksp | PgUp |
 * |----+----+----+----+----+----|       |------+------+----+-----+------+------|
 * | $  | =  | -  | +  | _  | (  |       |   )  |  ←   | ↓  |  →  | Del  | PgDn |
 * |----+----+----+----+----+----|--. .--|------+------+----+-----+------+------|
 * |    | %  |    | ^  | *  | {  |  | |  |   }  |      |    |     |      |      |
 * |----+----+----+----+----+----|  | |  |------+------+----+-----+------+------|
 * |    |    |    |    |    |    |  | |  |      |      |    |     |      |      |
 * `--------------------------------' '-----------------------------------------'
 */
[_FN1] = {
{ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
{ KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_AMPR, KC_LBRC,  _______,  KC_RBRC, KC_HOME, KC_UP,   KC_END,  KC_BSPC, KC_PGUP },
{ KC_DLR,  KC_EQL,  KC_MINS, KC_PLUS, KC_UNDS, KC_LPRN,  _______,  KC_RPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DELT, KC_PGDN },
{ _______, KC_PERC, _______, KC_CIRC, KC_ASTR, KC_LCBR,  _______,  KC_RCBR, _______, _______, _______, _______, _______ },
{ _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______ }
},

/* FN 2 (Numpad)
 * ,---------------------------------.       .-----------------------.
 * |        |    |    |    |    | <  |       | > |   | / | * | - |   |
 * |--------+----+----+----+----+----|       |---+---+---+---+---+---|
 * |        |    |    |    |    | [  |       | ] | 7 | 8 | 9 | + |   |
 * |--------+----+----+----+----+----|       |---+---+---+---+---+---|
 * |        |    |    |    |    | (  |       | ) | 4 | 5 | 6 | = |   |
 * |--------+----+----+----+----+----|--. .--|---+---+---+---+---+---|
 * |        |    |    |    |    | {  |  | |  | } | 1 | 2 | 3 |   |   |
 * |--------+----+----+----+----+----|  | |  |---+---+---+---+---+---|
 * |        |    |    |    |    |    |  | |  |   |   | 0 | . |   |   |
 * `------------------------------------' '--------------------------'
 */
[_FN2] = {
{ _______, _______, _______, _______, _______, KC_LABK,  _______,  KC_RABK, _______, KC_PSLS, KC_PAST, KC_PMNS, _______ },
{ _______, _______, _______, _______, _______, KC_LBRC,  _______,  KC_RBRC, KC_7,    KC_8,    KC_9,    KC_PPLS, _______ },
{ _______, _______, _______, _______, _______, KC_LPRN,  _______,  KC_RPRN, KC_4,    KC_5,    KC_6,    KC_EQL , _______ },
{ _______, _______, _______, _______, _______, KC_LCBR,  _______,  KC_RCBR, KC_1,    KC_2,    KC_3,    _______, _______ },
{ _______, _______, _______, _______, _______, _______,  _______,  _______, _______, KC_0,    KC_DOT,  _______, _______ }
},

/* FN 3 (Left)
 * ,----------------------------------.       .-------------------------------------.
 * |        |   |   |   |      |      |       |      |  Pwr  | Sleep | Wake |   | ⏏ |
 * |--------+---+---+---+------+------|       |------+-------+-------+------+---+---|
 * | CapLck |   |   |   |      |      |       | Vol+ | Rewnd |   ►   | Fwrd |   |   |
 * |--------+---+---+---+------+------|       |------+-------+-------+------+---+---|
 * |        |   |   |   | Calc | Comp |       | Vol- | Prev  |   ◾   | Next |   |   |
 * |--------+---+---+---+------+------|--. .--|------+-------+-------+------+---+---|
 * |        |   |   |   |      |      |  | |  | Mute | Menu  |  Sel  |      |   |   |
 * |--------+---+---+---+------+------|  | |  |------+-------+-------+------+---+---|
 * |        |   |   |   |      |      |  | |  |      |       |       |      |   |   |
 * `-------------------------------------' '----------------------------------------'
 */
[_FN3] = {
{ _______, _______, _______, _______,  _______, _______,  _______,  _______, KC_PWR,  KC_SLEP, KC_WAKE, _______, KC_EJCT },
{ KC_CAPS, _______, _______, _______,  _______, _______,  _______,  KC_VOLU, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______ },
{ _______, _______, _______, _______,  KC_CALC, KC_MYCM,  _______,  KC_VOLD, KC_MPRV, KC_MSTP, KC_MNXT, _______, _______ },
{ _______, _______, _______, _______,  _______, _______,  _______,  KC_MUTE, KC_MENU, KC_MSEL, _______, _______, _______ },
{ _______, _______, _______, _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______ }
},

/* FN 4 (Strong right)
 * ,---------------------------------.       .---------------------------------.
 * |   |   |   | î | ô |      €      |       |   |   |   | Linux | Win |  OSX  |
 * |---+---+---+---+---+-------------|       |---+---+---+-------+-----+-------|
 * |   |   | … | ʼ | â |      à      |       |   |   |   |       |     |       |
 * |---+---+---+---+---+-------------|       |---+---+---+-------+-----+-------|
 * |   |   | ç | é | ê |      è      |       | « | » |   |       |     |       |
 * |---+---+---+---+---+-------------|--. .--|---+---+---+-------+-----+-------|
 * |   |   |   | œ | û |      ù      |  | |  | “ | ” |   |       |     |       |
 * |---+---+---+---+---+-------------|  | |  |---+---+---+-------+-----+-------|
 * |   |   |   |   |   | insec space |  | |  |   |   |   |       |     | Reset |
 * `------------------------------------' '------------------------------------'
 */
[_FN4] = {
{ _______, _______, _______, _I_CIRC, _O_CIRC, _EUROSI,  _______,  _______, _______, _______, M(M_LINUX), M(M_WIN), M(M_OSX) },
{ _______, _______, _ELLIPS, _APOPUN, _A_CIRC, _A_GRAV,  _______,  _______, _______, _______, _______, _______, _______ },
{ _______, _______, _C_CEDI, _E_AIGU, _E_CIRC, _E_GRAV,  _______,  _LQUOTM, _RQUOTM, _______, _______, _______, _______ },
{ _______, _______, _OE_LIG, _______, _U_CIRC, _U_GRAV,  _______,  _LQUOTA, _RQUOTA, _______, _______, _______, _______ },
{ _______, _______, _______, _______, _______, _INSSPC,  _______,  _______, _______, _______, _______, _______, TO(_RESET) }
},

// RESET
//    x     x     x     x     x     x          ||           x     x      x      x     x     x
//    x     x     x     x     x     x          ||           x     x      x      x     x     x
//    x     x     x     x     x     x          ||           x     x      x      x     x     x
//    x     x     x     x     x     x          ||           x     x      x      x     x     x
//  RESET   x     x     x     x     x     x    ||  back to  x     x      x      x     x     x
//                                                 default
[_RESET] = {
{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },
{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },
{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },
{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },
{ RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  TO(_DEF),  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }
}

};


const uint16_t PROGMEM fn_actions[] = {

};


void matrix_init_user()
{
    set_unicode_input_mode(UC_LNX);
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch (id) {
    /*case 0:
        if (record->event.pressed) {
            register_code(KC_RSFT);
        }
        else {
            unregister_code(KC_RSFT);
        }
        break;*/
    case M_WIN:
        set_unicode_input_mode(UC_WIN);
        break;
    case M_LINUX:
        set_unicode_input_mode(UC_LNX);
        break;
    case M_OSX:
        set_unicode_input_mode(UC_OSX);
        break;
    }
    return MACRO_NONE;
};
