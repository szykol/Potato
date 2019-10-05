#include "Server.h"
#include "Socket.h"

#include "Request.h"

int main() {
    auto server = Server(Socket::Port(8080), 3);

    server.AddEndpoint("/", {HTTPRequest::RequestMethod::GET, HTTPRequest::RequestMethod::POST}, [](auto& req) {
        std::cout<<req.Method()<<std::endl;
    });

    server.run();
}
