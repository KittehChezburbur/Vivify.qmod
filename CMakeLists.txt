cmake_minimum_required(VERSION 3.21.0)
project(AutoplayMod)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/AutoplayMod.cpp
)

add_library(AutoplayMod SHARED ${SOURCES})

set_target_properties(AutoplayMod PROPERTIES
    PREFIX "lib"
    SUFFIX ".so"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs"
)
