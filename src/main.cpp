#include "Server.h"
#include "Socket.h"

int main() {
    auto server = Server(Socket::Port(8080), 3);
    server.run();
}