#pragma once

#include "../color/Color.h"

namespace ArduinoRGB {

class Led {

private:
    static const uint8_t PIN_RED = 3;
    static const uint8_t PIN_GREEN = 5;
    static const uint8_t PIN_BLUE = 6;

    static uint8_t max_value;
    static uint8_t min_value;

public: static void set_color(bool powerstate) {
    //If the LED's should light up or not
    if (powerstate) {
        //map() is used for PWM because otherwise off = x < 128 and on = x > 128
        analogWrite(Led::PIN_RED, Led::get_value(Color::get_red()));
        analogWrite(Led::PIN_GREEN, Led::get_value(Color::get_green()));
        analogWrite(Led::PIN_BLUE, Led::get_value(Color::get_blue()));
    } else {
        analogWrite(Led::PIN_RED, Led::max_value);
        analogWrite(Led::PIN_GREEN, Led::max_value);
        analogWrite(Led::PIN_BLUE, Led::max_value);
    }
}

private: static float get_value(float color_value) {
    float value = Led::max_value - map(color_value, Led::min_value,
        Led::max_value, Led::min_value, Led::max_value);
    return value;
}
};
uint8_t Led::max_value = Color::MAX_VALUE;
uint8_t Led::min_value = Color::MIN_VALUE;

} /* ArduinoRGB */
