#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _FN1 1
#define _FN2 2

#define KC_ KC_TRNS
#define KC_FN1 LT(_FN1, KC_NO)
#define KC_FN2 LT(_FN2, KC_NO)
#define KC_SPFN LT(_FN1, KC_SPACE)
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_kc_ortho_4x12(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
      TAB, Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      ESC, A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,      N  , M  ,COMM, DOT,SLSH,PGUP,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LCTL,LGUI,LALT, FN1, ENT, ENT,      SPC, SPC, FN2,HOME, END,PGDN
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

   [_FN1] = LAYOUT_kc_ortho_4x12(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
      GRV, 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      DEL,  F1, F2,  F3,  F4,  F5,        F6,MINS, EQL,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,  F7,  F8,  F9, F10, F11,      F12,    ,    ,    ,  UP,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,LEFT,DOWN,RIGHT
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_FN2] = LAYOUT_kc_ortho_4x12(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      DEL,RHUI,RSAI,RVAI,    ,    ,         ,UNDS,PLUS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,RHUD,RSAD,RVAD,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,RTOG,RMOD,    ,    ,    ,         ,    ,    ,    ,    ,
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

};
