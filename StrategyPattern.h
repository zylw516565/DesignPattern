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
            cout << "�û����������" << endl;
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
            cout << "Ѽ�����ɽ�" << endl;
        }
    };

    class Squeak :public  QuackBehavior
    {
        void quack()
        {
            cout << "��ƤѼ��֨֨��" << endl;
        }
    };

    class MuteQuack :public  QuackBehavior
    {
        void quack()
        {
            cout << "ʲô������, �����" << endl;
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
            cout << "��Ӿ" << endl;
        }

        void display()
        {
            cout << "�������ͷ" << endl;
        }

    };





}