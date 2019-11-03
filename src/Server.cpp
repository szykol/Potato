#include "Server.h"
#include "Request.h"
#include "Log.h"

Server::Server(const std::string &port, int maxConnections)
    : m_Port(port)
    , m_Socket(port)
    , m_MaxConnections(maxConnections)
{
    LOG_DEBUG("STARTING POTATO SERVER");
}

void Server::AddEndpoint(const std::string &URI, const std::vector<RequestMethod> &methods,
                         const std::function<void(const HTTPRequest &)> &callback)
{
    m_EndpointMap.insert(std::make_pair(URI, EndpointData(methods, callback)));
}
void Server::run()
{
    std::cout << "Server starts listening at the port " << m_Port << std::endl;
    LOG_DEBUG("Server starts listening at port {} and maxconnections={}", m_Port, m_MaxConnections);
    if (m_Socket.listen(m_MaxConnections) < 0) {
        LOG_ERROR("Error while listening socket | Error: {}", strerror(errno));
        return;
    }
    while (true) {
        auto in_sock = m_Socket.accept();
        if (in_sock < 0) {
            LOG_ERROR("Error while accepting socket fd={} | Error: {}", int(in_sock), strerror(errno));
            return;
        }
        LOG_DEBUG("Accepted new connection socket fd={}", int(in_sock));

        auto request = HTTPRequestParser::getHTTPRequest(in_sock);

        if (m_EndpointMap.find(request.URI()) != m_EndpointMap.end()) {
            auto method = request.Method();
            auto endpoint = m_EndpointMap.find(request.URI())->second;
            if (!endpoint.AllowsMethod(method)) {
                LOG_DEBUG("Method Not Allowed");
                request.Write("Method Not Allowed", 405);
                spdlog::get("CORE")->flush();
                in_sock.close();
                continue;
            }
            auto callback = endpoint.m_Callback;

            callback(request);
        }
        else {
            LOG_DEBUG("404 Not Found");
            request.Write("Not found", 404);
        }

        LOG_DEBUG("Method: {} | URI: {} | HTTPVersion: {}", request.Method(), request.URI(), request.HTTPVersion());
        LOG_DEBUG("Header Fields");
        for (auto &pair : request.HeaderFields()) {
            LOG_DEBUG("{}: {}", pair.first, pair.second);
        }
        LOG_DEBUG("Content Body: {}", request.Body());
        LOG_DEBUG("CLOSING SOCKET");
        spdlog::get("CORE")->flush();
        in_sock.close();
    }
}
