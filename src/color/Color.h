#pragma once

namespace ArduinoRGB {

class Color {
private:
    static float red;
    static float green;
    static float blue;

public:
    static const uint8_t MAX_VALUE;// = 255;
    static const uint8_t MIN_VALUE;// = 0;

private: static float validate_value(float value) {
    if (value > Color::MAX_VALUE) {
        value = Color::MAX_VALUE;
    } else if (value < Color::MIN_VALUE) {
        value = Color::MIN_VALUE;
    }
    return value;
}

public: static void set_red(float red) {
    Color::red = Color::validate_value(red);
}

public: static void set_green(float green) {
    Color::green = Color::validate_value(green);
}

public: static void set_blue(float blue) {
    Color::blue = Color::validate_value(blue);
}

public: static void set_color(float red, float green, float blue) {
    Color::set_red(red);
    Color::set_green(green);
    Color::set_blue(blue);
}

public: static float get_red() {
    return Color::red;
}

public: static float get_green() {
    return Color::green;
}

public: static float get_blue() {
    return Color::blue;
}
};

float Color::red = 0;
float Color::green = 0;
float Color::blue = 0;

const uint8_t Color::MAX_VALUE = 255;
const uint8_t Color::MIN_VALUE = 0;
} /* ArduinoRGB */
