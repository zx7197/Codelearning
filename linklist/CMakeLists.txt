cmake_minimum_required(VERSION 3.3)

# set the project name
project(linkrevert VERSION 1.0)
configure_file(linkrevert.h.in linkrevert.h)
SET(SRC_LIST linkrevert.c)

# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})
# add the MathFunctions library ,放在add_executable 后，否则编译不过去
add_subdirectory(MathFunctions)
target_link_libraries(${PROJECT_NAME} PUBLIC MathFunctions)
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
						   ${PROJECT_SOURCE_DIR}/MathFunctions
                           )