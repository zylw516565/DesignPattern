#include "DecoratorPattern.h"

#include <iostream>


using std::cout;
using std::endl;

namespace DecoratorPattern {



    void DecoratorPatternTest()
    {        
        Mocha mocha(0.3, new DarkRoast(0.5));
        cout << "mocha.getDescription: " << mocha.getDescription() << endl;
        cout << "mocha.cost: " << mocha.cost() << endl;
          
    }
}

int main()
{
    DecoratorPattern::DecoratorPatternTest();

    getchar();
}