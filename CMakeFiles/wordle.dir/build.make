# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alfonsorada/Desktop/cspractice/wordle-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alfonsorada/Desktop/cspractice/wordle-cpp

# Include any dependencies generated for this target.
include CMakeFiles/wordle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wordle.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wordle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wordle.dir/flags.make

CMakeFiles/wordle.dir/main.cpp.o: CMakeFiles/wordle.dir/flags.make
CMakeFiles/wordle.dir/main.cpp.o: main.cpp
CMakeFiles/wordle.dir/main.cpp.o: CMakeFiles/wordle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alfonsorada/Desktop/cspractice/wordle-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wordle.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wordle.dir/main.cpp.o -MF CMakeFiles/wordle.dir/main.cpp.o.d -o CMakeFiles/wordle.dir/main.cpp.o -c /Users/alfonsorada/Desktop/cspractice/wordle-cpp/main.cpp

CMakeFiles/wordle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wordle.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alfonsorada/Desktop/cspractice/wordle-cpp/main.cpp > CMakeFiles/wordle.dir/main.cpp.i

CMakeFiles/wordle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wordle.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alfonsorada/Desktop/cspractice/wordle-cpp/main.cpp -o CMakeFiles/wordle.dir/main.cpp.s

CMakeFiles/wordle.dir/wordle.cpp.o: CMakeFiles/wordle.dir/flags.make
CMakeFiles/wordle.dir/wordle.cpp.o: wordle.cpp
CMakeFiles/wordle.dir/wordle.cpp.o: CMakeFiles/wordle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/alfonsorada/Desktop/cspractice/wordle-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/wordle.dir/wordle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wordle.dir/wordle.cpp.o -MF CMakeFiles/wordle.dir/wordle.cpp.o.d -o CMakeFiles/wordle.dir/wordle.cpp.o -c /Users/alfonsorada/Desktop/cspractice/wordle-cpp/wordle.cpp

CMakeFiles/wordle.dir/wordle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wordle.dir/wordle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alfonsorada/Desktop/cspractice/wordle-cpp/wordle.cpp > CMakeFiles/wordle.dir/wordle.cpp.i

CMakeFiles/wordle.dir/wordle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wordle.dir/wordle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alfonsorada/Desktop/cspractice/wordle-cpp/wordle.cpp -o CMakeFiles/wordle.dir/wordle.cpp.s

# Object files for target wordle
wordle_OBJECTS = \
"CMakeFiles/wordle.dir/main.cpp.o" \
"CMakeFiles/wordle.dir/wordle.cpp.o"

# External object files for target wordle
wordle_EXTERNAL_OBJECTS =

wordle: CMakeFiles/wordle.dir/main.cpp.o
wordle: CMakeFiles/wordle.dir/wordle.cpp.o
wordle: CMakeFiles/wordle.dir/build.make
wordle: CMakeFiles/wordle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/alfonsorada/Desktop/cspractice/wordle-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable wordle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wordle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wordle.dir/build: wordle
.PHONY : CMakeFiles/wordle.dir/build

CMakeFiles/wordle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wordle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wordle.dir/clean

CMakeFiles/wordle.dir/depend:
	cd /Users/alfonsorada/Desktop/cspractice/wordle-cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alfonsorada/Desktop/cspractice/wordle-cpp /Users/alfonsorada/Desktop/cspractice/wordle-cpp /Users/alfonsorada/Desktop/cspractice/wordle-cpp /Users/alfonsorada/Desktop/cspractice/wordle-cpp /Users/alfonsorada/Desktop/cspractice/wordle-cpp/CMakeFiles/wordle.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/wordle.dir/depend

