#pragma once

#include <string>
#include <iostream>

using std::string;

using std::cout;
using std::endl;

enum PizzaType{
    CHEESE = 0,
    PEPPERONI,
    CLAM,
    VEGGIE,
    TOTALCOUNT
};


class Pizza
{
public:
    Pizza() {};
    virtual ~Pizza() {};

public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

class CheesePizza : public Pizza
{
public:
    void prepare() { cout << "CheesePizza::prepare" << endl;}

    void bake() { cout << "CheesePizza::bake" << endl; }

    void cut() { cout << "CheesePizza::cut" << endl; }

    void box() { cout << "CheesePizza::box" << endl; }
};

class PepperoniPizza : public Pizza
{
public:
    void prepare() { cout << "PepperoniPizza::prepare" << endl; }

    void bake() { cout << "PepperoniPizza::bake" << endl; }

    void cut() { cout << "PepperoniPizza::cut" << endl; }

    void box() { cout << "PepperoniPizza::box" << endl; }
};

class ClamPizza : public Pizza
{
public:
    void prepare() { cout << "ClamPizza::prepare" << endl; }

    void bake() { cout << "ClamPizza::bake" << endl; }

    void cut() { cout << "ClamPizza::cut" << endl; }

    void box() { cout << "ClamPizza::box" << endl; }
};

class VeggiePizza : public Pizza
{
public:
    void prepare() { cout << "VeggiePizza::prepare" << endl; }

    void bake() { cout << "VeggiePizza::bake" << endl; }

    void cut() { cout << "VeggiePizza::cut" << endl; }

    void box() { cout << "VeggiePizza::box" << endl; }
};


class SimplePizzaFactory
{
public:
    static Pizza* creatPizza(PizzaType type);



};


class PizzaStore
{
public:
    PizzaStore(){};

    Pizza* orderPizza(PizzaType type);

private:

};