#include "FactoryMethod.h"


Pizza* NYStylePizzaStore::creatPizza(PizzaType type)
{
    Pizza* pizza = nullptr;

    switch (type)
    {
    case CHEESE:
        pizza = new NYStyleCheesePizza();
        break;
    case PEPPERONI:
        pizza = new NYStylePepperoniPizza();
        break;
    case  CLAM:
        pizza = new NYStyleClamPizza();
        break;
    case VEGGIE:
        pizza = new NYStyleVeggiePizza();
        break;
    default:
        pizza = nullptr;
        break;
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
        break;
    case PEPPERONI: 
        pizza = new ChicagoStylePepperoniPizza();
        break;
    case  CLAM:     
        pizza = new ChicagoStyleClamPizza();
        break;
    case VEGGIE:
        pizza = new ChicagoStyleVeggiePizza();
        break;
    default:
        pizza = nullptr;
        break;
    }

    return pizza;
}


void FactoryMethodTest()
{
    NYStylePizzaStore objNYStore;
    ChicagoStylePizzaStore objChicagoStore;


    Pizza* pizza = objNYStore.orderPizza(CHEESE);
    cout << "Ethan order a " + pizza->getName() << endl;

    pizza = objChicagoStore.orderPizza(CHEESE);
    cout << "Joe order a " + pizza->getName() << endl;
}

int main()
{
    FactoryMethodTest();

    getchar();
}
