#pragma once

#include <string>

using std::string;

namespace DecoratorPattern {

    class Beverage
    {
    protected:
        double  price_;
        string  description_;

    public:

        Beverage()
        :price_(0.0),
        description_("Unknown Beverage")
        {            
        }

        virtual const double cost() const
        {
            return price_;
        }

        virtual const string getDescription() const
        {
            return description_;
        }

    };

    class DarkRoast : public Beverage
    {

    public:

        DarkRoast(double price)
        {
            price_ = price;
            description_ = "DarkRoast";
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
        CondimentDecorator()       
        {
            description_ = "CondimentDecorator";
        }

        virtual const double cost()
        {
            return price_;
        }

        virtual const string getDescription() const
        {
            return description_;
        }

    };


    class Mocha : public CondimentDecorator
    {
    private:
        Beverage* beverage_;

    public:

        Mocha(double price,
            Beverage* beverage)
            :beverage_(beverage)
        {
            price_ = price;
        }

        virtual const double cost()
        {
            return (price_ + beverage_->cost());
        }

        virtual const string getDescription() const
        {
            return beverage_->getDescription() + ", Mocha";
        }

    };

    class Soy : public CondimentDecorator
    {
    private:
        Beverage* beverage_;

    public:

        Soy(double price,
            Beverage* beverage)
            :beverage_(beverage)
        {
            price_ = price;
        }

        virtual const double cost()
        {
            return (price_ + beverage_->cost());
        }

        virtual const string getDescription() const
        {
            return beverage_->getDescription() + ", Soy";
        }

    };

    class Whip : public CondimentDecorator
    {
    private:
        Beverage* beverage_;

    public:

        Whip(double price,
            Beverage* beverage)
            :beverage_(beverage)
        {
            price_ = price;
        }

        virtual const double cost()
        {
            return (price_ + beverage_->cost());
        }

        virtual const string getDescription() const
        {
            return beverage_->getDescription() + ", Whip";
        }

    };

}