cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (CMPE-202-Final-Project
	VERSION 0.1
	DESCRIPTION "A Hello World Project")
	
# Set C++ standard explicitly to C++11 or higher
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# This project will output an executable file
add_executable(${PROJECT_NAME} CMPE-202-Final-Project.cpp MenuItem.cpp Enums.cpp MenuItemAdapter.cpp)

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

