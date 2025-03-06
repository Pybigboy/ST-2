#include "circle.h"
#include "tasks.h"
#include <gtest/gtest.h>

TEST(CircleTest, RadiusTest) {
    Circle c(10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10);
}

TEST(CircleTest, CircumferenceTest) {
    Circle c(10);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 2 * M_PI * 10);
}

TEST(CircleTest, AreaTest) {
    Circle c(10);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 10 * 10);
}

TEST(CircleTest, SetRadiusTest) {
    Circle c(10);
    c.setRadius(20);
    EXPECT_DOUBLE_EQ(c.getRadius(), 20);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 2 * M_PI * 20);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 20 * 20);
}

TEST(CircleTest, SetCircumferenceTest) {
    Circle c(10);
    c.setCircumference(2 * M_PI * 15);
    EXPECT_DOUBLE_EQ(c.getRadius(), 15);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 2 * M_PI * 15);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 15 * 15);
}

TEST(CircleTest, SetAreaTest) {
    Circle c(10);
    c.setArea(M_PI * 25 * 25);
    EXPECT_DOUBLE_EQ(c.getRadius(), 25);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 2 * M_PI * 25);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25 * 25);
}

TEST(CircleTest, ZeroRadiusTest) {
    Circle c(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, ZeroCircumferenceTest) {
    Circle c(10);
    c.setCircumference(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, ZeroAreaTest) {
    Circle c(10);
    c.setArea(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, LargeRadiusTest) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e6 * 1e6);
}

TEST(CircleTest, LargeCircumferenceTest) {
    Circle c(10);
    c.setCircumference(2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
}

TEST(CircleTest, LargeAreaTest) {
    Circle c(10);
    c.setArea(M_PI * 1e6 * 1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
}

TEST(CircleTest, PrecisionCircumferenceTest) {
    Circle c(1);
    EXPECT_NEAR(c.getCircumference(), 2 * M_PI * 1, 1e-10);
}

TEST(CircleTest, PrecisionAreaTest) {
    Circle c(1);
    EXPECT_NEAR(c.getArea(), M_PI * 1 * 1, 1e-10);
}

TEST(CircleTest, InvariantsTest) {
    Circle c(10);
    double r = c.getRadius();
    double a = c.getArea();
    double circ = c.getCircumference();
    EXPECT_DOUBLE_EQ(circ, 2 * M_PI * r);
    EXPECT_DOUBLE_EQ(a, M_PI * r * r);
}

TEST(CircleTest, NegativeRadiusTest) {
    EXPECT_THROW(Circle(-10), std::invalid_argument);
}
TEST(CircleTest, NegativeCircumferenceTest) {
    Circle c(10);
    EXPECT_THROW(c.setCircumference(-50), std::invalid_argument);
}

TEST(CircleTest, NegativeAreaTest) {
    Circle c(10);
    EXPECT_THROW(c.setArea(-100), std::invalid_argument);
}

TEST(CircleTest, ExtremeSmallRadiusTest) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getCircumference(), 2 * M_PI * 1e-6, 1e-12);
    EXPECT_NEAR(c.getArea(), M_PI * 1e-6 * 1e-6, 1e-12);
}

TEST(CircleTest, CopyConstructorTest) {
    Circle c1(10);
    Circle c2 = c1;
    EXPECT_DOUBLE_EQ(c2.getRadius(), c1.getRadius());
    EXPECT_DOUBLE_EQ(c2.getCircumference(), c1.getCircumference());
    EXPECT_DOUBLE_EQ(c2.getArea(), c1.getArea());
}

TEST(CircleTest, AssignmentOperatorTest) {
    Circle c1(10);
    Circle c2(20);
    c2 = c1;
    EXPECT_DOUBLE_EQ(c2.getRadius(), c1.getRadius());
    EXPECT_DOUBLE_EQ(c2.getCircumference(), c1.getCircumference());
    EXPECT_DOUBLE_EQ(c2.getArea(), c1.getArea());
}




