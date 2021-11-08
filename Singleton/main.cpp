#include <iostream>
#include "Singleton.h"

int main()
{
    printf("单例模式：\n");
    SingletonHungry *singleton_hungry = nullptr;
    singleton_hungry = singleton_hungry->getInstance();
    return 0;
}