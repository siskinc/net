#include <iostream>
#include "src/http/HTTPParser.hpp"

int main()
{
        HTTPParser httpParser = HTTPParser(
                "GET wss://live.github.com/_sockets/VjI6MjU4OTUzOTg5Ojg5NDkyMzg0Y2M3NDQzYzc0NzE1NTY2ZmMxNTUxMjBjNDAxZTU3MmM4NTg3YzBmM2ViZjYzNmIyMWEwNjMzNTU=--4fb2b3907a1dff03213c7dc2da916e40a55700ff HTTP/1.1\n"
                "Host: live.github.com\n"
                "Connection: Upgrade\n"
                "Pragma: no-cache\n"
                "Cache-Control: no-cache\n"
                "Upgrade: websocket\n"
                "Origin: https://github.com\n"
                "Sec-WebSocket-Version: 13\n"
                "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36\n"
                "Accept-Encoding: gzip, deflate, br\n"
                "Accept-Language: zh-CN,zh;q=0.9,en;q=0.8\r\n"
                "Cookie: _octo=GH1.1.187905561.1519216713; logged_in=yes; dotcom_user=siskinc; _ga=GA1.2.2147191024.1521452666; _gat=1\n"
                "Sec-WebSocket-Key: ORV4SHCpg9l9f+x8anweNg==\n"
                "Sec-WebSocket-Extensions: permessage-deflate; client_max_window_bits\n\n asd\na");


    return 0;
}