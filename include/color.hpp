/**
 * @file color.hpp
 * @brief The header file containing the color class
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/stealthninja)
 */

#ifndef MILCH_COLOR_HPP
#define MILCH_COLOR_HPP

#include <string>  /// For std::string
#include <cstring> /// For Cstring
#include <X11/Xlib.h> /// For XColor

/**
 * @brief namespace containing all functions of milch
 * @namespace milch
 */
namespace milch {

    /**
     * @brief Color class
     * @class color
     */
    class color {
    public:
        unsigned int red{}; ///< value of red
        unsigned int green{}; ///< value of green
        unsigned int blue{}; ///< value of blue
        std::string hexCode; ///< color in hexcode

        /**
         * @brief Color constructor
         * @param r value of red between 0-255
         * @param g value of green between 0-255
         * @param b value of blue between 0-255
         */
        color(
                unsigned int r,
                unsigned int g,
                unsigned int b
                ): red(r), green(g), blue(b){};

        /**
         * @brief color constructor with hexadecimal
         * @param hexadecimal value of color
         */
        explicit color(std::string hexadecimal): hexCode(std::move(hexadecimal)){};

        /**
         * @brief convert rgb to hexadecimal
         * @return string of hexadecimal in the format #rrggbb
         */
        std::string to_hexadecimal();

        /**
         * @brief convert color to the xlib equivalent
         * @details Neat trick used here
         * after fiddling around a lot i figured out
         * ((x/255*100)/100)*65535 this was the equation to find the
         * value from rgb to xlib colour.
         * managed to reduce it down to 257*x
         * meaning the 0-255 value times 257 is the value in xlib colour
         * @return XColor of the color
         */
        [[nodiscard]] XColor to_xlib_color() const;
    };

} // namespace milch

#endif //MILCH_COLOR_HPP
