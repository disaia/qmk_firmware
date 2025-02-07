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

#include "preonic.h"
#include "../../rev3/config.h"
#include "../../rev3/rev3.h"
#include "muse.h"
#include "keymap_swedish.h"
#include "rgblight.h"

// Keycode shorthands
#define DEL_ALT LALT_T(KC_DEL)
#define SPC_LOWER LT(_LOWER, KC_SPC)
#define BKSP_RAISE LT(_RAISE, KC_BSPC)
#define SPC_LOWER LT(_LOWER, KC_SPC)
#define DEL_ALTGR ALGR_T(KC_DEL)
#define ENT_RSFT RSFT_T(KC_ENT)
#define F_LSFT LSFT_T(KC_F)
#define J_RSFT RSFT_T(KC_J)
#define J_RSFT RSFT_T(KC_J)

enum preonic_layers {
  _QWERTY,
  _GAMING,
  _NUMPAD,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty for typing
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Å  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |DelAlt|    Space    |  Backspace  |DAltgr| Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_2x2u(
  GAMING,    KC_1,    KC_2,    KC_3,       KC_4,    KC_5,    KC_6,   KC_7,       KC_8,      KC_9,    KC_0,     KC_BSPC,
  KC_TAB,    KC_Q,    KC_W,    KC_E,       KC_R,    KC_T,    KC_Y,   KC_U,       KC_I,      KC_O,    KC_P,     SE_ARNG,
  KC_ESC,    KC_A,    KC_S,    KC_D,       F_LSFT,  KC_G,    KC_H,   J_RSFT,     KC_K,      KC_L,    SE_ODIA,  SE_ADIA,
  KC_LSFT,   KC_Z,    KC_X,    KC_C,       KC_V,    KC_B,    KC_N,   KC_M,       SE_COMM,   SE_DOT,  KC_UP,    ENT_RSFT,
  KC_LCTL,   KC_LGUI, MO(_ADJUST), DEL_ALT,     SPC_LOWER,        BKSP_RAISE,         DEL_ALTGR, KC_LEFT, KC_DOWN,  KC_RGHT
),

/* Qwerty for gaming
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Å  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Del  |    Space    |  Backspace  |  Del | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_preonic_2x2u(
  QWERTY,    KC_1,    KC_2,    KC_3,      KC_4,    KC_5,     KC_6,    KC_7,     KC_8,       KC_9,    KC_0,     KC_BSPC,
  KC_TAB,    KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,     KC_Y,    KC_U,     KC_I,       KC_O,    KC_P,     SE_ARNG,
  KC_ESC,    KC_A,    KC_S,    KC_D,      KC_F,    KC_G,     KC_H,    KC_J,     KC_K,       KC_L,    SE_ODIA,  SE_ADIA,
  KC_LSFT,   KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,     KC_N,    KC_M,     KC_COMM,    KC_DOT,  KC_UP,    ENT_RSFT,
  KC_LCTL,   KC_LGUI, KC_LALT, DEL_ALT,   KC_SPC,            KC_BSPC,           DEL_ALTGR,  KC_LEFT, KC_DOWN,  KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Del  |    Space    |  Backspace  |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_2x2u(
  KC_GRV,  KC_1,    KC_2,    KC_3,                  KC_4,    KC_5,          KC_6,    KC_7,          KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,                  KC_P,    KC_G,          KC_J,    KC_L,          KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_ESC,  KC_A,    KC_R,    KC_S,                  KC_T,    KC_D,          KC_H,    KC_N,          KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,                  KC_V,    KC_B,          KC_K,    KC_M,          KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_LGUI, KC_LALT, LT(_ADJUST, KC_DEL),   LT(_LOWER, KC_BSPC),    LT(_RAISE, KC_SPC),     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Del  |    Space    |  Backspace  |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_2x2u(
  KC_GRV,  KC_1,    KC_2,    KC_3,                KC_4,    KC_5,        KC_6,    KC_7,        KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,              KC_P,    KC_Y,        KC_F,    KC_G,        KC_C,    KC_R,    KC_L,    KC_DEL,
  KC_ESC,  KC_A,    KC_O,    KC_E,                KC_U,    KC_I,        KC_D,    KC_H,        KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,                KC_K,    KC_X,        KC_B,    KC_M,        KC_W,    KC_V,    KC_Z,    KC_ENT,
  KC_LCTL, KC_LCTL, KC_LALT, LT(_ADJUST, KC_DEL), LT(_LOWER, KC_BSPC),  LT(_RAISE, KC_SPC),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Numpad
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |      |      | PgDn | PgUp | Home |   /  |   *  |   -  | PgDn | PgUp | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |      |  Up  |      |      |      |   7  |   8  |   9  |      |   +  | Del  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Esc  | Left | Down | Right|      |      |   4  |   5  |   6  |      |      |  "   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|      |      |      |      |      |   1  |   2  |   3  |      | PgUp | Shift|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | GUI  | Alt  | Del  |    Space    |      0      |   .  | Home | PgDn |  End |
  * `-----------------------------------------------------------------------------------'
  */
  [_NUMPAD] = LAYOUT_preonic_2x2u(
    KC_ESC,  _______, _______,      _______,             _______, _______,      _______, KC_PSLS,    KC_PAST,   KC_PMNS,    KC_PGUP,  KC_BSPC,
    KC_TAB,  _______, _______,      _______,             _______, _______,      KC_P7,   KC_P8,      KC_P9,     _______,    KC_PPLS,  KC_DEL,
    KC_BSPC, _______, _______,      _______,             _______, _______,      KC_P4,   KC_P5,      KC_P6,     _______,    _______,  KC_QUOT,
    KC_LSFT, _______, _______,      _______,             _______, KC_COMM,      KC_P1,   KC_P2,      KC_P3,     _______,    KC_UP,    KC_ENT,
    KC_LCTL, KC_LALT, KC_LGUI,      LT(_ADJUST, KC_DEL), KC_SPC,                KC_P0,               KC_COMM,   KC_LEFT,    KC_DOWN,  KC_RGHT
  ),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ½  |   !  |   "  |   #  |   $  |   %  |   ^  |   &  |   (  |   )  |   =  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ½  |   !  |   "  |   €  |   $  |   %  |   ^  |   {  |   (  |   )  |   }  |  ~   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   @  |   $  |  F3  |   \  |   (  |   )  |   _  |   ?  |   {  |   }  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   ?  |   !  | Home |Pg Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             | Next | Home |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_2x2u(
  SE_HALF, KC_EXLM, SE_DQUO,    KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC,    KC_AMPR,     SE_LPRN,    SE_RPRN,  KC_RPRN, KC_DEL,
  SE_HALF, KC_EXLM, SE_DQUO,    SE_EURO, KC_DLR,  KC_PERC,  KC_CIRC,    SE_LCBR,     SE_LPRN,    SE_RPRN,  SE_RCBR, SE_TILD,
  _______, SE_AT,   SE_DLR,     KC_F3,   KC_F4,   SE_RPRN,  SE_RCBR,    SE_UNDS,     SE_QUES,    SE_LCBR,  SE_RCBR, SE_QUOT,
  _______, KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,   KC_F12,     S(KC_NUHS),  SE_QUES,    KC_EXLM,  KC_PGUP, _______,
  _______, _______, _______,    _______, _______,           _______,                 SE_PIPE,    KC_HOME,  KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   <  |   [  |   ]  |   >  |  ^   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |   /  |   {  |   }  |   -  |   +  |   [  |   ]  |  *   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_2x2u(
  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,   KC_F12,
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    SE_LABK,  SE_LBRC,  SE_RBRC, SE_RABK,  SE_CIRC,
  _______,  KC_F1,   KC_F2,   KC_F3,   SE_SLSH,  KC_F5,   KC_F6,   SE_MINS,  SE_PLUS,  SE_LBRC, SE_RBRC,  SE_ASTR,
  _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_NUHS,  KC_NUBS,  KC_PGUP, KC_PGDN,  _______,
  _______,  _______, _______, _______, _______,           _______,           SE_BSLS,  KC_VOLD, KC_VOLU,  KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|   |  |AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_2x2u(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   SE_PIPE, AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
            rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT);
          }
          return false;
          break;
        case GAMING:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAMING);
            rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT + 4);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
