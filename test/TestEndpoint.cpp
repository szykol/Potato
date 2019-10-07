#include <gtest/gtest.h>

#include "../src/Endpoint.h"

TEST(EndpointTest, EnumToStrWorks) {
    ASSERT_EQ("GET", EndpointData::EnumToStr(RequestMethod::GET));
    ASSERT_EQ("POST", EndpointData::EnumToStr(RequestMethod::POST));
}

TEST(EndpointTest, StrToEnumWorks) {
    ASSERT_EQ(RequestMethod::GET, EndpointData::StrToEnum("GET"));
    ASSERT_EQ(RequestMethod::POST, EndpointData::StrToEnum("POST"));
}

TEST(EndpointTest, AllowsMethodsWorksGET) {
    auto endpoint = EndpointData({RequestMethod::GET}, [](auto &r) {});

    ASSERT_TRUE(endpoint.AllowsMethod("GET"));
    ASSERT_FALSE(endpoint.AllowsMethod("POST"));
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

