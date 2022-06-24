
cmake_minimum_required(VERSION 3.10)

project(isvm VERSION 1.0 LANGUAGES C CXX)

if(WIN32)
    # Windows platforms (incl. Win64) not supported...yet
    message(FATAL_ERROR "Error: Windows platforms not supported.")
elseif(APPLE)
    # macOS, iOS, tvOS or watchOS platforms not supported
    message(FATAL_ERROR "Error: Apple platforms not supported.")
elseif(ANDROID)
    # android not supported
    message(FATAL_ERROR "Error: Android platform not supported.")
elseif(IOS)
    # IOS not supported
    message(FATAL_ERROR "Error: IOS platform not supported.")
endif()