cmake_minimum_required(VERSION 3.22)

project(lab_hashing VERSION 0.0.1 LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt stuff

# To include Qt auto generated files
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

# qt stuff end

# Add all parts of project
add_subdirectory(hashing)
add_subdirectory(form)
add_subdirectory(main)
