#include <gtest/gtest.h>
#include "Trapezoid.hpp"

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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}