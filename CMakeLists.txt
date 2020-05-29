cmake_minimum_required(VERSION 3.15)
project(cppProject)
FIND_PACKAGE(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS " version: ${OpenCV_VERSION}")
message(STATUS " libraries: ${OpenCV_LIBS}")
message(STATUS " include path: ${OpenCV_INCLUDE_DIRS}")
set(googleTestDir ./googletest)

#Add the google test subdirectory
add_subdirectory(${googleTestDir})
#include googletest/include dir
include_directories(${googleTestDir}/googletest/include)
#include the googlemock/include dir
include_directories(${googleTestDir}/googlemock/include)

include_directories(
        ${PROJECT_SOURCE_DIR}
        "/usr/include/opencv2"
)
set(CMAKE_CXX_STANDARD 14)

add_executable(cppProject main.cpp Matrix.hpp Vector.hpp)
target_link_libraries(cppProject ${OpenCV_LIBS})
target_link_libraries(cppProject gtest gtest_main)
target_link_libraries(cppProject gmock gmock_main)

message("Building with lcov Code Coverage Tools")
set(CMAKE_CXX_FLAGS "--coverage")