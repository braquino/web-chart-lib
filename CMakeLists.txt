cmake_minimum_required(VERSION 3.14)
project(corvo_svg_charts)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE)

include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

set(SRCS
  src/corvo_xml.cpp
  src/corvo_svg.cpp
  src/corvo_chart.cpp
)

include_directories(include)

add_library(corvo_svg_charts ${SRCS})

set(TEST_SRCS
  tests/test_corvo_xml.cpp
  tests/test_corvo_svg.cpp
  tests/test_corvo_chart.cpp
  tests/test_corvo_utils.cpp
)

enable_testing()
add_executable(corvo_tests ${TEST_SRCS} ${SRCS})
target_link_libraries(corvo_tests gtest_main)
gtest_discover_tests(corvo_tests)