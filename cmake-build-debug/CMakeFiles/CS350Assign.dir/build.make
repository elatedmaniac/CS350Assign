# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michael/Desktop/CS350Assign

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michael/Desktop/CS350Assign/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CS350Assign.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CS350Assign.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CS350Assign.dir/flags.make

CMakeFiles/CS350Assign.dir/main.c.o: CMakeFiles/CS350Assign.dir/flags.make
CMakeFiles/CS350Assign.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michael/Desktop/CS350Assign/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CS350Assign.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CS350Assign.dir/main.c.o   -c /Users/michael/Desktop/CS350Assign/main.c

CMakeFiles/CS350Assign.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CS350Assign.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michael/Desktop/CS350Assign/main.c > CMakeFiles/CS350Assign.dir/main.c.i

CMakeFiles/CS350Assign.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CS350Assign.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michael/Desktop/CS350Assign/main.c -o CMakeFiles/CS350Assign.dir/main.c.s

# Object files for target CS350Assign
CS350Assign_OBJECTS = \
"CMakeFiles/CS350Assign.dir/main.c.o"

# External object files for target CS350Assign
CS350Assign_EXTERNAL_OBJECTS =

CS350Assign: CMakeFiles/CS350Assign.dir/main.c.o
CS350Assign: CMakeFiles/CS350Assign.dir/build.make
CS350Assign: CMakeFiles/CS350Assign.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michael/Desktop/CS350Assign/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable CS350Assign"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CS350Assign.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CS350Assign.dir/build: CS350Assign

.PHONY : CMakeFiles/CS350Assign.dir/build

CMakeFiles/CS350Assign.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CS350Assign.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CS350Assign.dir/clean

CMakeFiles/CS350Assign.dir/depend:
	cd /Users/michael/Desktop/CS350Assign/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michael/Desktop/CS350Assign /Users/michael/Desktop/CS350Assign /Users/michael/Desktop/CS350Assign/cmake-build-debug /Users/michael/Desktop/CS350Assign/cmake-build-debug /Users/michael/Desktop/CS350Assign/cmake-build-debug/CMakeFiles/CS350Assign.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CS350Assign.dir/depend

