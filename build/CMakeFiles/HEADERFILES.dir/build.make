# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/foulonj/dev/SUscCGL_V2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/foulonj/dev/SUscCGL_V2/build

# Utility rule file for HEADERFILES.

# Include the progress variables for this target.
include CMakeFiles/HEADERFILES.dir/progress.make

CMakeFiles/HEADERFILES: embedfile
	$(CMAKE_COMMAND) -E cmake_progress_report /home/foulonj/dev/SUscCGL_V2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Creates header files"
	cd /home/foulonj/dev/SUscCGL_V2/include && /home/foulonj/dev/SUscCGL_V2/build/embedfile simple_frag_code ../shaders/shader.frag simple_shader_frag.h
	cd /home/foulonj/dev/SUscCGL_V2/include && /home/foulonj/dev/SUscCGL_V2/build/embedfile simple_vert_code ../shaders/shader.vert simple_shader_vert.h
	cd /home/foulonj/dev/SUscCGL_V2/include && /home/foulonj/dev/SUscCGL_V2/build/embedfile smooth_frag_code ../shaders/smooth_shader.frag smooth_shader_frag.h
	cd /home/foulonj/dev/SUscCGL_V2/include && /home/foulonj/dev/SUscCGL_V2/build/embedfile smooth_vert_code ../shaders/smooth_shader.vert smooth_shader_vert.h
	cd /home/foulonj/dev/SUscCGL_V2/include && /home/foulonj/dev/SUscCGL_V2/build/embedfile flat_frag_code ../shaders/flat_shader.frag flat_shader_frag.h
	cd /home/foulonj/dev/SUscCGL_V2/include && /home/foulonj/dev/SUscCGL_V2/build/embedfile flat_vert_code ../shaders/flat_shader.vert flat_shader_vert.h

HEADERFILES: CMakeFiles/HEADERFILES
HEADERFILES: CMakeFiles/HEADERFILES.dir/build.make
.PHONY : HEADERFILES

# Rule to build all files generated by this target.
CMakeFiles/HEADERFILES.dir/build: HEADERFILES
.PHONY : CMakeFiles/HEADERFILES.dir/build

CMakeFiles/HEADERFILES.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HEADERFILES.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HEADERFILES.dir/clean

CMakeFiles/HEADERFILES.dir/depend:
	cd /home/foulonj/dev/SUscCGL_V2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/foulonj/dev/SUscCGL_V2 /home/foulonj/dev/SUscCGL_V2 /home/foulonj/dev/SUscCGL_V2/build /home/foulonj/dev/SUscCGL_V2/build /home/foulonj/dev/SUscCGL_V2/build/CMakeFiles/HEADERFILES.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HEADERFILES.dir/depend

