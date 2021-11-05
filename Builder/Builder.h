#ifndef _BUILDER_H_
#define _BUILDER_H_

/*
*   建造者模式
*   将一个复杂对象的构建过程与表示分离，同样的构建过程可以创建不同的表示
*/

#include <iostream>
#include <string>

using namespace std;

/* 产品类House */
class House
{
public:
    House(){}
    void setFloor(string iFloor)
    {
        this->floor = iFloor;
    }
    void setWall(string iWall)
    {
        this->wall = iWall;
    }
    void setRoof(string iRoof)
    {
        this->roof = iRoof;
    }
    void printfHouseInfo()
    {
        printf("Floor:%s\t\n", this->floor.c_str());
        printf("Wall:%s\t\n", this->wall.c_str());
        printf("Roof:%s\t\n", this->roof.c_str());
    }
private:
    string floor;
    string wall;
    string roof;
};

/* 抽象建造者AbstractBuilder */
class AbstractBuilder
{
public:
    AbstractBuilder()
    {
        house = new House();
    }
    virtual ~AbstractBuilder(){}
    //抽象方法
    virtual void buildFloor() = 0;
    virtual void buildWall() = 0;
    virtual void buildRoof() = 0;
    virtual House *getHouse() = 0;

    House *house;
};

/* 具体建造者ConcreteBuilderA */
class ConcreteBuilderA : public AbstractBuilder
{
public:
    ConcreteBuilderA()
    {
        printf("ConcreteBuilderA\n");
    }
    //具体的实现方法
    void buildFloor()
    {
        this->house->setFloor("Floor_A");
    }
    void buildWall()
    {
        this->house->setWall("Wall_A");
    }
    void buildRoof()
    {
        this->house->setRoof("Roof_A");
    }
    House *getHouse()
    {
        return this->house;
    }
};

/* 具体建造者ConcreteBuilderB */
class ConcreteBuilderB : public AbstractBuilder
{
public:
    ConcreteBuilderB()
    {
        printf("ConcreteBuilderB\n");
    }
    //具体的实现方法
    void buildFloor()
    {
        this->house->setFloor("Floor_B");
    }
    void buildWall()
    {
        this->house->setWall("Wall_B");
    }
    void buildRoof()
    {
        this->house->setRoof("Roof_B");
    }
    House *getHouse()
    {
        return this->house;
    }
};

/* 指挥者Director */
class Director
{
public:
    Director(){}
    //具体实现方法
    void setBuilder(AbstractBuilder *iBuilder)
    {
        this->builder = iBuilder;
    }
    //封装组装流程，返回建造结果
    House *construct()
    {
        builder->buildFloor();
        builder->buildWall();
        builder->buildRoof();
        return builder->getHouse();
    }

private:
    AbstractBuilder *builder;
};

#endif