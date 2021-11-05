#ifndef __FACTORYMETHOD_H__
#define __FACTORYMETHOD_H__

#include <iostream>

/* 抽象产品类，定义公共方法，不实现 */
class AbstractProduct
{
public:
    AbstractProduct()
    {

    }
    //virtual ~AbstractProduct(){}

    virtual void printName() = 0;
    virtual void play() = 0;
};

/* 篮球类，对父类的抽象方法进行实现 */
class Basketball:public AbstractProduct
{
public:
    Basketball()
    {
        printName();
        play();
    }
    void printName()
    {
        printf("Wnxy get basketball!\n");
    }
    void play()
    {
        printf("Wnxy paly basketball!\n\n");
    }
};

/* 足球类，对父类的抽象方法进行实现 */
class Football:public AbstractProduct
{
public:
    Football()
    {
        printName();
        play();
    }
    void printName()
    {
        printf("Wnxy get football!\n");
    }
    void play()
    {
        printf("Wnxy paly football!\n\n");
    }
};

/* 抽象工厂类，声明工厂的公共方法 */
class AbstractFactory
{
public:
    AbstractFactory()
    {

    }
    virtual AbstractProduct *getProduct() = 0;
};

/* 篮球工厂类，实现具体的方法接口 */
class BasketballFactory:public AbstractFactory
{
public:
    BasketballFactory()
    {
        printf("BasketballFactory produce basketball!\n");
    }
    AbstractProduct *getProduct()
    {
        printf("basketball\n");
        AbstractProduct *pro = nullptr;
        pro = new Basketball;
        return pro;
    }
};

/* 足球工厂类，实现具体的方法接口 */
class FootballFactory:public AbstractFactory
{
public:
    FootballFactory()
    {
        printf("FootballFactory produce football!\n");
    }
    AbstractProduct *getProduct()
    {
        printf("football\n");
        AbstractProduct *pro = nullptr;
        pro = new Football;
        return pro;
    }
};

#endif //__FACTORYMETHOD_H__