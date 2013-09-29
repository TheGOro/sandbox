#include <gtest/gtest.h>
#include "../src/timetype.h"

TEST(TimeType, Degree0) {
    TimeType t1(0,  0);
    EXPECT_DOUBLE_EQ(0.0, t1.getDegree());
    
    TimeType t2(5, 25);
    EXPECT_DOUBLE_EQ(0.0, t2.getDegree());
    
    TimeType t3(10, 50);
    EXPECT_DOUBLE_EQ(0.0, t3.getDegree());
    
    TimeType t4(13, 05);
    EXPECT_DOUBLE_EQ(0.0, t4.getDegree());
}

TEST(TimeType, Degree90) {
    TimeType t1(13, 20);
    EXPECT_DOUBLE_EQ(90.0, t1.getDegree());
    
    TimeType t2( 9, 30);
    EXPECT_DOUBLE_EQ(90.0, t2.getDegree());
    
    TimeType t3(22,  5);
    EXPECT_DOUBLE_EQ(90.0, t3.getDegree());
    
    TimeType t4( 4, 25);
    EXPECT_DOUBLE_EQ(90.0, t4.getDegree());
}

TEST(TimeType, Degree180) {
    TimeType halfPastNoon(12, 30);
    EXPECT_DOUBLE_EQ(180.0, halfPastNoon.getDegree());
    
    TimeType quarterToFour(3, 45);
    EXPECT_DOUBLE_EQ(180.0, quarterToFour.getDegree());
    
    TimeType forteenForty(14, 40);
    EXPECT_DOUBLE_EQ(180.0, forteenForty.getDegree());
    
    TimeType elevenTwentyFive(11, 25);
    EXPECT_DOUBLE_EQ(180.0, elevenTwentyFive.getDegree());
}
