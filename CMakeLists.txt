# CMake version
cmake_minimum_required(VERSION 3.0)

set(myproject "IEP")
# Project name
project(${myproject})

# Define the executable    
include_directories(src)
add_executable(${PROJECT_NAME} src/main.cpp)  
