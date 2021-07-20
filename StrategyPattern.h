#pragma once

#include <iostream>



using std::cout;
using std::endl;

namespace StrategyPattern {


    class FlyBehavior
    {
    public:
        virtual void fly() = 0;

    };

    class FlyWithRocket :public FlyBehavior
    {
        void fly()
        {
            cout << "用火箭动力飞行" << endl;
        }

    };

    class QuackBehavior
    {
    public:
        virtual void quack() = 0;

    };

    class Quack :public  QuackBehavior
    {
        void quack()
        {
            cout << "鸭子呱呱叫" << endl;
        }
    };

    class Squeak :public  QuackBehavior
    {
        void quack()
        {
            cout << "橡皮鸭子吱吱叫" << endl;
        }
    };

    class MuteQuack :public  QuackBehavior
    {
        void quack()
        {
            cout << "什么都不做, 不会叫" << endl;
        }
    };


    class Duck
    {
    protected:
        FlyBehavior*    m_fly;
        QuackBehavior*  m_quack;

    public:

        virtual void swim() = 0;

        virtual void display() = 0;

        void setFlyBehavior(FlyBehavior* fb)
        {
            m_fly = fb;
        }

        void setQuackBehavior(QuackBehavior* fb)
        {
            m_quack = fb;
        }

        void performFly()
        {
            m_fly->fly();
        }

        void performQuack()
        {
            m_quack->quack();
        }
    };

    class MallardDuck :public Duck
    {
    public:

        MallardDuck()
        {
            m_fly = new FlyWithRocket();
            m_quack = new Quack();
        }

        void swim()
        {
            cout << "游泳" << endl;
        }

        void display()
        {
            cout << "外观是绿头" << endl;
        }

    };





}