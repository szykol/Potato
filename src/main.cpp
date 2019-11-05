#include "Server.h"
#include "Socket.h"

#include "Request.h"
#include "Log.h"

int main()
{
    Log::Init();
    auto server = Server("8080", 3);

    server.AddEndpoint("/", {RequestMethod::GET, RequestMethod::POST},
                       [](auto &req) { req.Write("<h1>Hello, World!</h1><h2>Welcome to Potato</h2>"); });

    server.AddEndpoint("/say_hi", {RequestMethod::GET}, [](auto &req) { req.Write(R"({"msg": "Hello"})"); });

    server.run();
}
