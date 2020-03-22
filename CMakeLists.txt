cmake_minimum_required(VERSION 3.0)
project(emoji-keyboard)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

cmake_policy(SET CMP0020 NEW)
cmake_policy(SET CMP0043 NEW)
if(${CMAKE_VERSION} VERSION_GREATER "3.10.0")
    cmake_policy(SET CMP0071 NEW)
endif()
if(${CMAKE_VERSION} VERSION_GREATER "3.13.0")
    cmake_policy(SET CMP0079 NEW)
endif()

find_package(Qt5 REQUIRED COMPONENTS Widgets Test)

add_executable(${PROJECT_NAME} main.cpp)
qt5_use_modules(${PROJECT_NAME} Widgets)
