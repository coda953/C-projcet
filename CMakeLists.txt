cmake_minimum_required(VERSION 3.15)
project(cppProject)
FIND_PACKAGE(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS " version: ${OpenCV_VERSION}")
message(STATUS " libraries: ${OpenCV_LIBS}")
message(STATUS " include path: ${OpenCV_INCLUDE_DIRS}")
include_directories(
        ${PROJECT_SOURCE_DIR}
        "/usr/include/opencv2"
)
set(CMAKE_CXX_STANDARD 14)

add_executable(cppProject main.cpp Matrix.cpp Matrix.hpp Vector.hpp Vector.cpp)
target_link_libraries(cppProject ${OpenCV_LIBS})