cmake_minimum_required(VERSION 3.0)

project(test_eigen)

# compile options
add_compile_options(-O3)

# include files
include_directories(./include .include/test_eigen ./src)

# output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")

# target
add_executable(main ./src/main.cpp )

set_target_properties(main PROPERTIES LINK_FLAGS "-s ASSERTIONS=0 -O3 -s ALLOW_MEMORY_GROWTH=1 --bind")
# set_target_properties(main PROPERTIES LINK_FLAGS "-s DISABLE_EXCEPTION_CATCHING=0 -s ASSERTIONS=0 -O3 -s ALLOW_MEMORY_GROWTH=1 --bind")

# 3rd party libs
include_directories("./eigen")
set_target_properties(main PROPERTIES COMPILE_FLAGS "-s USE_BOOST_HEADERS=1" LINK_FLAGS "-s USE_BOOST_HEADERS=1")
