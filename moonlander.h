/*
Copyright 2018 Jack Humbert <jack.humb@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MCP23018_DEFAULT_ADDRESS 0b0100000

#define ML_LED_1(status) writePin(B5, (bool)status)
#define ML_LED_2(status) writePin(B4, (bool)status)
#define ML_LED_3(status) writePin(B3, (bool)status)

#define ML_LED_4(status) mcp23018_leds[0] = (bool)status
#define ML_LED_5(status) mcp23018_leds[1] = (bool)status
#define ML_LED_6(status) mcp23018_leds[2] = (bool)status

#include "quantum.h"

#define LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05,      k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15,      k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25,      k81, k82, k83, k84, k85, k86, \
                   k33, k34, k35,      k91, k92, k93 \
) \
{ \
    { k00, k01, k02, k03, k04, k05, KC_NO }, \
    { k10, k11, k12, k13, k14, k15, KC_NO }, \
    { k20, k21, k22, k23, k24, k25, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, k33, k34, k35, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
\
    { KC_NO, k61, k62, k63, k64, k65, k66 }, \
    { KC_NO, k71, k72, k73, k74, k75, k76 }, \
    { KC_NO, k81, k82, k83, k84, k85, k86 }, \
    { KC_NO, k91, k92, k93, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  } \
}

enum planck_ez_keycodes {
    TOGGLE_LAYER_COLOR = SAFE_RANGE,
    LED_LEVEL,
    ML_SAFE_RANGE,
};

typedef union {
  uint32_t raw;
  struct {
    bool         disable_layer_led   :1;
    bool         rgb_matrix_enable   :1;
    bool         led_level           :1;
    uint8_t      led_level_res       :2; // DO NOT REMOVE
  };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;
