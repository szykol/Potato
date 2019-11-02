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
        while (req.find("\r\n") == std::string::npos) {
            req += socket.read(10);
        }
        auto newLinePos = req.find("\r\n");
        auto line = req.substr(0, newLinePos);
        auto remainder = req.substr(newLinePos + 2);
        if (line.length() == 0) {
            bodyRemainder = req.substr(newLinePos + 2);
            lines.push_back(bodyRemainder);
            break;
        }
        lines.push_back(line);

        req = remainder;
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
    if (m_HeaderFields.find(headerField.first) == m_HeaderFields.end()) {
        m_HeaderFields.insert(headerField);
        return true;
    }
    return false;
}

void HTTPRequest::Write(const std::string &content, int statusCode) const
{
    const auto length = content.length();
    if (length > 0) {
        std::string response = "HTTP/1.1 " + std::to_string(statusCode) +
                               " OK\r\nServer: Potato\r\nContent-Type: text/html\r\nContent-Length: ";
        response += std::to_string(length);
        response += "\r\n\r\n" + content;

        m_Socket.write(response);
    }
}
