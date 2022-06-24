
cmake_minimum_required(VERSION 3.10)

project(isvm VERSION 1.0 LANGUAGES C CXX)

if(MSVC)
    # Microsoft Visual C++ compilers not supported...yet.
    message(FATAL_ERROR "Error: MSVC not supported.")
elseif(APPLE)
    # macOS, iOS, tvOS or watchOS platform not supported.
    message(FATAL_ERROR "Error: Apple platforms not supported.")
else()
    # allow the compiler to raise all possible warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()