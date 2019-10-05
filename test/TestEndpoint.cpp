#include <gtest/gtest.h>

#include "../src/Endpoint.h"

TEST(EndpointTest, EnumToStrWorks) {
    ASSERT_EQ("GET", EndpointData::EnumToStr(HTTPRequest::RequestMethod::GET));
    ASSERT_EQ("POST", EndpointData::EnumToStr(HTTPRequest::RequestMethod::POST));
}

TEST(EndpointTest, StrToEnumWorks) {
    ASSERT_EQ(HTTPRequest::RequestMethod::GET, EndpointData::StrToEnum("GET"));
    ASSERT_EQ(HTTPRequest::RequestMethod::POST, EndpointData::StrToEnum("POST"));
}

TEST(EndpointTest, AllowsMethodsWorksGET) {
    auto endpoint = EndpointData({HTTPRequest::RequestMethod::GET}, [](auto &r) {});

    ASSERT_TRUE(endpoint.AllowsMethod("GET"));
    ASSERT_FALSE(endpoint.AllowsMethod("POST"));
}

TEST(EndpointTest, AllowsMethodsWorksPOST) {
    auto endpoint = EndpointData({HTTPRequest::RequestMethod::POST}, [](auto &r) {});

    ASSERT_TRUE(endpoint.AllowsMethod("POST"));
    ASSERT_FALSE(endpoint.AllowsMethod("GET"));
}

TEST(EndpointTest, AllowsMethodsWorksPOSTandGET) {
    auto endpoint = EndpointData({HTTPRequest::RequestMethod::POST, HTTPRequest::RequestMethod::GET}, [](auto &r) {});

    ASSERT_TRUE(endpoint.AllowsMethod("POST"));
    ASSERT_TRUE(endpoint.AllowsMethod("GET"));
}

