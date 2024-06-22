cmake_minimum_required(VERSION 3.10)
project(password_manager)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find MariaDB
find_package(PkgConfig REQUIRED)
pkg_check_modules(MARIADB REQUIRED libmariadb)

# Find Argon2
find_library(ARGON2_LIBRARY argon2)
find_path(ARGON2_INCLUDE_DIR argon2.h)

# Add your source files
set(SOURCES
    main.cpp
    manager.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${MARIADB_INCLUDE_DIRS}
    ${ARGON2_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${MARIADB_LIBRARIES}
    ${ARGON2_LIBRARY}
)

# Add compiler warnings
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
