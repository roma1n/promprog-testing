//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"


cpr::Response MockGet (const std::string& city, const cpr::Url& url) {
    cpr::Response res;

    if (city == "Dolgoprudny") {
        res.status_code = 403;
        return res;
    }

    res.status_code = 200;

    float temp = 25.3;
    float tomorrow_temp = 27.3;

    if (city == "Moscow") {
        temp = -15.3;
        tomorrow_temp = -25.8;
    }

    if (city == "Paris") {
        temp = 20;
        tomorrow_temp = 25;
    }

    if (city == "Omsk") {
        temp = -15.3;
        tomorrow_temp = -16.4;
    }

    if (city == "Los Angeles") {
        temp = 30;
        tomorrow_temp = 30.4;
    }

    res.text = "{\"main\": {\"temp\": " + std::to_string(temp) 
        + "}, \"list\": [{}, {}, {}, {}, {}, {}, {}, {\"main\": {\"temp\": " 
        + std::to_string(tomorrow_temp) + "} } ] }";

    return res;
}

WeatherMock::WeatherMock(): Weather() {
    ON_CALL(
        *this,
        Get
    ).WillByDefault([](const std::string& city, const cpr::Url& url){
        return MockGet(city, url);
    });
}
