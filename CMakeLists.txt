cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0091 NEW)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(luajitlib-test)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/LuaJitLib)

add_executable(${PROJECT_NAME} "main.cpp")
add_dependencies(${PROJECT_NAME} luajit-5.1)
target_link_libraries(${PROJECT_NAME} luajit-5.1)
