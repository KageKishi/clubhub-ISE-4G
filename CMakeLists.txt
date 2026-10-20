cmake_minimum_required(VERSION 3.20)

project(clubhub VERSION 0.1.0 LANGUAGES CXX)

add_library(clubhub_core
    src/banner.cpp
)

target_include_directories(clubhub_core
    PUBLIC include
)

target_compile_features(clubhub_core PUBLIC cxx_std_20)
set_target_properties(clubhub_core PROPERTIES CXX_EXTENSIONS OFF)

target_compile_definitions(clubhub_core
    PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}"
)

add_executable(clubhub
    src/main.cpp
)

target_link_libraries(clubhub PRIVATE clubhub_core)

if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
    target_compile_options(clubhub PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(clubhub PRIVATE -Wall -Wextra -Wpedantic)
endif()