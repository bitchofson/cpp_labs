cmake_minimum_required(VERSION 3.28)

project(bool_vec)

set(SOURCE_LIB sources/bool_vector.cpp)	

add_library(bool_vec STATIC ${SOURCE_LIB})