#pragma once

#include <string>
#include <iostream>
#include <vector>


using std::string;

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

namespace AbstractFactory
{

    enum PizzaType {
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
            cout << "Bake for 25 minutes at 350" << endl;
        }

        virtual void cut()
        {
            cout << "Cutting the pizza into diagonal slices" << endl;
        }

        virtual void box()
        {
            cout << "Place pizza in official PizzaStore box" << endl;
        }

        string getName() const
        {
            return name_;
        }

    protected:
        string  name_;   //披萨名称
        string  dough_;  //面团类型
        string  sauce_;  //酱料类型

        vector<string> toppings_;
    };

    //*******************
    class NYStyleCheesePizza : public Pizza
    {
    public:

        NYStyleCheesePizza()
        {
            name_ = "NY Style Sauce and Cheese Pizza";
            dough_ = "Thin Crust Dough";
            sauce_ = "Marinara Sauce";

            toppings_.push_back("Grated Reggiano Cheese");
        }

        //     void prepare() { cout << "NYStyleCheesePizza::prepare" << endl; }
        // 
        //     void bake() { cout << "NYStyleCheesePizza::bake" << endl; }
        // 
        //     void cut() { cout << "NYStyleCheesePizza::cut" << endl; }
        // 
        //     void box() { cout << "NYStyleCheesePizza::box" << endl; }
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

        ChicagoStyleCheesePizza()
        {
            name_ = "Chicago Style Sauce and Cheese Pizza";
            dough_ = "Chicago Crust Dough";
            sauce_ = "Chicago Sauce";

            toppings_.push_back("Grated Chicago Cheese");
        }

        //     void prepare() { cout << "ChicagoStyleCheesePizza::prepare" << endl; }
        // 
        //     void bake() { cout << "ChicagoStyleCheesePizza::bake" << endl; }

        void cut() { cout << "ChicagoStyleCheesePizza::cut" << endl; }

        //    void box() { cout << "ChicagoStyleCheesePizza::box" << endl; }
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
            :storeType(Type) {};
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
        NYStylePizzaStore() :PizzaStore(NY_STYLE) {};

        Pizza* creatPizza(PizzaType type);
    };

    class ChicagoStylePizzaStore : public PizzaStore
    {
    public:
        ChicagoStylePizzaStore() :PizzaStore(CHICAGO_STYLE) {};

        Pizza* creatPizza(PizzaType type);


    };

    class Dough {};

    class Sauce {};

    class Cheese {};

    class Pepperoni {};

    class Clam {};

    class Veggie {};

    class PizzaIngredientFactory
    {
    public:
        virtual ~PizzaIngredientFactory() = default;

        virtual shared_ptr<Dough> creatDough() = 0;
        virtual shared_ptr<Sauce> creatSauce() = 0;
        virtual shared_ptr<Cheese> creatCheese() = 0;
        virtual shared_ptr<std::vector<Veggie>> creatVeggies() = 0;
        virtual shared_ptr<Pepperoni> creatPepperoni() = 0;
        virtual shared_ptr<Clam> creatClam() = 0;
    };


    class ThinCrustDough : public Dough
    {};

    class MarinaraSauce : public Sauce
    {};

    class ReggianoCheese : public Cheese
    {};

    class SlicedPepperoni : public Pepperoni
    {};

    class FreshClam : public Clam
    {};


    class NYPizzaIngredientFactory : public PizzaIngredientFactory
    {

        shared_ptr<Dough> creatDough()
        {
            shared_ptr<Dough> tmp(new ThinCrustDough());
            return tmp;
        }
        shared_ptr<Sauce> creatSauce()
        {
            shared_ptr<Sauce> tmp(new MarinaraSauce());
            return tmp;
        }
        shared_ptr<Cheese> creatCheese()
        {
            shared_ptr<Cheese> tmp(new ReggianoCheese());
            return tmp;
        }
        shared_ptr<std::vector<Veggie>> creatVeggies()
        {
            shared_ptr<std::vector<Veggie>> tmp(new std::vector<Veggie>(2));
            return tmp;
        }
        shared_ptr<Pepperoni> creatPepperoni()
        {
            shared_ptr<Pepperoni> tmp(new SlicedPepperoni());
            return tmp;
        }
        shared_ptr<Clam> creatClam()
        {
            shared_ptr<Clam> tmp(new FreshClam());
            return tmp;
        }

    };


    class ThickCrustDough : public Dough
    {};

    class PlumTomatoSauce : public Sauce
    {};

//     class ReggianoCheese : public Cheese
//     {};

//     class SlicedPepperoni : public Pepperoni
//     {};

    class FrozenClam : public Clam
    {};

    class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
    {

        shared_ptr<Dough> creatDough()
        {
            shared_ptr<Dough> tmp(new ThickCrustDough());
            return tmp;
        }
        shared_ptr<Sauce> creatSauce()
        {
            shared_ptr<Sauce> tmp(new PlumTomatoSauce());
            return tmp;
        }
        shared_ptr<Cheese> creatCheese()
        {
            shared_ptr<Cheese> tmp(new ReggianoCheese());
            return tmp;
        }
        shared_ptr<std::vector<Veggie>> creatVeggies()
        {
            shared_ptr<std::vector<Veggie>> tmp(new std::vector<Veggie>(2));
            return tmp;
        }
        shared_ptr<Pepperoni> creatPepperoni()
        {
            shared_ptr<Pepperoni> tmp(new SlicedPepperoni());
            return tmp;
        }
        shared_ptr<Clam> creatClam()
        {
            shared_ptr<Clam> tmp(new FreshClam());
            return tmp;
        }

    };


}