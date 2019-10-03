#include "Server.h"
#include "Request.h"

Server::Server(Socket::Port port, int maxConnections)
    : m_Port(port.port), m_Socket(Socket::Port(port)), m_MaxConnections(maxConnections)
{
}

void Server::run()
{
    std::cout<<"Server starts listening at the port"<<m_Port<<std::endl;
    if (m_Socket.listen(3) < 0) {
        std::cout<<"Error while listening \n";
        return;
    }
    while(true) {
        auto in_sock = m_Socket.accept();
        if (in_sock < 0) {
            std::cout<<"Error in accepting\n";
            std::cout<<in_sock<<std::endl;
            std::cout<<strerror(errno)<<std::endl;
            return;
        }

        auto request = HTTPRequestParser::getHTTPRequest(in_sock);
        std::cout<<"Method: "<<request.Method()<<std::endl;
        std::cout<<"URI: "<<request.URI()<<std::endl;
        std::cout<<"HTTPVersion: "<<request.HTTPVersion()<<std::endl;
        std::cout<<"HeaderFields: "<<std::endl;

        for(auto& pair : request.HeaderFields()) {
            std::cout<<pair.first<<": "<<pair.second<<std::endl;
        }
        in_sock.write("Hello, from server!");
        in_sock.close();
    }
}