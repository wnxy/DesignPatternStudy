#include <iostream>
#include "SimpleFactory.h"

int main()
{
    printf("简单工厂模式\n");
    SimpleFactory *fac = new SimpleFactory();
    AbstractSportProducts *pro = nullptr;
    pro = fac->getProduct(baskball);
    delete pro;

    pro = fac->getProduct(football);
    delete pro;
    delete fac;
    return 0;
}