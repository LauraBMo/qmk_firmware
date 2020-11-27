/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
/* #include "keymap_danish.h" */
#include "keymap_spanish.h"

/* For the Alt_Tab key */
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum preonic_layers {
  _QWERTY,
  _QWERTY_ESP,
  _QWERTY_GRK,
  _MATH,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_ESP,
  QWERTY_GRK,
  MATH,
  LOWER,
  RAISE,
  MORE,
  BACKLIT,
  ALT_TAB
};

enum unicode_names {
   CALPHA,
   CBETA,
   CGAMMA,
   CDELTA,
   CEPSILON,
   CZETA,
   CETA,
   CTHETA,
   CIOTA,
   CKAPPA,
   CLAMBDA,
   CMU,
   CNU,
   CXI,
   COMICRON,
   CPI,
   CRHO,
   CSIGMA,
   CTAU,
   CUPSILON,
   CPHI,
   CCHI,
   CPSI,
   COMEGA,
   ALPHA,
   BETA,
   GAMMA,
   DELTA,
   EPSILON,
   ZETA,
   ETA,
   THETA,
   IOTA,
   KAPPA,
   LAMBDA,
   MU,
   NU,
   XI,
   OMICRON,
   PI,
   RHO,
   SIGMA,
   TAU,
   UPSILON,
   PHI,
   CHI,
   PSI,
   OMEGA
};

const uint32_t PROGMEM unicode_map[] = {
 [CALPHA]   = 0x0391, // Α 
 [CBETA]    = 0x0392, // Β 
 [CGAMMA]   = 0x0393, // Γ 
 [CDELTA]   = 0x0394, // Δ 
 [CEPSILON] = 0x0395, // Ε 
 [CZETA]    = 0x0396, // Ζ 
 [CETA]     = 0x0397, // Η 
 [CTHETA]   = 0x0398, // Θ 
 [CIOTA]    = 0x0399, // Ι 
 [CKAPPA]   = 0x039A, // Κ 
 [CLAMBDA]  = 0x039B, // Λ 
 [CMU]      = 0x039C, // Μ 
 [CNU]      = 0x039D, // Ν 
 [CXI]      = 0x039E, // Ξ 
 [COMICRON] = 0x039F, // Ο 
 [CPI]      = 0x03A0, // Π 
 [CRHO]     = 0x03A1, // Ρ 
 [CSIGMA]   = 0x03A3, // Σ 
 [CTAU]     = 0x03A4, // Τ 
 [CUPSILON] = 0x03A5, // Υ 
 [CPHI]     = 0x03A6, // Φ 
 [CCHI]     = 0x03A7, // Χ 
 [CPSI]     = 0x03A8, // Ψ 
 [COMEGA]   = 0x03A9, // Ω 
 [ALPHA]    = 0x03B1, // α
 [BETA]     = 0x03B2, // β
 [GAMMA]    = 0x03B3, // γ
 [DELTA]    = 0x03B4, // δ
 [EPSILON]  = 0x03B5, // ε
 [ZETA]     = 0x03B6, // ζ
 [ETA]      = 0x03B7, // η
 [THETA]    = 0x03B8, // θ
 [IOTA]     = 0x03B9, // ι
 [KAPPA]    = 0x03BA, // κ
 [LAMBDA]   = 0x03BB, // λ
 [MU]       = 0x03BC, // μ
 [NU]       = 0x03BD, // ν
 [XI]       = 0x03BE, // ξ
 [OMICRON]  = 0x03BF, // ο
 [PI]       = 0x03C0, // π
 [RHO]      = 0x03C1, // ρ
 [SIGMA]    = 0x03C3, // σ
 [TAU]      = 0x03C4, // τ
 [UPSILON]  = 0x03C5, // υ
 [PHI]      = 0x03C6, // φ
 [CHI]      = 0x03C7, // χ
 [PSI]      = 0x03C8, // ψ
 [OMEGA]    = 0x03C9, // ω
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |`/ESC |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |LGUI/:|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Ctrl/"|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Sf/Ent|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft/\ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGUI | MORE |Ctl/[ |Alt/( |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
 KC_GESC, KC_1, KC_2,            KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
 KC_TAB,  KC_Q, KC_W,            KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_ENT,
 KC_LSPO, KC_A, KC_S,            KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
 KC_RSPC, KC_Z, KC_X,            KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),
 KC_RGUI, MORE, LCTL_T(KC_LBRC), KC_LAPO, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* QWERTY_ESP
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_ESP] = LAYOUT_preonic_grid(
 ES_MORD,         ES_1,    ES_2,            ES_3,    ES_4,  ES_5,   ES_6,   ES_7,  ES_8,    ES_9,    ES_0,    KC_BSPC,
 KC_TAB,          ES_Q,    ES_W,            ES_E,    ES_R,  ES_T,   ES_Y,   ES_U,  ES_I,    ES_O,    ES_P,    KC_ENT,
 KC_LSPO,         ES_A,    ES_S,            ES_D,    ES_F,  ES_G,   ES_H,   ES_J,  ES_K,    ES_L,    ES_NTIL, RCTL_T(ES_CCED),
 LSFT_T(ES_GRV),  ES_Z,    ES_X,            ES_C,    ES_V,  ES_B,   ES_N,   ES_M,  ES_COMM, ES_DOT,  ES_QUOT, RSFT_T(ES_ACUT),
 KC_RGUI,         KC_ALGR, LCTL_T(KC_LBRC), KC_LAPO, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty Greek
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_GRK] = LAYOUT_preonic_grid(
KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
KC_TAB, XP(XI,CXI), XP(THETA,CTHETA), XP(EPSILON,CEPSILON), XP(RHO,CRHO), XP(TAU,CTAU), XP(PSI,CPSI), KC_U, XP(IOTA,CIOTA), XP(OMEGA,COMEGA), XP(PI,CPI), KC_ENT,
KC_LSPO, XP(ALPHA,CALPHA), XP(SIGMA,CSIGMA), XP(DELTA,CDELTA), XP(PHI,CPHI), XP(GAMMA,CGAMMA), XP(ETA,CETA), KC_J, XP(KAPPA,CKAPPA), XP(LAMBDA,CLAMBDA), KC_SCLN, RCTL_T(KC_QUOT),
LSFT_T(KC_ENT), XP(ZETA,CZETA), XP(CHI,CCHI), XP(OMICRON,COMICRON), XP(UPSILON,CUPSILON), XP(BETA,CBETA), XP(NU,CNU), XP(MU,CMU), KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLS),
KC_RGUI, MORE, LCTL_T(KC_LBRC), KC_LAPO, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

/* Qwerty Math
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MATH] = LAYOUT_preonic_grid(
KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
KC_TAB, XP(XI,CXI), XP(THETA,CTHETA), XP(EPSILON,CEPSILON), XP(RHO,CRHO), XP(TAU,CTAU), XP(PSI,CPSI), KC_U, XP(IOTA,CIOTA), XP(OMEGA,COMEGA), XP(PI,CPI), KC_ENT,
KC_LSPO, XP(ALPHA,CALPHA), XP(SIGMA,CSIGMA), XP(DELTA,CDELTA), XP(PHI,CPHI), XP(GAMMA,CGAMMA), XP(ETA,CETA), KC_J, XP(KAPPA,CKAPPA), XP(LAMBDA,CLAMBDA), KC_SCLN, RCTL_T(KC_QUOT),
LSFT_T(KC_ENT), XP(ZETA,CZETA), XP(CHI,CCHI), XP(OMICRON,COMICRON), XP(UPSILON,CUPSILON), XP(BETA,CBETA), XP(NU,CNU), XP(MU,CMU), KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLS),
KC_RGUI, MORE, LCTL_T(KC_LBRC), KC_LAPO, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
 _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, _______, _______, _______,
 _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_LT,   KC_GT,   KC_QUES, KC_PIPE,
 _______, _______, _______, _______, _______, KC_MPLY, KC_MPLY, KC_MSTP, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
 KC_GRAVE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,
 KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_RPRN, KC_RBRC, KC_RCBR,
 _______,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______, _______, KC_DQT,
 _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
 RESET,   _______,  _______, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_PWR,
 _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_SLEP,
 _______, RGB_SAD,  RGB_SAI, _______, _______, _______, _______, _______, QWERTY,  QWERTY_ESP, QWERTY_GRK, _______,
 RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______, _______, _______, _______, _______, _______,    _______,    _______,
 RGB_SPD, RGB_VAD,  RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______,    _______,    _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
            SEND_STRING(SS_RGUI("z"));
          }
          return false;
          break;
        case QWERTY_ESP:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY_ESP);
            SEND_STRING(SS_RGUI("z"));
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            update_tri_layer(_LOWER, _QWERTY_GRK, _MATH);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            update_tri_layer(_LOWER, _QWERTY_GRK, _MATH);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case MORE:
          if (record->event.pressed) {
            layer_on(_QWERTY_GRK);
            update_tri_layer(_LOWER, _QWERTY_GRK, _MATH);
          } else {
            layer_off(_QWERTY_GRK);
            update_tri_layer(_LOWER, _QWERTY_GRK, _MATH);
          }
          return false;
          break;
          case ALT_TAB:
          if (record->event.pressed) {
            if (!is_alt_tab_active) {
              is_alt_tab_active = true;
              register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
          } else {
            unregister_code(KC_TAB);
          }
          return false;
          break;
      }
    return true;
};

void matrix_scan_user(void) {
/* For the Alt_Tab key */
/* The very important timer. */
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
      }
    }
}


/* Local Variables: */
/* before-save-hook: nil */
/* eval: (setq-local before-save-hook nil) */
/* End: */
