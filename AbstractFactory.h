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


    class Dough {};

    class Sauce {};

    class Cheese {};

    class Pepperoni {};

    class Clam {};

    class Veggie {};


    class Pizza
    {
    protected:
        string                  name_;   //披萨名称
        shared_ptr<Dough>           dough_;  //面团类型
        shared_ptr<Sauce>           sauce_;  //酱料类型
        shared_ptr<vector<Veggie>>  veggies_;
        shared_ptr<Cheese>          cheese_;
        shared_ptr<Pepperoni>       pepperoni_;
        shared_ptr<Clam>            clam_;


    public:
        Pizza() = default;
        virtual ~Pizza() = default;

    public:
        virtual void prepare() = 0;

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

        void setName(const string& name)
        {
            name_ = name;
        }

    };

    class PizzaStore
    {
    public:
        PizzaStore() = default;
        ~PizzaStore() = default;

        Pizza* orderPizza(PizzaType type)
        {
            Pizza* pizza = nullptr;
            pizza = creatPizza(type);


            if (pizza == nullptr)
                return pizza;

            pizza->prepare();
            pizza->cut();
            pizza->box();

            return pizza;
        }

        virtual Pizza* creatPizza(PizzaType type) = 0;

    };

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

    class CheesePizza :public Pizza
    {
    private:
        shared_ptr<PizzaIngredientFactory> ingredientFactory_;
       
    public:
        CheesePizza(const shared_ptr<PizzaIngredientFactory>& ingredientFactory)
            :ingredientFactory_(ingredientFactory)
        {};

        void prepare() 
        {
            cout << "Preparing " + name_ << endl;
            dough_ = ingredientFactory_->creatDough();
            sauce_ = ingredientFactory_->creatSauce();
            cheese_ = ingredientFactory_->creatCheese();
        }
    };


    class ClamPizza :public Pizza
    {
    private:
        shared_ptr<PizzaIngredientFactory> ingredientFactory_;

    public:
        ClamPizza(const shared_ptr<PizzaIngredientFactory>& ingredientFactory)
            :ingredientFactory_(ingredientFactory)
        {};

        void prepare()
        {
            cout << "Preparing " + name_ << endl;
            dough_  = ingredientFactory_->creatDough();
            sauce_  = ingredientFactory_->creatSauce();
            cheese_ = ingredientFactory_->creatCheese();
            clam_   = ingredientFactory_->creatClam();
        }

    };


    class NYPizzaStore : public PizzaStore
    {
    public:

        Pizza* creatPizza(PizzaType type)
        {
            Pizza* pizza = nullptr;
            shared_ptr<PizzaIngredientFactory> ingredientFactory;
            ingredientFactory.reset(new NYPizzaIngredientFactory());

            switch (type)
            {
            case CHEESE:
                pizza = new CheesePizza(ingredientFactory);
                pizza->setName("New York Style Cheese Pizza");
                break;
            case CLAM:
                pizza = new ClamPizza(ingredientFactory);
                pizza->setName("New York Style Clam Pizza");
                break;
            default:
                break;
            }

            return pizza;
        }
    };

    class ChicagoPizzaStore : public PizzaStore
    {
    public:

        Pizza* creatPizza(PizzaType type)
        {
            Pizza* pizza = nullptr;
            shared_ptr<PizzaIngredientFactory> ingredientFactory;
            ingredientFactory.reset(new ChicagoPizzaIngredientFactory());

            switch (type)
            {
            case CHEESE:
                pizza = new CheesePizza(ingredientFactory);
                pizza->setName("Chicago Style Cheese Pizza");
                break;
            case CLAM:
                pizza = new ClamPizza(ingredientFactory);
                pizza->setName("Chicago Style Clam Pizza");
                break;
            default:
                break;
            }

            return pizza;
        }

    };

}