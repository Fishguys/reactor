# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/test/work/reactor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/test/work/reactor/build

# Include any dependencies generated for this target.
include CMakeFiles/log.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/log.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/log.dir/flags.make

CMakeFiles/log.dir/base/timestamp.cpp.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/base/timestamp.cpp.o: ../base/timestamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/log.dir/base/timestamp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/base/timestamp.cpp.o -c /home/test/work/reactor/base/timestamp.cpp

CMakeFiles/log.dir/base/timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/base/timestamp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/base/timestamp.cpp > CMakeFiles/log.dir/base/timestamp.cpp.i

CMakeFiles/log.dir/base/timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/base/timestamp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/base/timestamp.cpp -o CMakeFiles/log.dir/base/timestamp.cpp.s

CMakeFiles/log.dir/base/timestamp.cpp.o.requires:

.PHONY : CMakeFiles/log.dir/base/timestamp.cpp.o.requires

CMakeFiles/log.dir/base/timestamp.cpp.o.provides: CMakeFiles/log.dir/base/timestamp.cpp.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/base/timestamp.cpp.o.provides.build
.PHONY : CMakeFiles/log.dir/base/timestamp.cpp.o.provides

CMakeFiles/log.dir/base/timestamp.cpp.o.provides.build: CMakeFiles/log.dir/base/timestamp.cpp.o


CMakeFiles/log.dir/base/logging.cpp.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/base/logging.cpp.o: ../base/logging.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/log.dir/base/logging.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/base/logging.cpp.o -c /home/test/work/reactor/base/logging.cpp

CMakeFiles/log.dir/base/logging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/base/logging.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/base/logging.cpp > CMakeFiles/log.dir/base/logging.cpp.i

CMakeFiles/log.dir/base/logging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/base/logging.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/base/logging.cpp -o CMakeFiles/log.dir/base/logging.cpp.s

CMakeFiles/log.dir/base/logging.cpp.o.requires:

.PHONY : CMakeFiles/log.dir/base/logging.cpp.o.requires

CMakeFiles/log.dir/base/logging.cpp.o.provides: CMakeFiles/log.dir/base/logging.cpp.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/base/logging.cpp.o.provides.build
.PHONY : CMakeFiles/log.dir/base/logging.cpp.o.provides

CMakeFiles/log.dir/base/logging.cpp.o.provides.build: CMakeFiles/log.dir/base/logging.cpp.o


CMakeFiles/log.dir/base/logstream.cpp.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/base/logstream.cpp.o: ../base/logstream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/log.dir/base/logstream.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/base/logstream.cpp.o -c /home/test/work/reactor/base/logstream.cpp

CMakeFiles/log.dir/base/logstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/base/logstream.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/base/logstream.cpp > CMakeFiles/log.dir/base/logstream.cpp.i

CMakeFiles/log.dir/base/logstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/base/logstream.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/base/logstream.cpp -o CMakeFiles/log.dir/base/logstream.cpp.s

CMakeFiles/log.dir/base/logstream.cpp.o.requires:

.PHONY : CMakeFiles/log.dir/base/logstream.cpp.o.requires

CMakeFiles/log.dir/base/logstream.cpp.o.provides: CMakeFiles/log.dir/base/logstream.cpp.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/base/logstream.cpp.o.provides.build
.PHONY : CMakeFiles/log.dir/base/logstream.cpp.o.provides

CMakeFiles/log.dir/base/logstream.cpp.o.provides.build: CMakeFiles/log.dir/base/logstream.cpp.o


CMakeFiles/log.dir/s07/Buffer.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/Buffer.cc.o: ../s07/Buffer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/log.dir/s07/Buffer.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/Buffer.cc.o -c /home/test/work/reactor/s07/Buffer.cc

CMakeFiles/log.dir/s07/Buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/Buffer.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/Buffer.cc > CMakeFiles/log.dir/s07/Buffer.cc.i

CMakeFiles/log.dir/s07/Buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/Buffer.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/Buffer.cc -o CMakeFiles/log.dir/s07/Buffer.cc.s

CMakeFiles/log.dir/s07/Buffer.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/Buffer.cc.o.requires

CMakeFiles/log.dir/s07/Buffer.cc.o.provides: CMakeFiles/log.dir/s07/Buffer.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/Buffer.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/Buffer.cc.o.provides

CMakeFiles/log.dir/s07/Buffer.cc.o.provides.build: CMakeFiles/log.dir/s07/Buffer.cc.o


CMakeFiles/log.dir/s07/EventLoop.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/EventLoop.cc.o: ../s07/EventLoop.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/log.dir/s07/EventLoop.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/EventLoop.cc.o -c /home/test/work/reactor/s07/EventLoop.cc

CMakeFiles/log.dir/s07/EventLoop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/EventLoop.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/EventLoop.cc > CMakeFiles/log.dir/s07/EventLoop.cc.i

CMakeFiles/log.dir/s07/EventLoop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/EventLoop.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/EventLoop.cc -o CMakeFiles/log.dir/s07/EventLoop.cc.s

CMakeFiles/log.dir/s07/EventLoop.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/EventLoop.cc.o.requires

CMakeFiles/log.dir/s07/EventLoop.cc.o.provides: CMakeFiles/log.dir/s07/EventLoop.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/EventLoop.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/EventLoop.cc.o.provides

CMakeFiles/log.dir/s07/EventLoop.cc.o.provides.build: CMakeFiles/log.dir/s07/EventLoop.cc.o


CMakeFiles/log.dir/s07/Channel.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/Channel.cc.o: ../s07/Channel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/log.dir/s07/Channel.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/Channel.cc.o -c /home/test/work/reactor/s07/Channel.cc

CMakeFiles/log.dir/s07/Channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/Channel.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/Channel.cc > CMakeFiles/log.dir/s07/Channel.cc.i

CMakeFiles/log.dir/s07/Channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/Channel.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/Channel.cc -o CMakeFiles/log.dir/s07/Channel.cc.s

CMakeFiles/log.dir/s07/Channel.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/Channel.cc.o.requires

CMakeFiles/log.dir/s07/Channel.cc.o.provides: CMakeFiles/log.dir/s07/Channel.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/Channel.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/Channel.cc.o.provides

CMakeFiles/log.dir/s07/Channel.cc.o.provides.build: CMakeFiles/log.dir/s07/Channel.cc.o


CMakeFiles/log.dir/s07/Poller.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/Poller.cc.o: ../s07/Poller.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/log.dir/s07/Poller.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/Poller.cc.o -c /home/test/work/reactor/s07/Poller.cc

CMakeFiles/log.dir/s07/Poller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/Poller.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/Poller.cc > CMakeFiles/log.dir/s07/Poller.cc.i

CMakeFiles/log.dir/s07/Poller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/Poller.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/Poller.cc -o CMakeFiles/log.dir/s07/Poller.cc.s

CMakeFiles/log.dir/s07/Poller.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/Poller.cc.o.requires

CMakeFiles/log.dir/s07/Poller.cc.o.provides: CMakeFiles/log.dir/s07/Poller.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/Poller.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/Poller.cc.o.provides

CMakeFiles/log.dir/s07/Poller.cc.o.provides.build: CMakeFiles/log.dir/s07/Poller.cc.o


CMakeFiles/log.dir/s07/Timer.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/Timer.cc.o: ../s07/Timer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/log.dir/s07/Timer.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/Timer.cc.o -c /home/test/work/reactor/s07/Timer.cc

CMakeFiles/log.dir/s07/Timer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/Timer.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/Timer.cc > CMakeFiles/log.dir/s07/Timer.cc.i

CMakeFiles/log.dir/s07/Timer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/Timer.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/Timer.cc -o CMakeFiles/log.dir/s07/Timer.cc.s

CMakeFiles/log.dir/s07/Timer.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/Timer.cc.o.requires

CMakeFiles/log.dir/s07/Timer.cc.o.provides: CMakeFiles/log.dir/s07/Timer.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/Timer.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/Timer.cc.o.provides

CMakeFiles/log.dir/s07/Timer.cc.o.provides.build: CMakeFiles/log.dir/s07/Timer.cc.o


CMakeFiles/log.dir/s07/TimerQueue.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/TimerQueue.cc.o: ../s07/TimerQueue.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/log.dir/s07/TimerQueue.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/TimerQueue.cc.o -c /home/test/work/reactor/s07/TimerQueue.cc

CMakeFiles/log.dir/s07/TimerQueue.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/TimerQueue.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/TimerQueue.cc > CMakeFiles/log.dir/s07/TimerQueue.cc.i

CMakeFiles/log.dir/s07/TimerQueue.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/TimerQueue.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/TimerQueue.cc -o CMakeFiles/log.dir/s07/TimerQueue.cc.s

CMakeFiles/log.dir/s07/TimerQueue.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/TimerQueue.cc.o.requires

CMakeFiles/log.dir/s07/TimerQueue.cc.o.provides: CMakeFiles/log.dir/s07/TimerQueue.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/TimerQueue.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/TimerQueue.cc.o.provides

CMakeFiles/log.dir/s07/TimerQueue.cc.o.provides.build: CMakeFiles/log.dir/s07/TimerQueue.cc.o


CMakeFiles/log.dir/s07/EventLoopThread.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/EventLoopThread.cc.o: ../s07/EventLoopThread.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/log.dir/s07/EventLoopThread.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/EventLoopThread.cc.o -c /home/test/work/reactor/s07/EventLoopThread.cc

CMakeFiles/log.dir/s07/EventLoopThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/EventLoopThread.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/EventLoopThread.cc > CMakeFiles/log.dir/s07/EventLoopThread.cc.i

CMakeFiles/log.dir/s07/EventLoopThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/EventLoopThread.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/EventLoopThread.cc -o CMakeFiles/log.dir/s07/EventLoopThread.cc.s

CMakeFiles/log.dir/s07/EventLoopThread.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/EventLoopThread.cc.o.requires

CMakeFiles/log.dir/s07/EventLoopThread.cc.o.provides: CMakeFiles/log.dir/s07/EventLoopThread.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/EventLoopThread.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/EventLoopThread.cc.o.provides

CMakeFiles/log.dir/s07/EventLoopThread.cc.o.provides.build: CMakeFiles/log.dir/s07/EventLoopThread.cc.o


CMakeFiles/log.dir/s07/SocketsOps.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/SocketsOps.cc.o: ../s07/SocketsOps.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/log.dir/s07/SocketsOps.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/SocketsOps.cc.o -c /home/test/work/reactor/s07/SocketsOps.cc

CMakeFiles/log.dir/s07/SocketsOps.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/SocketsOps.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/SocketsOps.cc > CMakeFiles/log.dir/s07/SocketsOps.cc.i

CMakeFiles/log.dir/s07/SocketsOps.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/SocketsOps.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/SocketsOps.cc -o CMakeFiles/log.dir/s07/SocketsOps.cc.s

CMakeFiles/log.dir/s07/SocketsOps.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/SocketsOps.cc.o.requires

CMakeFiles/log.dir/s07/SocketsOps.cc.o.provides: CMakeFiles/log.dir/s07/SocketsOps.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/SocketsOps.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/SocketsOps.cc.o.provides

CMakeFiles/log.dir/s07/SocketsOps.cc.o.provides.build: CMakeFiles/log.dir/s07/SocketsOps.cc.o


CMakeFiles/log.dir/s07/InetAddress.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/InetAddress.cc.o: ../s07/InetAddress.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/log.dir/s07/InetAddress.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/InetAddress.cc.o -c /home/test/work/reactor/s07/InetAddress.cc

CMakeFiles/log.dir/s07/InetAddress.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/InetAddress.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/InetAddress.cc > CMakeFiles/log.dir/s07/InetAddress.cc.i

CMakeFiles/log.dir/s07/InetAddress.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/InetAddress.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/InetAddress.cc -o CMakeFiles/log.dir/s07/InetAddress.cc.s

CMakeFiles/log.dir/s07/InetAddress.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/InetAddress.cc.o.requires

CMakeFiles/log.dir/s07/InetAddress.cc.o.provides: CMakeFiles/log.dir/s07/InetAddress.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/InetAddress.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/InetAddress.cc.o.provides

CMakeFiles/log.dir/s07/InetAddress.cc.o.provides.build: CMakeFiles/log.dir/s07/InetAddress.cc.o


CMakeFiles/log.dir/s07/Socket.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/Socket.cc.o: ../s07/Socket.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/log.dir/s07/Socket.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/Socket.cc.o -c /home/test/work/reactor/s07/Socket.cc

CMakeFiles/log.dir/s07/Socket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/Socket.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/Socket.cc > CMakeFiles/log.dir/s07/Socket.cc.i

CMakeFiles/log.dir/s07/Socket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/Socket.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/Socket.cc -o CMakeFiles/log.dir/s07/Socket.cc.s

CMakeFiles/log.dir/s07/Socket.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/Socket.cc.o.requires

CMakeFiles/log.dir/s07/Socket.cc.o.provides: CMakeFiles/log.dir/s07/Socket.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/Socket.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/Socket.cc.o.provides

CMakeFiles/log.dir/s07/Socket.cc.o.provides.build: CMakeFiles/log.dir/s07/Socket.cc.o


CMakeFiles/log.dir/s07/Acceptor.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/Acceptor.cc.o: ../s07/Acceptor.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/log.dir/s07/Acceptor.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/Acceptor.cc.o -c /home/test/work/reactor/s07/Acceptor.cc

CMakeFiles/log.dir/s07/Acceptor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/Acceptor.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/Acceptor.cc > CMakeFiles/log.dir/s07/Acceptor.cc.i

CMakeFiles/log.dir/s07/Acceptor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/Acceptor.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/Acceptor.cc -o CMakeFiles/log.dir/s07/Acceptor.cc.s

CMakeFiles/log.dir/s07/Acceptor.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/Acceptor.cc.o.requires

CMakeFiles/log.dir/s07/Acceptor.cc.o.provides: CMakeFiles/log.dir/s07/Acceptor.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/Acceptor.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/Acceptor.cc.o.provides

CMakeFiles/log.dir/s07/Acceptor.cc.o.provides.build: CMakeFiles/log.dir/s07/Acceptor.cc.o


CMakeFiles/log.dir/s07/TcpConnection.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/TcpConnection.cc.o: ../s07/TcpConnection.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/log.dir/s07/TcpConnection.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/TcpConnection.cc.o -c /home/test/work/reactor/s07/TcpConnection.cc

CMakeFiles/log.dir/s07/TcpConnection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/TcpConnection.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/TcpConnection.cc > CMakeFiles/log.dir/s07/TcpConnection.cc.i

CMakeFiles/log.dir/s07/TcpConnection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/TcpConnection.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/TcpConnection.cc -o CMakeFiles/log.dir/s07/TcpConnection.cc.s

CMakeFiles/log.dir/s07/TcpConnection.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/TcpConnection.cc.o.requires

CMakeFiles/log.dir/s07/TcpConnection.cc.o.provides: CMakeFiles/log.dir/s07/TcpConnection.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/TcpConnection.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/TcpConnection.cc.o.provides

CMakeFiles/log.dir/s07/TcpConnection.cc.o.provides.build: CMakeFiles/log.dir/s07/TcpConnection.cc.o


CMakeFiles/log.dir/s07/TcpServer.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/TcpServer.cc.o: ../s07/TcpServer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/log.dir/s07/TcpServer.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/TcpServer.cc.o -c /home/test/work/reactor/s07/TcpServer.cc

CMakeFiles/log.dir/s07/TcpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/TcpServer.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/TcpServer.cc > CMakeFiles/log.dir/s07/TcpServer.cc.i

CMakeFiles/log.dir/s07/TcpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/TcpServer.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/TcpServer.cc -o CMakeFiles/log.dir/s07/TcpServer.cc.s

CMakeFiles/log.dir/s07/TcpServer.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/TcpServer.cc.o.requires

CMakeFiles/log.dir/s07/TcpServer.cc.o.provides: CMakeFiles/log.dir/s07/TcpServer.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/TcpServer.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/TcpServer.cc.o.provides

CMakeFiles/log.dir/s07/TcpServer.cc.o.provides.build: CMakeFiles/log.dir/s07/TcpServer.cc.o


CMakeFiles/log.dir/s07/test8.cc.o: CMakeFiles/log.dir/flags.make
CMakeFiles/log.dir/s07/test8.cc.o: ../s07/test8.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/log.dir/s07/test8.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/s07/test8.cc.o -c /home/test/work/reactor/s07/test8.cc

CMakeFiles/log.dir/s07/test8.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/s07/test8.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/test/work/reactor/s07/test8.cc > CMakeFiles/log.dir/s07/test8.cc.i

CMakeFiles/log.dir/s07/test8.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/s07/test8.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/test/work/reactor/s07/test8.cc -o CMakeFiles/log.dir/s07/test8.cc.s

CMakeFiles/log.dir/s07/test8.cc.o.requires:

.PHONY : CMakeFiles/log.dir/s07/test8.cc.o.requires

CMakeFiles/log.dir/s07/test8.cc.o.provides: CMakeFiles/log.dir/s07/test8.cc.o.requires
	$(MAKE) -f CMakeFiles/log.dir/build.make CMakeFiles/log.dir/s07/test8.cc.o.provides.build
.PHONY : CMakeFiles/log.dir/s07/test8.cc.o.provides

CMakeFiles/log.dir/s07/test8.cc.o.provides.build: CMakeFiles/log.dir/s07/test8.cc.o


# Object files for target log
log_OBJECTS = \
"CMakeFiles/log.dir/base/timestamp.cpp.o" \
"CMakeFiles/log.dir/base/logging.cpp.o" \
"CMakeFiles/log.dir/base/logstream.cpp.o" \
"CMakeFiles/log.dir/s07/Buffer.cc.o" \
"CMakeFiles/log.dir/s07/EventLoop.cc.o" \
"CMakeFiles/log.dir/s07/Channel.cc.o" \
"CMakeFiles/log.dir/s07/Poller.cc.o" \
"CMakeFiles/log.dir/s07/Timer.cc.o" \
"CMakeFiles/log.dir/s07/TimerQueue.cc.o" \
"CMakeFiles/log.dir/s07/EventLoopThread.cc.o" \
"CMakeFiles/log.dir/s07/SocketsOps.cc.o" \
"CMakeFiles/log.dir/s07/InetAddress.cc.o" \
"CMakeFiles/log.dir/s07/Socket.cc.o" \
"CMakeFiles/log.dir/s07/Acceptor.cc.o" \
"CMakeFiles/log.dir/s07/TcpConnection.cc.o" \
"CMakeFiles/log.dir/s07/TcpServer.cc.o" \
"CMakeFiles/log.dir/s07/test8.cc.o"

# External object files for target log
log_EXTERNAL_OBJECTS =

log: CMakeFiles/log.dir/base/timestamp.cpp.o
log: CMakeFiles/log.dir/base/logging.cpp.o
log: CMakeFiles/log.dir/base/logstream.cpp.o
log: CMakeFiles/log.dir/s07/Buffer.cc.o
log: CMakeFiles/log.dir/s07/EventLoop.cc.o
log: CMakeFiles/log.dir/s07/Channel.cc.o
log: CMakeFiles/log.dir/s07/Poller.cc.o
log: CMakeFiles/log.dir/s07/Timer.cc.o
log: CMakeFiles/log.dir/s07/TimerQueue.cc.o
log: CMakeFiles/log.dir/s07/EventLoopThread.cc.o
log: CMakeFiles/log.dir/s07/SocketsOps.cc.o
log: CMakeFiles/log.dir/s07/InetAddress.cc.o
log: CMakeFiles/log.dir/s07/Socket.cc.o
log: CMakeFiles/log.dir/s07/Acceptor.cc.o
log: CMakeFiles/log.dir/s07/TcpConnection.cc.o
log: CMakeFiles/log.dir/s07/TcpServer.cc.o
log: CMakeFiles/log.dir/s07/test8.cc.o
log: CMakeFiles/log.dir/build.make
log: CMakeFiles/log.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/test/work/reactor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable log"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/log.dir/build: log

.PHONY : CMakeFiles/log.dir/build

CMakeFiles/log.dir/requires: CMakeFiles/log.dir/base/timestamp.cpp.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/base/logging.cpp.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/base/logstream.cpp.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/Buffer.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/EventLoop.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/Channel.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/Poller.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/Timer.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/TimerQueue.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/EventLoopThread.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/SocketsOps.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/InetAddress.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/Socket.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/Acceptor.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/TcpConnection.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/TcpServer.cc.o.requires
CMakeFiles/log.dir/requires: CMakeFiles/log.dir/s07/test8.cc.o.requires

.PHONY : CMakeFiles/log.dir/requires

CMakeFiles/log.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/log.dir/cmake_clean.cmake
.PHONY : CMakeFiles/log.dir/clean

CMakeFiles/log.dir/depend:
	cd /home/test/work/reactor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/test/work/reactor /home/test/work/reactor /home/test/work/reactor/build /home/test/work/reactor/build /home/test/work/reactor/build/CMakeFiles/log.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/log.dir/depend
