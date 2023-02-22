cmake_minimum_required(VERSION 3.15)

# project name
project(Cpp_Learning)

# cpp standard
set(CMAKE_CXX_STANDARD 20)

# output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# with conan
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

# subdirectory
add_subdirectory(src)