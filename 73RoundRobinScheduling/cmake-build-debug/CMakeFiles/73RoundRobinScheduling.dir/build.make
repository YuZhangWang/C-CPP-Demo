# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Code\C&C++\73RoundRobinScheduling"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Code\C&C++\73RoundRobinScheduling\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/73RoundRobinScheduling.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/73RoundRobinScheduling.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/73RoundRobinScheduling.dir/flags.make

CMakeFiles/73RoundRobinScheduling.dir/main.c.obj: CMakeFiles/73RoundRobinScheduling.dir/flags.make
CMakeFiles/73RoundRobinScheduling.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Code\C&C++\73RoundRobinScheduling\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/73RoundRobinScheduling.dir/main.c.obj"
	C:\PROGRA~1\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\73RoundRobinScheduling.dir\main.c.obj   -c "D:\Code\C&C++\73RoundRobinScheduling\main.c"

CMakeFiles/73RoundRobinScheduling.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/73RoundRobinScheduling.dir/main.c.i"
	C:\PROGRA~1\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Code\C&C++\73RoundRobinScheduling\main.c" > CMakeFiles\73RoundRobinScheduling.dir\main.c.i

CMakeFiles/73RoundRobinScheduling.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/73RoundRobinScheduling.dir/main.c.s"
	C:\PROGRA~1\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Code\C&C++\73RoundRobinScheduling\main.c" -o CMakeFiles\73RoundRobinScheduling.dir\main.c.s

# Object files for target 73RoundRobinScheduling
73RoundRobinScheduling_OBJECTS = \
"CMakeFiles/73RoundRobinScheduling.dir/main.c.obj"

# External object files for target 73RoundRobinScheduling
73RoundRobinScheduling_EXTERNAL_OBJECTS =

73RoundRobinScheduling.exe: CMakeFiles/73RoundRobinScheduling.dir/main.c.obj
73RoundRobinScheduling.exe: CMakeFiles/73RoundRobinScheduling.dir/build.make
73RoundRobinScheduling.exe: CMakeFiles/73RoundRobinScheduling.dir/linklibs.rsp
73RoundRobinScheduling.exe: CMakeFiles/73RoundRobinScheduling.dir/objects1.rsp
73RoundRobinScheduling.exe: CMakeFiles/73RoundRobinScheduling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Code\C&C++\73RoundRobinScheduling\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 73RoundRobinScheduling.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\73RoundRobinScheduling.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/73RoundRobinScheduling.dir/build: 73RoundRobinScheduling.exe

.PHONY : CMakeFiles/73RoundRobinScheduling.dir/build

CMakeFiles/73RoundRobinScheduling.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\73RoundRobinScheduling.dir\cmake_clean.cmake
.PHONY : CMakeFiles/73RoundRobinScheduling.dir/clean

CMakeFiles/73RoundRobinScheduling.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Code\C&C++\73RoundRobinScheduling" "D:\Code\C&C++\73RoundRobinScheduling" "D:\Code\C&C++\73RoundRobinScheduling\cmake-build-debug" "D:\Code\C&C++\73RoundRobinScheduling\cmake-build-debug" "D:\Code\C&C++\73RoundRobinScheduling\cmake-build-debug\CMakeFiles\73RoundRobinScheduling.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/73RoundRobinScheduling.dir/depend

