cmake_minimum_required(VERSION 3.15)
include(ExternalProject)
set(LUAJIT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/LuaJIT)
set(LUAJIT_DEST ${CMAKE_CURRENT_BINARY_DIR}/LuaJIT)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "LUAJIT_SRC = ${LUAJIT_SRC}")
message(STATUS "LUAJIT_DEST = ${LUAJIT_DEST}")

if(APPLE)
    set(DEPLOYMENT_TARGET "MACOSX_DEPLOYMENT_TARGET=${CMAKE_OSX_DEPLOYMENT_TARGET}")
    ExternalProject_Add(
        luajitlib
        BUILD_IN_SOURCE 1
        SOURCE_DIR ${LUAJIT_SRC}
        CONFIGURE_COMMAND ${CMAKE_MAKE_PROGRAM} clean
        BUILD_COMMAND ${CMAKE_MAKE_PROGRAM} CC=${DEPLOYMENT_TARGET} amalg
        INSTALL_COMMAND ""
    )
    set(LUAJIT_LIBRARY "libluajit.dylib")
    #set(LUAJIT_LIBRARY "libluajit.a")

elseif(UNIX)
    ExternalProject_Add(
        luajitlib
        BUILD_IN_SOURCE 1
        SOURCE_DIR ${LUAJIT_SRC}
        CONFIGURE_COMMAND ${CMAKE_MAKE_PROGRAM} clean
        BUILD_COMMAND ${CMAKE_MAKE_PROGRAM} amalg
        INSTALL_COMMAND ""
    )
    set(LUAJIT_LIBRARY "libluajit.a")

elseif(MINGW)
    set(LUAJIT_BUILDCOMMAND "mingw32-make")
    ExternalProject_Add(
        luajitlib
        BUILD_IN_SOURCE 1
        SOURCE_DIR ${LUAJIT_SRC}/src
        CONFIGURE_COMMAND ${LUAJIT_BUILDCOMMAND} clean
        BUILD_COMMAND ${LUAJIT_BUILDCOMMAND}
        INSTALL_COMMAND ""
    )
    set(LUAJIT_LIBRARY "libluajit-5.1.dll.a")

elseif(MSVC)
    ExternalProject_Add(
        luajitlib
        BUILD_IN_SOURCE 1
        SOURCE_DIR ${LUAJIT_SRC}
        #CONFIGURE_COMMAND ${CMAKE_MAKE_PROGRAM} clean
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ${CMAKE_COMMAND} -E chdir ${LUAJIT_SRC}/src/ ${LUAJIT_SRC}/src/msvcbuild.bat
        INSTALL_COMMAND ""
    )
    set(LUAJIT_LIBRARY "lua51.lib")
    
else()
    message(FATAL_ERROR "Failed to build LuaJIT, unsupported build environment ${CMAKE_SYSTEM_NAME}/${CMAKE_C_COMPILER_ID}")
endif()

add_library(luajit STATIC IMPORTED GLOBAL)
set_property(TARGET luajit PROPERTY IMPORTED_LOCATION ${LUAJIT_SRC}/src/${LUAJIT_LIBRARY})
add_dependencies(luajit luajitlib)
include_directories(${LUAJIT_SRC}/src)
