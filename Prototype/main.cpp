#include <iostream>
#include "Prototype.h"

#define DEEP_COPY
//#define SHALLOW_COPY

using namespace std;


int main()
{
#ifdef SHALLOW_COPY
    //浅拷贝示例
    printf("原型模式\n\n");
    ConcreteWork *wnxyWork = new ConcreteWork("Wnxy", 1001, "Wnxy_Model");
    printf("wnxy的作业：\n");
    wnxyWork->printfWorkInfo();

    printf("\nwyy直接抄作业......\n");
    ConcreteWork *wyyWork = wnxyWork;
    printf("wyy的作业：\n");   
    wyyWork->printfWorkInfo(); 

    printf("\nwyy抄完作业改名字和学号，不改要完蛋......\n");
    wyyWork->setName("Wyy");
    wyyWork->setIdName(1005);
    WorkModel *wyyModel = new WorkModel();
    wyyModel->setModelName("Wyy_Model");
    wyyWork->setWorkModel(wyyModel);

    printf("\nwyy检查信息是否修改成功：\n");
    printf("wnxy的作业：\n");
    wnxyWork->printfWorkInfo();
    printf("wyy的作业：\n");
    wyyWork->printfWorkInfo();

#else
    //深拷贝示例
    printf("原型模式\n\n");
    ConcreteWork *wnxyWork = new ConcreteWork("Wnxy", 1001, "Wnxy_Model");
    printf("wnxy的作业：\n");
    wnxyWork->printfWorkInfo();

    printf("\nwyy直接抄作业......\n");
    ConcreteWork *wyyWork = wnxyWork->clone();
    printf("wyy的作业：\n");   
    wyyWork->printfWorkInfo(); 

    printf("\nwyy抄完作业改名字和学号，不改要完蛋......\n");
    wyyWork->setName("Wyy");
    wyyWork->setIdName(1005);
    WorkModel *wyyModel = new WorkModel();
    wyyModel->setModelName("Wyy_Model");
    wyyWork->setWorkModel(wyyModel);

    printf("\nwyy检查信息是否修改成功：\n");
    printf("wnxy的作业：\n");
    wnxyWork->printfWorkInfo();
    printf("wyy的作业：\n");
    wyyWork->printfWorkInfo();
#endif

    return 0;
}