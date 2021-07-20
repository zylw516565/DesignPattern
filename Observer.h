#pragma once

#include <set>
#include <memory>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

using std::set;
using std::weak_ptr;
using std::shared_ptr;

namespace ObserverPattern {

    struct WeatherInfo
    {
        float m_fTemperature;
        float m_fHumidity;
        float m_fPressure;

        WeatherInfo()
            :m_fTemperature(0)
            , m_fHumidity(0)
            , m_fPressure(0)
        {}

        WeatherInfo(const WeatherInfo& other)
        {
            m_fTemperature = other.m_fTemperature;
            m_fHumidity = other.m_fHumidity;
            m_fPressure = other.m_fPressure;
        }

        WeatherInfo& operator=(const WeatherInfo& other)
        {
            m_fTemperature = other.m_fTemperature;
            m_fHumidity = other.m_fHumidity;
            m_fPressure = other.m_fPressure;
            return *this;
        }
    };

    class Subject;

    class Observer
    {
    public:
        Observer() = default;
        virtual ~Observer() = default;

    public:
        virtual void update(const WeatherInfo& stWeatherInfo) = 0;

    protected:
        WeatherInfo  m_stWeatherInfo;

        Subject*  weatherData_;
    };


    class Subject
    {
    public:
        Subject() = default;
        virtual ~Subject() = default;

    public:
        virtual void registerObserver(const shared_ptr<Observer>& observer) = 0;

        virtual void removeObserver(const shared_ptr<Observer>& observer) = 0;

        virtual void notifyObserver() = 0;
    };


    class WeatherData :public Subject
    {
    public:
        WeatherData()
            :m_fTemperature(0.0)
            , m_fHumidity(0.0)
            , m_fPressure(0.0)
        {}


    public:

        virtual void registerObserver(const shared_ptr<Observer>& observer)
        {
            m_setObservers.insert(observer);
        }

        virtual void removeObserver(const shared_ptr<Observer>& observer)
        {
            auto iter = m_setObservers.find(observer);
            if (iter != m_setObservers.end())
            {
                m_setObservers.erase(iter);
            }
        }

        virtual void notifyObserver()
        {
            for (auto item : m_setObservers)
            {
                item->update(m_stWeatherInfo);
            }
        }

    public:

        float getTemperature();
        float getHumidity();
        float getPressure();

        void measurementsChanged();

        void setMeasurements(const WeatherInfo& stWeatherInfo);

    private:

        set<shared_ptr<Observer>>  m_setObservers;

        WeatherInfo m_stWeatherInfo;

        float m_fTemperature;
        float m_fHumidity;
        float m_fPressure;
    };

    class DisplayElement
    {
    public:
        DisplayElement() = default;
        virtual~DisplayElement() = default;

    public:
        virtual void display() = 0;
    };

    class CurrentConditionDispaly : public Observer, DisplayElement
    {
    public:
        CurrentConditionDispaly(Subject* spWeatherData)
        {
            weatherData_ = spWeatherData;
            weatherData_->registerObserver(shared_ptr<Observer>(this));
        }

        virtual ~CurrentConditionDispaly() {}

    public:
        virtual void update(const WeatherInfo& stWeatherInfo)
        {
            m_stWeatherInfo = stWeatherInfo;
            cout << "CurrentConditionDispaly::update" << endl;
        }

        virtual void display()
        {
        }

    };

    class StatisticDispaly : public Observer, DisplayElement
    {
    public:
        StatisticDispaly(Subject* spWeatherData)
        {
            weatherData_ = spWeatherData;
            weatherData_->registerObserver(shared_ptr<Observer>(this));
        }

        virtual void update(const WeatherInfo& stWeatherInfo)
        {
            m_stWeatherInfo = stWeatherInfo;
            cout << "StatisticDispaly::update" << endl;
        }

        virtual void display()
        {
        }
    };

    class ForecastDispaly : public Observer, DisplayElement
    {
    public:
        ForecastDispaly(Subject* spWeatherData)
        {
            weatherData_ = spWeatherData;
            weatherData_->registerObserver(shared_ptr<Observer>(this));
        }

        virtual void update(const WeatherInfo& stWeatherInfo)
        {
            m_stWeatherInfo = stWeatherInfo;
            cout << "ForecastDispaly::update" << endl;
        }

        virtual void display()
        {
        }
    };

    class ThirdPartyDispaly : public Observer, DisplayElement
    {
    public:
        ThirdPartyDispaly(Subject* spWeatherData)
        {
            weatherData_ = spWeatherData;
            weatherData_->registerObserver(shared_ptr<Observer>(this));
        }

        virtual void update(const WeatherInfo& stWeatherInfo)
        {
            m_stWeatherInfo = stWeatherInfo;
            cout << "ThirdPartyDispaly::update" << endl;
        }

        virtual void display()
        {
        }
    };

}