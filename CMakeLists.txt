cmake_minimum_required(VERSION 3.13.0)

# Settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME ris)

# Project
project(${PROJECT_NAME})
add_library(${PROJECT_NAME} INTERFACE)

# Files
target_include_directories(${PROJECT_NAME} INTERFACE src)
target_sources(${PROJECT_NAME} INTERFACE
    src/ris/ris.h
)

# Configure
if(RIS_VERBOSE_NAMING) # usage set(RIS_VERBOSE_NAMING ON/OFF)
    target_compile_definitions(${PROJECT_NAME} INTERFACE RIS_VERBOSE_NAMING)
endif()

# Playground (only build if this is the main project)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(playground playground/main.cpp)
    target_link_libraries(playground PRIVATE ${PROJECT_NAME} ${PROJECT_NAME})
endif()
