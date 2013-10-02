#include <gtest/gtest.h>
#include "../../src/shed.h"
#include <string>
#include <cstring>

TEST(Shed, PalindromeConstEmptyCString) {
    const char input[] = "";
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeConstEmptyString) {
    const std::string input("");
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeEmptyCString) {
    char input[] = "";
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeEmptyString) {
    std::string input("");
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}
