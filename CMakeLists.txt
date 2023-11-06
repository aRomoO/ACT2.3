cmake_minimum_required(VERSION 3.13)  # CMake version check
project(act2_3)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES main.cpp
        MyBST.cpp
        MyBST.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(ac2_3 ${SOURCE_FILES} Dato.cpp LinkedList.cpp)