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

#include <chrono>
#include <random>
#include <milch/milch.h> /// for window and show_window function
#include <thread>

using namespace milch;

/**
 * @brief Main function
 * @returns 0 on success
 */
int main() {
    milch::Window win(1280,800, "my window");
    win.show_window();
    win.set_background_color(milch::color(255,192,192));


    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);


    int length = 25;
    while(true){
        float random_value = dist(mt);
        float rand_2value = dist(mt);
        float random_length = dist(mt);
        int random_x = std::ceil(random_value * 1280.0f);
        int random_y = std::ceil(rand_2value * 800.0f);
        int random_depth = std::ceil(random_length * length);

        win.draw_rectangle(shapes::point(random_x, random_y), shapes::point(random_x+random_depth, random_y+random_depth));
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        win.draw();
    }
}