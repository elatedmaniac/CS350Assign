# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Syndikit\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6603.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Syndikit\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6603.37\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Syndikit\CLionProjects\CS350Assign

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Syndikit\CLionProjects\CS350Assign\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.c.dir/flags.make

CMakeFiles/main.c.dir/minidb.c.obj: CMakeFiles/main.c.dir/flags.make
CMakeFiles/main.c.dir/minidb.c.obj: ../minidb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Syndikit\CLionProjects\CS350Assign\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.c.dir/minidb.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\main.c.dir\minidb.c.obj   -c C:\Users\Syndikit\CLionProjects\CS350Assign\minidb.c

CMakeFiles/main.c.dir/minidb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.c.dir/minidb.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Syndikit\CLionProjects\CS350Assign\minidb.c > CMakeFiles\main.c.dir\minidb.c.i

CMakeFiles/main.c.dir/minidb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.c.dir/minidb.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Syndikit\CLionProjects\CS350Assign\minidb.c -o CMakeFiles\main.c.dir\minidb.c.s

CMakeFiles/main.c.dir/imSubsample.c.obj: CMakeFiles/main.c.dir/flags.make
CMakeFiles/main.c.dir/imSubsample.c.obj: ../imSubsample.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Syndikit\CLionProjects\CS350Assign\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.c.dir/imSubsample.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\main.c.dir\imSubsample.c.obj   -c C:\Users\Syndikit\CLionProjects\CS350Assign\imSubsample.c

CMakeFiles/main.c.dir/imSubsample.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.c.dir/imSubsample.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Syndikit\CLionProjects\CS350Assign\imSubsample.c > CMakeFiles\main.c.dir\imSubsample.c.i

CMakeFiles/main.c.dir/imSubsample.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.c.dir/imSubsample.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Syndikit\CLionProjects\CS350Assign\imSubsample.c -o CMakeFiles\main.c.dir\imSubsample.c.s

# Object files for target main.c
main_c_OBJECTS = \
"CMakeFiles/main.c.dir/minidb.c.obj" \
"CMakeFiles/main.c.dir/imSubsample.c.obj"

# External object files for target main.c
main_c_EXTERNAL_OBJECTS =

main.c.exe: CMakeFiles/main.c.dir/minidb.c.obj
main.c.exe: CMakeFiles/main.c.dir/imSubsample.c.obj
main.c.exe: CMakeFiles/main.c.dir/build.make
main.c.exe: CMakeFiles/main.c.dir/linklibs.rsp
main.c.exe: CMakeFiles/main.c.dir/objects1.rsp
main.c.exe: CMakeFiles/main.c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Syndikit\CLionProjects\CS350Assign\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable main.c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.c.dir/build: main.c.exe

.PHONY : CMakeFiles/main.c.dir/build

CMakeFiles/main.c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.c.dir/clean

CMakeFiles/main.c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Syndikit\CLionProjects\CS350Assign C:\Users\Syndikit\CLionProjects\CS350Assign C:\Users\Syndikit\CLionProjects\CS350Assign\cmake-build-debug C:\Users\Syndikit\CLionProjects\CS350Assign\cmake-build-debug C:\Users\Syndikit\CLionProjects\CS350Assign\cmake-build-debug\CMakeFiles\main.c.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.c.dir/depend

