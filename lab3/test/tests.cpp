#include <gtest/gtest.h>
#include "Trapezoid.hpp"
#include "Rhombus.hpp"
#include "Pentagon.hpp"

const double EPS = 0.0001;

TEST(trapezoid_center, test_01){
    Trapezoid trap{Point{2, 3}, Point{5, 3}, Point{0, 0}, Point{7, 0}};
    ASSERT_EQ(trap.getCenter(), Point(3.5, 1.5));
}

TEST(trapezoid_center, test_02){
    Trapezoid trap{Point{0, 13}, Point{3, 13}, Point{-2, 10}, Point{5, 10}};
    ASSERT_EQ(trap.getCenter(), Point(1.5, 11.5));
}

TEST(trapezoid_center, test_03){
    Trapezoid trap{Point{1, 4}, Point{6, 4}, Point{-1, -1}, Point{8, -1}};
    ASSERT_EQ(trap.getCenter(), Point(3.5, 1.5));
}

TEST(trapezoid_area, test_01){
    Trapezoid trap{Point{2, 3}, Point{5, 3}, Point{0, 0}, Point{7, 0}};
    ASSERT_EQ(double(trap), 15);
}

TEST(trapezoid_area, test_02){
    Trapezoid trap{Point{0, 13}, Point{3, 13}, Point{-2, 10}, Point{5, 10}};
    ASSERT_EQ(double(trap), 15);
}

TEST(rhombus_center, test_01){
    Rhombus romb{Point{4, 3}, Point{7, 0}, Point{4, -3}, Point{1, 0}};
    ASSERT_EQ(romb.getCenter(), Point(4, 0));
}

TEST(rhombus_center, test_02){
    Rhombus romb{Point{4, 4}, Point{8, 0}, Point{4, -4}, Point{0, 0}};
    ASSERT_EQ(romb.getCenter(), Point(4, 0));
}

TEST(rhombus_center, test_03){
    Rhombus romb{Point{-1.5, 100}, Point{-24.1, 95}, Point{-1.5, 90}, Point{21.1, 95}};
    ASSERT_EQ(romb.getCenter(), Point(-1.5, 95));
}

TEST(rhombus_area, test_01){
    Rhombus romb{Point{4, 4}, Point{8, 0}, Point{4, -4}, Point{0, 0}};
    ASSERT_EQ(double(romb), 32);
}

TEST(rhombus_area, test_02){
    Rhombus romb{Point{4, 3}, Point{7, 0}, Point{4, -3}, Point{1, 0}};
    ASSERT_EQ(double(romb), 18);
}

TEST(pentagon_center, test_01){
    Pentagon pent{Point{1, 0}, Point{0.3090, 0.9511}, Point{-0.8090, 0.5878}, Point{-0.8090, -0.5878}, Point{0.3090, -0.9511}};
    Point cent = pent.getCenter();
    ASSERT_TRUE((fabs(cent.getX() - 1) < EPS) and (fabs(cent.getY() + 1) < EPS));
}

TEST(pentagon_area, test_01){
    Pentagon pent{Point{1, 0}, Point{0.3090, 0.9511}, Point{-0.8090, 0.5878}, Point{-0.8090, -0.5878}, Point{0.3090, -0.9511}};
    double s = double(pent);
    ASSERT_TRUE(s - 2.37784 < EPS);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}