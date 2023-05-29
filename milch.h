/**
 * @file
 * @brief Header file containing all functions needed for milch
 * @details
 * This is the main header of milch, And as such contains all functions
 * related to and needed by milch
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/realstealthninja)
 */
#ifndef MILCH_LIBRARY_H
#define MILCH_LIBRARY_H

#include <X11/Xlib.h> // For XLib functions

/**
 * @brief namespace containing all functions of milch
 * @namespace milch
 */
namespace milch {
    /**
     * @brief window class contains functions relating to windows
     */
    class window {
    public:
        unsigned int width; /// window width
        unsigned int height; /// window height

        Display *display = XOpenDisplay(nullptr); /// display struct from XLib
        Window win{}; /// window struct from XLib

        /**
         * @brief window constructor creates a window using XLib
         *
         * @param width
         * @param height
         */
        window(
                unsigned int width,
                unsigned int height);

        /**
         *  @brief Makes the window visible
         *  @returns void
         */
        void show_window() const;

        /**
         * @brief window deconstruction
         * @details
         * deletes all the pointers and alleviates memory
         */
        ~window();
    };
} // namespace milch

#endif //MILCH_LIBRARY_H
