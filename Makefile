# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amarnath/Projects/hazmat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amarnath/Projects/hazmat

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/amarnath/Projects/hazmat/CMakeFiles /home/amarnath/Projects/hazmat//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/amarnath/Projects/hazmat/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named hazmat

# Build rule for target.
hazmat: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hazmat
.PHONY : hazmat

# fast build rule for target.
hazmat/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/build
.PHONY : hazmat/fast

src/cli/cli.o: src/cli/cli.cc.o
.PHONY : src/cli/cli.o

# target to build an object file
src/cli/cli.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/cli/cli.cc.o
.PHONY : src/cli/cli.cc.o

src/cli/cli.i: src/cli/cli.cc.i
.PHONY : src/cli/cli.i

# target to preprocess a source file
src/cli/cli.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/cli/cli.cc.i
.PHONY : src/cli/cli.cc.i

src/cli/cli.s: src/cli/cli.cc.s
.PHONY : src/cli/cli.s

# target to generate assembly for a file
src/cli/cli.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/cli/cli.cc.s
.PHONY : src/cli/cli.cc.s

src/list/list.o: src/list/list.cc.o
.PHONY : src/list/list.o

# target to build an object file
src/list/list.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/list/list.cc.o
.PHONY : src/list/list.cc.o

src/list/list.i: src/list/list.cc.i
.PHONY : src/list/list.i

# target to preprocess a source file
src/list/list.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/list/list.cc.i
.PHONY : src/list/list.cc.i

src/list/list.s: src/list/list.cc.s
.PHONY : src/list/list.s

# target to generate assembly for a file
src/list/list.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/list/list.cc.s
.PHONY : src/list/list.cc.s

src/main.o: src/main.cc.o
.PHONY : src/main.o

# target to build an object file
src/main.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/main.cc.o
.PHONY : src/main.cc.o

src/main.i: src/main.cc.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/main.cc.i
.PHONY : src/main.cc.i

src/main.s: src/main.cc.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/main.cc.s
.PHONY : src/main.cc.s

src/master/master.o: src/master/master.cc.o
.PHONY : src/master/master.o

# target to build an object file
src/master/master.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/master/master.cc.o
.PHONY : src/master/master.cc.o

src/master/master.i: src/master/master.cc.i
.PHONY : src/master/master.i

# target to preprocess a source file
src/master/master.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/master/master.cc.i
.PHONY : src/master/master.cc.i

src/master/master.s: src/master/master.cc.s
.PHONY : src/master/master.s

# target to generate assembly for a file
src/master/master.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/master/master.cc.s
.PHONY : src/master/master.cc.s

src/password/password.o: src/password/password.cc.o
.PHONY : src/password/password.o

# target to build an object file
src/password/password.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/password/password.cc.o
.PHONY : src/password/password.cc.o

src/password/password.i: src/password/password.cc.i
.PHONY : src/password/password.i

# target to preprocess a source file
src/password/password.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/password/password.cc.i
.PHONY : src/password/password.cc.i

src/password/password.s: src/password/password.cc.s
.PHONY : src/password/password.s

# target to generate assembly for a file
src/password/password.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hazmat.dir/build.make CMakeFiles/hazmat.dir/src/password/password.cc.s
.PHONY : src/password/password.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... hazmat"
	@echo "... src/cli/cli.o"
	@echo "... src/cli/cli.i"
	@echo "... src/cli/cli.s"
	@echo "... src/list/list.o"
	@echo "... src/list/list.i"
	@echo "... src/list/list.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/master/master.o"
	@echo "... src/master/master.i"
	@echo "... src/master/master.s"
	@echo "... src/password/password.o"
	@echo "... src/password/password.i"
	@echo "... src/password/password.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

