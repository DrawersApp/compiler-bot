cmake_minimum_required(VERSION 3.3)
project(echo_bot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -lgloox -lpthread")

set(SOURCE_FILES
    src/bot.cpp
    src/bot.h
    src/connListener.cpp
    src/connListener.h
    src/jsonExtension.cpp
    src/jsonExtension.h
    src/main.cpp)

include_directories(src)

add_executable(echo_bot ${SOURCE_FILES})