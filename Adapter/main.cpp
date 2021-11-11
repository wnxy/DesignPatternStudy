#include <iostream>
#include "Adapter.h"

using namespace std;

int main()
{
    printf("适配器模式：\n");
    AbstractTarget *iTarget = new Adapter();
    iTarget->request();
    return 0;
}