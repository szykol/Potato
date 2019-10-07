#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "Socket.h"

enum class RequestMethod { GET = 0, POST };
class HTTPRequest
{
    std::string m_Method;
    std::string m_URI;
    std::string m_HTTPVersion;

    std::unordered_map<std::string, std::string> m_HeaderFields;
    std::string m_Body;

    mutable Socket m_Socket;
public:
public:
    HTTPRequest(Socket socket, const std::string& method, const std::string& uri, const std::string& httpVer);
    bool AddHeaderField(const std::pair<std::string, std::string>& headerField);
    inline void SetBody(const std::string& body) { m_Body = body; }

    inline const std::string& Method() const { return m_Method; }
    inline const std::string& URI() const { return m_URI; }
    inline const std::string& HTTPVersion() const { return m_HTTPVersion; }

    inline const std::unordered_map<std::string, std::string>& HeaderFields() const { return m_HeaderFields; }
    inline const std::string& Body() const { return m_Body; }

    void Write(const std::string& content) const;
};

class HTTPRequestParser
{
    static std::vector<std::string> getLines(Socket socket);
public:
    HTTPRequestParser() = delete;
    static HTTPRequest getHTTPRequest(Socket socket);
    static std::string parseHTTPRequest();
};
