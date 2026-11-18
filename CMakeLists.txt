cmake_minimum_required(VERSION 3.20)
project(clubhub LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(clubhub_core
    src/Student.cpp
    src/ConsoleOutput.cpp
)
target_include_directories(clubhub_core PUBLIC include)

add_executable(student_privacy_test
    tests/StudentPrivacyTest.cpp
    tests/ConsoleOutputTest.cpp
)
target_link_libraries(student_privacy_test PRIVATE clubhub_core gtest_main)

include(GoogleTest)
gtest_discover_tests(student_privacy_test)
