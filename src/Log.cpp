#include "Log.h"

#include <spdlog/sinks/basic_file_sink.h>

std::shared_ptr<spdlog::logger> Log::s_Logger;

void Log::Init()
{
    s_Logger = spdlog::basic_logger_mt("CORE", "logs/potato.log");
    spdlog::set_level(spdlog::level::trace);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%l] %v");
    auto coreLogger = spdlog::get("CORE");
    LOG_DEBUG("Core logger initialized");
    coreLogger->flush(); 
}