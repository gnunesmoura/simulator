# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/vostro/Documents/Programming/c++/Simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vostro/Documents/Programming/c++/Simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/init_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/init_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/init_lib.dir/flags.make

CMakeFiles/init_lib.dir/src/init/node/node.cpp.o: CMakeFiles/init_lib.dir/flags.make
CMakeFiles/init_lib.dir/src/init/node/node.cpp.o: ../src/init/node/node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vostro/Documents/Programming/c++/Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/init_lib.dir/src/init/node/node.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/init_lib.dir/src/init/node/node.cpp.o -c /home/vostro/Documents/Programming/c++/Simulator/src/init/node/node.cpp

CMakeFiles/init_lib.dir/src/init/node/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/init_lib.dir/src/init/node/node.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vostro/Documents/Programming/c++/Simulator/src/init/node/node.cpp > CMakeFiles/init_lib.dir/src/init/node/node.cpp.i

CMakeFiles/init_lib.dir/src/init/node/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/init_lib.dir/src/init/node/node.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vostro/Documents/Programming/c++/Simulator/src/init/node/node.cpp -o CMakeFiles/init_lib.dir/src/init/node/node.cpp.s

CMakeFiles/init_lib.dir/src/init/node/node.cpp.o.requires:

.PHONY : CMakeFiles/init_lib.dir/src/init/node/node.cpp.o.requires

CMakeFiles/init_lib.dir/src/init/node/node.cpp.o.provides: CMakeFiles/init_lib.dir/src/init/node/node.cpp.o.requires
	$(MAKE) -f CMakeFiles/init_lib.dir/build.make CMakeFiles/init_lib.dir/src/init/node/node.cpp.o.provides.build
.PHONY : CMakeFiles/init_lib.dir/src/init/node/node.cpp.o.provides

CMakeFiles/init_lib.dir/src/init/node/node.cpp.o.provides.build: CMakeFiles/init_lib.dir/src/init/node/node.cpp.o


# Object files for target init_lib
init_lib_OBJECTS = \
"CMakeFiles/init_lib.dir/src/init/node/node.cpp.o"

# External object files for target init_lib
init_lib_EXTERNAL_OBJECTS =

libinit_lib.a: CMakeFiles/init_lib.dir/src/init/node/node.cpp.o
libinit_lib.a: CMakeFiles/init_lib.dir/build.make
libinit_lib.a: CMakeFiles/init_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vostro/Documents/Programming/c++/Simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libinit_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/init_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/init_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/init_lib.dir/build: libinit_lib.a

.PHONY : CMakeFiles/init_lib.dir/build

CMakeFiles/init_lib.dir/requires: CMakeFiles/init_lib.dir/src/init/node/node.cpp.o.requires

.PHONY : CMakeFiles/init_lib.dir/requires

CMakeFiles/init_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/init_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/init_lib.dir/clean

CMakeFiles/init_lib.dir/depend:
	cd /home/vostro/Documents/Programming/c++/Simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vostro/Documents/Programming/c++/Simulator /home/vostro/Documents/Programming/c++/Simulator /home/vostro/Documents/Programming/c++/Simulator/build /home/vostro/Documents/Programming/c++/Simulator/build /home/vostro/Documents/Programming/c++/Simulator/build/CMakeFiles/init_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/init_lib.dir/depend

