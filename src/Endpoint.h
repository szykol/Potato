#pragma once

#include "Request.h"
#include <vector>
#include <functional>

struct EndpointData {
    std::vector<RequestMethod> m_AllowedMethods;
    std::function<void(const HTTPRequest&)> m_Callback;
    EndpointData(const std::vector<RequestMethod>& methods, std::function<void(const HTTPRequest&)> callback);
    bool AllowsMethod(RequestMethod method);
    bool AllowsMethod(const std::string& method);
    static std::string EnumToStr(RequestMethod method);
    static RequestMethod StrToEnum(const std::string& method);
};
