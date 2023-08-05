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

#include "window.hpp"  /// For milch::function
#include <X11/Xlib.h> /// for XLib functions

/**
 * @brief namespace containing all functions of milch
 * @namespace milch
 */
namespace milch {
    window::window(unsigned int width, unsigned int height):
            width(width),
            height(height),
            title("my window"),
            win(XCreateWindow(
                    this->display,
                    DefaultRootWindow(this->display),
                    0, 0,
                    width, height,
                    0,
                    CopyFromParent,
                    CopyFromParent,
                    CopyFromParent,
                    0, nullptr
            )) {
        this->gc = XCreateGC(this->display, this->win, 0, nullptr);
        XStoreName(this->display, this->win, "my window");
        set_background_color(milch::color(255,255,225));
        XSetErrorHandler(error_handler);
    }
    window::window(unsigned int width,
                   unsigned int height,
                   const std::string& title,
                   const milch::color &background_color,
                   const milch::color &foreground_color): window(width, height) {
        set_background_color(background_color);
        set_foreground_color(foreground_color);
        XStoreName(this->display, this->win, title.c_str());
    }

    void window::show_window() const {
        if (!this->win) return;
        XMapWindow(this->display, this->win);
        XFlush(this->display);
    }

    window::~window() {
        if (!this->win) return;
        XFreeGC(this->display, this->gc);
        XDestroyWindow(this->display, this->win);
        XCloseDisplay(this->display);

    }

    void window::set_background_color(const milch::color& color) const {
        Colormap map = XDefaultColormap(this->display, 0);
        XColor clr = color.to_xlib_color();
        XAllocColor(this->display, map, &clr);
        XSetWindowBackground(this->display, this->win, clr.pixel);
        XClearWindow(this->display, this->win);
        XFlush(this->display);
    }

    void window::set_foreground_color(const color &color) const {
        Colormap map = XDefaultColormap(this->display, 0);
        XColor clr = color.to_xlib_color();
        XAllocColor(this->display, map, &clr);
        XSetForeground(this->display, this->gc, clr.pixel);
        XClearWindow(this->display, this->win);
        XFlush(this->display);
    }

    window::operator Window() const {
        return this->win;
    }

    window::operator GC() const {
        return this->gc;
    }

    window::operator Display*() const {
        return this->display;
    }

    window::window(window &w) {
        w.width = this->width;
        w.height = this->height;
        w.display = this->display;
        w.win = this->win;
        w.gc = this->gc;
        w.title = this->title;
    }
} // namespace milch