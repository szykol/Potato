#include "Server.h"
#include "Socket.h"

#include "Request.h"

int main() {
    auto server = Server(Socket::Port(8080), 3);

    server.AddEndpoint("/", {RequestMethod::GET, RequestMethod::POST}, [](auto& req) {
        req.Write("Welcome to /!");
    });

    server.AddEndpoint("/say_hi", {RequestMethod::GET}, [](auto& req) {
        req.Write("Hello!");
    });

    server.run();
}
