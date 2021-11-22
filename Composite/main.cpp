#include <iostream>
#include <memory>
#include "Composite.h"

using namespace std;

int main()
{
    printf("组合模式\n");

    std::shared_ptr<Component> component_ptr(new SubComponent("计算机学院")); 
    std::shared_ptr<Component> office_ptr1(new Office("行政办公室"));
    std::shared_ptr<Component> office_ptr2(new Office("新媒体办公室"));
    std::shared_ptr<Component> office_ptr3(new Office("招生办公室"));
    std::shared_ptr<Component> office_ptr4(new Office("教务办公室"));

    component_ptr->Add(office_ptr1.get());
    component_ptr->Add(office_ptr2.get());
    component_ptr->Add(office_ptr3.get());
    component_ptr->Add(office_ptr4.get());

    component_ptr->Operation();

    printf("\n\n");
    Component *tmp_ptr = component_ptr->getChild(1);
    tmp_ptr->Operation();

    printf("\n\n");
    component_ptr->Remove(tmp_ptr);
    component_ptr->Operation();

    return 0;
}