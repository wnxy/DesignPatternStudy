#include <iostream>
#include "Singleton.h"

using namespace std;

int main()
{
    printf("单例模式：\n");
    SingletonHungry *singleton_hungry = nullptr;
    singleton_hungry = singleton_hungry->getInstance();

    SingletonLazy1 *singleton_lazy1 = nullptr;
    singleton_lazy1 = singleton_lazy1->getInstance();

    SingletonLazy2 *singleton_lazy2 = nullptr;
    singleton_lazy2 = singleton_lazy2->getInstance();
    return 0;
}