#include <iostream>
#include "src/http/HTTPParser.hpp"
#include <boost/algorithm/string.hpp>
#include <container/vector.hpp>
#include <map>


int main()
{

    std::string a = "UM_distinctid=161cd94fcd03d8-02454dda4dc4fa-102c1709-100200-161cd94fcd143a; CNZZDATA3685059=cnzz_eid%3D1863967296-1519568593-%26ntime%3D1519568593; CNZZDATA1256907=cnzz_eid%3D1752420124-1521688023-https%253A%252F%252Fwww.google.co.jp%252F%26ntime%3D1521688023; __utma=226521935.1172772262.1519217903.1519268711.1522587999.2; __utmz=226521935.1522587999.2.2.utmcsr=google|utmccn=(organic)|utmcmd=organic|utmctr=(not%20provided); __gads=ID=15318577cd5e00b4:T=1522667454:S=ALNI_Man0ozAXp4UGdyZIWht2COsom8Azw; _ga=GA1.2.1172772262.1519217903; _gid=GA1.2.1431877508.1523022547; OUTFOX_SEARCH_USER_ID_NCOO=385605275.11766404; CNZZDATA1465781=cnzz_eid%3D1893482952-1523258840-https%253A%252F%252Fwww.google.co.jp%252F%26ntime%3D1523258840";
    auto lines = String::explode<std::string>(' ', a, a.length());
    size_t equal_sign_index;
    for (auto &line:lines)
    {
        std::cout << line << std::endl;
        equal_sign_index = line.find_first_of('=');
        std::cout << line.substr(0, equal_sign_index) << " = " << line.substr(equal_sign_index + 1) << std::endl;
    }
    return 0;
}