# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/61/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/61/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/saymon/CLionProjects/Proyecto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saymon/CLionProjects/Proyecto/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Proyecto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Proyecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proyecto.dir/flags.make

CMakeFiles/Proyecto.dir/main.cpp.o: CMakeFiles/Proyecto.dir/flags.make
CMakeFiles/Proyecto.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Proyecto.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto.dir/main.cpp.o -c /home/saymon/CLionProjects/Proyecto/main.cpp

CMakeFiles/Proyecto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saymon/CLionProjects/Proyecto/main.cpp > CMakeFiles/Proyecto.dir/main.cpp.i

CMakeFiles/Proyecto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saymon/CLionProjects/Proyecto/main.cpp -o CMakeFiles/Proyecto.dir/main.cpp.s

CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.o: CMakeFiles/Proyecto.dir/flags.make
CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.o: ../Tablero/Tablero.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.o -c /home/saymon/CLionProjects/Proyecto/Tablero/Tablero.cpp

CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saymon/CLionProjects/Proyecto/Tablero/Tablero.cpp > CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.i

CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saymon/CLionProjects/Proyecto/Tablero/Tablero.cpp -o CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.s

CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.o: CMakeFiles/Proyecto.dir/flags.make
CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.o: ../Tablero/Elemento.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.o -c /home/saymon/CLionProjects/Proyecto/Tablero/Elemento.cpp

CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saymon/CLionProjects/Proyecto/Tablero/Elemento.cpp > CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.i

CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saymon/CLionProjects/Proyecto/Tablero/Elemento.cpp -o CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.s

CMakeFiles/Proyecto.dir/Prueba.cpp.o: CMakeFiles/Proyecto.dir/flags.make
CMakeFiles/Proyecto.dir/Prueba.cpp.o: ../Prueba.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Proyecto.dir/Prueba.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto.dir/Prueba.cpp.o -c /home/saymon/CLionProjects/Proyecto/Prueba.cpp

CMakeFiles/Proyecto.dir/Prueba.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto.dir/Prueba.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saymon/CLionProjects/Proyecto/Prueba.cpp > CMakeFiles/Proyecto.dir/Prueba.cpp.i

CMakeFiles/Proyecto.dir/Prueba.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto.dir/Prueba.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saymon/CLionProjects/Proyecto/Prueba.cpp -o CMakeFiles/Proyecto.dir/Prueba.cpp.s

CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.o: CMakeFiles/Proyecto.dir/flags.make
CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.o: ../Dealer/Ficha.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.o -c /home/saymon/CLionProjects/Proyecto/Dealer/Ficha.cpp

CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saymon/CLionProjects/Proyecto/Dealer/Ficha.cpp > CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.i

CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saymon/CLionProjects/Proyecto/Dealer/Ficha.cpp -o CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.s

CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.o: CMakeFiles/Proyecto.dir/flags.make
CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.o: ../Dealer/Dealer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.o -c /home/saymon/CLionProjects/Proyecto/Dealer/Dealer.cpp

CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saymon/CLionProjects/Proyecto/Dealer/Dealer.cpp > CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.i

CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saymon/CLionProjects/Proyecto/Dealer/Dealer.cpp -o CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.s

CMakeFiles/Proyecto.dir/Estructuras/List.cpp.o: CMakeFiles/Proyecto.dir/flags.make
CMakeFiles/Proyecto.dir/Estructuras/List.cpp.o: ../Estructuras/List.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Proyecto.dir/Estructuras/List.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto.dir/Estructuras/List.cpp.o -c /home/saymon/CLionProjects/Proyecto/Estructuras/List.cpp

CMakeFiles/Proyecto.dir/Estructuras/List.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto.dir/Estructuras/List.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saymon/CLionProjects/Proyecto/Estructuras/List.cpp > CMakeFiles/Proyecto.dir/Estructuras/List.cpp.i

CMakeFiles/Proyecto.dir/Estructuras/List.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto.dir/Estructuras/List.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saymon/CLionProjects/Proyecto/Estructuras/List.cpp -o CMakeFiles/Proyecto.dir/Estructuras/List.cpp.s

CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.o: CMakeFiles/Proyecto.dir/flags.make
CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.o: ../Estructuras/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.o -c /home/saymon/CLionProjects/Proyecto/Estructuras/Node.cpp

CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saymon/CLionProjects/Proyecto/Estructuras/Node.cpp > CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.i

CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saymon/CLionProjects/Proyecto/Estructuras/Node.cpp -o CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.s

# Object files for target Proyecto
Proyecto_OBJECTS = \
"CMakeFiles/Proyecto.dir/main.cpp.o" \
"CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.o" \
"CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.o" \
"CMakeFiles/Proyecto.dir/Prueba.cpp.o" \
"CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.o" \
"CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.o" \
"CMakeFiles/Proyecto.dir/Estructuras/List.cpp.o" \
"CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.o"

# External object files for target Proyecto
Proyecto_EXTERNAL_OBJECTS =

Proyecto: CMakeFiles/Proyecto.dir/main.cpp.o
Proyecto: CMakeFiles/Proyecto.dir/Tablero/Tablero.cpp.o
Proyecto: CMakeFiles/Proyecto.dir/Tablero/Elemento.cpp.o
Proyecto: CMakeFiles/Proyecto.dir/Prueba.cpp.o
Proyecto: CMakeFiles/Proyecto.dir/Dealer/Ficha.cpp.o
Proyecto: CMakeFiles/Proyecto.dir/Dealer/Dealer.cpp.o
Proyecto: CMakeFiles/Proyecto.dir/Estructuras/List.cpp.o
Proyecto: CMakeFiles/Proyecto.dir/Estructuras/Node.cpp.o
Proyecto: CMakeFiles/Proyecto.dir/build.make
Proyecto: CMakeFiles/Proyecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Proyecto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Proyecto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proyecto.dir/build: Proyecto

.PHONY : CMakeFiles/Proyecto.dir/build

CMakeFiles/Proyecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Proyecto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Proyecto.dir/clean

CMakeFiles/Proyecto.dir/depend:
	cd /home/saymon/CLionProjects/Proyecto/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saymon/CLionProjects/Proyecto /home/saymon/CLionProjects/Proyecto /home/saymon/CLionProjects/Proyecto/cmake-build-debug /home/saymon/CLionProjects/Proyecto/cmake-build-debug /home/saymon/CLionProjects/Proyecto/cmake-build-debug/CMakeFiles/Proyecto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Proyecto.dir/depend
