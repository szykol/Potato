#pragma once

#include <iostream>
#include "Socket.h"

class Server
{
    const int m_Port = 8080;
    const int m_MaxConnections = 10;

    Socket m_Socket;
public:
    Server(Socket::Port port, int max_connections);
    void run();
};