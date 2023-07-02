/**
 * @file color.cpp
 * @brief The source file containing the color class
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/stealthninja)
 */

#include "color.hpp"

namespace milch {
    std::string color::to_hexadecimal() {
        if (!hexCode.empty()) {
            return hexCode;
        }
        std::stringstream string_stream;
        string_stream << std::hex << red << std::hex << green << std::hex << blue;
        hexCode = string_stream.str();
        return hexCode;
    }
} // milch