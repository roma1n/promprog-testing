//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>

class LeapTestCase : public ::testing::Test {
public:
    bool TestYear(int year);
    int TestMonthDays(int year, int month);
};


