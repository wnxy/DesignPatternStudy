#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_
/*
*   抽象工厂模式，具体工厂类不仅生产一种产品，具体工厂类可以生产一类产品
*/

#include <iostream>

using namespace std;

class AbstractBall
{
public:
    AbstractBall(){}
    ~AbstractBall(){}
    //抽象产品的公共方法，纯虚函数
    virtual void play() = 0;
};

class AbstractShirt
{
public:
    AbstractShirt(){}
    ~AbstractShirt(){}
    //抽象产品的公共方法，纯虚函数
    virtual void wear() = 0;
};

class Basketball : public AbstractBall
{
public:
    Basketball()
    {
        play();
    }
    ~Basketball(){}
    //具体产品类实现公共方法
    void play()
    {
        printf("Wnxy play basketball!\n");
    }
};

class Football : public AbstractBall
{
public:
    Football()
    {
        play();
    }
    ~Football(){}
    //具体产品类实现公共方法
    void play()
    {
        printf("Wnxy play football!\n");
    }
};

class BasketballShirt : public AbstractShirt
{
public:
    BasketballShirt()
    {
        wear();
    }
    ~BasketballShirt(){}
    //具体产品类实现公共方法
    void wear()
    {
        printf("Wnxy wear basketball shirt!\n");
    }
};

class FootballShirt : public AbstractShirt
{
public:
    FootballShirt()
    {
        wear();
    }
    ~FootballShirt(){}
    //具体产品类实现公共方法
    void wear()
    {
        printf("Wnxy wear football shirt!\n");
    }
};

class AbstractFactory
{
public:
    AbstractFactory(){}
    ~AbstractFactory(){}
    //抽象工厂类的公共方法，纯虚函数
    virtual AbstractBall *getBall() = 0;
    virtual AbstractShirt *getShirt() = 0;
};

class BasketballFactory : public AbstractFactory
{
public:
    BasketballFactory(){}
    ~BasketballFactory(){}
    //具体产品类的公共方法实现
    AbstractBall *getBall()
    {
        AbstractBall *pro = nullptr;
        pro = new Basketball();
        return pro;
    }
    AbstractShirt *getShirt()
    {
        AbstractShirt *cloth = nullptr;
        cloth = new BasketballShirt();
        return cloth;
    }
};

class FootballFactory : public AbstractFactory
{
public:
    FootballFactory(){}
    ~FootballFactory(){}
    //具体产品类的公共方法实现
    AbstractBall *getBall()
    {
        AbstractBall *pro = nullptr;
        pro = new Football();
        return pro;
    }
    AbstractShirt *getShirt()
    {
        AbstractShirt *cloth = nullptr;
        cloth = new FootballShirt();
        return cloth;
    }
};

#endif