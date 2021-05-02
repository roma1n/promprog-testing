//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"


std::string WeatherTestCase::TestDif(std::string city1, std::string city2) {
    WeatherMock w;
    auto res = w.GetDifferenceString(city1, city2);
    return res;
}

std::string WeatherTestCase::TestTomorrowDif(std::string city) {
    WeatherMock w;
    auto res = w.GetTomorrowDiff(city);
    return res;
}

void WeatherTestCase::TestApyKey(std::string key) {
    WeatherMock w;
    w.SetApiKey(key);
}

TEST_F(WeatherTestCase, TestDifWarmer) {
    EXPECT_NO_THROW(WeatherTestCase::TestDif("Moscow", "London"));
}

TEST_F(WeatherTestCase, TestDifColder) {
    EXPECT_NO_THROW(WeatherTestCase::TestDif("London", "Moscow"));
}

TEST_F(WeatherTestCase, TestTomorrowDifMuchColder) {
    EXPECT_NO_THROW(WeatherTestCase::TestTomorrowDif("Moscow"));
}

TEST_F(WeatherTestCase, TestTomorrowDifWarmer) {
    EXPECT_NO_THROW(WeatherTestCase::TestTomorrowDif("London"));
}

TEST_F(WeatherTestCase, TestTomorrowDifMuchWarmer) {
    EXPECT_NO_THROW(WeatherTestCase::TestTomorrowDif("Paris"));
}

TEST_F(WeatherTestCase, TestTomorrowDifColder) {
    EXPECT_NO_THROW(WeatherTestCase::TestTomorrowDif("Omsk"));
}

TEST_F(WeatherTestCase, TestTomorrowDifSame) {
    EXPECT_NO_THROW(WeatherTestCase::TestTomorrowDif("Los Angeles"));
}

TEST_F(WeatherTestCase, ApiKey) {
    EXPECT_NO_THROW(WeatherTestCase::TestApyKey("abacaba"));
}

