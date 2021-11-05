#include <iostream>
#include "FactoryMethod.h"

using namespace std;

int main()
{
    printf("工厂方法模式\n");
    AbstractFactory *fac = nullptr;
    AbstractProduct *pro = nullptr;
    fac = new BasketballFactory;
    pro = fac->getProduct();
    delete fac;
    delete pro;

    fac = new FootballFactory;
    pro = fac->getProduct();
    delete fac;
    delete pro;
    return 0;
}