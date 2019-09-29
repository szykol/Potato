#pragma once

#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#include <string>

class Socket
{
    int m_Socketfd = -1;
    sockaddr_in m_Addr;
public:
    struct Port
    {
        int port;
        Port(int port) : port(port) {}
    };
public:
    Socket(Port port);
    Socket(int filefd) : m_Socketfd(filefd) {}
    int listen(int maxConnections);
    Socket accept();
    std::string read();
    void write(const std::string& content);
    void close();
    inline operator int() { return m_Socketfd; }
};