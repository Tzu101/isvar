cmake_minimum_required(VERSION 3.13.0)

# Settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME ris)

# Project
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Include
target_include_directories(${PROJECT_NAME} INTERFACE include)
