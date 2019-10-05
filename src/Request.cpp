#include "Request.h"

#include <iostream>

#include "Utill.h"

std::string HTTPRequestParser::parseHTTPRequest()
{
    return "";
}

HTTPRequest HTTPRequestParser::getHTTPRequest(Socket socket)
{
    auto lines = getLines(socket);
    auto firstLine = lines[0];

    auto firstLineData = split(firstLine, " ");

    auto r = HTTPRequest(firstLineData[0], firstLineData[1], firstLineData[2]);
    for (int i = 1; i < lines.size(); i++) {
        auto line = lines[i];
        auto keyVal = split(line, ":");
		
        r.AddHeaderField(std::make_pair(keyVal[0], trim(keyVal[1])));
    }

    return r;
}

std::vector<std::string> HTTPRequestParser::getLines(Socket socket)
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

HTTPRequest::HTTPRequest(const std::string& method, const std::string& uri, const std::string& httpVer)
    : m_Method(method), m_URI(uri), m_HTTPVersion(httpVer)
{
}

bool HTTPRequest::AddHeaderField(const std::pair<std::string, std::string>& headerField)
{
    m_HeaderFields.insert(headerField);
}
