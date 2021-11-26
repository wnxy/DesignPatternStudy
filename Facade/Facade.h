#ifndef _FACADE_H_
#define _FACADE_H_

/*
*   外观模式
*   为多个复杂的子系统提供一个统一的接口，使得客户端对子系统的访问更加方便
*/
#include <iostream>
#include <memory>

using namespace std;

//子系统A
class Memory
{
public:
    Memory(){}
    virtual ~Memory(){}
    void setCheck()
    {
        printf("Request check memory...\n");
    }
};

//子系统B
class CPU
{
public:
    CPU(){}
    virtual ~CPU(){}
    void run()
    {
        printf("Request run cpu...\n");
    }
};

//子系统C
class HardDisk
{
public:
    HardDisk(){}
    virtual ~HardDisk(){}
    void read()
    {
        printf("Request read hard disk...\n");
    }
};

//子系统D
class OS
{
public:
    OS(){}
    virtual ~OS(){}
    void manage()
    {
        printf("Request os manage...\n");
    }
};

class Facade
{
public:
    Facade()
    {
        memPtr.reset(new Memory());
        cpuPtr.reset(new CPU());
        harPtr.reset(new HardDisk());
        osPtr.reset(new OS());
    }
    virtual ~Facade(){}
    void control()
    {
        memPtr->setCheck();
        cpuPtr->run();
        harPtr->read();
        osPtr->manage();
    }

private:
    std::shared_ptr<Memory> memPtr;
    std::shared_ptr<CPU> cpuPtr;
    std::shared_ptr<HardDisk> harPtr;
    std::shared_ptr<OS> osPtr;
};

#endif