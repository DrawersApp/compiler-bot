cmake_minimum_required(VERSION 3.3)
project(echo_bot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -lgloox -lpthread -lrestclient-cpp -lcurl")

set(SOURCE_FILES
    src/bot.cpp
    src/bot.h
    src/connListener.cpp
    src/connListener.h
    src/jsonExtension.cpp
    src/jsonExtension.h
    src/main.cpp
        src/builder.h
        src/compileTask.h
        src/compileTask.cpp
        src/cloudinary.cpp
        src/cloudinary.h
        src/param.cpp src/param.h
        src/builder.cpp
        src/BotStringElement.cpp src/BotStringElement.h
        src/BotStringType.cpp src/BotStringType.h
        src/DrawersBotString.cpp src/DrawersBotString.h
        src/OutputBody.h
        src/CompileOutput.cpp src/CompileOutput.h)

include_directories(include src)

add_executable(compiler_bot ${SOURCE_FILES})