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

#include "oddball.h"
#include "pointing_device.h"
#include "./pmw3360/pmw3360.h"
#define SCROLL_DIVIDER 12
#define CPI_1 2000
#define CPI_2 4000
#define CPI_3 8000
#define CLAMP_HID(value) value < -127 ? -127 : value > 127 ? 127 : value

//static bool scroll_pressed;
//static int8_t scroll_h;
//static int8_t scroll_v;

void on_mouse_button(uint8_t mouse_button, bool pressed) {
    report_mouse_t report = pointing_device_get_report();

    if(pressed)
        report.buttons |= mouse_button;
    else
        report.buttons &= ~mouse_button;
    pointing_device_set_report(report);
	pointing_device_send();
}

void on_cpi_button(int16_t cpi) {

    // read cpi first to prevent unnecessary writes to EEPROM
    if(pmw_get_config().cpi == cpi)
        return;

    pmw_set_config((config_pmw_t){ cpi });

    config_oddball_t kb_config;
    kb_config.cpi = cpi;
    eeconfig_update_kb(kb_config.raw);
}

void pointing_device_init(void){
    if(!is_keyboard_master())
        return;

    pmw_init();
    // read config from EEPROM and update if needed

    config_oddball_t kb_config;
    kb_config.raw = eeconfig_read_kb();

    if(!kb_config.cpi) {
        kb_config.cpi = CPI_2;
        eeconfig_update_kb(kb_config.raw);
    }

    pmw_set_config((config_pmw_t){ kb_config.cpi });
}

int16_t cum_x = 0;
int16_t cum_y = 0;
// Triggers help to move only horizontal or vertical. When accumulated distance triggeres, only move one discrete value in direction with bigger delta.
uint8_t carret_trigger = 80;
uint8_t scroll_trigger = 32;
float cursor_multiplier = 0.4; // adjust cursor speed
uint8_t integration_divisor = 50; // slow down every mode in integration mode

void tap_tb(int16_t delta, uint16_t keycode0, uint16_t keycode1) {
	if(delta > 0) {
		tap_code(keycode0);
	} else if(delta < 0) {
		tap_code(keycode1);
	}
}

int16_t clamped_x;
int16_t clamped_y;
bool integrationMode = false;
int16_t cumi_x = 0;
int16_t cumi_y = 0;
uint8_t trackMode = 0; // 0 Mousecursor; 1 arrowkeys/carret; 2 scrollwheel

void pointing_device_task(void){
    if(!is_keyboard_master() || (timer_read32() > motion_time && !integrationMode))
        return;

    report_mouse_t mouse_report = pointing_device_get_report();
    report_pmw_t pmw_report = pmw_get_report();

	if (integrationMode) {
		cumi_x += pmw_report.x;
		cumi_y += pmw_report.y;
		clamped_x = CLAMP_HID(cumi_x / integration_divisor);
		clamped_y = CLAMP_HID(cumi_y / integration_divisor);
	} else {
		clamped_x = CLAMP_HID(pmw_report.x);
		clamped_y = CLAMP_HID(pmw_report.y);
	}

    if(trackMode == 2) {//scroll
        // accumulate scroll
		cum_x = CLAMP_HID(cum_x + clamped_x);
		cum_y = CLAMP_HID(cum_y + clamped_y);
		if(abs(cum_x) + abs(cum_y) >= scroll_trigger){
			if(abs(cum_x) > abs(cum_y)) {
				mouse_report.h = cum_x/scroll_trigger;
			} else {
				mouse_report.v = cum_y/scroll_trigger;
			}
			cum_x = 0;
			cum_y = 0;
		}
    }
	else if (trackMode == 0) { //cursor
        mouse_report.x = (int)(clamped_x * cursor_multiplier);
        mouse_report.y = (int)(-clamped_y * cursor_multiplier);
    } else { //carret
		cum_x = CLAMP_HID(cum_x + clamped_x);
		cum_y = CLAMP_HID(cum_y + clamped_y);
		if(abs(cum_x) + abs(cum_y) >= carret_trigger){
			if(abs(cum_x) > abs(cum_y)) {
				tap_tb(cum_x, KC_RIGHT, KC_LEFT);
			} else {
				tap_tb(cum_y,  KC_UP, KC_DOWN  );
			}
			cum_x = 0;
			cum_y = 0;
		}
	}

    pointing_device_set_report(mouse_report);
    pointing_device_send();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if(!process_record_user(keycode, record))
        return false;

    // handle mouse drag and scroll
    switch (keycode) {

    	case KC_CURS:
    	  if (record->event.pressed) {
			  trackMode = 0;
		  } else {
		  }
  		  return false;

    	//case KC_CHRT:
    	//  if (record->event.pressed) {
		//	  trackMode = 1;
		//  } else {
		//  }
  		//  return false;

    	case KC_SCRL:
    	  if (record->event.pressed) {
			  trackMode = 2;
		  } else {
		  }
  		  return false;

    	case KC_INTE:
    	  if (record->event.pressed) {
			cumi_x = 0;
			cumi_y = 0;
			integrationMode = true;
		  } else {
			integrationMode = false;
		  }
  		  return false;

        case KC_BTN1:
            on_mouse_button(MOUSE_BTN1, record->event.pressed);
            return false;

        case KC_BTN2:
            on_mouse_button(MOUSE_BTN2, record->event.pressed);
            return false;

        case KC_BTN3:
            on_mouse_button(MOUSE_BTN3, record->event.pressed);
            return false;

        case KC_BTN4:
            on_mouse_button(MOUSE_BTN4, record->event.pressed);
            return false;

        case KC_BTN5:
            on_mouse_button(MOUSE_BTN5, record->event.pressed);
            return false;

		default:
    	  return true;
  }
}

ISR(INT2_vect) {
    motion_time = timer_read32() + 50;
    //mouse_report = pointing_device_get_report();
    //pmw_report = pmw_get_report();
}
