cmake_minimum_required(VERSION 3.30.5)
project(hazmat)

# Specify the Argon2 include and library directories manually
set(ARGON2_INCLUDE_DIR /usr/local/include)
set(ARGON2_LIBRARY /usr/lib/libargon2.so)  # or .a for static library

# Add your source files
add_executable(hazmat
  main.cc
  cli/cli.cc
  list/list.cc
  master/master.cc
  password/password.cc
)

# Link Argon2 to the executable
target_include_directories(hazmat PRIVATE ${ARGON2_INCLUDE_DIR})
target_link_libraries(hazmat PRIVATE ${ARGON2_LIBRARY})
