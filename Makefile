# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\" \"libassimp3.0-r1270-OGLtuts\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/CMakeFiles /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/danielbaranowski/Workspace/personal/CLionProjects/open-gl-tutorial/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named open_gl_tutorial

# Build rule for target.
open_gl_tutorial: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 open_gl_tutorial
.PHONY : open_gl_tutorial

# fast build rule for target.
open_gl_tutorial/fast:
	$(MAKE) -f CMakeFiles/open_gl_tutorial.dir/build.make CMakeFiles/open_gl_tutorial.dir/build
.PHONY : open_gl_tutorial/fast

#=============================================================================
# Target rules for targets named ANTTWEAKBAR_116_OGLCORE_GLFW

# Build rule for target.
ANTTWEAKBAR_116_OGLCORE_GLFW: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ANTTWEAKBAR_116_OGLCORE_GLFW
.PHONY : ANTTWEAKBAR_116_OGLCORE_GLFW

# fast build rule for target.
ANTTWEAKBAR_116_OGLCORE_GLFW/fast:
	$(MAKE) -f external/CMakeFiles/ANTTWEAKBAR_116_OGLCORE_GLFW.dir/build.make external/CMakeFiles/ANTTWEAKBAR_116_OGLCORE_GLFW.dir/build
.PHONY : ANTTWEAKBAR_116_OGLCORE_GLFW/fast

#=============================================================================
# Target rules for targets named GLEW_1130

# Build rule for target.
GLEW_1130: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 GLEW_1130
.PHONY : GLEW_1130

# fast build rule for target.
GLEW_1130/fast:
	$(MAKE) -f external/CMakeFiles/GLEW_1130.dir/build.make external/CMakeFiles/GLEW_1130.dir/build
.PHONY : GLEW_1130/fast

#=============================================================================
# Target rules for targets named uninstall

# Build rule for target.
uninstall: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 uninstall
.PHONY : uninstall

# fast build rule for target.
uninstall/fast:
	$(MAKE) -f external/glfw-3.1.2/CMakeFiles/uninstall.dir/build.make external/glfw-3.1.2/CMakeFiles/uninstall.dir/build
.PHONY : uninstall/fast

#=============================================================================
# Target rules for targets named glfw

# Build rule for target.
glfw: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glfw
.PHONY : glfw

# fast build rule for target.
glfw/fast:
	$(MAKE) -f external/glfw-3.1.2/src/CMakeFiles/glfw.dir/build.make external/glfw-3.1.2/src/CMakeFiles/glfw.dir/build
.PHONY : glfw/fast

#=============================================================================
# Target rules for targets named heightmap

# Build rule for target.
heightmap: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 heightmap
.PHONY : heightmap

# fast build rule for target.
heightmap/fast:
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/heightmap.dir/build
.PHONY : heightmap/fast

#=============================================================================
# Target rules for targets named wave

# Build rule for target.
wave: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 wave
.PHONY : wave

# fast build rule for target.
wave/fast:
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/wave.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/wave.dir/build
.PHONY : wave/fast

#=============================================================================
# Target rules for targets named splitview

# Build rule for target.
splitview: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 splitview
.PHONY : splitview

# fast build rule for target.
splitview/fast:
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/splitview.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/splitview.dir/build
.PHONY : splitview/fast

#=============================================================================
# Target rules for targets named simple

# Build rule for target.
simple: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 simple
.PHONY : simple

# fast build rule for target.
simple/fast:
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/simple.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/simple.dir/build
.PHONY : simple/fast

#=============================================================================
# Target rules for targets named particles

# Build rule for target.
particles: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 particles
.PHONY : particles

# fast build rule for target.
particles/fast:
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/particles.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/particles.dir/build
.PHONY : particles/fast

#=============================================================================
# Target rules for targets named gears

# Build rule for target.
gears: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gears
.PHONY : gears

# fast build rule for target.
gears/fast:
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/gears.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/gears.dir/build
.PHONY : gears/fast

#=============================================================================
# Target rules for targets named boing

# Build rule for target.
boing: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 boing
.PHONY : boing

# fast build rule for target.
boing/fast:
	$(MAKE) -f external/glfw-3.1.2/examples/CMakeFiles/boing.dir/build.make external/glfw-3.1.2/examples/CMakeFiles/boing.dir/build
.PHONY : boing/fast

#=============================================================================
# Target rules for targets named windows

# Build rule for target.
windows: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 windows
.PHONY : windows

# fast build rule for target.
windows/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/windows.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/windows.dir/build
.PHONY : windows/fast

#=============================================================================
# Target rules for targets named title

# Build rule for target.
title: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 title
.PHONY : title

# fast build rule for target.
title/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/title.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/title.dir/build
.PHONY : title/fast

#=============================================================================
# Target rules for targets named threads

# Build rule for target.
threads: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 threads
.PHONY : threads

# fast build rule for target.
threads/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/threads.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/threads.dir/build
.PHONY : threads/fast

#=============================================================================
# Target rules for targets named tearing

# Build rule for target.
tearing: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tearing
.PHONY : tearing

# fast build rule for target.
tearing/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/tearing.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/tearing.dir/build
.PHONY : tearing/fast

#=============================================================================
# Target rules for targets named empty

# Build rule for target.
empty: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 empty
.PHONY : empty

# fast build rule for target.
empty/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/empty.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/empty.dir/build
.PHONY : empty/fast

#=============================================================================
# Target rules for targets named glfwinfo

# Build rule for target.
glfwinfo: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glfwinfo
.PHONY : glfwinfo

# fast build rule for target.
glfwinfo/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/glfwinfo.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/glfwinfo.dir/build
.PHONY : glfwinfo/fast

#=============================================================================
# Target rules for targets named cursor

# Build rule for target.
cursor: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cursor
.PHONY : cursor

# fast build rule for target.
cursor/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/build
.PHONY : cursor/fast

#=============================================================================
# Target rules for targets named monitors

# Build rule for target.
monitors: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 monitors
.PHONY : monitors

# fast build rule for target.
monitors/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/monitors.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/monitors.dir/build
.PHONY : monitors/fast

#=============================================================================
# Target rules for targets named reopen

# Build rule for target.
reopen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 reopen
.PHONY : reopen

# fast build rule for target.
reopen/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/reopen.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/reopen.dir/build
.PHONY : reopen/fast

#=============================================================================
# Target rules for targets named joysticks

# Build rule for target.
joysticks: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 joysticks
.PHONY : joysticks

# fast build rule for target.
joysticks/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/joysticks.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/joysticks.dir/build
.PHONY : joysticks/fast

#=============================================================================
# Target rules for targets named events

# Build rule for target.
events: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 events
.PHONY : events

# fast build rule for target.
events/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/events.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/events.dir/build
.PHONY : events/fast

#=============================================================================
# Target rules for targets named iconify

# Build rule for target.
iconify: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 iconify
.PHONY : iconify

# fast build rule for target.
iconify/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/iconify.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/iconify.dir/build
.PHONY : iconify/fast

#=============================================================================
# Target rules for targets named gamma

# Build rule for target.
gamma: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gamma
.PHONY : gamma

# fast build rule for target.
gamma/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/gamma.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/gamma.dir/build
.PHONY : gamma/fast

#=============================================================================
# Target rules for targets named sharing

# Build rule for target.
sharing: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 sharing
.PHONY : sharing

# fast build rule for target.
sharing/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/sharing.dir/build
.PHONY : sharing/fast

#=============================================================================
# Target rules for targets named msaa

# Build rule for target.
msaa: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 msaa
.PHONY : msaa

# fast build rule for target.
msaa/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/msaa.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/msaa.dir/build
.PHONY : msaa/fast

#=============================================================================
# Target rules for targets named clipboard

# Build rule for target.
clipboard: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 clipboard
.PHONY : clipboard

# fast build rule for target.
clipboard/fast:
	$(MAKE) -f external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/build.make external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/build
.PHONY : clipboard/fast

#=============================================================================
# Target rules for targets named zlib

# Build rule for target.
zlib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 zlib
.PHONY : zlib

# fast build rule for target.
zlib/fast:
	$(MAKE) -f external/assimp-3.0.1270/contrib/zlib/CMakeFiles/zlib.dir/build.make external/assimp-3.0.1270/contrib/zlib/CMakeFiles/zlib.dir/build
.PHONY : zlib/fast

#=============================================================================
# Target rules for targets named assimp

# Build rule for target.
assimp: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 assimp
.PHONY : assimp

# fast build rule for target.
assimp/fast:
	$(MAKE) -f external/assimp-3.0.1270/code/CMakeFiles/assimp.dir/build.make external/assimp-3.0.1270/code/CMakeFiles/assimp.dir/build
.PHONY : assimp/fast

#=============================================================================
# Target rules for targets named BulletSoftBody

# Build rule for target.
BulletSoftBody: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 BulletSoftBody
.PHONY : BulletSoftBody

# fast build rule for target.
BulletSoftBody/fast:
	$(MAKE) -f external/bullet-2.81-rev2613/src/BulletSoftBody/CMakeFiles/BulletSoftBody.dir/build.make external/bullet-2.81-rev2613/src/BulletSoftBody/CMakeFiles/BulletSoftBody.dir/build
.PHONY : BulletSoftBody/fast

#=============================================================================
# Target rules for targets named BulletCollision

# Build rule for target.
BulletCollision: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 BulletCollision
.PHONY : BulletCollision

# fast build rule for target.
BulletCollision/fast:
	$(MAKE) -f external/bullet-2.81-rev2613/src/BulletCollision/CMakeFiles/BulletCollision.dir/build.make external/bullet-2.81-rev2613/src/BulletCollision/CMakeFiles/BulletCollision.dir/build
.PHONY : BulletCollision/fast

#=============================================================================
# Target rules for targets named BulletDynamics

# Build rule for target.
BulletDynamics: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 BulletDynamics
.PHONY : BulletDynamics

# fast build rule for target.
BulletDynamics/fast:
	$(MAKE) -f external/bullet-2.81-rev2613/src/BulletDynamics/CMakeFiles/BulletDynamics.dir/build.make external/bullet-2.81-rev2613/src/BulletDynamics/CMakeFiles/BulletDynamics.dir/build
.PHONY : BulletDynamics/fast

#=============================================================================
# Target rules for targets named LinearMath

# Build rule for target.
LinearMath: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 LinearMath
.PHONY : LinearMath

# fast build rule for target.
LinearMath/fast:
	$(MAKE) -f external/bullet-2.81-rev2613/src/LinearMath/CMakeFiles/LinearMath.dir/build.make external/bullet-2.81-rev2613/src/LinearMath/CMakeFiles/LinearMath.dir/build
.PHONY : LinearMath/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/open_gl_tutorial.dir/build.make CMakeFiles/open_gl_tutorial.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/open_gl_tutorial.dir/build.make CMakeFiles/open_gl_tutorial.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/open_gl_tutorial.dir/build.make CMakeFiles/open_gl_tutorial.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... open_gl_tutorial"
	@echo "... ANTTWEAKBAR_116_OGLCORE_GLFW"
	@echo "... GLEW_1130"
	@echo "... uninstall"
	@echo "... glfw"
	@echo "... heightmap"
	@echo "... wave"
	@echo "... splitview"
	@echo "... simple"
	@echo "... particles"
	@echo "... gears"
	@echo "... boing"
	@echo "... windows"
	@echo "... title"
	@echo "... threads"
	@echo "... tearing"
	@echo "... empty"
	@echo "... glfwinfo"
	@echo "... cursor"
	@echo "... monitors"
	@echo "... reopen"
	@echo "... joysticks"
	@echo "... events"
	@echo "... iconify"
	@echo "... gamma"
	@echo "... sharing"
	@echo "... msaa"
	@echo "... clipboard"
	@echo "... zlib"
	@echo "... assimp"
	@echo "... BulletSoftBody"
	@echo "... BulletCollision"
	@echo "... BulletDynamics"
	@echo "... LinearMath"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

