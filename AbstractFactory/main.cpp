#include <iostream>
#include "AbstractFactory.h"

using namespace std;

int main()
{
    printf("抽象工厂模式\n");
    AbstractFactory *fac = nullptr;
    AbstractBall *ball = nullptr;
    AbstractShirt *shirt = nullptr;
    fac = new BasketballFactory();
    ball = fac->getBall();
    shirt = fac->getShirt();
    delete fac;
    delete ball;
    delete shirt;
    fac = nullptr;
    ball = nullptr;
    shirt = nullptr;
    
    fac = new FootballFactory();
    ball = fac->getBall();
    shirt = fac->getShirt();
    delete fac;
    delete ball;
    delete shirt;
    fac = nullptr;
    ball = nullptr;
    shirt = nullptr;

    return 0;
}