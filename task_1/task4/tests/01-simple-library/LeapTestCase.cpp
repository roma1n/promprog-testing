//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

bool LeapTestCase::TestYear(int year) {
    return IsLeap(year);
}

int LeapTestCase::TestMonthDays(int year, int month) {
    return GetMonthDays(year, month);
}

TEST_F(LeapTestCase, TestSimpleNotLeap) {
    EXPECT_EQ(LeapTestCase::TestYear(2007), false);
}

TEST_F(LeapTestCase, TestSimpleLeap) {
    EXPECT_EQ(LeapTestCase::TestYear(2008), true);
}

TEST_F(LeapTestCase, TestHardLeap) {
    EXPECT_EQ(LeapTestCase::TestYear(2000), true);
}

TEST_F(LeapTestCase, TestHardNotLeap) {
    EXPECT_EQ(LeapTestCase::TestYear(1900), false);
}

TEST_F(LeapTestCase, TestIncorrectInput) {
    EXPECT_THROW(LeapTestCase::TestYear(-1900), std::invalid_argument);
}

TEST_F(LeapTestCase, TestJan) {
    EXPECT_EQ(LeapTestCase::TestMonthDays(2000, 1), 31);
}

TEST_F(LeapTestCase, TestLeapFeb) {
    EXPECT_EQ(LeapTestCase::TestMonthDays(2000, 2), 29);
}

TEST_F(LeapTestCase, TestNotLeapFeb) {
    EXPECT_EQ(LeapTestCase::TestMonthDays(2001, 2), 28);
}

TEST_F(LeapTestCase, TestApr) {
    EXPECT_EQ(LeapTestCase::TestMonthDays(2000, 4), 30);
}

TEST_F(LeapTestCase, TestJun) {
    EXPECT_EQ(LeapTestCase::TestMonthDays(2000, 6), 30);
}

TEST_F(LeapTestCase, TestSep) {
    EXPECT_EQ(LeapTestCase::TestMonthDays(2000, 9), 30);
}

TEST_F(LeapTestCase, TestNov) {
    EXPECT_EQ(LeapTestCase::TestMonthDays(2000, 11), 30);
}

TEST_F(LeapTestCase, TestIncorrectInputMonthDays1) {
    EXPECT_THROW(LeapTestCase::TestMonthDays(2000, 13), std::invalid_argument);
}

TEST_F(LeapTestCase, TestIncorrectInputMonthDays2) {
    EXPECT_THROW(LeapTestCase::TestMonthDays(2000, -11), std::invalid_argument);
}
