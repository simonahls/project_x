cmake_minimum_required(VERSION 3.10)
project(fileio)


include_directories(lib/include)

set(SourcesLib lib/src/file_io.cpp)
set(SourcesApp app/src/main.cpp)


add_library(file_io_lib ${SourcesLib})

add_executable(fileio ${SourcesApp})

target_link_libraries(fileio file_io_lib)


#Google Test
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.0
)

FetchContent_MakeAvailable(googletest)

add_executable(lib_ut_tests lib/ut/tests.cpp lib/ut/lib_ut_tests.cpp)
target_link_libraries(lib_ut_tests gtest gtest_main file_io_lib)