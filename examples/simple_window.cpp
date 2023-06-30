/**
 * @file simple_window.cpp
 * @brief A simple window using milch!
 * @details
 * This file contains a simple window made using libmilch
 * hopefully this shows you the potential of using milch
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/realstealthninja)
 */

#include <unistd.h> /// for sleep
#include <milch.h> /// for window and show_window function

using namespace milch;

/**
 * @brief Main function
 * @returns 0 on success
 */
int main() {
    window win(400,200, "my window");
    win.show_window();
    sleep(200); // waiting long enough to see window
    return 0;
}