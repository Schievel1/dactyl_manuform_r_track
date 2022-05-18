/* Copyright 2020 Alexander Tulloh
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


#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_5x6(
     KC_EQL , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0    ,KC_QUOT,
	 KC_TAB, KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  ,                          KC_J  , KC_L  , KC_U  , KC_Y  , KC_SCLN ,KC_MINS,
     KC_ESC , KC_A, KC_R , KC_S  , KC_T  , KC_D  ,                            KC_H  , KC_N  , KC_E  , KC_I  , KC_O    ,KC_INTE,
     KC_TILD, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_K  , KC_M  ,KC_COMM, KC_DOT, KC_SLSH ,KC_BSLASH,
                       KC_MS_BTN1, KC_MS_BTN2,                                                     KC_LBRC,KC_RBRC,
//                                      KC_LSFT,  KC_ENT,                   _______,  KC_SPC,
//                                      KC_LCTL,  RAISE,                    _______,  KC_LGUI,
//                                      KC_LALT,  LOWER,                    KC_BSPC,  KC_DEL

                                      LSFT, KC_CHRT),  KC_ENT,                   _______,  KC_SPC,
                                      LCTL_T(KC_CURS),  RAISE,                    _______,  KC_LGUI,
                                      LALT_T(KC_SCRL),  LOWER,                    KC_BSPC,  KC_DEL

//                                      KC_CHRT,  KC_ENT,                   _______,  KC_SPC,
//                                      KC_CURS,  RAISE,                    _______,  KC_LGUI,
//                                      KC_SCRL,  LOWER,                    KC_BSPC,  KC_DEL
  ),

  [_LOWER] = LAYOUT_5x6(

     KC_TILD,KC_EXLM   , KC_AT    ,KC_HASH  , KC_DLR ,KC_PERC,                        KC_CIRC, KC_AMPR       , KC_ASTR      ,KC_LPRN   ,KC_RPRN    ,KC_DEL,
     _______,_______   ,_______   ,_______  ,_______ ,KC_LBRC,                        KC_RBRC, KC_P7         , KC_P8        , KC_P9    ,_______    ,KC_PLUS,
       _______,RALT(KC_Q),RALT(KC_S),RALT(KC_S), KC_RBRC,KC_LBRC,                  KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC),RALT(KC_P), RALT(KC_P), KC_MUTE,
     _______,KC_HOME   ,KC_PGUP   ,KC_PGDN  , KC_END ,KC_LPRN,                        KC_RPRN, KC_P4         , KC_P5        , KC_P6    ,KC_MINS   ,KC_PIPE,
                                             _______,KC_PSCR,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_RAISE] = LAYOUT_5x6(
       _______,KC_LEFT   , KC_U     , KC_DOWN , KC_RGHT,KC_LPRN,                  KC_RPRN, KC_MPRV      , KC_MPLY      , KC_MNXT  , _______, KC_VOLU,
       _______, _______  , _______  , _______ , _______,_______,                  KC_TILD, _______      , RALT(KC_Y)   ,_______   , _______, KC_VOLD,
     _______,KC_LPRN   ,KC_RPRN   , KC_LBRC , KC_RBRC,KC_LBRC,                        KC_RBRC, LSFT(KC_LBRC) , LSFT(KC_RBRC),RALT(KC_P), RALT(KC_P), KC_MUTE,
       KC_F12 ,KC_F1     , KC_F2    , KC_F3   , KC_F4  , KC_F5 ,                  KC_F6  , KC_F7        , KC_F8        , KC_F9    , KC_F10 , KC_F11 ,
                                               _______,_______,            KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
};
