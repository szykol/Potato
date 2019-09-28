#include "Server.h"

int main() {
    auto server = Server(7777, 3);
    server.run();
}