#pragma once

#include <string>

using std::string;

namespace DecoratorPattern {

    class Beverage
    {
    protected:
        string  description_;

    public:

        Beverage()
        :description_("")
        {            
        }

        virtual const double cost() const
        {
            return 0;
        }

        virtual const string getDescription() const
        {
            return description_;
        }

    };

    class DarkRoast : public Beverage
    {
    private:
        double  price_;

    public:

        DarkRoast(double price)
            :price_(price)
        {
        }

        const double cost() const
        {
            return price_;
        }

    };


    //************Decorator*******************

    class CondimentDecorator : public Beverage
    {

    public:
        virtual const double cost()
        {
            return 0;
        }

        virtual const string getDescription() const
        {
            return description_;
        }

    };


    class Mocha : public CondimentDecorator
    {
    private:
        double     price_;
        Beverage* beverage_;

    public:

        Mocha(double price,
            Beverage* beverage)
            :price_(price),
            beverage_(beverage)
        {
            description_ = "Most Excelent Mocha";
        }

        virtual const double cost()
        {
            return (price_ + beverage_->cost());
        }

        virtual const string getDescription() const
        {
            return description_;
        }

    };

}