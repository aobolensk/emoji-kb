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

file(DOWNLOAD https://unicode.org/Public/emoji/13.0/emoji-test.txt ${CMAKE_SOURCE_DIR}/resources/emoji-test.txt)
qt5_add_resources(RC_SRC ${CMAKE_SOURCE_DIR}/resources/resources.qrc)

include_directories(include)
add_executable(${PROJECT_NAME}
    src/emoji.cpp
    src/emojikeyboard.cpp
    src/emojireader.cpp
    src/main.cpp
    ${RC_SRC}
)
qt5_use_modules(${PROJECT_NAME} Widgets)


set(CMAKE_CXX_STANDARD 17)
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX /wd4127 /O2")
    # disabled warning C4127: conditional expression is constant
else(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Werror -pedantic -Wconversion")
endif(MSVC)
