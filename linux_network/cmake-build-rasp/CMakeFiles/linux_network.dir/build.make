# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/linux_network

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/linux_network/cmake-build-rasp

# Include any dependencies generated for this target.
include CMakeFiles/linux_network.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linux_network.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linux_network.dir/flags.make

CMakeFiles/linux_network.dir/main.c.o: CMakeFiles/linux_network.dir/flags.make
CMakeFiles/linux_network.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/linux_network/cmake-build-rasp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/linux_network.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_network.dir/main.c.o   -c /home/pi/linux_network/main.c

CMakeFiles/linux_network.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_network.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/linux_network/main.c > CMakeFiles/linux_network.dir/main.c.i

CMakeFiles/linux_network.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_network.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/linux_network/main.c -o CMakeFiles/linux_network.dir/main.c.s

# Object files for target linux_network
linux_network_OBJECTS = \
"CMakeFiles/linux_network.dir/main.c.o"

# External object files for target linux_network
linux_network_EXTERNAL_OBJECTS =

linux_network: CMakeFiles/linux_network.dir/main.c.o
linux_network: CMakeFiles/linux_network.dir/build.make
linux_network: CMakeFiles/linux_network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/linux_network/cmake-build-rasp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable linux_network"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linux_network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linux_network.dir/build: linux_network

.PHONY : CMakeFiles/linux_network.dir/build

CMakeFiles/linux_network.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linux_network.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linux_network.dir/clean

CMakeFiles/linux_network.dir/depend:
	cd /home/pi/linux_network/cmake-build-rasp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/linux_network /home/pi/linux_network /home/pi/linux_network/cmake-build-rasp /home/pi/linux_network/cmake-build-rasp /home/pi/linux_network/cmake-build-rasp/CMakeFiles/linux_network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linux_network.dir/depend

