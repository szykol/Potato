#pragma once

#include <cstring>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <string>

class Socket {
    int m_Socketfd = -1;
    sockaddr_in m_Addr;

  public:
    struct Port {
        int port;
        Port(int port)
            : port(port)
        {
        }
    };

  public:
    Socket(Port port);
    Socket(int filefd)
        : m_Socketfd(filefd)
    {
    }
    virtual int listen(int maxConnections);
    virtual Socket accept();
    virtual std::string read(uint bytes);
    virtual void write(const std::string &content);
    virtual void close();
    inline operator int() { return m_Socketfd; }
};