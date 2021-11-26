#ifndef _DECORATOR_H_
#define _DECORATOR_H_

/*
*   装饰器模式
*   动态的给对象增加一些职责，即给对象添加一些功能
*/
#include <iostream>

using namespace std;

//被装饰的抽象基类
class AbstractComponent
{
public:
    AbstractComponent(){}
    virtual ~AbstractComponent(){}
    virtual void Operator() = 0;
};

//需要装饰的具体派生类
class ConcreteComponent : public AbstractComponent
{
public:
    ConcreteComponent(){}
    virtual ~ConcreteComponent(){}
    void Operator()
    {
        printf("This is ConcreteComponent\n");
    }
};

//装饰品抽象基类
class AbstractDecorator : public AbstractComponent
{
public:
    AbstractDecorator(){}
    AbstractDecorator(AbstractComponent *tmpComp)
    {
        this->comp = tmpComp;
    }
    virtual ~AbstractDecorator(){}
    void Operator()
    {
        this->comp->Operator();
    }
    AbstractComponent *getDecorator()
    {
        return this->comp;
    }
    void setDecorator(AbstractComponent *tmpComp)
    {
        this->comp = tmpComp;
    }

private:
    AbstractComponent *comp;
};

//装饰品具体派生类
class ConcreteDecorator : public AbstractDecorator
{
public:
    ConcreteDecorator(){}
    ConcreteDecorator(AbstractComponent *tmpComp)
    {
        this->setDecorator(tmpComp);
    }
    virtual ~ConcreteDecorator(){}
    void Operator()
    {
        this->getDecorator()->Operator();
        this->newDecorator();
    }
    void newDecorator()
    {
        printf("使用装饰品装饰\n");
    }
};

#endif