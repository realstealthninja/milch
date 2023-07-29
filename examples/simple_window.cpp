/**
 * @file simple_window.cpp
 * @brief A simple window using milch!
 * @details
 * This file contains a simple window made using lib milch
 * hopefully this shows you the potential of using milch
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/realstealthninja)
 */

#include <unistd.h> /// for sleep
#include <milch/milch.h> /// for window and show_window function

using milch::window;

/**
 * @brief Main function
 * @returns 0 on success
 */
int main() {
    window win(400,200, "my window");
    win.show_window();
    sleep(2);
    win.set_background_color(milch::color(255,192,192));
    sleep(5); // waiting long enough to see window
    return 0;
}