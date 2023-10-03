#include <gtest/gtest.h>
#include "../include/Five.hpp"

TEST(equal, test_01){
    Five a{'1'};
    int res = (a == a);
    ASSERT_TRUE(res == 1);
}

TEST(equal, test_02){
    Five a{'1'};
    Five b{'0'};
    int res = (a == b);
    ASSERT_TRUE(res == 0);
}

TEST(equal, test_03){
    Five a{'1'};
    Five b{'1'};
    int res = (a == b);
    ASSERT_TRUE(res == 1);
}



TEST(assignment, test_01){
    Five a{'1'};
    Five b{'0'};
    a = b;
    ASSERT_TRUE(a == b);
}



TEST(not_equal, test01) {
    Five num1("21"), num2("21");
    ASSERT_FALSE(num1 != num2);
}

TEST(not_equal, test02) {
    Five num1("23"), num2("1");
    ASSERT_TRUE(num1 != num2);
}

TEST(not_equal, test03) {
    Five num1("322");
    ASSERT_FALSE(num1 != Five{"322"});
}

TEST(not_equal, test04) {
    Five num1("10");
    ASSERT_TRUE(num1 != Five{"433"});
}



TEST (greater, test01) {
    Five num1("34"), num2("1");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test02) {
    Five num1("143");
    ASSERT_FALSE(num1 > num1);
}

TEST(greater, test03) {
    Five num1("22"), num2("12");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test04) {
    Five num1("10"), num2("1220");
    ASSERT_FALSE(num1 > num2);
}

TEST(greater_or_equal, test01) {
    Five num1("34"), num2("1");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_equal, test02) {
    Five num1("144");
    ASSERT_TRUE(num1 >= num1);
}

TEST(greater_or_equal, test03) {
    Five num1("22"), num2("12");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_equal, test04) {
    Five num1("10"), num2("1220");
    ASSERT_FALSE(num1 >= num2);
}



TEST(less, test01) {
    Five num1("34"), num2("1");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test02) {
    Five num1("142");
    ASSERT_FALSE(num1 < num1);
}

TEST(less, test03) {
    Five num1("22"), num2("12");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test04) {
    Five num1("10"), num2("1220");
    ASSERT_TRUE(num1 < num2);
}

TEST(less, test05) {
    Five num1("10100"), num2("10010");
    ASSERT_FALSE(num1 < num2);
}



TEST(less_or_equal, test01) {
    Five num1("34"), num2("1");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_equal, test02) {
    Five num1("144");
    ASSERT_TRUE(num1 <= num1);
}

TEST(less_or_equal, test03) {
    Five num1("22"), num2("12");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_equal, test04) {
    Five num1("10"), num2("1220");
    ASSERT_TRUE(num1 <= num2);
}



TEST(add, test01) {
    Five num1("0"), num2("12");
    ASSERT_TRUE(num1 + num2 == Five{"12"});
}

TEST(add, test02) {
    Five num1("234"), num2("0");
    ASSERT_TRUE(num1 + num2 == Five{"234"});
}

TEST(add, test03) {
    Five num1("40"), num2("1");
    ASSERT_TRUE(num1 + num2 == Five{"41"});
}

TEST(add, test04) {
    Five num1("4"), num2("10");
    ASSERT_TRUE(num1 + num2 == Five{"14"});
}

TEST(add, test05) {
    Five num1("4"), num2("1");
    ASSERT_TRUE(num1 + num2 == Five{"10"});
}

TEST(add, test06) {
    Five num1("30"), num2("12");
    ASSERT_TRUE(num1 + num2 == Five{"42"});
}

TEST(add, test07) {
    Five num1("123000000000000232211232211111112"), num2("123424314232332");
    ASSERT_TRUE(num1 + num2 == Five{"123000000000000232340212030343444"});
}



TEST(sub, test01) {
    Five num1("12"), num2("10");
    ASSERT_TRUE(num1 - num2 == Five{'2'});
}

TEST(sub, test02) {
    Five num1("4"), num2("1");
    ASSERT_TRUE(num1 - num2 == Five{'3'});
}

TEST(sub, test03) {
    Five num1("10"), num2("3");
    ASSERT_TRUE(num1 - num2 == Five{'2'});
}

TEST(sub, test04) {
    Five num1("24232"), num2("24232");
    ASSERT_TRUE(num1 - num2 == Five{'0'});
}

TEST(sub, test05) {
    Five num1("3"), num2("12");
    ASSERT_ANY_THROW(num1 - num2);
}

TEST(sub, test06) {
    Five num1("123000000000000232211232211111112"), num2("44444444444444444444");
    ASSERT_TRUE(num1 - num2 == Five{"122444444444400232211232211111113"});
}

TEST(sub, test07) {
    Five num1("10100"), num2("10010");
    ASSERT_TRUE(num1 - num2 == Five{"40"});
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}