#include "Endpoint.h"

#include <algorithm>

EndpointData::EndpointData(const std::vector<RequestMethod>& methods, std::function<void( const HTTPRequest&)> callback) 
    : m_AllowedMethods(methods), m_Callback(callback)
{

}

bool EndpointData::AllowsMethod(RequestMethod method) {
    return std::find(m_AllowedMethods.begin(), m_AllowedMethods.end(), method) != m_AllowedMethods.end();
}

bool EndpointData::AllowsMethod(const std::string& method) {
    auto en = EndpointData::StrToEnum(method);
    return AllowsMethod(en);
}

std::string EndpointData::EnumToStr(RequestMethod method) {
    if (method == RequestMethod::GET) return "GET";
    if (method == RequestMethod::POST) return "POST";
}

RequestMethod EndpointData::StrToEnum(const std::string& method)
{
    if (method == "GET") return RequestMethod::GET;
    if (method == "POST") return RequestMethod::POST;
}
