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
CMAKE_SOURCE_DIR = "/home/pi/tmp/port mqtt to linux"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry"

# Include any dependencies generated for this target.
include CMakeFiles/mqtt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mqtt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mqtt.dir/flags.make

CMakeFiles/mqtt.dir/mqtt_client.c.o: CMakeFiles/mqtt.dir/flags.make
CMakeFiles/mqtt.dir/mqtt_client.c.o: ../mqtt_client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mqtt.dir/mqtt_client.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mqtt.dir/mqtt_client.c.o   -c "/home/pi/tmp/port mqtt to linux/mqtt_client.c"

CMakeFiles/mqtt.dir/mqtt_client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mqtt.dir/mqtt_client.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/pi/tmp/port mqtt to linux/mqtt_client.c" > CMakeFiles/mqtt.dir/mqtt_client.c.i

CMakeFiles/mqtt.dir/mqtt_client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mqtt.dir/mqtt_client.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/pi/tmp/port mqtt to linux/mqtt_client.c" -o CMakeFiles/mqtt.dir/mqtt_client.c.s

CMakeFiles/mqtt.dir/mqttlib/mqtt.c.o: CMakeFiles/mqtt.dir/flags.make
CMakeFiles/mqtt.dir/mqttlib/mqtt.c.o: ../mqttlib/mqtt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mqtt.dir/mqttlib/mqtt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mqtt.dir/mqttlib/mqtt.c.o   -c "/home/pi/tmp/port mqtt to linux/mqttlib/mqtt.c"

CMakeFiles/mqtt.dir/mqttlib/mqtt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mqtt.dir/mqttlib/mqtt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/pi/tmp/port mqtt to linux/mqttlib/mqtt.c" > CMakeFiles/mqtt.dir/mqttlib/mqtt.c.i

CMakeFiles/mqtt.dir/mqttlib/mqtt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mqtt.dir/mqttlib/mqtt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/pi/tmp/port mqtt to linux/mqttlib/mqtt.c" -o CMakeFiles/mqtt.dir/mqttlib/mqtt.c.s

CMakeFiles/mqtt.dir/mqttlib/network.c.o: CMakeFiles/mqtt.dir/flags.make
CMakeFiles/mqtt.dir/mqttlib/network.c.o: ../mqttlib/network.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mqtt.dir/mqttlib/network.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mqtt.dir/mqttlib/network.c.o   -c "/home/pi/tmp/port mqtt to linux/mqttlib/network.c"

CMakeFiles/mqtt.dir/mqttlib/network.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mqtt.dir/mqttlib/network.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/pi/tmp/port mqtt to linux/mqttlib/network.c" > CMakeFiles/mqtt.dir/mqttlib/network.c.i

CMakeFiles/mqtt.dir/mqttlib/network.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mqtt.dir/mqttlib/network.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/pi/tmp/port mqtt to linux/mqttlib/network.c" -o CMakeFiles/mqtt.dir/mqttlib/network.c.s

# Object files for target mqtt
mqtt_OBJECTS = \
"CMakeFiles/mqtt.dir/mqtt_client.c.o" \
"CMakeFiles/mqtt.dir/mqttlib/mqtt.c.o" \
"CMakeFiles/mqtt.dir/mqttlib/network.c.o"

# External object files for target mqtt
mqtt_EXTERNAL_OBJECTS =

mqtt: CMakeFiles/mqtt.dir/mqtt_client.c.o
mqtt: CMakeFiles/mqtt.dir/mqttlib/mqtt.c.o
mqtt: CMakeFiles/mqtt.dir/mqttlib/network.c.o
mqtt: CMakeFiles/mqtt.dir/build.make
mqtt: CMakeFiles/mqtt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable mqtt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mqtt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mqtt.dir/build: mqtt

.PHONY : CMakeFiles/mqtt.dir/build

CMakeFiles/mqtt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mqtt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mqtt.dir/clean

CMakeFiles/mqtt.dir/depend:
	cd "/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/pi/tmp/port mqtt to linux" "/home/pi/tmp/port mqtt to linux" "/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry" "/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry" "/home/pi/tmp/port mqtt to linux/cmake-build-release-raspberry/CMakeFiles/mqtt.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mqtt.dir/depend

