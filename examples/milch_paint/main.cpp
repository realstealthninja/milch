/**
 * @file main.cpp
 * @brief A simple paint using milch!
 * @details
 * This file contains a simple paint application made using lib milch
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/realstealthninja)
 */


#include <unistd.h> /// for sleep
#include <milch/milch.h> /// for window and show_window function

using namespace milch;

/**
 * @brief Main function
 * @returns 0 on success
 */
int main() {
    milch::Window win(400,200, "my window");
    win.show_window();

    while(true) {
        shapes::point mos_pos = win.get_mouse_position();

        win.draw_rectangle(shapes::point(mos_pos.x-1, mos_pos.y-1), shapes::point(mos_pos.x+1, mos_pos.y+1), 1, true);
        win.draw();
    }

}