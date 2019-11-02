#include "Server.h"
#include "Socket.h"

#include "Request.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

int main()
{
    auto server = Server("8080", 3);

    server.AddEndpoint("/", {RequestMethod::GET, RequestMethod::POST},
                       [](auto &req) { req.Write("<h1>Hello, World!</h1><h2>Welcome to Potato</h2>"); });

    server.AddEndpoint("/say_hi", {RequestMethod::GET}, [](auto &req) { req.Write(R"({"msg": "Hello"})"); });

    try 
    {
        auto coreLogger = spdlog::basic_logger_mt("CORE", "logs/potato.log");
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    spdlog::set_level(spdlog::level::debug);
    auto coreLogger = spdlog::get("CORE");
    coreLogger->debug("System logger initialized");
    coreLogger->flush();
    
    server.run();
}
