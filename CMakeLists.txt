cmake_minimum_required(VERSION 3.6.0)
project(microgl VERSION 0.0.1 LANGUAGES C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mavx")

file(GLOB sources 
    "main.c"
    "src/*.c"

    "src/microgl/*.c"

    "src/math/*.c"
    "src/math/*/*.c"
)

set(includes 
    "include/"
)

add_executable(${PROJECT_NAME} ${sources})

include_directories(${includes})
target_link_libraries(${PROJECT_NAME} ncurses m)
