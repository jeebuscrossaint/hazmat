cmake_minimum_required(VERSION 3.30.5)
project(hazmat)

# Set compiler and flags
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Copy compile_commands.json to the project root after generation
if (EXISTS ${CMAKE_BINARY_DIR}/compile_commands.json)
    add_custom_target(copy_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
        DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
    )
endif()

set(CMAKE_RULE_MESSAGES OFF)
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Add your source files
add_executable(hazmat
    src/main.cc
    src/setup.cc
    src/entry.cc
    src/crypt.cc
    src/help.cc
)

# Link OpenSSL to hazmat target
target_link_libraries(hazmat
    PRIVATE
    OpenSSL::Crypto
    OpenSSL::SSL
)

# Include directories
target_include_directories(hazmat
    PRIVATE
    ${OPENSSL_INCLUDE_DIR}
)