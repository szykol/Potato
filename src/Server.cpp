#include "Server.h"
#include "Request.h"

Server::Server(const std::string &port, int maxConnections)
    : m_Port(port)
    , m_Socket(port)
    , m_MaxConnections(maxConnections)
{
}

void Server::AddEndpoint(const std::string &URI, const std::vector<RequestMethod> &methods,
                         const std::function<void(const HTTPRequest &)> &callback)
{
    m_EndpointMap.insert(std::make_pair(URI, EndpointData(methods, callback)));
}
void Server::run()
{
    std::cout << "Server starts listening at the port" << m_Port << std::endl;
    if (m_Socket.listen(3) < 0) {
        std::cout << "Error while listening \n";
        return;
    }
    while (true) {
        auto in_sock = m_Socket.accept();
        if (in_sock < 0) {
            std::cout << "Error in accepting\n";
            std::cout << in_sock << std::endl;
            std::cout << strerror(errno) << std::endl;
            return;
        }

        auto request = HTTPRequestParser::getHTTPRequest(in_sock);

        if (m_EndpointMap.find(request.URI()) != m_EndpointMap.end()) {
            auto method = request.Method();
            auto endpoint = m_EndpointMap.find(request.URI())->second;
            if (!endpoint.AllowsMethod(method)) {
                std::cout << "Method not allowed!" << std::endl;
                continue;
            }
            auto callback = endpoint.m_Callback;

            callback(request);
        }
        else {
            request.Write("Not found");
        }

        std::cout << "Method: " << request.Method() << std::endl;
        std::cout << "URI: " << request.URI() << std::endl;
        std::cout << "HTTPVersion: " << request.HTTPVersion() << std::endl;
        std::cout << "HeaderFields: " << std::endl;

        for (auto &pair : request.HeaderFields()) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }

        if (request.Body().length() > 0)
            std::cout << "Content body: " << request.Body() << std::endl;
        in_sock.close();
    }
}
