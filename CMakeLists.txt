cmake_minimum_required(VERSION 3.16)
project(doubly_linked_list C)
file(GLOB SOURCES *.c)
add_executable(doubly_linked_list ${SOURCES})
