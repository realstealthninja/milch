/**
 * @file color.hpp
 * @brief The header file containing the color class
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/stealthninja)
 */

#ifndef MILCH_COLOR_HPP
#define MILCH_COLOR_HPP

#include <string>
#include <format>
#include <cstring>
#include <sstream>
#include <utility>

namespace milch {

    class color {
    public:
        unsigned int red{};
        unsigned int green{};
        unsigned int blue{};
        std::string hexCode;

        color(unsigned int r, unsigned int g, unsigned int b): red(r), green(g), blue(b){};
        explicit color(std::string hexadecimal): hexCode(std::move(hexadecimal)){};
        std::string to_hexadecimal();
        [[nodiscard]] unsigned long to_xlib_color() const;
    };

} // milch

#endif //MILCH_COLOR_HPP
