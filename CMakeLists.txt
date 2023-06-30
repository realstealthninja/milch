cmake_minimum_required(VERSION 3.9)
project(milch VERSION 1.0.1 DESCRIPTION "a simple ui lib for c++")
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} SHARED milch.cpp milch.h)
add_executable(${PROJECT_NAME}_test EXCLUDE_FROM_ALL examples/simple_window.cpp)
target_link_libraries(${PROJECT_NAME}_test milch)
target_link_libraries(${PROJECT_NAME} "-lX11")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER milch.h)


install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )