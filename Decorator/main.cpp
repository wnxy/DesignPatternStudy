#include <iostream>
#include "Decorator.h"

using namespace std;

int main()
{
    printf("装饰器模式\n");
    AbstractComponent *tmpCompPtr = new ConcreteComponent();
    tmpCompPtr->Operator();

    AbstractDecorator *tmpDecPtr = new ConcreteDecorator(tmpCompPtr);
    tmpDecPtr->Operator();

    delete tmpCompPtr;
    delete tmpDecPtr;
    return 0;
}