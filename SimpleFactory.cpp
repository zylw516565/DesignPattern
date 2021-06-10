#include "SimpleFactory.h"

namespace SimpleFactory {

    Pizza* SimplePizzaFactory::creatPizza(PizzaType type)
    {
        Pizza* pizza = nullptr;

        switch (type)
        {
        case CHEESE:
            pizza = new CheesePizza();
        case PEPPERONI:
            pizza = new PepperoniPizza();
        case  CLAM:
            pizza = new ClamPizza();
        case VEGGIE:
            pizza = new VeggiePizza();
        default:
            pizza = nullptr;
        }

        return pizza;
    }



    Pizza* PizzaStore::orderPizza(PizzaType type)
    {
        Pizza* pizza = nullptr;
        pizza = SimplePizzaFactory::creatPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

}