# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/thomii/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.6693.114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/thomii/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.6693.114/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/cpptris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpptris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpptris.dir/flags.make

CMakeFiles/cpptris.dir/src/main.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpptris.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/main.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/main.cpp"

CMakeFiles/cpptris.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/main.cpp" > CMakeFiles/cpptris.dir/src/main.cpp.i

CMakeFiles/cpptris.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/main.cpp" -o CMakeFiles/cpptris.dir/src/main.cpp.s

CMakeFiles/cpptris.dir/src/piece.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/piece.cpp.o: ../src/piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpptris.dir/src/piece.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/piece.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/piece.cpp"

CMakeFiles/cpptris.dir/src/piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/piece.cpp" > CMakeFiles/cpptris.dir/src/piece.cpp.i

CMakeFiles/cpptris.dir/src/piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/piece.cpp" -o CMakeFiles/cpptris.dir/src/piece.cpp.s

CMakeFiles/cpptris.dir/src/common.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/common.cpp.o: ../src/common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cpptris.dir/src/common.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/common.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/common.cpp"

CMakeFiles/cpptris.dir/src/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/common.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/common.cpp" > CMakeFiles/cpptris.dir/src/common.cpp.i

CMakeFiles/cpptris.dir/src/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/common.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/common.cpp" -o CMakeFiles/cpptris.dir/src/common.cpp.s

CMakeFiles/cpptris.dir/src/lobby.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/lobby.cpp.o: ../src/lobby.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cpptris.dir/src/lobby.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/lobby.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/lobby.cpp"

CMakeFiles/cpptris.dir/src/lobby.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/lobby.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/lobby.cpp" > CMakeFiles/cpptris.dir/src/lobby.cpp.i

CMakeFiles/cpptris.dir/src/lobby.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/lobby.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/lobby.cpp" -o CMakeFiles/cpptris.dir/src/lobby.cpp.s

CMakeFiles/cpptris.dir/src/game.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cpptris.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/game.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/game.cpp"

CMakeFiles/cpptris.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/game.cpp" > CMakeFiles/cpptris.dir/src/game.cpp.i

CMakeFiles/cpptris.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/game.cpp" -o CMakeFiles/cpptris.dir/src/game.cpp.s

CMakeFiles/cpptris.dir/src/network/client.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/network/client.cpp.o: ../src/network/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cpptris.dir/src/network/client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/network/client.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/client.cpp"

CMakeFiles/cpptris.dir/src/network/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/network/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/client.cpp" > CMakeFiles/cpptris.dir/src/network/client.cpp.i

CMakeFiles/cpptris.dir/src/network/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/network/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/client.cpp" -o CMakeFiles/cpptris.dir/src/network/client.cpp.s

CMakeFiles/cpptris.dir/src/network/connection.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/network/connection.cpp.o: ../src/network/connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cpptris.dir/src/network/connection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/network/connection.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/connection.cpp"

CMakeFiles/cpptris.dir/src/network/connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/network/connection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/connection.cpp" > CMakeFiles/cpptris.dir/src/network/connection.cpp.i

CMakeFiles/cpptris.dir/src/network/connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/network/connection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/connection.cpp" -o CMakeFiles/cpptris.dir/src/network/connection.cpp.s

CMakeFiles/cpptris.dir/src/network/server.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/network/server.cpp.o: ../src/network/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cpptris.dir/src/network/server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/network/server.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/server.cpp"

CMakeFiles/cpptris.dir/src/network/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/network/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/server.cpp" > CMakeFiles/cpptris.dir/src/network/server.cpp.i

CMakeFiles/cpptris.dir/src/network/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/network/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/network/server.cpp" -o CMakeFiles/cpptris.dir/src/network/server.cpp.s

CMakeFiles/cpptris.dir/src/keyboard.cpp.o: CMakeFiles/cpptris.dir/flags.make
CMakeFiles/cpptris.dir/src/keyboard.cpp.o: ../src/keyboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cpptris.dir/src/keyboard.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpptris.dir/src/keyboard.cpp.o -c "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/keyboard.cpp"

CMakeFiles/cpptris.dir/src/keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpptris.dir/src/keyboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/keyboard.cpp" > CMakeFiles/cpptris.dir/src/keyboard.cpp.i

CMakeFiles/cpptris.dir/src/keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpptris.dir/src/keyboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/src/keyboard.cpp" -o CMakeFiles/cpptris.dir/src/keyboard.cpp.s

# Object files for target cpptris
cpptris_OBJECTS = \
"CMakeFiles/cpptris.dir/src/main.cpp.o" \
"CMakeFiles/cpptris.dir/src/piece.cpp.o" \
"CMakeFiles/cpptris.dir/src/common.cpp.o" \
"CMakeFiles/cpptris.dir/src/lobby.cpp.o" \
"CMakeFiles/cpptris.dir/src/game.cpp.o" \
"CMakeFiles/cpptris.dir/src/network/client.cpp.o" \
"CMakeFiles/cpptris.dir/src/network/connection.cpp.o" \
"CMakeFiles/cpptris.dir/src/network/server.cpp.o" \
"CMakeFiles/cpptris.dir/src/keyboard.cpp.o"

# External object files for target cpptris
cpptris_EXTERNAL_OBJECTS =

cpptris: CMakeFiles/cpptris.dir/src/main.cpp.o
cpptris: CMakeFiles/cpptris.dir/src/piece.cpp.o
cpptris: CMakeFiles/cpptris.dir/src/common.cpp.o
cpptris: CMakeFiles/cpptris.dir/src/lobby.cpp.o
cpptris: CMakeFiles/cpptris.dir/src/game.cpp.o
cpptris: CMakeFiles/cpptris.dir/src/network/client.cpp.o
cpptris: CMakeFiles/cpptris.dir/src/network/connection.cpp.o
cpptris: CMakeFiles/cpptris.dir/src/network/server.cpp.o
cpptris: CMakeFiles/cpptris.dir/src/keyboard.cpp.o
cpptris: CMakeFiles/cpptris.dir/build.make
cpptris: /usr/lib/x86_64-linux-gnu/libsfml-system.so
cpptris: /usr/lib/x86_64-linux-gnu/libsfml-window.so
cpptris: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
cpptris: /usr/lib/x86_64-linux-gnu/libsfml-network.so
cpptris: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
cpptris: CMakeFiles/cpptris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable cpptris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpptris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpptris.dir/build: cpptris

.PHONY : CMakeFiles/cpptris.dir/build

CMakeFiles/cpptris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpptris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpptris.dir/clean

CMakeFiles/cpptris.dir/depend:
	cd "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris" "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris" "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug" "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug" "/home/thomii/IT Stuffs/Study/20202/Network Programming/Capstone Project/cpptris/cmake-build-debug/CMakeFiles/cpptris.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/cpptris.dir/depend

