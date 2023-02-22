project(app)

# source code files
aux_source_directory(. app_src)

# executable target
add_executable(${PROJECT_NAME} ${app_src})

# find_package
find_package(fmt REQUIRED)

# library
target_link_libraries(${PROJECT_NAME} PUBLIC test)
target_link_libraries(${PROJECT_NAME} PUBLIC fmt::fmt)