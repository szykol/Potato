#include "Endpoint.h"

#include "Exception.h"
#include <algorithm>

EndpointData::EndpointData(const std::vector<RequestMethod> &methods, std::function<void(const HTTPRequest &)> callback)
    : m_AllowedMethods(methods)
    , m_Callback(callback)
{
}

bool EndpointData::AllowsMethod(RequestMethod method)
{
    if (method == RequestMethod::NONE)
        throw InvalidRequestMethod();

    return std::find(m_AllowedMethods.begin(), m_AllowedMethods.end(), method) != m_AllowedMethods.end();
}

bool EndpointData::AllowsMethod(const std::string &method)
{
    auto en = EndpointData::StrToEnum(method);
    return AllowsMethod(en);
}

std::string EndpointData::EnumToStr(RequestMethod method)
{
    if (method == RequestMethod::GET)
        return "GET";
    if (method == RequestMethod::POST)
        return "POST";
    if (method == RequestMethod::PATCH)
        return "PATCH";
    if (method == RequestMethod::DELETE)
        return "DELETE";
    if (method == RequestMethod::UPDATE)
        return "UPDATE";
    if (method == RequestMethod::OPTIONS)
        return "OPTIONS";
    if (method == RequestMethod::HEAD)
        return "HEAD";
    if (method == RequestMethod::PUT)
        return "PUT";
    if (method == RequestMethod::CONNECT)
        return "CONNECT";
    if (method == RequestMethod::TRACE)
        return "TRACE";

    return "NONE";
}

RequestMethod EndpointData::StrToEnum(const std::string &method)
{
    if (method == "GET")
        return RequestMethod::GET;
    if (method == "POST")
        return RequestMethod::POST;
    if (method == "PATCH")
        return RequestMethod::PATCH;
    if (method == "DELETE")
        return RequestMethod::DELETE;
    if (method == "UPDATE")
        return RequestMethod::UPDATE;
    if (method == "OPTIONS")
        return RequestMethod::OPTIONS;
    if (method == "HEAD")
        return RequestMethod::HEAD;
    if (method == "PUT")
        return RequestMethod::PUT;
    if (method == "CONNECT")
        return RequestMethod::CONNECT;
    if (method == "TRACE")
        return RequestMethod::TRACE;

    return RequestMethod::NONE;
}
