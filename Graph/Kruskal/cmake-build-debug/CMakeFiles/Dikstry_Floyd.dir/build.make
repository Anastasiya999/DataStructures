# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\git_repos\DataStructures\Graph\Kruskal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\git_repos\DataStructures\Graph\Kruskal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Dikstry_Floyd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dikstry_Floyd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dikstry_Floyd.dir/flags.make

CMakeFiles/Dikstry_Floyd.dir/main.cpp.obj: CMakeFiles/Dikstry_Floyd.dir/flags.make
CMakeFiles/Dikstry_Floyd.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\git_repos\DataStructures\Graph\Kruskal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dikstry_Floyd.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dikstry_Floyd.dir\main.cpp.obj -c C:\git_repos\DataStructures\Graph\Kruskal\main.cpp

CMakeFiles/Dikstry_Floyd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dikstry_Floyd.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\git_repos\DataStructures\Graph\Kruskal\main.cpp > CMakeFiles\Dikstry_Floyd.dir\main.cpp.i

CMakeFiles/Dikstry_Floyd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dikstry_Floyd.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\git_repos\DataStructures\Graph\Kruskal\main.cpp -o CMakeFiles\Dikstry_Floyd.dir\main.cpp.s

# Object files for target Dikstry_Floyd
Dikstry_Floyd_OBJECTS = \
"CMakeFiles/Dikstry_Floyd.dir/main.cpp.obj"

# External object files for target Dikstry_Floyd
Dikstry_Floyd_EXTERNAL_OBJECTS =

Dikstry_Floyd.exe: CMakeFiles/Dikstry_Floyd.dir/main.cpp.obj
Dikstry_Floyd.exe: CMakeFiles/Dikstry_Floyd.dir/build.make
Dikstry_Floyd.exe: CMakeFiles/Dikstry_Floyd.dir/linklibs.rsp
Dikstry_Floyd.exe: CMakeFiles/Dikstry_Floyd.dir/objects1.rsp
Dikstry_Floyd.exe: CMakeFiles/Dikstry_Floyd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\git_repos\DataStructures\Graph\Kruskal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Dikstry_Floyd.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Dikstry_Floyd.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dikstry_Floyd.dir/build: Dikstry_Floyd.exe

.PHONY : CMakeFiles/Dikstry_Floyd.dir/build

CMakeFiles/Dikstry_Floyd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Dikstry_Floyd.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Dikstry_Floyd.dir/clean

CMakeFiles/Dikstry_Floyd.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\git_repos\DataStructures\Graph\Kruskal C:\git_repos\DataStructures\Graph\Kruskal C:\git_repos\DataStructures\Graph\Kruskal\cmake-build-debug C:\git_repos\DataStructures\Graph\Kruskal\cmake-build-debug C:\git_repos\DataStructures\Graph\Kruskal\cmake-build-debug\CMakeFiles\Dikstry_Floyd.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dikstry_Floyd.dir/depend

