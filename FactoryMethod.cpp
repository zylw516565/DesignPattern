#include "FactoryMethod.h"


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
