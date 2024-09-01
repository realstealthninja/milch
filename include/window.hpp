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
#include <string> /// For std::string
#include <iostream> /// For I/O operations
#include "color.hpp"  /// For color
#include "shapes.hpp" /// For shapes::point

typedef Window XWindow;

/**
 * @brief namespace containing all functions of milch
 * @namespace milch
 */
namespace milch {

    /**
     * @brief class contains functions relating to windows
     * @class window
     */
    class Window {

    private:
        Display *display = XOpenDisplay(nullptr); ///< display struct from XLib
        GC gc{}; ///< Graphics context of window / display
        XWindow win {}; ///< window struct from XLib

        Colormap color_map; ///< color map of the given display

    public:
        size_t width{}; ///< window width
        size_t height{}; ///< window height
        std::string title; ///< window's title



        /**
         * @brief base window constructor creates a window using XLib
         * @param width of the window
         * @param height of the window
         */
        Window(size_t width, size_t height);

        /**
         * @brief A simple constructor for easier development
         * @param width of the window
         * @param height of the window
         * @param title of the window
         */
        Window(size_t width,
               size_t height,
               const std::string &title,
               const milch::color &background_color = milch::color(255,255,255),
               const milch::color &foreground_color = milch::color(1,1,1));

        /**
         * @brief copy constructor of window
         */
        Window(Window &w);

        /**
         * @brief move constructor of window
         */
        Window(Window&& w) = default;

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
         * @brief Set the background colour of the window
         * @param hex_color color of the background in hex
         * @returns void
         */
        void set_foreground_color(const milch::color& color) const;

        /**
         * @brief Internal Error handler
         * @param d display causing the error
         * @param error XErrorEvent of the error
         * @return 0 and exit the program if an erorr occurs
         */
        static int error_handler(Display *d, XErrorEvent *error) {
            char* buf;
            XGetErrorText(d, error->error_code, buf, 256);

            std::cerr << "\033[1;31mERROR\033[0m XLIB " << buf << "\n";
            std::cerr.flush();
            return 0;
        }

        // Drawing section
        void draw_line(shapes::point a, shapes::point b, int width_of_line = 1) const;

        void draw_rectangle(shapes::point a, shapes::point b, int width_of_line = 1, bool fill = false) const;
        // end of drawing section

        void draw_circle(shapes::point center, float radius);

        /**
         * @brief draws everything to the screen
         * 
         */
        void draw();

        shapes::point get_mouse_position();

        /**
         * @breif conversion of window to display
         * @return XLib Display*
         */
        explicit operator Display *() const;

        /**
         * @breif conversion of window to Window
         * @return XLib Window
         */
        explicit operator XWindow() const;

        /**
         * @breif conversion of window to graphics context
         * @return XLib Graphics context
         */
        explicit operator GC() const;
        /**
         * @brief window deconstruction
         * @details
         * deletes all the pointers and alleviates memory
         */
        ~Window();
    };

} // namespace milch

#endif //MILCH_WINDOW_HPP
