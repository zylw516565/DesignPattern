#include "StrategyPattern.h"

#include <string>

using std::string;

namespace StrategyPattern {

    void testStrategyPattern()
    {
        MallardDuck objMallardDuck;
        objMallardDuck.performQuack();
        objMallardDuck.setQuackBehavior(new Squeak());
        objMallardDuck.performQuack();

    }



}

// int main()
// {
// 
//     StrategyPattern::testStrategyPattern();
// 
//     getchar();
// }
