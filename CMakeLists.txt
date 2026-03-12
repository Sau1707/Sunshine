cmake_minimum_required(VERSION 3.20)

project(Sunshine VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_MODULE_PATH}/prep/options.cmake)
include(${CMAKE_MODULE_PATH}/prep/constants.cmake)
include(${CMAKE_MODULE_PATH}/prep/init.cmake)
include(${CMAKE_MODULE_PATH}/macros/common.cmake)
include(${CMAKE_MODULE_PATH}/dependencies/common.cmake)
include(${CMAKE_MODULE_PATH}/compile_definitions/common.cmake)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
