# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\My shit)\treeExample"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\My shit)\treeExample\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/treeExample.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/treeExample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/treeExample.dir/flags.make

CMakeFiles/treeExample.dir/decanat.c.obj: CMakeFiles/treeExample.dir/flags.make
CMakeFiles/treeExample.dir/decanat.c.obj: ../decanat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\My shit)\treeExample\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/treeExample.dir/decanat.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\treeExample.dir\decanat.c.obj -c "D:\My shit)\treeExample\decanat.c"

CMakeFiles/treeExample.dir/decanat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/treeExample.dir/decanat.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\My shit)\treeExample\decanat.c" > CMakeFiles\treeExample.dir\decanat.c.i

CMakeFiles/treeExample.dir/decanat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/treeExample.dir/decanat.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\My shit)\treeExample\decanat.c" -o CMakeFiles\treeExample.dir\decanat.c.s

CMakeFiles/treeExample.dir/tree.c.obj: CMakeFiles/treeExample.dir/flags.make
CMakeFiles/treeExample.dir/tree.c.obj: ../tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\My shit)\treeExample\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/treeExample.dir/tree.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\treeExample.dir\tree.c.obj -c "D:\My shit)\treeExample\tree.c"

CMakeFiles/treeExample.dir/tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/treeExample.dir/tree.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\My shit)\treeExample\tree.c" > CMakeFiles\treeExample.dir\tree.c.i

CMakeFiles/treeExample.dir/tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/treeExample.dir/tree.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\My shit)\treeExample\tree.c" -o CMakeFiles\treeExample.dir\tree.c.s

# Object files for target treeExample
treeExample_OBJECTS = \
"CMakeFiles/treeExample.dir/decanat.c.obj" \
"CMakeFiles/treeExample.dir/tree.c.obj"

# External object files for target treeExample
treeExample_EXTERNAL_OBJECTS =

treeExample.exe: CMakeFiles/treeExample.dir/decanat.c.obj
treeExample.exe: CMakeFiles/treeExample.dir/tree.c.obj
treeExample.exe: CMakeFiles/treeExample.dir/build.make
treeExample.exe: CMakeFiles/treeExample.dir/linklibs.rsp
treeExample.exe: CMakeFiles/treeExample.dir/objects1.rsp
treeExample.exe: CMakeFiles/treeExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\My shit)\treeExample\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable treeExample.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\treeExample.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/treeExample.dir/build: treeExample.exe
.PHONY : CMakeFiles/treeExample.dir/build

CMakeFiles/treeExample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\treeExample.dir\cmake_clean.cmake
.PHONY : CMakeFiles/treeExample.dir/clean

CMakeFiles/treeExample.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\My shit)\treeExample" "D:\My shit)\treeExample" "D:\My shit)\treeExample\cmake-build-debug" "D:\My shit)\treeExample\cmake-build-debug" "D:\My shit)\treeExample\cmake-build-debug\CMakeFiles\treeExample.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/treeExample.dir/depend

