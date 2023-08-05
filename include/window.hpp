/**
 * @file milch.h
 * @brief Header file containing all functions needed for milch
 * @details
 * This is the main header of milch, And as such contains all functions
 * related to and needed by milch
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/realstealthninja)
 */
#ifndef MILCH_WINDOW_HPP
#define MILCH_WINDOW_HPP

#include <X11/Xlib.h> /// For XLib functions
#include <string> /// for std::string
#include <iostream> /// for I/O operations
#include "color.hpp"  /// for color

/**
 * @brief namespace containing all functions of milch
 * @namespace milch
 */
namespace milch {

    /**
     * @brief class contains functions relating to windows
     * @class window
     */
    class window {
    public:
        unsigned int width{}; ///< window width
        unsigned int height{}; ///< window height
        std::string title; ///< window's title

        Display *display = XOpenDisplay(nullptr); ///< display struct from XLib
        GC gc{}; ///< Graphics context of window / display
        Window win {}; ///< window struct from XLib

        /**
         * @brief window constructor creates a window using XLib
         *
         * @param width of the window
         * @param height of the window
         */
        window(unsigned int width, unsigned int height);

        /**
         * @brief A more expansive constructor for easier development
         * @param width of the window
         * @param height of the window
         * @param title of the window
         */
        window(unsigned int width,
               unsigned int height,
               const std::string &title);

        /**
         * @brief Makes the window visible
         * @returns void
         */
        void show_window() const;

        /**
         * @brief Set the background colour of the window
         * @param hex_color color of the background in hex
         * @returns void
         */
        void set_background_color(const milch::color& color) const;

        /**
         * @brief Internal Error handler
         * @param d display causing the error
         * @param error XErrorEvent of the error
         * @return 0 if the error handling was successful
         */
        static int error_handler(Display* d,XErrorEvent* error) {
            std::cerr << "ERROR: "<< error->error_code << "\n";
            return 0;
        }

        /**
         * @brief window deconstruction
         * @details
         * deletes all the pointers and alleviates memory
         */
        ~window();
    };

} // namespace milch

#endif //MILCH_WINDOW_HPP
