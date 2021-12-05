#include <iostream>
#include "Facade.h"

int main()
{
    printf("外观模式\n");
    Facade *tmpPtr = new Facade();
    tmpPtr->control();
    delete tmpPtr;
    return 0;
}