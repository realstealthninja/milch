/**
 * @file color.cpp
 * @brief The source file containing the color class
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/stealthninja)
 */

#include "color.hpp" /// for defining functions in color.hpp

namespace milch {
    std::string color::to_hexadecimal() {
        if (!hexCode.empty()) {
            return hexCode;
        }
        std::stringstream string_stream;
        string_stream << "#" << std::hex << this->red << std::hex << this->blue << this->green;
        hexCode = string_stream.str();
        return hexCode;
    }

    XColor color::to_xlib_color() const {
        XColor clr;
        clr.blue = 257*this->blue;
        clr.red = 257*this->red;
        clr.green= 257*this->green;
        return clr;
    }
} // namespace milch