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
include laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/compiler_depend.make

# Include the progress variables for this target.
include laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/progress.make

# Include the compile flags for this target's objects.
include laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/flags.make

laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/date.cpp.o: laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/flags.make
laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/date.cpp.o: ../laboratory-work-01-kapavkin/date/date.cpp
laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/date.cpp.o: laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/date.cpp.o"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/laboratory-work-01-kapavkin/date && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/date.cpp.o -MF CMakeFiles/date.dir/date.cpp.o.d -o CMakeFiles/date.dir/date.cpp.o -c /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/laboratory-work-01-kapavkin/date/date.cpp

laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/date.dir/date.cpp.i"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/laboratory-work-01-kapavkin/date && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/laboratory-work-01-kapavkin/date/date.cpp > CMakeFiles/date.dir/date.cpp.i

laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/date.dir/date.cpp.s"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/laboratory-work-01-kapavkin/date && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/laboratory-work-01-kapavkin/date/date.cpp -o CMakeFiles/date.dir/date.cpp.s

# Object files for target date
date_OBJECTS = \
"CMakeFiles/date.dir/date.cpp.o"

# External object files for target date
date_EXTERNAL_OBJECTS =

laboratory-work-01-kapavkin/date/libdate.dylib: laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/date.cpp.o
laboratory-work-01-kapavkin/date/libdate.dylib: laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/build.make
laboratory-work-01-kapavkin/date/libdate.dylib: laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libdate.dylib"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/laboratory-work-01-kapavkin/date && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/date.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/build: laboratory-work-01-kapavkin/date/libdate.dylib
.PHONY : laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/build

laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/clean:
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/laboratory-work-01-kapavkin/date && $(CMAKE_COMMAND) -P CMakeFiles/date.dir/cmake_clean.cmake
.PHONY : laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/clean

laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/depend:
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/laboratory-work-01-kapavkin/date /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/laboratory-work-01-kapavkin/date /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : laboratory-work-01-kapavkin/date/CMakeFiles/date.dir/depend

