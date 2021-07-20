#include "Observer.h"

using std::unique_ptr;

namespace ObserverPattern {
    void WeatherData::measurementsChanged()
    {
        notifyObserver();
    }

    void WeatherData::setMeasurements(const WeatherInfo& stWeatherInfo)
    {
        m_stWeatherInfo = stWeatherInfo;
        measurementsChanged();
    }

    void testObserver()
    {
        WeatherData* spWeatherData = new WeatherData();
    
        shared_ptr<CurrentConditionDispaly> spCurrentCondition(new CurrentConditionDispaly(spWeatherData));
        shared_ptr<StatisticDispaly> spStatistic(new StatisticDispaly(spWeatherData));
        shared_ptr<ForecastDispaly> spForecast(new ForecastDispaly(spWeatherData));
        shared_ptr<ThirdPartyDispaly> spThirdParty(new ThirdPartyDispaly(spWeatherData));


        WeatherInfo stWeatherInfo;
        stWeatherInfo.m_fTemperature = 1.0;
        stWeatherInfo.m_fHumidity = 2.0;
        stWeatherInfo.m_fPressure = 3.0;
        spWeatherData->setMeasurements(stWeatherInfo);
    }

}

int main()
{
    ObserverPattern::testObserver();

    getchar();
    return 0;
}