#ifndef _SINGLETON_H_
#define _SINGLETON_H_

/*
*   单例模式
*   应用程序中某个实例有且仅有一个，没有任何方法实现创建多个实例
*   分类：
*       1. 饿汉模式：类定义的时候进行实例化，是线程安全的。
*       2. 懒汉模式：类首次使用的时候需要进行实例化，不是线程安全的。
*/
#include <iostream>
#include <mutex>

using namespace std;

//单例模式 饿汉实现
class SingletonHungry
{
private:
    //构造函数私有化，不允许外部方法通过new来创建实例
    SingletonHungry(){}
    static SingletonHungry *p1;     //静态成员变量声明

public:
    static SingletonHungry *getInstance();
};
SingletonHungry *SingletonHungry::p1 = new SingletonHungry();        //静态成员变量的定义及初始化
SingletonHungry *SingletonHungry::getInstance()
{
    printf("单例模式，饿汉实现进行对象实例化\n");
    return p1;
}


//单例模式 懒汉模式，加锁机制实现线程安全
class SingletonLazy1
{
private:
    //构造函数私有化
    SingletonLazy1(){}
    static SingletonLazy1 *p2;      //静态成员变量声明
    static mutex lock_;             //静态成员变量声明

public:
    static SingletonLazy1 *getInstance();
};
SingletonLazy1 *SingletonLazy1::p2 = nullptr;           //静态成员变量的定义及初始化
std::mutex SingletonLazy1::lock_;                       //静态成员变量的定义
SingletonLazy1 *SingletonLazy1::getInstance()
{
    printf("单例模式，懒汉实现进行对象初始化\n");
    {
        //对象实例化加锁，保证线程安全
        lock_guard<mutex> my_lock(lock_);
        if(!p2)
        {
            return new SingletonLazy1();
        }
        else
        {
            return p2;
        }
    }
}

//单例模式 懒汉模式，DLCP(双重检查锁模式----Double-Checked Locking Pattern)实现线程安全]
class SingletonLazy2
{
private:
    //构造函数私有化
    SingletonLazy2(){}
    static SingletonLazy2 *p3;         //静态成员变量声明
    static mutex lock_;                //静态成员变量声明

public:
    static SingletonLazy2 *getInstance();
};
SingletonLazy2 *SingletonLazy2::p3 = nullptr;        //静态成员变量的定义及初始化
std::mutex SingletonLazy2::lock_;                    //静态成员变量的定义
SingletonLazy2 *SingletonLazy2::getInstance()
{
    printf("单例模式，懒汉实现进行对象实例化DCLP\n");
    if(p3 == nullptr)
    {
        lock_.lock();
        if(p3 == nullptr)
        {
            p3 = new SingletonLazy2();
        }
        lock_.unlock();
    }
    return p3;
}

#endif