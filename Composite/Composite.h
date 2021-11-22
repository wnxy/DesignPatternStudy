#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

/*
*   组合模式
*   将对象组合成树状层次结构，使的用户对单个对象和组合对象具有一致的访问性
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 组合模式
// 透明式实现：客户端不区分树叶对象还是树枝对象，对客户端来说都是透明的。
// 无论是树叶对象还是树枝对象都要实现抽象类的方法，对于一些树叶对象并不需要的方法，实现为空操作或者抛出异常

// 构件抽象基类
class Component
{
public:
    Component(){}
    Component(string iName)
    {
        this->Name = iName;
    }
    virtual ~Component(){}
    
    //增加一个构件/部门
    virtual void Add(Component *) = 0;
    //撤销一个构件/部门
    virtual void Remove(Component *) = 0;

    virtual Component* getChild(int) = 0;

    virtual void Operation() = 0;
private:
    string Name;
};

//树叶派生类：办公室
class Office : public Component
{
public:
    Office(){}
    Office(string iName)
    {
        this->Name = iName;
    }
    virtual ~Office(){}

    void Add(Component *)
    {
        printf("Office not exist Add function\n");
        return;
    }
    void Remove(Component *)
    {
        printf("Office not exist Remove function\n");
        return;
    }
    Component* getChild(int)
    {
        printf("Office not exist getChile function\n");
        return nullptr;
    }
    void Operation()
    {
        printf("this(%s) is Office\n", Name.c_str());
    }

private:
    string Name;
};

// 树枝派生类
class SubComponent : public Component
{
public:
    SubComponent(){}
    SubComponent(string iName)
    {
        this->Name = iName;
    }
    virtual ~SubComponent(){}
    void Add(Component *comp)
    {
        ComponentList.emplace_back(comp);
        return;
    }
    void Remove(Component *comp)
    {
        for(auto it = ComponentList.begin(); it != ComponentList.end(); ++it)
        {
            if(comp == *it)
            {
                ComponentList.erase(it);
                break;
            }
        }
        return;
    }
    Component *getChild(int i)
    {
        if(i >= 0 && i < ComponentList.size())
        {
            return ComponentList[i];
        }
        return nullptr;
    }
    void Operation()
    {
        for(auto *component : ComponentList)
        {
            component->Operation();
        }
    }

private:
    string Name;
    vector<Component*> ComponentList;
};

#endif