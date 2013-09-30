#include <gtest/gtest.h>
#include <limits>
#include "../src/shed.h"

TEST(Shed, SwapBoolsTrueTrue) {
    bool a = true, b = true;
    sandbox::swap(a, b);
    EXPECT_TRUE(a);
    EXPECT_TRUE(b);
}

TEST(Shed, SwapBoolsFalseFalse) {
    bool a = false, b = false;
    sandbox::swap(a, b);
    EXPECT_FALSE(a);
    EXPECT_FALSE(b);
}

TEST(Shed, SwapBoolsTrueFalse) {
    bool a = true, b = false;
    sandbox::swap(a, b);
    EXPECT_FALSE(a);
    EXPECT_TRUE(b);
}

TEST(Shed, SwapIntsBothPositive) {
    int a = 174, b = 7931;
    sandbox::swap(a, b);
    EXPECT_EQ(7931, a);
    EXPECT_EQ(174, b);
}

TEST(Shed, SwapIntsPositiveNegative) {
    int a = 739, b = -941;
    sandbox::swap(a, b);
    EXPECT_EQ(-941, a);
    EXPECT_EQ(739, b);
}

TEST(Shed, SwapIntsNullNull) {
    int a = 0, b = 0;
    sandbox::swap(a, b);
    EXPECT_EQ(0, a);
    EXPECT_EQ(0, b);
}

TEST(Shed, SwapIntsMinMax) {
    std::numeric_limits<int> limits;
    int a = limits.min(), b = limits.max();
    sandbox::swap(a, b);
    EXPECT_EQ(limits.max(), a);
    EXPECT_EQ(limits.min(), b);
}

TEST(Shed, SwapIntsMaxMin) {
    std::numeric_limits<int> limits;
    int a = limits.max(), b = limits.min();
    sandbox::swap(a, b);
    EXPECT_EQ(limits.min(), a);
    EXPECT_EQ(limits.max(), b);
}

TEST(Shed, SwapIntsMinMin) {
    std::numeric_limits<int> limits;
    int a = limits.min(), b = limits.min();
    sandbox::swap(a, b);
    EXPECT_EQ(limits.min(), a);
    EXPECT_EQ(limits.min(), b);
}

TEST(Shed, SwapIntsMaxMax) {
    std::numeric_limits<int> limits;
    int a = limits.max(), b = limits.max();
    sandbox::swap(a, b);
    EXPECT_EQ(limits.max(), a);
    EXPECT_EQ(limits.max(), b);
}

TEST(Shed, SwapCharsDifferentLowercase) {
    char a = 'b', b = 'a';
    sandbox::swap(a, b);
    EXPECT_EQ('a', a);
    EXPECT_EQ('b', b);
}

TEST(Shed, SwapCharsSameLowercase) {
    char a = 's', b = 's';
    sandbox::swap(a, b);
    EXPECT_EQ('s', a);
    EXPECT_EQ('s', b);
}

TEST(Shed, SwapCharsDifferentUppercase) {
    char a = 'T', b = 'F';
    sandbox::swap(a, b);
    EXPECT_EQ('F', a);
    EXPECT_EQ('T', b);
}

TEST(Shed, SwapCharsSameUppercase) {
    char a = 'Q', b = 'Q';
    sandbox::swap(a, b);
    EXPECT_EQ('Q', a);
    EXPECT_EQ('Q', b);
}

TEST(Shed, SwapCharsDifferentMixedcase) {
    char a = 'E', b = 'p';
    sandbox::swap(a, b);
    EXPECT_EQ('p', a);
    EXPECT_EQ('E', b);
}

TEST(Shed, SwapCharsMinAndMax) {
    std::numeric_limits<char> limits;
    char a = limits.min(), b = limits.max();
    sandbox::swap(a, b);
    EXPECT_EQ(limits.max(), a);
    EXPECT_EQ(limits.min(), b);
}

TEST(Shed, SwapCharsMinMin) {
    std::numeric_limits<char> limits;
    char a = limits.min(), b = limits.min();
    sandbox::swap(a, b);
    EXPECT_EQ(limits.min(), a);
    EXPECT_EQ(limits.min(), b);
}

TEST(Shed, SwapCharsMaxMax) {
    std::numeric_limits<char> limits;
    char a = limits.max(), b = limits.max();
    sandbox::swap(a, b);
    EXPECT_EQ(limits.max(), a);
    EXPECT_EQ(limits.max(), b);
}