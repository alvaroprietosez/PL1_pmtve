# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_COMMAND = /opt/Clion/clion-2021.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/Clion/clion-2021.1.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alvaro/CLionProjects/primitive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alvaro/CLionProjects/primitive/cmake-build-debug

# Include any dependencies generated for this target.
include u_test/CMakeFiles/u_test.dir/depend.make
# Include the progress variables for this target.
include u_test/CMakeFiles/u_test.dir/progress.make

# Include the compile flags for this target's objects.
include u_test/CMakeFiles/u_test.dir/flags.make

u_test/CMakeFiles/u_test.dir/primitive_test.cpp.o: u_test/CMakeFiles/u_test.dir/flags.make
u_test/CMakeFiles/u_test.dir/primitive_test.cpp.o: ../u_test/primitive_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvaro/CLionProjects/primitive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object u_test/CMakeFiles/u_test.dir/primitive_test.cpp.o"
	cd /home/alvaro/CLionProjects/primitive/cmake-build-debug/u_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/u_test.dir/primitive_test.cpp.o -c /home/alvaro/CLionProjects/primitive/u_test/primitive_test.cpp

u_test/CMakeFiles/u_test.dir/primitive_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/u_test.dir/primitive_test.cpp.i"
	cd /home/alvaro/CLionProjects/primitive/cmake-build-debug/u_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvaro/CLionProjects/primitive/u_test/primitive_test.cpp > CMakeFiles/u_test.dir/primitive_test.cpp.i

u_test/CMakeFiles/u_test.dir/primitive_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/u_test.dir/primitive_test.cpp.s"
	cd /home/alvaro/CLionProjects/primitive/cmake-build-debug/u_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvaro/CLionProjects/primitive/u_test/primitive_test.cpp -o CMakeFiles/u_test.dir/primitive_test.cpp.s

# Object files for target u_test
u_test_OBJECTS = \
"CMakeFiles/u_test.dir/primitive_test.cpp.o"

# External object files for target u_test
u_test_EXTERNAL_OBJECTS =

u_test/u_test: u_test/CMakeFiles/u_test.dir/primitive_test.cpp.o
u_test/u_test: u_test/CMakeFiles/u_test.dir/build.make
u_test/u_test: libmatrix_lib.a
u_test/u_test: /usr/local/lib/libgtest_main.a
u_test/u_test: /usr/local/lib/libgtest.a
u_test/u_test: u_test/CMakeFiles/u_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alvaro/CLionProjects/primitive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable u_test"
	cd /home/alvaro/CLionProjects/primitive/cmake-build-debug/u_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/u_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
u_test/CMakeFiles/u_test.dir/build: u_test/u_test
.PHONY : u_test/CMakeFiles/u_test.dir/build

u_test/CMakeFiles/u_test.dir/clean:
	cd /home/alvaro/CLionProjects/primitive/cmake-build-debug/u_test && $(CMAKE_COMMAND) -P CMakeFiles/u_test.dir/cmake_clean.cmake
.PHONY : u_test/CMakeFiles/u_test.dir/clean

u_test/CMakeFiles/u_test.dir/depend:
	cd /home/alvaro/CLionProjects/primitive/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alvaro/CLionProjects/primitive /home/alvaro/CLionProjects/primitive/u_test /home/alvaro/CLionProjects/primitive/cmake-build-debug /home/alvaro/CLionProjects/primitive/cmake-build-debug/u_test /home/alvaro/CLionProjects/primitive/cmake-build-debug/u_test/CMakeFiles/u_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : u_test/CMakeFiles/u_test.dir/depend
