cmake_minimum_required(VERSION 3.13)
project(reverse_s CXX)

find_package(HPX REQUIRED)
add_executable(reverse_s reverse_s.cpp)
target_link_libraries(reverse_s HPX::hpx HPX::wrap_main)

