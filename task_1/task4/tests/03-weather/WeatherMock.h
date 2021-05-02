//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>
#include "cpr/cpr.h"

class WeatherMock : public Weather {
public:
    cpr::Response Get (const std::string& city, const cpr::Url& url);
};
