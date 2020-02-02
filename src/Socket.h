#pragma once

#include <cstring>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <string>
#include <asio.hpp>

struct addrinfo;

class Socket {
    int m_Socketfd = -1;

  public:
    Socket(const std::string &port);
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

  private:
    void initSocket(const std::string &port);
};