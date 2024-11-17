cmake_minimum_required(VERSION 3.30.5)
project(hazmat)

# Specify the Argon2 include and library directories manually
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(ARGON2_INCLUDE_DIR /usr/local/include)
set(ARGON2_LIBRARY /usr/lib/libargon2.so)  # or .a for static library
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Copy compile_commands.json to the project root after generation
if (EXISTS ${CMAKE_BINARY_DIR}/compile_commands.json)
    add_custom_target(copy_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
        DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
    )
endif()

# Add your source files
add_executable(hazmat
  src/main.cc
  src/setup.cc
  src/entry.cc
  src/crypt.cc
)
