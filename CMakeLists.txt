cmake_minimum_required(VERSION 3.8.0)

# just an echo
message("*** project test-apache-arrow ***")
project(test-apache-arrow LANGUAGES CXX)

# extend module path
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules ${CMAKE_MODULE_PATH})


find_package(Arrow)
if (NOT ARROW_FOUND)
    message("*** ERROR: no Apache Arrow Found ***")
else()
    message("*** Apache Arrow is all good ***")
    message("ARROW_INCLUDE_DIR = ${ARROW_INCLUDE_DIR}")
    message("ARROW_LIBS = ${ARROW_LIBS}")
    message("ARROW_SHARED_LIB = ${ARROW_SHARED_LIB}")
    include_directories(${ARROW_INCLUDE_DIR})
endif()

# simple tests
add_subdirectory(simple_tests)
