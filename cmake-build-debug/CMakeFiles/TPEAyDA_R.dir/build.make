# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\fermi\CLionProjects\TPEAyDA_R

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\fermi\CLionProjects\TPEAyDA_R\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TPEAyDA_R.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TPEAyDA_R.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TPEAyDA_R.dir/flags.make

CMakeFiles/TPEAyDA_R.dir/main.cpp.obj: CMakeFiles/TPEAyDA_R.dir/flags.make
CMakeFiles/TPEAyDA_R.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fermi\CLionProjects\TPEAyDA_R\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TPEAyDA_R.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TPEAyDA_R.dir\main.cpp.obj -c C:\Users\fermi\CLionProjects\TPEAyDA_R\main.cpp

CMakeFiles/TPEAyDA_R.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPEAyDA_R.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\fermi\CLionProjects\TPEAyDA_R\main.cpp > CMakeFiles\TPEAyDA_R.dir\main.cpp.i

CMakeFiles/TPEAyDA_R.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPEAyDA_R.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\fermi\CLionProjects\TPEAyDA_R\main.cpp -o CMakeFiles\TPEAyDA_R.dir\main.cpp.s

CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.obj: CMakeFiles/TPEAyDA_R.dir/flags.make
CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.obj: ../Canciones.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fermi\CLionProjects\TPEAyDA_R\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TPEAyDA_R.dir\Canciones.cpp.obj -c C:\Users\fermi\CLionProjects\TPEAyDA_R\Canciones.cpp

CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\fermi\CLionProjects\TPEAyDA_R\Canciones.cpp > CMakeFiles\TPEAyDA_R.dir\Canciones.cpp.i

CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\fermi\CLionProjects\TPEAyDA_R\Canciones.cpp -o CMakeFiles\TPEAyDA_R.dir\Canciones.cpp.s

# Object files for target TPEAyDA_R
TPEAyDA_R_OBJECTS = \
"CMakeFiles/TPEAyDA_R.dir/main.cpp.obj" \
"CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.obj"

# External object files for target TPEAyDA_R
TPEAyDA_R_EXTERNAL_OBJECTS =

TPEAyDA_R.exe: CMakeFiles/TPEAyDA_R.dir/main.cpp.obj
TPEAyDA_R.exe: CMakeFiles/TPEAyDA_R.dir/Canciones.cpp.obj
TPEAyDA_R.exe: CMakeFiles/TPEAyDA_R.dir/build.make
TPEAyDA_R.exe: CMakeFiles/TPEAyDA_R.dir/linklibs.rsp
TPEAyDA_R.exe: CMakeFiles/TPEAyDA_R.dir/objects1.rsp
TPEAyDA_R.exe: CMakeFiles/TPEAyDA_R.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\fermi\CLionProjects\TPEAyDA_R\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TPEAyDA_R.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TPEAyDA_R.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TPEAyDA_R.dir/build: TPEAyDA_R.exe
.PHONY : CMakeFiles/TPEAyDA_R.dir/build

CMakeFiles/TPEAyDA_R.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TPEAyDA_R.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TPEAyDA_R.dir/clean

CMakeFiles/TPEAyDA_R.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\fermi\CLionProjects\TPEAyDA_R C:\Users\fermi\CLionProjects\TPEAyDA_R C:\Users\fermi\CLionProjects\TPEAyDA_R\cmake-build-debug C:\Users\fermi\CLionProjects\TPEAyDA_R\cmake-build-debug C:\Users\fermi\CLionProjects\TPEAyDA_R\cmake-build-debug\CMakeFiles\TPEAyDA_R.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TPEAyDA_R.dir/depend

