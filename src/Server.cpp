#include "Server.h"

Server::Server(int port, int maxConnections)
    : m_Port(port), m_MaxConnections(maxConnections)
{
    m_AccSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_AccSocket < 0) {
        std::cout<<"Could not create socket\n";
        return;
    }

    std::memset((char*)&m_Addr, 0, sizeof(m_Addr));
    m_Addr.sin_family = AF_INET;
    m_Addr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_Addr.sin_port = htons(m_Port);

    if (bind(m_AccSocket, (sockaddr*)&m_Addr, sizeof(m_Addr)) < 0) {
        std::cout<<"Bind failed\n";
        return;
    }

}

void Server::run()
{
    std::cout<<"Server starts listening at the port"<<m_Port<<std::endl;
    if (listen(m_AccSocket, m_MaxConnections) < 0) {
        std::cout<<"Error while listening \n";
        return;
    }
    socklen_t socklen = sizeof(m_Addr);
    while(true) {
        auto in_sock = accept(m_AccSocket, (sockaddr*)&m_Addr, &socklen);
        if (in_sock < 0) {
            std::cout<<"Error in accepting\n";
            std::cout<<in_sock<<std::endl;
            std::cout<<strerror(errno)<<std::endl;
            return;
        }
        char buffer[3000] = {0};
        auto val_read = read(in_sock, buffer, 3000);
        std::cout<<buffer<<std::endl;
        auto const to_write = "Hello from server\n";
        write(in_sock, to_write, strlen(to_write));
        close(in_sock);
    }
}