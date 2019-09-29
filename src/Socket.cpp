#include "Socket.h"

#include <iostream>

Socket::Socket(Socket::Port port)
{
    m_Socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_Socketfd < 0) {
        std::cout<<"Could not create socket\n";
        return;
    }

    std::memset((char*)&m_Addr, 0, sizeof(m_Addr));
    m_Addr.sin_family = AF_INET;
    m_Addr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_Addr.sin_port = htons(port.port);

    if (bind(m_Socketfd, (sockaddr*)&m_Addr, sizeof(m_Addr)) < 0) {
        std::cout<<"Bind failed\n";
        return;
    }
}

int Socket::listen(int maxConnections)
{
    return ::listen(*this, maxConnections);
}

Socket Socket::accept()
{
    socklen_t socklen = sizeof(m_Addr);
    return ::accept(*this, (sockaddr*)&m_Addr, &socklen);
}

std::string Socket::read()
{
    char buffer[3000] = {0};    
    auto sizeRead = ::read(*this, buffer, 3000);

    return buffer;
}

void Socket::write(const std::string& content)
{
    ::write(*this, content.c_str(), content.length());
}

void Socket::close()
{
    ::close(*this);
}