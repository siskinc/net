cmake_minimum_required(VERSION 3.9)
project(net)

include_directories(/usr/local/include/boost)
include_directories(/usr/local/include/glog)

set(CMAKE_CXX_STANDARD 17)

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
        src/utils/String.hpp
        src/type_traits/IsContainerTraits.hpp
        src/http/HTTPHeaderException.hpp
        src/http/HTTPServer.cpp
        src/http/HTTPServer.hpp
        src/http/HTTPContext.cpp
        src/http/HTTPContext.hpp
        src/http/HTTPSession.cpp
        src/http/HTTPSession.hpp
        src/http/HTTPCookie.cpp
        src/http/HTTPCookie.hpp
        src/http/HTTPCookies.cpp
        src/http/HTTPCookies.hpp
        src/http/HTTPHeaders.cpp
        src/http/HTTPHeaders.hpp
        src/sockets/AddressListenException.hpp
        src/http/HTTPHandlers.cpp
        src/http/HTTPHandlers.hpp
        src/http/HTTPHandler.cpp
        src/http/HTTPHandler.hpp
        src/http/HTTPMethods.hpp
        src/parser/Serialize.hpp
        src/parser/json11/json11.hpp
        src/parser/json11/json11.cpp)


add_executable(qunland main.cpp ${SRC})

target_link_libraries(qunland pthread boost_system boost_thread glog)