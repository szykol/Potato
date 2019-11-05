#pragma once

#include <memory>
#include <spdlog/spdlog.h>

class Log {
private:
    static std::shared_ptr<spdlog::logger> s_Logger;
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
};

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef POTATO_DEBUG
    #define LOG_ERROR(fmt, ...) ::Log::GetLogger()->error(fmt " [{}:{}]", ##__VA_ARGS__, __FILENAME__, __LINE__)
    #define LOG_INFO(fmt, ...) ::Log::GetLogger()->info(fmt " [{}:{}]", ##__VA_ARGS__, __FILENAME__, __LINE__)
    #define LOG_WARN(fmt, ...) ::Log::GetLogger()->warn(fmt " [{}:{}]", ##__VA_ARGS__, __FILENAME__, __LINE__)
    #define LOG_TRACE(fmt, ...) ::Log::GetLogger()->trace(fmt " [{}:{}]", ##__VA_ARGS__, __FILENAME__, __LINE__)
    #define LOG_DEBUG(fmt, ...) ::Log::GetLogger()->debug(fmt " [{}:{}]", ##__VA_ARGS__, __FILENAME__, __LINE__)
#else
    #define LOG_ERROR(fmt, ...) 
    #define LOG_INFO(fmt, ...) 
    #define LOG_WARN(fmt, ...) 
    #define LOG_TRACE(fmt, ...) 
    #define LOG_DEBUG(fmt, ...) 
#endif
