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
    virtual int listen(int maxConnections);
    virtual Socket accept();
    virtual std::string read(uint bytes);
    virtual void write(const std::string& content);
    virtual void close();
    inline operator int() { return m_Socketfd; }
};