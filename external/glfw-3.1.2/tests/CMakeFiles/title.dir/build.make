# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "/Users/danielbaranowski/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/danielbaranowski/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial

# Include any dependencies generated for this target.
include external/glfw-3.1.2/tests/CMakeFiles/title.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/tests/CMakeFiles/title.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/tests/CMakeFiles/title.dir/flags.make

external/glfw-3.1.2/tests/CMakeFiles/title.dir/title.c.o: external/glfw-3.1.2/tests/CMakeFiles/title.dir/flags.make
external/glfw-3.1.2/tests/CMakeFiles/title.dir/title.c.o: external/glfw-3.1.2/tests/title.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/tests/CMakeFiles/title.dir/title.c.o"
	cd /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/title.dir/title.c.o   -c /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests/title.c

external/glfw-3.1.2/tests/CMakeFiles/title.dir/title.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/title.c.i"
	cd /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests/title.c > CMakeFiles/title.dir/title.c.i

external/glfw-3.1.2/tests/CMakeFiles/title.dir/title.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/title.c.s"
	cd /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests/title.c -o CMakeFiles/title.dir/title.c.s

# Object files for target title
title_OBJECTS = \
"CMakeFiles/title.dir/title.c.o"

# External object files for target title
title_EXTERNAL_OBJECTS =

external/glfw-3.1.2/tests/title.app/Contents/MacOS/title: external/glfw-3.1.2/tests/CMakeFiles/title.dir/title.c.o
external/glfw-3.1.2/tests/title.app/Contents/MacOS/title: external/glfw-3.1.2/tests/CMakeFiles/title.dir/build.make
external/glfw-3.1.2/tests/title.app/Contents/MacOS/title: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/tests/title.app/Contents/MacOS/title: external/glfw-3.1.2/tests/CMakeFiles/title.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable title.app/Contents/MacOS/title"
	cd /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/title.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/tests/CMakeFiles/title.dir/build: external/glfw-3.1.2/tests/title.app/Contents/MacOS/title

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/title.dir/build

external/glfw-3.1.2/tests/CMakeFiles/title.dir/clean:
	cd /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/title.dir/cmake_clean.cmake
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/title.dir/clean

external/glfw-3.1.2/tests/CMakeFiles/title.dir/depend:
	cd /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/external/glfw-3.1.2/tests/CMakeFiles/title.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/title.dir/depend

