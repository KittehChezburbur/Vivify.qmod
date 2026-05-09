cmake_minimum_required(VERSION 3.21.0)
project(vivify)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(extern/beatsaber-hook/include)
include_directories(extern/beatsaber-hook/src)

set(SOURCES
    src/main.cpp
    src/vivify.cpp
)

add_library(vivify SHARED ${SOURCES})

target_link_libraries(vivify PUBLIC
    beatsaber-hook
)

set_target_properties(vivify PROPERTIES
    PREFIX ""
    SUFFIX ".so"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs"
)
