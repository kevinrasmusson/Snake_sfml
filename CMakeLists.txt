cmake_minimum_required(VERSION 3.25)
project(Snake)

set(CMAKE_CXX_STANDARD 17)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML 2.6 COMPONENTS graphics REQUIRED)

add_executable(Snake main.cpp Food.cpp Food.h Direction.h Snake.cpp Snake.h)

target_link_libraries(Snake sfml-graphics)
