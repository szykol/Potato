#pragma once

#include <string>
#include <vector>

#include "Socket.h"

class HTTPRequest
{
    static std::vector<std::string> getLines(Socket socket);
public:
    HTTPRequest() = delete;
    static std::string getHTTPRequest(Socket socket);
    static std::string parseHTTPRequest();
};