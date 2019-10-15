#include "Request.h"

#include <iostream>

#include "Endpoint.h"
#include "Exception.h"
#include "Utill.h"

std::string HTTPRequestParser::parseHTTPRequest() { return ""; }

HTTPRequest HTTPRequestParser::getHTTPRequest(Socket &socket)
{
    auto lines = getLines(socket);
    auto firstLine = lines[0];

    auto firstLineData = split(firstLine, " ");
    if (firstLineData.size() < 3) {
        throw BadRequest();
    }

    auto method = firstLineData[0];
    auto URI = firstLineData[1];
    auto version = firstLineData[2];

    if (!methodExists(method)) {
        throw InvalidRequestMethod();
    }

    auto r = HTTPRequest(socket, method, URI, version);
    for (int i = 1; i < lines.size() - 1; i++) {
        auto line = lines[i];
        auto keyVal = split(line, ":");

        r.AddHeaderField(std::make_pair(keyVal[0], trim(keyVal[1])));
    }
    if (r.HeaderFields().find("Content-Length") != r.HeaderFields().end()) {
        auto val = r.HeaderFields().find("Content-Length")->second;
        auto toRead = std::stoi(val);
        auto alreadyRead = lines[lines.size() - 1];
        auto body = alreadyRead + socket.read(toRead - alreadyRead.length());

        r.SetBody(body);
    }
    return r;
}

std::vector<std::string> HTTPRequestParser::getLines(Socket &socket)
{
    std::string req;
    std::vector<std::string> lines;

    std::string bodyRemainder;
    while (true) {
        while (req.find("\n") == std::string::npos) {
            req += socket.read(10);
        }
        auto newLinePos = req.find("\n");
        auto line = req.substr(0, newLinePos);
        if (line.length() == 1) {
            bodyRemainder = req.substr(newLinePos + 1);
            lines.push_back(bodyRemainder);
            break;
        }
        line.erase(line.find("\r"));
        lines.push_back(line);

        auto remainder = req.substr(newLinePos + 1);
        req.clear();
        req += remainder;
    }

    return lines;
}

bool HTTPRequestParser::methodExists(const std::string &method)
{
    for (auto i = int(RequestMethod::GET); i < int(RequestMethod::NONE); i++) {
        if (method == EndpointData::EnumToStr(RequestMethod(i)))
            return true;
    }
    return false;
}

HTTPRequest::HTTPRequest(Socket socket, const std::string &method, const std::string &uri, const std::string &httpVer)
    : m_Socket(socket)
    , m_Method(method)
    , m_URI(uri)
    , m_HTTPVersion(httpVer)
{
}

bool HTTPRequest::AddHeaderField(const std::pair<std::string, std::string> &headerField)
{
    m_HeaderFields.insert(headerField);
}

void HTTPRequest::Write(const std::string &content) const
{
    if (content.length() > 0) {
        m_Socket.write(content);
    }
}
