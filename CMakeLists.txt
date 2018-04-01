cmake_minimum_required(VERSION 3.9)
project(net)

include_directories(/usr/local/include/boost)

set(CMAKE_CXX_STANDARD 11)

set(SRC src/sockets/Socket.hpp
        src/sockets/TcpSocket.cpp
        src/sockets/TcpSocket.hpp
        src/sockets/SocketException.hpp
        src/sockets/TcpSocketServer.cpp
        src/sockets/TcpSocketServer.hpp)

add_executable(net main.cpp ${SRC})