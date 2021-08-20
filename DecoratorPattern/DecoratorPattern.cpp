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
    std::time_t course_start_time1 = 1483232400;
    char buf[32];
    strftime(buf, sizeof(buf), "%FT%TZ", gmtime(&course_start_time1));
    std::cout << buf << std::endl;

    DecoratorPattern::DecoratorPatternTest();

    getchar();
}