#ifndef __SIMPLEFACTORY_H__
#define __SIMPLEFACTORY_H__

#include <iostream>
#include <string>

using namespace std;

enum sportProduct
{
    baskball = 1,
    football,
};

class AbstractSportProducts
{
public:
    AbstractSportProducts()
    {
        
    }
    //基类的纯虚函数，派生类必须进行实例化
    virtual void printName() = 0;
    virtual void play() = 0;
};

class Basketball:public AbstractSportProducts
{
public:
    Basketball()
    {
        printName();
        play();
    }
    void printName()
    {
        printf("Factory produce baskball!\n");
    }
    void play()
    {
        printf("Wnxy play baskball!\n");
    }
};

class Football:public AbstractSportProducts
{
public:
    Football()
    {
        printName();
        play();
    }
    void printName()
    {
        printf("Factory produce football!\n");
    }
    void play()
    {
        printf("Wnxy play football!\n");
    }
};

class SimpleFactory
{
private:
    /* data */
public:
    SimpleFactory(/* args */)
    {

    }
    ~SimpleFactory()
    {

    }
    AbstractSportProducts *getProduct(int name)
    {
        AbstractSportProducts *ptr = nullptr;
        if(name == 1)
        {
            ptr = new Basketball();
        }
        else if(name == 2)
        {
            ptr = new Football();
        }
        return ptr;
    }
};

#endif