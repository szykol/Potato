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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /var/users/szykol/potato

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/users/szykol/potato/debug

# Include any dependencies generated for this target.
include test/CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/Test.dir/flags.make

test/CMakeFiles/Test.dir/Test.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/Test.cpp.o: ../test/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/users/szykol/potato/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/Test.dir/Test.cpp.o"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/Test.cpp.o -c /var/users/szykol/potato/test/Test.cpp

test/CMakeFiles/Test.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/Test.cpp.i"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/users/szykol/potato/test/Test.cpp > CMakeFiles/Test.dir/Test.cpp.i

test/CMakeFiles/Test.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/Test.cpp.s"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/users/szykol/potato/test/Test.cpp -o CMakeFiles/Test.dir/Test.cpp.s

test/CMakeFiles/Test.dir/TestEndpoint.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/TestEndpoint.cpp.o: ../test/TestEndpoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/users/szykol/potato/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/Test.dir/TestEndpoint.cpp.o"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/TestEndpoint.cpp.o -c /var/users/szykol/potato/test/TestEndpoint.cpp

test/CMakeFiles/Test.dir/TestEndpoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/TestEndpoint.cpp.i"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/users/szykol/potato/test/TestEndpoint.cpp > CMakeFiles/Test.dir/TestEndpoint.cpp.i

test/CMakeFiles/Test.dir/TestEndpoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/TestEndpoint.cpp.s"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/users/szykol/potato/test/TestEndpoint.cpp -o CMakeFiles/Test.dir/TestEndpoint.cpp.s

test/CMakeFiles/Test.dir/TestRequest.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/TestRequest.cpp.o: ../test/TestRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/users/szykol/potato/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/Test.dir/TestRequest.cpp.o"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/TestRequest.cpp.o -c /var/users/szykol/potato/test/TestRequest.cpp

test/CMakeFiles/Test.dir/TestRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/TestRequest.cpp.i"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/users/szykol/potato/test/TestRequest.cpp > CMakeFiles/Test.dir/TestRequest.cpp.i

test/CMakeFiles/Test.dir/TestRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/TestRequest.cpp.s"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/users/szykol/potato/test/TestRequest.cpp -o CMakeFiles/Test.dir/TestRequest.cpp.s

test/CMakeFiles/Test.dir/TestUtill.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/TestUtill.cpp.o: ../test/TestUtill.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/users/szykol/potato/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/Test.dir/TestUtill.cpp.o"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/TestUtill.cpp.o -c /var/users/szykol/potato/test/TestUtill.cpp

test/CMakeFiles/Test.dir/TestUtill.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/TestUtill.cpp.i"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/users/szykol/potato/test/TestUtill.cpp > CMakeFiles/Test.dir/TestUtill.cpp.i

test/CMakeFiles/Test.dir/TestUtill.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/TestUtill.cpp.s"
	cd /var/users/szykol/potato/debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/users/szykol/potato/test/TestUtill.cpp -o CMakeFiles/Test.dir/TestUtill.cpp.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/Test.cpp.o" \
"CMakeFiles/Test.dir/TestEndpoint.cpp.o" \
"CMakeFiles/Test.dir/TestRequest.cpp.o" \
"CMakeFiles/Test.dir/TestUtill.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

test/Test: test/CMakeFiles/Test.dir/Test.cpp.o
test/Test: test/CMakeFiles/Test.dir/TestEndpoint.cpp.o
test/Test: test/CMakeFiles/Test.dir/TestRequest.cpp.o
test/Test: test/CMakeFiles/Test.dir/TestUtill.cpp.o
test/Test: test/CMakeFiles/Test.dir/build.make
test/Test: lib/libgtest_main.a
test/Test: libPotato.a
test/Test: lib/libgtest.a
test/Test: spdlog/libspdlog.a
test/Test: test/CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/users/szykol/potato/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Test"
	cd /var/users/szykol/potato/debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/Test.dir/build: test/Test

.PHONY : test/CMakeFiles/Test.dir/build

test/CMakeFiles/Test.dir/clean:
	cd /var/users/szykol/potato/debug/test && $(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/Test.dir/clean

test/CMakeFiles/Test.dir/depend:
	cd /var/users/szykol/potato/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/users/szykol/potato /var/users/szykol/potato/test /var/users/szykol/potato/debug /var/users/szykol/potato/debug/test /var/users/szykol/potato/debug/test/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/Test.dir/depend

