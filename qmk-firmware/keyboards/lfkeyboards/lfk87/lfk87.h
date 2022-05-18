#ifndef LFK87_H
#define LFK87_H

/* if the kb.h file exists (because we're running from qmkbuilder) include it */
#if __has_include("kb.h")
#include "kb.h"
#endif

#include "quantum.h"
#include "matrix.h"
#include <avr/sfr_defs.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif

#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif


typedef struct RGB_Color {
    uint16_t red;
    uint16_t green;
    uint16_t blue;
} RGB_Color;

typedef struct Layer_Info {
    uint32_t layer;
    uint32_t mask;
    RGB_Color color;
} Layer_Info;

extern const uint32_t layer_count;
extern const Layer_Info layer_info[];

enum action_functions {
    LFK_CLEAR = 0,          // Resets all layers
    LFK_ESC_TILDE,          // esc+lshift = ~
    LFK_SET_DEFAULT_LAYER,  // changes and saves current base layer to eeprom
    LFK_CLICK_TOGGLE,       // Adjusts click duration
    LFK_CLICK_FREQ_HIGHER,  // Adjusts click frequency
    LFK_CLICK_FREQ_LOWER,   // Adjusts click frequency
    LFK_CLICK_TIME_LONGER,  // Adjusts click duration
    LFK_CLICK_TIME_SHORTER, // Adjusts click duration
    LFK_DEBUG_SETTINGS,     // prints LED and click settings to HID
    LFK_LED_TEST,           // cycles through switch and RGB LEDs
    LFK_PLAY_ONEUP
};

#define CLICK_HZ 500
#define CLICK_MS 2
#define CLICK_ENABLED 0

void reset_keyboard_kb(void);
void click(uint16_t freq, uint16_t duration);

#define ___ KC_NO

#ifdef LFK_TKL_REV_A
    #ifndef LAYOUT_tkl_ansi
        #define LAYOUT_tkl_ansi( \
            k11,       k13, k14, k15, k16,    k17, k18, k19, k1a,    k1b, k1c, k1d, k1e,   k1f, k1g, k1h, \
            k21,  k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d,       k2e,   k2f, k2g, k2h, \
            k31,    k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d,     k3e,   k3f, k3g, k3h, \
            k41,     k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c,         k4d, \
            k51,      k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c,             k5d,        k5g, \
            k61,   k62,   k63,                 k67,            k6b,   k6c,   k6d,   k6e,   k6f, k6g, k6h  \
        ) \
        { \
            { k11, ___, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, k1f, k1g, k1h }, \
            { k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e, k2f, k2g, k2h }, \
            { k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e, k3f, k3g, k3h }, \
            { k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, k4d, ___, ___, ___, ___ }, \
            { k51, ___, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c, k5d, ___, ___, k5g, ___ }, \
            { k61, k62, k63, ___, ___, ___, k67, ___, ___, ___, k6b, k6c, k6d, k6e, k6f, k6g, k6h }, \
        }

    #endif // !LAYOUT_tkl_ansi
    #ifndef LAYOUT_tkl_iso
        #define LAYOUT_tkl_iso( \
            k11,       k13, k14, k15, k16,    k17, k18, k19, k1a,    k1b, k1c, k1d, k1e,   k1f, k1g, k1h, \
            k21,  k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d,       k2e,   k2f, k2g, k2h, \
            k31,    k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d,            k3f, k3g, k3h, \
            k41,     k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, k4d,    k3e, \
            k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c,             k5d,        k5g, \
            k61,   k62,   k63,                 k67,            k6b,   k6c,   k6d,   k6e,   k6f, k6g, k6h  \
        ) \
        { \
            { k11, ___, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, k1f, k1g, k1h }, \
            { k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e, k2f, k2g, k2h }, \
            { k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e, k3f, k3g, k3h }, \
            { k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, k4d, ___, ___, ___, ___ }, \
            { k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c, k5d, ___, ___, k5g, ___ }, \
            { k61, k62, k63, ___, ___, ___, k67, ___, ___, ___, k6b, k6c, k6d, k6e, k6f, k6g, k6h }, \
        }

    #endif // !LAYOUT_tkl_iso
#else  // RevC+ keymaps
    #ifndef LAYOUT_tkl_ansi
        #define LAYOUT_tkl_ansi( \
            k71,       k11, k12, k13, k14,    k15, k16, k17, k18,    k19, k1a, k1b, k1c,   k1e, k1f, k1g, \
            k72,  k73, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,       k2c,   k2e, k2f, k2g, \
            k74,    k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c,     k3d,   k3e, k3f, k3g, \
            k61,     k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b,         k4c, \
            k62,      k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b,             k5c,        k5f, \
            k63,   k64,   k65,                 k67,            k6a,   k6b,   k6c,   k6d,   k6e, k6f, k6g  \
        ) \
        { \
            { k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, ___, k1e, k1f, k1g }, \
            { k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, ___, k2e, k2f, k2g }, \
            { k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e, k3f, k3g }, \
            { k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, ___, ___, ___, ___ }, \
            { ___, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c, ___, ___, k5f, ___ }, \
            { k61, k62, k63, k64, k65, ___, k67, ___, ___, k6a, k6b, k6c, k6d, k6e, k6f, k6g }, \
            { k71, k72, k73, k74, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
        }

    #endif // !LAYOUT_tkl_ansi
    #ifndef LAYOUT_tkl_iso
        #define LAYOUT_tkl_iso( \
            k71,       k11, k12, k13, k14,    k15, k16, k17, k18,    k19, k1a, k1b, k1c,   k1e, k1f, k1g, \
            k72,  k73, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,       k2c,   k2e, k2f, k2g, \
            k74,    k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c,            k3e, k3f, k3g, \
            k61,     k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c,    k3d, \
            k62, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b,             k5c,        k5f, \
            k63,   k64,   k65,                 k67,            k6a,   k6b,   k6c,   k6d,   k6e, k6f, k6g  \
        ) \
        { \
            { k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, ___, k1e, k1f, k1g }, \
            { k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, ___, k2e, k2f, k2g }, \
            { k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e, k3f, k3g }, \
            { k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, ___, ___, ___, ___ }, \
            { k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c, ___, ___, k5f, ___ }, \
            { k61, k62, k63, k64, k65, ___, k67, ___, ___, k6a, k6b, k6c, k6d, k6e, k6f, k6g }, \
            { k71, k72, k73, k74, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
        }

    #endif // !LAYOUT_tkl_iso
#endif //Rev

#endif //LFK87_H
