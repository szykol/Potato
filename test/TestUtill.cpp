#include <gtest/gtest.h>

#include "../src/Utill.h"

TEST(UtillSplitTest, WorksAsExpected) {
    auto str = "POST / HTTP/1.1";

    auto splitStrings = split(str, " ");
    ASSERT_EQ(splitStrings.size(), 3);

    ASSERT_EQ(splitStrings[0], "POST");
    ASSERT_EQ(splitStrings[1], "/");
    ASSERT_EQ(splitStrings[2], "HTTP/1.1");
}

TEST(UtillSplitTest, EmptySubstr) {
    auto str = "POST / HTTP/1.1";

    auto splitStrings = split(str, "");
    ASSERT_EQ(splitStrings.size(), 0);
}

TEST(UtillSplitTest, SubstrDoesNotOccur) {
    auto str = "POST / HTTP/1.1";

    auto splitStrings = split(str, "Does not occur");
    ASSERT_EQ(splitStrings.size(), 0);
}

TEST(UtillSplitTest, WeirdInputs) {
    auto str = std::string("ffffffffffff");

    auto splitStrings = split(str, "f");
    ASSERT_EQ(splitStrings.size(), str.size());
}

TEST(UtillSplitTest, SubstrIsStr) {
    auto str = std::string("fff");

    auto splitStrings = split(str, "fff");
    ASSERT_EQ(splitStrings.size(), 1);
}

TEST(UtillTrimTest, TrimWorks) {
	ASSERT_EQ(trim("  Hello, World!\n"), "Hello,World!");	
}

TEST(UtillTrimTest, EmptyString) {
	ASSERT_EQ(trim(""), "");
}

TEST(UtillTrimTest, OnlyWhiteSpace) {
	ASSERT_EQ(trim("   \n \t"), "");
}

TEST(UtillTrimTest, NoWhitespace) {
	ASSERT_EQ(trim("Hello,World!"), "Hello,World!");
}
