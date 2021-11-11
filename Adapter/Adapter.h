#ifndef _ADAPTER_H_
#define _ADAPTER_H_

/*
*   适配器模式
*   软件已有的旧接口和使用的目标接口之间不匹配，无法直接调用，Adapter模式能够保证两种不同的接口一起工作
*   Adapter模式应用场景：遗留代码复用、类库迁移
*/
#include <iostream>

using namespace std;

//目标接口，即当前系统需要的接口
class AbstractTarget
{
public:
    AbstractTarget(){}
    virtual void request() = 0;
};

//被适配者
class Adaptee
{
public:
    Adaptee(){}
    virtual void specificRequest()
    {
        printf("旧接口进行接口适配\n");
    }
};

//适配器类
class Adapter : public AbstractTarget, public Adaptee
{
public:
    Adapter(){}
    virtual void request()
    {
        specificRequest();
    }
};

#endif