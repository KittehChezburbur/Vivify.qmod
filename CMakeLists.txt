cmake_minimum_required(VERSION 3.10)
project(AutoplayMod)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add the library
add_library(AutoplayMod SHARED
    src/AutoplayMod.cpp
)

# Link required libraries
target_link_libraries(AutoplayMod PUBLIC
    beatsaber-hook
    modloader
)

# Output directory
set_target_properties(AutoplayMod PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
