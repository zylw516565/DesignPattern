#include "AbstractFactory.h"


namespace AbstractFactory
{

    void AbstractFactoryTest()
    {
        NYPizzaStore objNYStore;
        ChicagoPizzaStore objChicagoStore;


        Pizza* pizza = objNYStore.orderPizza(CHEESE);
        cout << "Ethan order a " + pizza->getName() << endl;

        pizza = objChicagoStore.orderPizza(CHEESE);
        cout << "Joe order a " + pizza->getName() << endl;
    }

}


int main()
{
    AbstractFactory::AbstractFactoryTest();

    getchar();
}
