cmake_minimum_required(VERSION 3.9)
project(net)

include_directories(/usr/local/include/boost)

set(CMAKE_CXX_STANDARD 11)

add_executable(net main.cpp src/sockets/Socket.cpp src/sockets/Socket.hpp src/sockets/Address.cpp src/sockets/Address.hpp src/sockets/util.hpp src/sockets/Common.hpp src/sockets/TcpSocket.cpp src/sockets/TcpSocket.hpp src/sockets/EpollSocket.cpp src/sockets/EpollSocket.hpp)