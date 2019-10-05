#pragma once

#include "Request.h"
#include <vector>
#include <functional>

struct EndpointData {
	std::vector<HTTPRequest::RequestMethod> m_AllowedMethods;
	std::function<void(const HTTPRequest&)> m_Callback;
	EndpointData(const std::vector<HTTPRequest::RequestMethod>& methods, std::function<void(const HTTPRequest&)> callback);
    bool AllowsMethod(HTTPRequest::RequestMethod method);
    bool AllowsMethod(const std::string& method);
    static std::string EnumToStr(HTTPRequest::RequestMethod method);
    static HTTPRequest::RequestMethod StrToEnum(const std::string& method);
};
