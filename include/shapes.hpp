/**
 * @file shapes.hpp
 * @brief The header file containing the shapes and points
 *
 * @copyright This project is licensed under the MIT license
 * @author [stealthninja](https://github.com/stealthninja)
 */

namespace milch::shapes {
        class point {
        public:
            int x;
            int y;
            point(int x, int y): x(x), y(y) {};
            XPoint to_x_point() {
                return {static_cast<short>(this->x), static_cast<short>(this->y)};
            }
        };
    }