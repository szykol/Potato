#include "Endpoint.h"

#include <algorithm>

EndpointData::EndpointData(const std::vector<HTTPRequest::RequestMethod>& methods, std::function<void( const HTTPRequest&)> callback) 
    : m_AllowedMethods(methods), m_Callback(callback)
{
    
}

bool EndpointData::AllowsMethod(HTTPRequest::RequestMethod method) {
    return std::find(m_AllowedMethods.begin(), m_AllowedMethods.end(), method) != m_AllowedMethods.end();
}

bool EndpointData::AllowsMethod(const std::string& method) {
    auto en = EndpointData::StrToEnum(method);
    return AllowsMethod(en);
}

std::string EndpointData::EnumToStr(HTTPRequest::RequestMethod method) {
    if (method == HTTPRequest::RequestMethod::GET) return "GET";
    if (method == HTTPRequest::RequestMethod::POST) return "POST";
}

HTTPRequest::RequestMethod EndpointData::StrToEnum(const std::string& method)
{
    if (method == "GET") return HTTPRequest::RequestMethod::GET;
    if (method == "POST") return HTTPRequest::RequestMethod::POST;
}
