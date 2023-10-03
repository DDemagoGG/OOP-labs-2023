#include <gtest/gtest.h>
#include "lab1header.hpp"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(result("aba") == "bab");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(result("acb") == "bca");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(result("aabacbaa") == "bbabcabb");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
