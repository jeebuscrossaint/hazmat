cmake_minimum_required(VERSION 3.30.5)
project(hazmat)

# Specify the Argon2 include and library directories manually
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(ARGON2_INCLUDE_DIR /usr/local/include)
set(ARGON2_LIBRARY /usr/lib/libargon2.so)  # or .a for static library
set(CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Add your source files
add_executable(hazmat
  src/main.cc
  src/setup.cc
  src/entry.cc
  src/crpyt.cc
)