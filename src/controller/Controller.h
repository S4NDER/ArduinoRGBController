#pragma once

#include "../led/Led.h"
#include "Arduino.h"

namespace ArduinoRGB {

class Controller {

private:
    static bool powerstate;

public: static void toggle_power() {
    Controller::powerstate = !powerstate;
}

public: static bool get_power_state() {
    return Controller::powerstate;
}

public: static void set_led() {
    Led::set_color(Controller::powerstate);
}
};
bool Controller::powerstate = false;
} /* ArduinoRGB */
