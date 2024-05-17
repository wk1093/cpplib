cmake_minimum_required(VERSION 3.27)
project(cpplib)

set(CMAKE_CXX_STANDARD 17)

add_library(cpplib src/main.cpp
        src/cpplib/str.hpp
        src/cpplib/vec.hpp
        src/cpplib/debug.hpp
        src/cpplib/map.hpp)

target_include_directories(cpplib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# fetchcontent
include(FetchContent)
FetchContent_Declare(
        docgen
        GIT_REPOSITORY https://github.com/wk1093/docgen.git
        GIT_TAG main
)
FetchContent_MakeAvailable(docgen)

# add custom target to run docgen
add_custom_target(cpplib_docs
        COMMAND docgen ${CMAKE_CURRENT_SOURCE_DIR}/src/cpplib
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating documentation"
        VERBATIM
        )