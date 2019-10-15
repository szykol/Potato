#include <gtest/gtest.h>

#include "../src/Request.h"
#include "../src/Socket.h"
#include "../src/Utill.h"
#include "../src/Exception.h"
#include "../src/Endpoint.h"

class MockSocket : public Socket {
public:
    std::string buffer;
    virtual std::string read(uint bytes) override {
        auto substr = buffer.substr(0, bytes);
        buffer.erase(0, bytes);

        return substr;
    }
    MockSocket() : Socket(0) {}
};

TEST(RequestTest, ParsingWorksPOST) {
    const auto httpReq = "POST / HTTP/1.1\r\nAccept: */*\r\nUser-Agent: tests\r\nContent-Length: 5\r\n\r\nhellolo";
    MockSocket m;
    
    m.buffer = httpReq;
    auto r = HTTPRequestParser::getHTTPRequest(m);
    ASSERT_EQ(r.Method(), "POST");
    ASSERT_EQ(r.URI(), "/");
    ASSERT_EQ(r.HTTPVersion(), "HTTP/1.1");

    auto hFields = r.HeaderFields();
    ASSERT_EQ(hFields.size(), 3);
    ASSERT_EQ(hFields["User-Agent"], "tests");
    
    ASSERT_EQ(hFields["Content-Length"], "5");
    ASSERT_EQ(r.Body(), "hello");    
}

TEST(RequestTest, ParsingWorksPOSTTrailing) {
    const auto httpReq = "POST / HTTP/1.1\r\nAccept: */*\r\nUser-Agent: tests\r\nContent-Length: 5\r\n\r\nhelloloasdasdasdasdad";
    MockSocket m;
    
    m.buffer = httpReq;
    auto r = HTTPRequestParser::getHTTPRequest(m);
    ASSERT_EQ(r.Method(), "POST");
    ASSERT_EQ(r.URI(), "/");
    ASSERT_EQ(r.HTTPVersion(), "HTTP/1.1");

    auto hFields = r.HeaderFields();
    ASSERT_EQ(hFields.size(), 3);
    ASSERT_EQ(hFields["User-Agent"], "tests");
    
    ASSERT_EQ(hFields["Content-Length"], "5");
    ASSERT_EQ(r.Body(), "hello");    
}

TEST(RequestTest, ParsingWorksGET) {
    const auto httpReq = "GET / HTTP/1.1\r\nAccept: */*\r\nUser-Agent: tests\r\n\r\n";
    MockSocket m;
    
    m.buffer = httpReq;
    auto r = HTTPRequestParser::getHTTPRequest(m);
    ASSERT_EQ(r.Method(), "GET");
    ASSERT_EQ(r.URI(), "/");
    ASSERT_EQ(r.HTTPVersion(), "HTTP/1.1");

    auto hFields = r.HeaderFields();
    ASSERT_EQ(hFields.size(), 2);
    ASSERT_EQ(hFields["User-Agent"], "tests");
    ASSERT_EQ(hFields["Accept"], "*/*");

    ASSERT_EQ(r.Body(), "");
}

TEST(RequestTest, ParsingWorksGETTrailing) {
    const auto httpReq = "GET / HTTP/1.1\r\nAccept: */*\r\nUser-Agent: tests\r\n\r\n sdsadsad asdsa asd";
    MockSocket m;
    
    m.buffer = httpReq;
    auto r = HTTPRequestParser::getHTTPRequest(m);
    ASSERT_EQ(r.Method(), "GET");
    ASSERT_EQ(r.URI(), "/");
    ASSERT_EQ(r.HTTPVersion(), "HTTP/1.1");

    auto hFields = r.HeaderFields();
    ASSERT_EQ(hFields.size(), 2);
    ASSERT_EQ(hFields["User-Agent"], "tests");
    ASSERT_EQ(hFields["Accept"], "*/*");

    ASSERT_EQ(r.Body(), "");
}

TEST(RequestTest, ParsingWrongStartLine) {
    const auto httpReq = "GET HTTP/1.1\r\nAccept: */*\r\nUser-Agent: tests\r\n\r\n sdsadsad asdsa asd";
    MockSocket m;

    m.buffer = httpReq;
    
    ASSERT_THROW(HTTPRequestParser::getHTTPRequest(m), BadRequest);
}

TEST(RequestTest, MethodExists) {
    ASSERT_FALSE(HTTPRequestParser::methodExists("GOAT"));

    for(int i = int(RequestMethod::GET); i < int(RequestMethod::NONE); i++) {
        ASSERT_TRUE(HTTPRequestParser::methodExists(EndpointData::EnumToStr(RequestMethod(i))));
    }
}

TEST(RequestTest, ParsingWrongHTTPMethod) {
    const auto httpReq = "GOAT / HTTP/1.1\r\nAccept: */*\r\nUser-Agent: tests\r\n\r\n sdsadsad asdsa asd";
    MockSocket m;

    m.buffer = httpReq;

    ASSERT_THROW(HTTPRequestParser::getHTTPRequest(m), InvalidRequestMethod);
}