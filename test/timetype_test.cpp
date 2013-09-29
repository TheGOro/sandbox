#include <gtest/gtest.h>
#include "../src/timetype.h"

TEST(TimeType, DegreeOfMidnight) {
    TimeType t(0,  0);
    EXPECT_DOUBLE_EQ(0.0, t.getDegree());
}

TEST(TimeType, DegreeOfFiveToHalfPastFive) {
    TimeType t(5, 25);
    EXPECT_DOUBLE_EQ(0.0, t.getDegree());
}

TEST(TimeType, DegreeOfTenToEleven) {
    TimeType t(10, 50);
    EXPECT_DOUBLE_EQ(0.0, t.getDegree());
}

TEST(TimeType, DegreeOfFivePastThirteen) {
    TimeType t(13, 05);
    EXPECT_DOUBLE_EQ(0.0, t.getDegree());
}

TEST(TimeType, DegreeOfTenToHalfPastThirteen) {
    TimeType t(13, 20);
    EXPECT_DOUBLE_EQ(90.0, t.getDegree());
}

TEST(TimeType, DegreeOfHalfPastNine) {
    TimeType t( 9, 30);
    EXPECT_DOUBLE_EQ(90.0, t.getDegree());
}

TEST(TimeType, DegreeOfFivePastTwentytwo) {
    TimeType t(22,  5);
    EXPECT_DOUBLE_EQ(90.0, t.getDegree());
}

TEST(TimeType, DegreeOfFivePastHalfPastFour) {    
    TimeType t( 4, 35);
    EXPECT_DOUBLE_EQ(90.0, t.getDegree());
}

TEST(TimeType, DegreeOfHalfPastNoon) {
    TimeType t(12, 30);
    EXPECT_DOUBLE_EQ(180.0, t.getDegree());
}

TEST(TimeType, DegreeOfQuarterToFour) {
    TimeType t(3, 45);
    EXPECT_DOUBLE_EQ(180.0, t.getDegree());
}

TEST(TimeType, DegreeOfTenPastHalfPastFourteen) {    
    TimeType t(14, 40);
    EXPECT_DOUBLE_EQ(180.0, t.getDegree());
}

TEST(TimeType, DegreeOfFiveToHalfPastEleven) {
    TimeType t(11, 25);
    EXPECT_DOUBLE_EQ(180.0, t.getDegree());
}
