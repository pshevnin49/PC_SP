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
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pshev\git\PC_SP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pshev\git\PC_SP\build

# Include any dependencies generated for this target.
include CMakeFiles/PC_SP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PC_SP.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PC_SP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PC_SP.dir/flags.make

CMakeFiles/PC_SP.dir/main.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/main.c.obj: ../main.c
CMakeFiles/PC_SP.dir/main.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PC_SP.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/main.c.obj -MF CMakeFiles\PC_SP.dir\main.c.obj.d -o CMakeFiles\PC_SP.dir\main.c.obj -c C:\Users\pshev\git\PC_SP\main.c

CMakeFiles/PC_SP.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\main.c > CMakeFiles\PC_SP.dir\main.c.i

CMakeFiles/PC_SP.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\main.c -o CMakeFiles\PC_SP.dir\main.c.s

CMakeFiles/PC_SP.dir/parameters.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/parameters.c.obj: ../parameters.c
CMakeFiles/PC_SP.dir/parameters.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/PC_SP.dir/parameters.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/parameters.c.obj -MF CMakeFiles\PC_SP.dir\parameters.c.obj.d -o CMakeFiles\PC_SP.dir\parameters.c.obj -c C:\Users\pshev\git\PC_SP\parameters.c

CMakeFiles/PC_SP.dir/parameters.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/parameters.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\parameters.c > CMakeFiles\PC_SP.dir\parameters.c.i

CMakeFiles/PC_SP.dir/parameters.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/parameters.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\parameters.c -o CMakeFiles\PC_SP.dir\parameters.c.s

CMakeFiles/PC_SP.dir/out_file.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/out_file.c.obj: ../out_file.c
CMakeFiles/PC_SP.dir/out_file.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/PC_SP.dir/out_file.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/out_file.c.obj -MF CMakeFiles\PC_SP.dir\out_file.c.obj.d -o CMakeFiles\PC_SP.dir\out_file.c.obj -c C:\Users\pshev\git\PC_SP\out_file.c

CMakeFiles/PC_SP.dir/out_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/out_file.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\out_file.c > CMakeFiles\PC_SP.dir\out_file.c.i

CMakeFiles/PC_SP.dir/out_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/out_file.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\out_file.c -o CMakeFiles\PC_SP.dir\out_file.c.s

CMakeFiles/PC_SP.dir/algorithm.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/algorithm.c.obj: ../algorithm.c
CMakeFiles/PC_SP.dir/algorithm.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/PC_SP.dir/algorithm.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/algorithm.c.obj -MF CMakeFiles\PC_SP.dir\algorithm.c.obj.d -o CMakeFiles\PC_SP.dir\algorithm.c.obj -c C:\Users\pshev\git\PC_SP\algorithm.c

CMakeFiles/PC_SP.dir/algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/algorithm.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\algorithm.c > CMakeFiles\PC_SP.dir\algorithm.c.i

CMakeFiles/PC_SP.dir/algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/algorithm.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\algorithm.c -o CMakeFiles\PC_SP.dir\algorithm.c.s

CMakeFiles/PC_SP.dir/bfs.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/bfs.c.obj: ../bfs.c
CMakeFiles/PC_SP.dir/bfs.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/PC_SP.dir/bfs.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/bfs.c.obj -MF CMakeFiles\PC_SP.dir\bfs.c.obj.d -o CMakeFiles\PC_SP.dir\bfs.c.obj -c C:\Users\pshev\git\PC_SP\bfs.c

CMakeFiles/PC_SP.dir/bfs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/bfs.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\bfs.c > CMakeFiles\PC_SP.dir\bfs.c.i

CMakeFiles/PC_SP.dir/bfs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/bfs.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\bfs.c -o CMakeFiles\PC_SP.dir\bfs.c.s

CMakeFiles/PC_SP.dir/queue.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/queue.c.obj: ../queue.c
CMakeFiles/PC_SP.dir/queue.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/PC_SP.dir/queue.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/queue.c.obj -MF CMakeFiles\PC_SP.dir\queue.c.obj.d -o CMakeFiles\PC_SP.dir\queue.c.obj -c C:\Users\pshev\git\PC_SP\queue.c

CMakeFiles/PC_SP.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/queue.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\queue.c > CMakeFiles\PC_SP.dir\queue.c.i

CMakeFiles/PC_SP.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/queue.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\queue.c -o CMakeFiles\PC_SP.dir\queue.c.s

CMakeFiles/PC_SP.dir/loader.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/loader.c.obj: ../loader.c
CMakeFiles/PC_SP.dir/loader.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/PC_SP.dir/loader.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/loader.c.obj -MF CMakeFiles\PC_SP.dir\loader.c.obj.d -o CMakeFiles\PC_SP.dir\loader.c.obj -c C:\Users\pshev\git\PC_SP\loader.c

CMakeFiles/PC_SP.dir/loader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/loader.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\loader.c > CMakeFiles\PC_SP.dir\loader.c.i

CMakeFiles/PC_SP.dir/loader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/loader.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\loader.c -o CMakeFiles\PC_SP.dir\loader.c.s

CMakeFiles/PC_SP.dir/vector.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/vector.c.obj: ../vector.c
CMakeFiles/PC_SP.dir/vector.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/PC_SP.dir/vector.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/vector.c.obj -MF CMakeFiles\PC_SP.dir\vector.c.obj.d -o CMakeFiles\PC_SP.dir\vector.c.obj -c C:\Users\pshev\git\PC_SP\vector.c

CMakeFiles/PC_SP.dir/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/vector.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\vector.c > CMakeFiles\PC_SP.dir\vector.c.i

CMakeFiles/PC_SP.dir/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/vector.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\vector.c -o CMakeFiles\PC_SP.dir\vector.c.s

CMakeFiles/PC_SP.dir/node.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/node.c.obj: ../node.c
CMakeFiles/PC_SP.dir/node.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/PC_SP.dir/node.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/node.c.obj -MF CMakeFiles\PC_SP.dir\node.c.obj.d -o CMakeFiles\PC_SP.dir\node.c.obj -c C:\Users\pshev\git\PC_SP\node.c

CMakeFiles/PC_SP.dir/node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/node.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\node.c > CMakeFiles\PC_SP.dir\node.c.i

CMakeFiles/PC_SP.dir/node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/node.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\node.c -o CMakeFiles\PC_SP.dir\node.c.s

CMakeFiles/PC_SP.dir/edge.c.obj: CMakeFiles/PC_SP.dir/flags.make
CMakeFiles/PC_SP.dir/edge.c.obj: ../edge.c
CMakeFiles/PC_SP.dir/edge.c.obj: CMakeFiles/PC_SP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/PC_SP.dir/edge.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PC_SP.dir/edge.c.obj -MF CMakeFiles\PC_SP.dir\edge.c.obj.d -o CMakeFiles\PC_SP.dir\edge.c.obj -c C:\Users\pshev\git\PC_SP\edge.c

CMakeFiles/PC_SP.dir/edge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PC_SP.dir/edge.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pshev\git\PC_SP\edge.c > CMakeFiles\PC_SP.dir\edge.c.i

CMakeFiles/PC_SP.dir/edge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PC_SP.dir/edge.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pshev\git\PC_SP\edge.c -o CMakeFiles\PC_SP.dir\edge.c.s

# Object files for target PC_SP
PC_SP_OBJECTS = \
"CMakeFiles/PC_SP.dir/main.c.obj" \
"CMakeFiles/PC_SP.dir/parameters.c.obj" \
"CMakeFiles/PC_SP.dir/out_file.c.obj" \
"CMakeFiles/PC_SP.dir/algorithm.c.obj" \
"CMakeFiles/PC_SP.dir/bfs.c.obj" \
"CMakeFiles/PC_SP.dir/queue.c.obj" \
"CMakeFiles/PC_SP.dir/loader.c.obj" \
"CMakeFiles/PC_SP.dir/vector.c.obj" \
"CMakeFiles/PC_SP.dir/node.c.obj" \
"CMakeFiles/PC_SP.dir/edge.c.obj"

# External object files for target PC_SP
PC_SP_EXTERNAL_OBJECTS =

PC_SP.exe: CMakeFiles/PC_SP.dir/main.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/parameters.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/out_file.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/algorithm.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/bfs.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/queue.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/loader.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/vector.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/node.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/edge.c.obj
PC_SP.exe: CMakeFiles/PC_SP.dir/build.make
PC_SP.exe: CMakeFiles/PC_SP.dir/linklibs.rsp
PC_SP.exe: CMakeFiles/PC_SP.dir/objects1.rsp
PC_SP.exe: CMakeFiles/PC_SP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pshev\git\PC_SP\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable PC_SP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PC_SP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PC_SP.dir/build: PC_SP.exe
.PHONY : CMakeFiles/PC_SP.dir/build

CMakeFiles/PC_SP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PC_SP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PC_SP.dir/clean

CMakeFiles/PC_SP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pshev\git\PC_SP C:\Users\pshev\git\PC_SP C:\Users\pshev\git\PC_SP\build C:\Users\pshev\git\PC_SP\build C:\Users\pshev\git\PC_SP\build\CMakeFiles\PC_SP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PC_SP.dir/depend

