cmake_minimum_required(VERSION 3.9)
project(net)

include_directories(/usr/local/include/boost)

include_directories(/usr/local/include/fmt)

set(CMAKE_CXX_STANDARD 11)

set(SRC src/sockets/Socket.hpp
        src/sockets/TcpSocket.cpp
        src/sockets/TcpSocket.hpp
        src/sockets/SocketException.hpp
        src/sockets/TcpSocketServer.cpp
        src/sockets/TcpSocketServer.hpp
        src/sockets/Socket.cpp
        src/sockets/Comment.hpp
        src/sockets/Util.cpp
        src/sockets/Util.hpp
        src/http/HTTPParser.cpp
        src/http/HTTPParser.hpp
        src/http/HTTPCode.hpp
        src/http/HTTPVersion.hpp
        src/http/HTTPVersionException.hpp
        src/utils/String.cpp
        src/utils/String.hpp src/type_traits/IsContainerTraits.hpp)

add_executable(net main.cpp ${SRC})

target_link_libraries(net fmt)