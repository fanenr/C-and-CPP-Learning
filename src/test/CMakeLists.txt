project(test)

# source files
aux_source_directory(. test_src)

# shared library
add_library(${PROJECT_NAME} SHARED ${test_src})

# includes
target_include_directories(${PROJECT_NAME} PUBLIC ..)