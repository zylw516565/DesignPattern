#include "DecoratorPattern.h"

#include <iostream>


using std::cout;
using std::endl;

namespace DecoratorPattern {

    void DecoratorPatternTest()
    {        
        Whip* pWhip = new Whip(0.10, (new Soy(0.15,(new Mocha(0.3, (new Mocha(0.3, new DarkRoast(0.5))))))));
        cout << "mocha.getDescription: " << pWhip->getDescription() << endl;
        cout << "mocha.cost: " << pWhip->cost() << endl;          
    }

}

int main()
{
    DecoratorPattern::DecoratorPatternTest();

    getchar();
}
