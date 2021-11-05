#include <iostream>
#include "Builder.h"

using namespace std;

int main()
{
    printf("建造者模式\n");
    //抽象建造者
    AbstractBuilder *builder = nullptr;
    //指挥者
    Director *director = new Director();
    //产品：House
    House *house = nullptr;

    //指定具体的建造者A
    builder = new ConcreteBuilderA();
    director->setBuilder(builder);
    house = director->construct();
    house->printfHouseInfo();
    delete builder;
    builder = nullptr;
    delete house;
    house = nullptr;

    //指定具体的建造者B
    builder = new ConcreteBuilderB();
    director->setBuilder(builder);
    house = director->construct();
    house->printfHouseInfo();
    delete builder;
    builder = nullptr;
    delete house;
    house = nullptr;
    delete director;
    director = nullptr;

    return 0;
}