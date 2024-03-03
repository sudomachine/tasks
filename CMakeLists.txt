cmake_minimum_required(VERSION 3.14)

project(Tasks)

include_directories(headers)

add_executable(
    ${PROJECT_NAME}
    sources/main.cpp
    )