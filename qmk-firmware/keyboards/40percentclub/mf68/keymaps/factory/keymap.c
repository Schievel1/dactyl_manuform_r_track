#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FN1 1
#define _FN2 2
#define KC_ KC_TRNS
#define KC_X0 LT(_FN2, KC_CAPS)
#define KC_X1 MO(_FN1)
#define KC_X2 BL_STEP
#define KC_X3 BL_BRTG
#define KC_X4 BL_TOGG
#define KC_X5 BL_INC
#define KC_X6 BL_DEC



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------.  ,----+----. */
    ESC , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,  BSPC  ,   INS ,PGUP,
 /*|----`----`----`----`----`----`----`----`----`----`----`----`----`--------|  |----`----| */
    TAB   , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC, BSLS ,   DEL ,PGDN,
 /*|------`----`----`----`----`----`----`----`----`----`----`----`----`------|  `----`----' */
    X0     , A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,QUOT,    ENTER ,
 /*|-------`----`----`----`----`----`----`----`----`----`----`----`----------|  ,----. */
    LSFT     , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH,       RSFT  ,    UP ,
 /*|---------`----`----`----`----`----`----`----`----`----`----`-------------.--|----|----. */
    LCTL ,LGUI ,LALT ,            SPACE             ,  X1  ,RALT ,RCTL ,    LEFT,DOWN,RGHT
 /*`-----+-----+-----+------------------------------+------+-----+-----'   `----+----+----' */
  ),

  [_FN1] = LAYOUT_kc(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------.  ,----+----. */
    GRV , F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,   BSPC ,       ,HOME,
 /*|esc-`-1--`-2--`-3--`-4--`-5--`-6--`-7--`-8--`-9--`-0--`mnus`plus`--bksp--|  |ins-`pgup| */
          ,    , UP ,    ,    ,    ,    ,    ,    ,PSCR,SLCK,PAUS, X2 ,      ,       ,END,
 /*|tab---`-q--`-w--`-e--`-r--`-t--`-y--`-u--`-i--`-o--`-p--`-{--`-}--`--|---|  `del-`pgdn' */
     X0    ,LEFT,DOWN,RGHT,    , X6 , X5 , X4 , X3 , X2 ,HOME,    ,          ,
 /*|caps---`-a--`-s--`-d--`-f--`-g--`-h--`-j--`-k--`-l--`-;--`-'--`----enter-|  ,----. */
             ,    ,MPLY,MSTP,MPRV,MNXT,VOLD,VOLU,MUTE,    ,END ,             ,    X5 ,
 /*|shift----`-z--`-x--`-c--`-v--`-b--`-n--`-m--`-,--`-.--`-/--`-------shift-.--|-up-|----. */
         ,     ,     ,                              ,      ,     ,     ,     X3 , X6 , X4
 /*`ctrl-+-gui-+-alt-+----------space---------------+-fn---+-alt-+ctrl-'   `left+down+rght' */
  ),

  [_FN2] = LAYOUT_kc(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------.  ,----+----. */
    GRV , F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,   BSPC ,   VOLU,HOME,
 /*|esc-`-1--`-2--`-3--`-4--`-5--`-6--`-7--`-8--`-9--`-0--`mnus`plus`--bksp--|  |ins-`pgup| */
          ,    ,    , UP ,    ,    ,    , 7  , 8  , 9  ,    ,    ,    ,      ,   VOLD,END,
 /*|tab---`-q--`-w--`-e--`-r--`-t--`-y--`-u--`-i--`-o--`-p--`-{--`-}--`--|---|  `del-`pgdn' */
           ,    ,LEFT,DOWN,RGHT,    ,    , 4  , 5  , 6  ,    ,    ,          ,
 /*|caps---`-a--`-s--`-d--`-f--`-g--`-h--`-j--`-k--`-l--`-;--`-'--`----enter-|  ,----. */
             ,    ,    ,    ,    ,    , 0  , 1  , 2  , 3  ,    ,             ,   MUTE,
 /*|shift----`-z--`-x--`-c--`-v--`-b--`-n--`-m--`-,--`-.--`-/--`-------shift-.--|-up-|----. */
         ,     ,     ,                              ,      ,     ,     ,    MPRV,MPLY,MNXT
 /*`ctrl-+-gui-+-alt-+----------space---------------+-fn---+-alt-+ctrl-'   `left+down+rght' */
  )
};
