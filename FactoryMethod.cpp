#include "FactoryMethod.h"

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
    pizza = creatPizza(type);

    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();

    return pizza;
}

Pizza* NYStylePizzaStore::creatPizza(PizzaType type)
{
    Pizza* pizza = nullptr;

    switch (type)
    {
    case CHEESE:
        pizza = new NYStyleCheesePizza();
    case PEPPERONI:
        pizza = new NYStylePepperoniPizza();
    case  CLAM:
        pizza = new NYStyleClamPizza();
    case VEGGIE:
        pizza = new NYStyleVeggiePizza();
    default:
        pizza = nullptr;
    }

    return pizza;
}


Pizza* ChicagoStylePizzaStore::creatPizza(PizzaType type)
{
    Pizza* pizza = nullptr;

    switch (type)
    {
    case CHEESE:
        pizza = new ChicagoStyleCheesePizza();
    case PEPPERONI: 
        pizza = new ChicagoStylePepperoniPizza();
    case  CLAM:     
        pizza = new ChicagoStyleClamPizza();
    case VEGGIE:
        pizza = new ChicagoStyleVeggiePizza();
    default:
        pizza = nullptr;
    }

    return pizza;
}


void FactoryMethodTest()
{
    NYStylePizzaStore objStore;
    objStore.orderPizza(CHEESE);


}
