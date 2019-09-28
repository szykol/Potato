#pragma once

#include <iostream>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

class Server
{
    const int m_Port = 8080;
    const int m_MaxConnections = 10;

    int m_AccSocket;
    sockaddr_in m_Addr;
public:
    Server(int port, int max_connections);
    void run();
};