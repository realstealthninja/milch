cmake_minimum_required(VERSION 3.9)
project(milch VERSION 1.0.1 DESCRIPTION "a simple gui lib for c++")
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)


add_library(${PROJECT_NAME} SHARED
        src/window.cpp
        src/color.cpp
)

include_directories(${PROJECT_NAME} include/)

target_link_libraries(${PROJECT_NAME} "-lX11")

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/milch/milch.h)


install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

option(MILCH_BUILD_EXAMPLES "Build milch examples." OFF)

if(MILCH_BUILD_EXAMPLES)
        add_subdirectory(examples/)
endif()