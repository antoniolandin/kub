# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/practica2/fileManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/practica2/fileManager

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/servidor/main_servidor.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/servidor/main_servidor.cpp.o: servidor/main_servidor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/practica2/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/servidor/main_servidor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/servidor/main_servidor.cpp.o -c /home/ubuntu/practica2/fileManager/servidor/main_servidor.cpp

CMakeFiles/server.dir/servidor/main_servidor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/servidor/main_servidor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/practica2/fileManager/servidor/main_servidor.cpp > CMakeFiles/server.dir/servidor/main_servidor.cpp.i

CMakeFiles/server.dir/servidor/main_servidor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/servidor/main_servidor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/practica2/fileManager/servidor/main_servidor.cpp -o CMakeFiles/server.dir/servidor/main_servidor.cpp.s

CMakeFiles/server.dir/servidor/main_servidor.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/servidor/main_servidor.cpp.o.requires

CMakeFiles/server.dir/servidor/main_servidor.cpp.o.provides: CMakeFiles/server.dir/servidor/main_servidor.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/servidor/main_servidor.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/servidor/main_servidor.cpp.o.provides

CMakeFiles/server.dir/servidor/main_servidor.cpp.o.provides.build: CMakeFiles/server.dir/servidor/main_servidor.cpp.o


CMakeFiles/server.dir/servidor/serverFileManager.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/servidor/serverFileManager.cpp.o: servidor/serverFileManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/practica2/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/servidor/serverFileManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/servidor/serverFileManager.cpp.o -c /home/ubuntu/practica2/fileManager/servidor/serverFileManager.cpp

CMakeFiles/server.dir/servidor/serverFileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/servidor/serverFileManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/practica2/fileManager/servidor/serverFileManager.cpp > CMakeFiles/server.dir/servidor/serverFileManager.cpp.i

CMakeFiles/server.dir/servidor/serverFileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/servidor/serverFileManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/practica2/fileManager/servidor/serverFileManager.cpp -o CMakeFiles/server.dir/servidor/serverFileManager.cpp.s

CMakeFiles/server.dir/servidor/serverFileManager.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/servidor/serverFileManager.cpp.o.requires

CMakeFiles/server.dir/servidor/serverFileManager.cpp.o.provides: CMakeFiles/server.dir/servidor/serverFileManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/servidor/serverFileManager.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/servidor/serverFileManager.cpp.o.provides

CMakeFiles/server.dir/servidor/serverFileManager.cpp.o.provides.build: CMakeFiles/server.dir/servidor/serverFileManager.cpp.o


CMakeFiles/server.dir/servidor/filemanager.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/servidor/filemanager.cpp.o: servidor/filemanager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/practica2/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/servidor/filemanager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/servidor/filemanager.cpp.o -c /home/ubuntu/practica2/fileManager/servidor/filemanager.cpp

CMakeFiles/server.dir/servidor/filemanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/servidor/filemanager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/practica2/fileManager/servidor/filemanager.cpp > CMakeFiles/server.dir/servidor/filemanager.cpp.i

CMakeFiles/server.dir/servidor/filemanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/servidor/filemanager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/practica2/fileManager/servidor/filemanager.cpp -o CMakeFiles/server.dir/servidor/filemanager.cpp.s

CMakeFiles/server.dir/servidor/filemanager.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/servidor/filemanager.cpp.o.requires

CMakeFiles/server.dir/servidor/filemanager.cpp.o.provides: CMakeFiles/server.dir/servidor/filemanager.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/servidor/filemanager.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/servidor/filemanager.cpp.o.provides

CMakeFiles/server.dir/servidor/filemanager.cpp.o.provides.build: CMakeFiles/server.dir/servidor/filemanager.cpp.o


CMakeFiles/server.dir/servidor/utils.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/servidor/utils.cpp.o: servidor/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/practica2/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/servidor/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/servidor/utils.cpp.o -c /home/ubuntu/practica2/fileManager/servidor/utils.cpp

CMakeFiles/server.dir/servidor/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/servidor/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/practica2/fileManager/servidor/utils.cpp > CMakeFiles/server.dir/servidor/utils.cpp.i

CMakeFiles/server.dir/servidor/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/servidor/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/practica2/fileManager/servidor/utils.cpp -o CMakeFiles/server.dir/servidor/utils.cpp.s

CMakeFiles/server.dir/servidor/utils.cpp.o.requires:

.PHONY : CMakeFiles/server.dir/servidor/utils.cpp.o.requires

CMakeFiles/server.dir/servidor/utils.cpp.o.provides: CMakeFiles/server.dir/servidor/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/servidor/utils.cpp.o.provides.build
.PHONY : CMakeFiles/server.dir/servidor/utils.cpp.o.provides

CMakeFiles/server.dir/servidor/utils.cpp.o.provides.build: CMakeFiles/server.dir/servidor/utils.cpp.o


# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/servidor/main_servidor.cpp.o" \
"CMakeFiles/server.dir/servidor/serverFileManager.cpp.o" \
"CMakeFiles/server.dir/servidor/filemanager.cpp.o" \
"CMakeFiles/server.dir/servidor/utils.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/servidor/main_servidor.cpp.o
server: CMakeFiles/server.dir/servidor/serverFileManager.cpp.o
server: CMakeFiles/server.dir/servidor/filemanager.cpp.o
server: CMakeFiles/server.dir/servidor/utils.cpp.o
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/practica2/fileManager/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/servidor/main_servidor.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/servidor/serverFileManager.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/servidor/filemanager.cpp.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/servidor/utils.cpp.o.requires

.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/ubuntu/practica2/fileManager && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/practica2/fileManager /home/ubuntu/practica2/fileManager /home/ubuntu/practica2/fileManager /home/ubuntu/practica2/fileManager /home/ubuntu/practica2/fileManager/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

