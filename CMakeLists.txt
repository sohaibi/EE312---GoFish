cmake_minimum_required(VERSION 3.13)
project(SixthLab)

set(CMAKE_CXX_STANDARD 11)

add_executable(SixthLab card.h card_demo.cpp player.h deck.h card.cpp player.cpp deck.cpp)