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

using namespace milch;

/**
 * @brief Main function
 * @returns 0 on success
 */
int main() {
    milch::Window win(400,200, "my window");
    win.show_window();
    sleep(2);
    win.set_background_color(milch::color(255,192,192));
    int i = 0;
    while(true){

        win.draw_rectangle(shapes::point(20+i, 30+i), shapes::point(40+i, 50+i));
        win.draw_line(shapes::point(20, 30), shapes::point(60, 70));

        sleep(1);
        i+=3;
    }
}