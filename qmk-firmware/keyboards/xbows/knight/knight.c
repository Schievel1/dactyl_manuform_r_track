#include "knight.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();
    led_init_ports();
}

void led_init_ports(void) {
    setPinOutput(D1);
    writePinHigh(D1);
    setPinOutput(C7);
    writePinHigh(C7);
}
bool led_update_kb(led_t led_state) {
    if(led_update_user(led_state)) {
        writePin(C7, !led_state.caps_lock);
        writePin(D1, !led_state.num_lock);
    }
    return true;
}
