# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build

# Include any dependencies generated for this target.
include array/stack/CMakeFiles/stack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include array/stack/CMakeFiles/stack.dir/compiler_depend.make

# Include the progress variables for this target.
include array/stack/CMakeFiles/stack.dir/progress.make

# Include the compile flags for this target's objects.
include array/stack/CMakeFiles/stack.dir/flags.make

array/stack/CMakeFiles/stack.dir/stack.cpp.o: array/stack/CMakeFiles/stack.dir/flags.make
array/stack/CMakeFiles/stack.dir/stack.cpp.o: ../array/stack/stack.cpp
array/stack/CMakeFiles/stack.dir/stack.cpp.o: array/stack/CMakeFiles/stack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object array/stack/CMakeFiles/stack.dir/stack.cpp.o"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT array/stack/CMakeFiles/stack.dir/stack.cpp.o -MF CMakeFiles/stack.dir/stack.cpp.o.d -o CMakeFiles/stack.dir/stack.cpp.o -c /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/array/stack/stack.cpp

array/stack/CMakeFiles/stack.dir/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stack.dir/stack.cpp.i"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/array/stack/stack.cpp > CMakeFiles/stack.dir/stack.cpp.i

array/stack/CMakeFiles/stack.dir/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stack.dir/stack.cpp.s"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/array/stack/stack.cpp -o CMakeFiles/stack.dir/stack.cpp.s

array/stack/CMakeFiles/stack.dir/__/array.cpp.o: array/stack/CMakeFiles/stack.dir/flags.make
array/stack/CMakeFiles/stack.dir/__/array.cpp.o: ../array/array.cpp
array/stack/CMakeFiles/stack.dir/__/array.cpp.o: array/stack/CMakeFiles/stack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object array/stack/CMakeFiles/stack.dir/__/array.cpp.o"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT array/stack/CMakeFiles/stack.dir/__/array.cpp.o -MF CMakeFiles/stack.dir/__/array.cpp.o.d -o CMakeFiles/stack.dir/__/array.cpp.o -c /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/array/array.cpp

array/stack/CMakeFiles/stack.dir/__/array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stack.dir/__/array.cpp.i"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/array/array.cpp > CMakeFiles/stack.dir/__/array.cpp.i

array/stack/CMakeFiles/stack.dir/__/array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stack.dir/__/array.cpp.s"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/array/array.cpp -o CMakeFiles/stack.dir/__/array.cpp.s

# Object files for target stack
stack_OBJECTS = \
"CMakeFiles/stack.dir/stack.cpp.o" \
"CMakeFiles/stack.dir/__/array.cpp.o"

# External object files for target stack
stack_EXTERNAL_OBJECTS =

array/stack/libstack.dylib: array/stack/CMakeFiles/stack.dir/stack.cpp.o
array/stack/libstack.dylib: array/stack/CMakeFiles/stack.dir/__/array.cpp.o
array/stack/libstack.dylib: array/stack/CMakeFiles/stack.dir/build.make
array/stack/libstack.dylib: array/stack/CMakeFiles/stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libstack.dylib"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
array/stack/CMakeFiles/stack.dir/build: array/stack/libstack.dylib
.PHONY : array/stack/CMakeFiles/stack.dir/build

array/stack/CMakeFiles/stack.dir/clean:
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack && $(CMAKE_COMMAND) -P CMakeFiles/stack.dir/cmake_clean.cmake
.PHONY : array/stack/CMakeFiles/stack.dir/clean

array/stack/CMakeFiles/stack.dir/depend:
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/array/stack /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/array/stack/CMakeFiles/stack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : array/stack/CMakeFiles/stack.dir/depend
