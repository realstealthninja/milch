cmake_minimum_required(VERSION 3.28)

project(simple_window)

find_library(milch NAMES milch libmilch
            HINTS "../../build/")

add_executable(${PROJECT_NAME} simple_window.cpp)


target_link_libraries(${PROJECT_NAME} milch)
