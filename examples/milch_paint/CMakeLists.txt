cmake_minimum_required(VERSION 3.28)

project(milch_paint)

find_library(milch NAMES milch libmilch
            HINTS "../../build/")

add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} milch)
