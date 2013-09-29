#include <gtest/gtest.h>
#include "../src/timetype.h"

TEST(TimeType, DegreeOfMidnight) {
    sandbox::TimeType t(0,  0);
    EXPECT_DOUBLE_EQ(0.0, t.getDegree());
}

TEST(TimeType, DegreeOfFiveToHalfPastFive) {
    sandbox::TimeType t(5, 25);
    EXPECT_DOUBLE_EQ(0.0, t.getDegree());
}

TEST(TimeType, DegreeOfTenToEleven) {
    sandbox::TimeType t(10, 50);
    EXPECT_DOUBLE_EQ(0.0, t.getDegree());
}

TEST(TimeType, DegreeOfFivePastThirteen) {
    sandbox::TimeType t(13, 05);
    EXPECT_DOUBLE_EQ(0.0, t.getDegree());
}

TEST(TimeType, DegreeOfTenToHalfPastThirteen) {
    sandbox::TimeType t(13, 20);
    EXPECT_DOUBLE_EQ(90.0, t.getDegree());
}

TEST(TimeType, DegreeOfHalfPastNine) {
    sandbox::TimeType t( 9, 30);
    EXPECT_DOUBLE_EQ(90.0, t.getDegree());
}

TEST(TimeType, DegreeOfFivePastTwentytwo) {
    sandbox::TimeType t(22,  5);
    EXPECT_DOUBLE_EQ(90.0, t.getDegree());
}

TEST(TimeType, DegreeOfFivePastHalfPastFour) {    
    sandbox::TimeType t( 4, 35);
    EXPECT_DOUBLE_EQ(90.0, t.getDegree());
}

TEST(TimeType, DegreeOfHalfPastNoon) {
    sandbox::TimeType t(12, 30);
    EXPECT_DOUBLE_EQ(180.0, t.getDegree());
}

TEST(TimeType, DegreeOfQuarterToFour) {
    sandbox::TimeType t(3, 45);
    EXPECT_DOUBLE_EQ(180.0, t.getDegree());
}

TEST(TimeType, DegreeOfTenPastHalfPastFourteen) {    
    sandbox::TimeType t(14, 40);
    EXPECT_DOUBLE_EQ(180.0, t.getDegree());
}

TEST(TimeType, DegreeOfFiveToHalfPastEleven) {
    sandbox::TimeType t(11, 25);
    EXPECT_DOUBLE_EQ(180.0, t.getDegree());
}
