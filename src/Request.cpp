#include "Request.h"

#include <iostream>

std::string HTTPRequest::parseHTTPRequest()
{
    return "";
}

std::string HTTPRequest::getHTTPRequest(Socket socket)
{
    auto lines = getLines(socket);
    std::string retVal;
    for (auto &line: lines) {
        retVal += line + "\n";
    }
    return retVal;
}

std::vector<std::string> HTTPRequest::getLines(Socket socket)
{
    std::string req;
    std::vector<std::string> lines;

    while(true) {
        while(req.find("\n") == std::string::npos) {
            req += socket.read(10);
        }
        auto newLinePos = req.find("\n");
        auto line = req.substr(0, newLinePos);
        if (line.length() == 1) break;
        line.erase(line.find("\r"));
        lines.push_back(line);

        auto remainder = req.substr(newLinePos + 1);
        req.clear();
        req += remainder;
    }
    
    return lines;
}