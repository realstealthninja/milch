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


#include <X11/Xlib.h> /// for XLib functions
#include <cstdint>
#include "window.hpp"  /// For milch::function
#include "color.hpp"
#include "shapes.hpp"

/**
 * @brief namespace containing all functions of milch
 * @namespace milch
 */
namespace milch {
    Window::Window(size_t width, size_t height):
            width(width),
            height(height),
            title("my Window"),
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
        this->color_map = XDefaultColormap(this->display, 0);

        XStoreName(this->display, this->win, "my Window");
        set_background_color(milch::color(255,255,225));
        XSetErrorHandler(error_handler);
    }
    Window::Window(size_t width,
                   size_t height,
                   const std::string& title,
                   const milch::color &background_color,
                   const milch::color &foreground_color): Window(width, height) {
        set_background_color(background_color);
        set_foreground_color(foreground_color);
        XStoreName(this->display, this->win, title.c_str());


    }

    void Window::show_window() const {
        if (!this->win) return;
        XMapWindow(this->display, this->win);
        XFlush(this->display);
    }

    Window::~Window() {
        if (!this->win) return;
        XFreeGC(this->display, this->gc);
        XDestroyWindow(this->display, this->win);
        XCloseDisplay(this->display);

    }

    void Window::set_background_color(const milch::color& color) const {
        XColor clr = color.to_xlib_color();

        XAllocColor(this->display, this->color_map, &clr);
        XSetWindowBackground(this->display, this->win, clr.pixel);
        XClearWindow(this->display, this->win);
    }

    void Window::set_foreground_color(const color &color) const {
        XColor clr = color.to_xlib_color();

        XAllocColor(this->display, this->color_map, &clr);
        XSetForeground(this->display, this->gc, clr.pixel);
        XClearWindow(this->display, this->win);
    }

    void Window::draw() {
        XFlush(this->display);
    }

    shapes::point Window::get_mouse_position() {
        int x, y, root_x, root_y = 0;
        uint32_t mask = 0;
        XWindow root_win, child_win;

        XQueryPointer(this->display, this->win, &root_win, &child_win, &root_x, &root_y, &x, &y, &mask);
        return shapes::point(x, y);
    }

    Window::operator XWindow() const {
        return this->win;
    }

    Window::operator GC() const {
        return this->gc;
    }

    Window::operator Display*() const {
        return this->display;
    }

    Window::Window(Window &w) {
        w.width = this->width;
        w.height = this->height;
        w.display = this->display;
        w.win = this->win;
        w.gc = this->gc;
        w.title = this->title;
    }

    void Window::draw_line(shapes::point a, shapes::point b, int width_of_line) const {
        XGCValues values;
        values.line_width = width_of_line;
        XChangeGC(this->display, this->gc, GCLineWidth, &values);
        XDrawLine(this->display, this->win, this->gc, a.x + width_of_line, a.y + width_of_line, b.x + width_of_line,
                  b.y + width_of_line);
    }

    void Window::draw_rectangle(shapes::point a, shapes::point b, int width_of_line, bool filled) const {
        XGCValues values;
        values.line_width = width_of_line;
        XChangeGC(this->display, this->gc, GCLineWidth, &values);
        

        if (filled) {
            XFillRectangle(this->display, this->win, this->gc, a.x, a.y, b.x-a.x, b.y-a.y);
        } else {
            XDrawRectangle(this->display, this->win, this->gc, a.x, a.y, b.x-a.x, b.y-a.y);
        }
    }
} // namespace milch
