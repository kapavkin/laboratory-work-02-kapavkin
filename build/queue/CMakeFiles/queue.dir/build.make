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
include queue/CMakeFiles/queue.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include queue/CMakeFiles/queue.dir/compiler_depend.make

# Include the progress variables for this target.
include queue/CMakeFiles/queue.dir/progress.make

# Include the compile flags for this target's objects.
include queue/CMakeFiles/queue.dir/flags.make

queue/CMakeFiles/queue.dir/queue.cpp.o: queue/CMakeFiles/queue.dir/flags.make
queue/CMakeFiles/queue.dir/queue.cpp.o: ../queue/queue.cpp
queue/CMakeFiles/queue.dir/queue.cpp.o: queue/CMakeFiles/queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object queue/CMakeFiles/queue.dir/queue.cpp.o"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/queue && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT queue/CMakeFiles/queue.dir/queue.cpp.o -MF CMakeFiles/queue.dir/queue.cpp.o.d -o CMakeFiles/queue.dir/queue.cpp.o -c /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/queue/queue.cpp

queue/CMakeFiles/queue.dir/queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queue.dir/queue.cpp.i"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/queue && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/queue/queue.cpp > CMakeFiles/queue.dir/queue.cpp.i

queue/CMakeFiles/queue.dir/queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queue.dir/queue.cpp.s"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/queue && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/queue/queue.cpp -o CMakeFiles/queue.dir/queue.cpp.s

# Object files for target queue
queue_OBJECTS = \
"CMakeFiles/queue.dir/queue.cpp.o"

# External object files for target queue
queue_EXTERNAL_OBJECTS =

queue/libqueue.dylib: queue/CMakeFiles/queue.dir/queue.cpp.o
queue/libqueue.dylib: queue/CMakeFiles/queue.dir/build.make
queue/libqueue.dylib: queue/CMakeFiles/queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libqueue.dylib"
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/queue && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
queue/CMakeFiles/queue.dir/build: queue/libqueue.dylib
.PHONY : queue/CMakeFiles/queue.dir/build

queue/CMakeFiles/queue.dir/clean:
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/queue && $(CMAKE_COMMAND) -P CMakeFiles/queue.dir/cmake_clean.cmake
.PHONY : queue/CMakeFiles/queue.dir/clean

queue/CMakeFiles/queue.dir/depend:
	cd /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/queue /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/queue /Users/kirillpavkin/Downloads/laboratory-work-02-kapavkin/build/queue/CMakeFiles/queue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : queue/CMakeFiles/queue.dir/depend

