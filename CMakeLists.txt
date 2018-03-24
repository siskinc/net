cmake_minimum_required(VERSION 3.9)
project(net)

include_directories(/usr/local/include/boost)

set(CMAKE_CXX_STANDARD 11)

add_executable(net main.cpp src/Socket.cpp src/Socket.hpp src/Address.cpp src/Address.hpp src/util.hpp src/Common.hpp src/TcpSocket.cpp src/TcpSocket.hpp src/EpollSocket.cpp src/EpollSocket.hpp)