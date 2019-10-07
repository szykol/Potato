#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

#include "Socket.h"
#include "Endpoint.h"

class Server
{
    const int m_Port = 8080;
    const int m_MaxConnections = 10;

    Socket m_Socket;
    std::unordered_map<std::string, EndpointData> m_EndpointMap;
public:
    Server(Socket::Port port, int max_connections);
    void AddEndpoint(const std::string& URI, const std::vector<RequestMethod>& methods, const std::function<void(const HTTPRequest&)>& callback);
    void run();
};
