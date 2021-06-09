#pragma once

#include <string>
#include <iostream>
#include <vector>


using std::string;

using std::cout;
using std::endl;
using std::vector;

enum PizzaType{
    CHEESE = 0,
    PEPPERONI,
    CLAM,
    VEGGIE,
    TOTALCOUNT
};

enum StoreType {
    NY_STYLE = 0,
    CHICAGO_STYLE,
    STORE_TOTAL_COUNT
};


class Pizza
{
public:
    Pizza() = default;
    virtual ~Pizza() = default;

public:
    virtual void prepare()
    {
        cout << "Preparing " + name_ << endl;
        cout << "Tossing  dough..." << endl;
        cout << "Adding  sauce..." << endl;
        cout << "Adding  toppings: " << endl;
        for (auto topping : toppings_)
        {
            cout << "  " << topping;
        }

        cout << endl;
    }
    virtual void bake()
    {
    }

    virtual void cut() 
    {
    }

    virtual void box()
    {
    }

    string getName() const
    {
        return name_;
    }

private:
    string  name_;   //披萨名称
    string  dough_;  //面团类型
    string  sauce_;  //酱料类型

    vector<string> toppings_;
};

// class CheesePizza : public Pizza
// {
// public:
//     void prepare() { cout << "CheesePizza::prepare" << endl;}
// 
//     void bake() { cout << "CheesePizza::bake" << endl; }
// 
//     void cut() { cout << "CheesePizza::cut" << endl; }
// 
//     void box() { cout << "CheesePizza::box" << endl; }
// };
// 
// class PepperoniPizza : public Pizza
// {
// public:
//     void prepare() { cout << "PepperoniPizza::prepare" << endl; }
// 
//     void bake() { cout << "PepperoniPizza::bake" << endl; }
// 
//     void cut() { cout << "PepperoniPizza::cut" << endl; }
// 
//     void box() { cout << "PepperoniPizza::box" << endl; }
// };
// 
// class ClamPizza : public Pizza
// {
// public:
//     void prepare() { cout << "ClamPizza::prepare" << endl; }
// 
//     void bake() { cout << "ClamPizza::bake" << endl; }
// 
//     void cut() { cout << "ClamPizza::cut" << endl; }
// 
//     void box() { cout << "ClamPizza::box" << endl; }
// };
// 
// class VeggiePizza : public Pizza
// {
// public:
//     void prepare() { cout << "VeggiePizza::prepare" << endl; }
// 
//     void bake() { cout << "VeggiePizza::bake" << endl; }
// 
//     void cut() { cout << "VeggiePizza::cut" << endl; }
// 
//     void box() { cout << "VeggiePizza::box" << endl; }
// };

//*******************
class NYStyleCheesePizza : public Pizza
{
public:
    void prepare() { cout << "NYStyleCheesePizza::prepare" << endl; }

    void bake() { cout << "NYStyleCheesePizza::bake" << endl; }

    void cut() { cout << "NYStyleCheesePizza::cut" << endl; }

    void box() { cout << "NYStyleCheesePizza::box" << endl; }
};

class NYStylePepperoniPizza : public Pizza
{
public:
    void prepare() { cout << "NYStylePepperoniPizza::prepare" << endl; }

    void bake() { cout << "NYStylePepperoniPizza::bake" << endl; }

    void cut() { cout << "NYStylePepperoniPizza::cut" << endl; }

    void box() { cout << "NYStylePepperoniPizza::box" << endl; }
};

class NYStyleClamPizza : public Pizza
{
public:
    void prepare() { cout << "NYStyleClamPizza::prepare" << endl; }

    void bake() { cout << "NYStyleClamPizza::bake" << endl; }

    void cut() { cout << "NYStyleClamPizza::cut" << endl; }

    void box() { cout << "NYStyleClamPizza::box" << endl; }
};

class NYStyleVeggiePizza : public Pizza
{
public:
    void prepare() { cout << "NYStyleVeggiePizza::prepare" << endl; }

    void bake() { cout << "NYStyleVeggiePizza::bake" << endl; }

    void cut() { cout << "NYStyleVeggiePizza::cut" << endl; }

    void box() { cout << "NYStyleVeggiePizza::box" << endl; }
};


//************************
class ChicagoStyleCheesePizza : public Pizza
{
public:
    void prepare() { cout << "ChicagoStyleCheesePizza::prepare" << endl; }

    void bake() { cout << "ChicagoStyleCheesePizza::bake" << endl; }

    void cut() { cout << "ChicagoStyleCheesePizza::cut" << endl; }

    void box() { cout << "ChicagoStyleCheesePizza::box" << endl; }
};

class ChicagoStylePepperoniPizza : public Pizza
{
public:
    void prepare() { cout << "ChicagoStylePepperoniPizza::prepare" << endl; }

    void bake() { cout << "ChicagoStylePepperoniPizza::bake" << endl; }

    void cut() { cout << "ChicagoStylePepperoniPizza::cut" << endl; }

    void box() { cout << "ChicagoStylePepperoniPizza::box" << endl; }
};

class ChicagoStyleClamPizza : public Pizza
{
public:
    void prepare() { cout << "ChicagoStyleClamPizza::prepare" << endl; }

    void bake() { cout << "ChicagoStyleClamPizza::bake" << endl; }

    void cut() { cout << "ChicagoStyleClamPizza::cut" << endl; }

    void box() { cout << "ChicagoStyleClamPizza::box" << endl; }
};

class ChicagoStyleVeggiePizza : public Pizza
{
public:
    void prepare() { cout << "ChicagoStyleVeggiePizza::prepare" << endl; }

    void bake() { cout << "ChicagoStyleVeggiePizza::bake" << endl; }

    void cut() { cout << "ChicagoStyleVeggiePizza::cut" << endl; }

    void box() { cout << "ChicagoStyleVeggiePizza::box" << endl; }
};


class PizzaStore
{
public:
    PizzaStore(StoreType Type)
        :storeType(Type){};
    ~PizzaStore() {};

    Pizza* orderPizza(PizzaType type)
    {
        Pizza* pizza = nullptr;
        pizza = creatPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

    virtual Pizza* creatPizza(PizzaType type) = 0;

protected:
    StoreType storeType;
};

class NYStylePizzaStore : public PizzaStore
{
public:
    NYStylePizzaStore():PizzaStore(NY_STYLE) {};

    Pizza* creatPizza(PizzaType type);
};

class ChicagoStylePizzaStore : public PizzaStore
{
public:
    ChicagoStylePizzaStore() :PizzaStore(CHICAGO_STYLE) {};
    Pizza* creatPizza(PizzaType type);


};