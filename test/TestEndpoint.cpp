#include <gtest/gtest.h>
#include <gtest/gtest-param-test.h>

#include "../src/Endpoint.h"
#include "../src/Exception.h"

class EndpointTestMethod : public testing::TestWithParam<std::pair<std::string, RequestMethod>>
{

};

INSTANTIATE_TEST_SUITE_P(EndpointMethods,
                        EndpointTestMethod,
                        testing::Values(
                            std::make_pair("GET", RequestMethod::GET),
                            std::make_pair("POST", RequestMethod::POST),
                            std::make_pair("PATCH",RequestMethod::PATCH),
                            std::make_pair("DELETE",RequestMethod::DELETE),
                            std::make_pair("UPDATE",RequestMethod::UPDATE),
                            std::make_pair("OPTIONS",RequestMethod::OPTIONS),
                            std::make_pair("HEAD",RequestMethod::HEAD),
                            std::make_pair("PUT",RequestMethod::PUT),
                            std::make_pair("CONNECT",RequestMethod::CONNECT),
                            std::make_pair("TRACE",RequestMethod::TRACE)
                        )
);

TEST_P(EndpointTestMethod, EnumToStrWorks) {
    auto pair = GetParam();
    auto methodStr = pair.first;
    auto methodEnum = pair.second;

    ASSERT_EQ(methodStr, EndpointData::EnumToStr(methodEnum));
}

TEST_P(EndpointTestMethod, StrToEnumWorks) {
    auto pair = GetParam();
    auto methodStr = pair.first;
    auto methodEnum = pair.second;

    ASSERT_EQ(methodEnum, EndpointData::StrToEnum(methodStr));
}

TEST(EndpointTest, EnumToStrNoneAndInvalid) {
    ASSERT_EQ(RequestMethod::NONE, EndpointData::StrToEnum("NONE"));
    ASSERT_EQ(RequestMethod::NONE, EndpointData::StrToEnum("BLAH"));
}

TEST(EndpointTest, StrToEnumNoneAndInvalid) {
    ASSERT_EQ("NONE", EndpointData::EnumToStr(RequestMethod::NONE));
    ASSERT_EQ("NONE", EndpointData::EnumToStr(RequestMethod(100)));
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