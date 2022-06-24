
cmake_minimum_required(VERSION 3.10)

project(isvm VERSION 1.0 LANGUAGES C CXX)

if(WIN32)
    # Windows platform (incl. Win64) not supported...yet
    message(FATAL_ERROR "Error: Windows platform not supported.")
elseif(APPLE)
    # macOS, iOS, tvOS or watchOS platforms not supported
    message(FATAL_ERROR "Error: Apple platform not supported.")
endif()