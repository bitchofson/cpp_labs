cmake_minimum_required(VERSION 3.28)

project(file_system)

set(
SOURCE_LIB 
sources/FileObject.cpp 
sources/File.cpp 
sources/Folder.cpp 
sources/Link.cpp
sources/SymbolicLink.cpp
sources/HardLink.cpp
)	

add_library(file_system STATIC ${SOURCE_LIB})