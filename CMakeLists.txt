cmake_minimum_required(VERSION 3.21.0)
project(AutoplayMod)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(extern/beatsaber-hook/include)
include_directories(extern/beatsaber-hook/src)

set(SOURCES
    src/AutoplayMod.cpp
)

add_library(AutoplayMod SHARED ${SOURCES})

target_link_libraries(AutoplayMod PUBLIC
    beatsaber-hook
)

set_target_properties(AutoplayMod PROPERTIES
    PREFIX "lib"
    SUFFIX ".so"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs"
)
