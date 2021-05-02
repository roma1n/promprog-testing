
#pragma once

#include <gtest/gtest.h>

#include<string>

class WeatherTestCase : public ::testing::Test {
public:
    std::string TestDif(std::string city1, std::string city2);
    std::string TestTomorrowDif(std::string city);
    void TestApyKey(std::string city);
};
