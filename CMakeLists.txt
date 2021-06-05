cmake_minimum_required(VERSION 3.5)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

set(PROJECT minesweeper)
set(SRC main.c Model/case.c Model/terrain.c View/view.c Controler/jeu.c)
set(HEADER Model/case.h Model/terrain.h View/view.h Controler/jeu.h)

project(${PROJECT})

add_executable(minesweeper ${SRC} ${HEADER})

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

target_link_libraries(${PROJECT} SDL2::Main SDL2::TTF)