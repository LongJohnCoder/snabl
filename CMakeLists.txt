cmake_minimum_required(VERSION 3.0)

project(snabl)

set(CMAKE_CXX_COMPILER g++)

add_compile_options(-std=c++17 -Wall -Werror -g)

file(GLOB_RECURSE sources src/snabl/*.cpp)

add_library(libsnabl STATIC ${sources})
target_include_directories(libsnabl PUBLIC src/)

set_target_properties(libsnabl PROPERTIES PREFIX "")

add_executable(snabl ${sources} src/main.cpp)
target_include_directories(snabl PUBLIC src/)

file(GLOB headers src/snabel/*.hpp)
install(FILES ${headers} DESTINATION include/snabl)

install(FILES build/libsnabl.a DESTINATION lib)
install(FILES build/snabl DESTINATION bin)
