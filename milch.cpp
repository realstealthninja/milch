/**
 * @file
 * @brief Header file containing all functions needed for milch
 *
 * @details
 * This is the main source of milch, And as such contains definitions to all functions
 * related to and needed by milch
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/realstealthninja)
 */

#include "milch.h" /// For milch::function
#include <X11/Xlib.h> /// for XLib functions

/**
 * @brief namespace containing all functions of milch
 * @namespace milch
 */
namespace milch {
    window::window(unsigned int width, unsigned int height) {
        this->width = width;
        this->height = height;
        this->win = XCreateWindow(this->display,
                                  DefaultRootWindow(this->display),
                                  0, 0, // Int x, y
                                  width, height,
                                  0, // border width
                                  CopyFromParent, // depth
                                  CopyFromParent,
                                  CopyFromParent,
                                  0,
                                  nullptr
        );
        XStoreName(this->display, this->win, "my window");
    }

    window::window(unsigned int width, unsigned int height, const std::string& title): window(width, height) {
        XStoreName(this->display, this->win, title.c_str());
    }

    void window::show_window() const {
        if (!this->win) return;
        XMapWindow(this->display, this->win);
        XFlush(this->display);
    }

    window::~window() {
        if (!this->win) return;
        XDestroyWindow(this->display, this->win);
        XCloseDisplay(this->display);

    }


} // namespace milch