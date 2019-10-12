#include <gtest/gtest.h>

#include "../src/Endpoint.h"
#include "../src/Exception.h"

TEST(EndpointTest, EnumToStrWorks) {
    ASSERT_EQ("GET", EndpointData::EnumToStr(RequestMethod::GET));
    ASSERT_EQ("POST", EndpointData::EnumToStr(RequestMethod::POST));
    ASSERT_EQ("PATCH", EndpointData::EnumToStr(RequestMethod::PATCH)); 
    ASSERT_EQ("DELETE", EndpointData::EnumToStr(RequestMethod::DELETE));
    ASSERT_EQ("UPDATE", EndpointData::EnumToStr(RequestMethod::UPDATE));
    ASSERT_EQ("OPTIONS", EndpointData::EnumToStr(RequestMethod::OPTIONS));
    ASSERT_EQ("HEAD", EndpointData::EnumToStr(RequestMethod::HEAD));
    ASSERT_EQ("PUT", EndpointData::EnumToStr(RequestMethod::PUT));
    ASSERT_EQ("CONNECT", EndpointData::EnumToStr(RequestMethod::CONNECT));
    ASSERT_EQ("TRACE", EndpointData::EnumToStr(RequestMethod::TRACE));

    ASSERT_EQ("NONE", EndpointData::EnumToStr(RequestMethod(100)));
    ASSERT_EQ("NONE", EndpointData::EnumToStr(RequestMethod::NONE));
}

TEST(EndpointTest, StrToEnumWorks) {
    ASSERT_EQ(RequestMethod::GET, EndpointData::StrToEnum("GET"));
    ASSERT_EQ(RequestMethod::POST, EndpointData::StrToEnum("POST"));
    ASSERT_EQ(RequestMethod::PATCH, EndpointData::StrToEnum("PATCH"));
    ASSERT_EQ(RequestMethod::DELETE, EndpointData::StrToEnum("DELETE"));
    ASSERT_EQ(RequestMethod::UPDATE, EndpointData::StrToEnum("UPDATE"));
    ASSERT_EQ(RequestMethod::OPTIONS, EndpointData::StrToEnum("OPTIONS"));
    ASSERT_EQ(RequestMethod::HEAD, EndpointData::StrToEnum("HEAD"));
    ASSERT_EQ(RequestMethod::PUT, EndpointData::StrToEnum("PUT"));
    ASSERT_EQ(RequestMethod::CONNECT, EndpointData::StrToEnum("CONNECT"));
    ASSERT_EQ(RequestMethod::TRACE, EndpointData::StrToEnum("TRACE"));

    ASSERT_EQ(RequestMethod::NONE, EndpointData::StrToEnum("DOESNTEXIST"));
}

TEST(EndpointTest, AllowsMethodsWorksGET) {
    auto endpoint = EndpointData({RequestMethod::GET}, [](auto &r) {});

    auto allowed = RequestMethod::GET;
    ASSERT_TRUE(endpoint.AllowsMethod(allowed));
    for (int i = int(RequestMethod::GET); i < int(RequestMethod::NONE); i++) {
        auto unallowed = RequestMethod(i);
        if (unallowed != allowed)
            ASSERT_FALSE(endpoint.AllowsMethod(RequestMethod(i)));
    }
}

TEST(EndpointTest, AllowsMethodsWorksPOST) {
    auto endpoint = EndpointData({RequestMethod::POST}, [](auto &r) {});

    ASSERT_TRUE(endpoint.AllowsMethod("POST"));
    ASSERT_FALSE(endpoint.AllowsMethod("GET"));
}

TEST(EndpointTest, AllowsMethodsWorksPOSTandGET) {
    auto endpoint = EndpointData({RequestMethod::POST, RequestMethod::GET}, [](auto &r) {});

    ASSERT_TRUE(endpoint.AllowsMethod("POST"));
    ASSERT_TRUE(endpoint.AllowsMethod("GET"));
}

TEST(EndpointTest, AllowsMethodThrowsOnIncorrectData) {
    auto endpoint = EndpointData({RequestMethod::POST, RequestMethod::GET}, [](auto &r) {});

    ASSERT_THROW(endpoint.AllowsMethod("NONE"), InvalidRequestMethod);
    ASSERT_THROW(endpoint.AllowsMethod(RequestMethod::NONE), InvalidRequestMethod);
}