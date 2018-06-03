#include "src/controller/Controller.h"
#include "src/color/Color.h"

#define BAUDRATE 9600
#define PIN_RED 3
#define PIN_GREEN 5
#define PIN_BLUE 6

using namespace ArduinoRGB;

void setup()
{
    configure_led_pins();
    Serial.begin(BAUDRATE);
    Controller::toggle_power();

    // Setup the "threads"

}

void configure_led_pins()
{
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
}

void loop()
{
    //Color::set_color(255,0,0);
    //Controller::set_led();
    Color::set_color(0,0,255);
    Controller::set_led();
    /*
    Color::set_color(255,0,0);
    Controller::set_led();
    Color::set_color(255,0,0);
    Controller::set_led();
    */
}
