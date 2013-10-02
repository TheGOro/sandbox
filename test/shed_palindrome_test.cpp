#include <gtest/gtest.h>
#include "../src/shed.h"
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

TEST(Shed, PalindromeOneLetterCString) {
    char input[] = "R";
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeOneLetterString) {
    std::string input("y");
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeString_AlplA) {
    std::string input("AlplA");
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeString_wqw) {
    std::string input("wqw");
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeString_alorTvwLPooPLwvTrola) {
    std::string input("alorTvwLPooPLwvTrola");
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeConstString_Atpta) {
    const std::string input("Atpta");
    bool result = sandbox::isPalindrome(input);
    EXPECT_FALSE(result);
}

TEST(Shed, PalindromeConstCString_LoOoL) {
    const char input[] = "LoOoL";
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeCString_Bad_example) {
    char input[] = "Bad example";
    bool result = sandbox::isPalindrome(input);
    EXPECT_FALSE(result);
}

TEST(Shed, PalindromeCString_nNnnnNnNNnNNnNnnnNn) {
    char input[] = "nNnnnNnNNnNNnNnnnNn";
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeCString_aA_Aa) {
    char input[] = "aA Aa";
    bool result = sandbox::isPalindrome(input);
    EXPECT_TRUE(result);
}

TEST(Shed, PalindromeCString_xyzx) {
    char input[] = "xyzx";
    bool result = sandbox::isPalindrome(input);
    EXPECT_FALSE(result);
}
