#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "Endpoint.h"
#include "Socket.h"

class Server {
    const std::string m_Port = "8080";
    const int m_MaxConnections = 10;

    Socket m_Socket;
    std::unordered_map<std::string, EndpointData> m_EndpointMap;

  public:
    Server(const std::string &port, int max_connections);
    void AddEndpoint(const std::string &URI, const std::vector<RequestMethod> &methods,
                     const std::function<void(const HTTPRequest &)> &callback);
    void run();
};
