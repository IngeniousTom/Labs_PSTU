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
CMAKE_COMMAND = /cygdrive/c/Users/Artyom/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Artyom/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LR_13_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LR_13_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LR_13_3.dir/flags.make

CMakeFiles/LR_13_3.dir/main.cpp.o: CMakeFiles/LR_13_3.dir/flags.make
CMakeFiles/LR_13_3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LR_13_3.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LR_13_3.dir/main.cpp.o -c "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/main.cpp"

CMakeFiles/LR_13_3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LR_13_3.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/main.cpp" > CMakeFiles/LR_13_3.dir/main.cpp.i

CMakeFiles/LR_13_3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LR_13_3.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/main.cpp" -o CMakeFiles/LR_13_3.dir/main.cpp.s

CMakeFiles/LR_13_3.dir/Time.cpp.o: CMakeFiles/LR_13_3.dir/flags.make
CMakeFiles/LR_13_3.dir/Time.cpp.o: ../Time.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LR_13_3.dir/Time.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LR_13_3.dir/Time.cpp.o -c "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/Time.cpp"

CMakeFiles/LR_13_3.dir/Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LR_13_3.dir/Time.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/Time.cpp" > CMakeFiles/LR_13_3.dir/Time.cpp.i

CMakeFiles/LR_13_3.dir/Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LR_13_3.dir/Time.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/Time.cpp" -o CMakeFiles/LR_13_3.dir/Time.cpp.s

# Object files for target LR_13_3
LR_13_3_OBJECTS = \
"CMakeFiles/LR_13_3.dir/main.cpp.o" \
"CMakeFiles/LR_13_3.dir/Time.cpp.o"

# External object files for target LR_13_3
LR_13_3_EXTERNAL_OBJECTS =

LR_13_3.exe: CMakeFiles/LR_13_3.dir/main.cpp.o
LR_13_3.exe: CMakeFiles/LR_13_3.dir/Time.cpp.o
LR_13_3.exe: CMakeFiles/LR_13_3.dir/build.make
LR_13_3.exe: CMakeFiles/LR_13_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LR_13_3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LR_13_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LR_13_3.dir/build: LR_13_3.exe

.PHONY : CMakeFiles/LR_13_3.dir/build

CMakeFiles/LR_13_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LR_13_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LR_13_3.dir/clean

CMakeFiles/LR_13_3.dir/depend:
	cd "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3" "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3" "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/cmake-build-debug" "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/cmake-build-debug" "/cygdrive/d/Stuff/Programming/C & C++/OAIP/1-2/LR-13-3/cmake-build-debug/CMakeFiles/LR_13_3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LR_13_3.dir/depend

