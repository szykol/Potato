#include "Socket.h"

#include <iostream>
#include <sys/socket.h>
#include <netdb.h>

Socket::Socket(const std::string& port)
{
    initSocket(port);
}

int Socket::listen(int maxConnections) { return ::listen(*this, maxConnections); }

Socket Socket::accept()
{
    sockaddr_storage incoming;
    socklen_t socklen = sizeof(incoming);
    return ::accept(*this, (sockaddr *)&incoming, &socklen);
}

std::string Socket::read(uint bytes)
{
    auto buffer = new char[bytes];
    std::memset(buffer, 0, bytes);

    auto sizeRead = ::read(*this, buffer, bytes);
    std::string bufferString = buffer;
    delete[] buffer;

    return bufferString;
}

void Socket::write(const std::string &content) {
    auto sendBytes = 0;
    auto toWrite = content.length();

    while(sendBytes < toWrite) {
        sendBytes += ::write(*this, content.c_str(), toWrite);
        toWrite -= sendBytes;
    }
}

void Socket::close() { ::close(*this); }

void Socket::initSocket(const std::string& port) 
{
    addrinfo hints;
    addrinfo *res;
    
    std::memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, port.c_str(), &hints, &res);

    int yes = 1;
    for (auto node = res; node != nullptr; node = node->ai_next) {
        if ((m_Socketfd = socket(node->ai_family, node->ai_socktype, node->ai_protocol)) == -1) {
            continue;
        }

        if (setsockopt(m_Socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) < 0) {
            continue;
        }

        if (::bind(m_Socketfd, node->ai_addr, node->ai_addrlen) < 0) {
            continue;
        } else {
            break;
        }
    }

    freeaddrinfo(res); 
}