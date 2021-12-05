#include <iostream>
#include "Bridge.h"

using namespace std;

int main()
{
    printf("桥接器模式\n");
    Game *game = new GameA();
    Phone *phone = new PhoneA();
    phone->setGame(game);
    phone->play();
    delete game;
    game = nullptr;
    delete phone;
    phone = nullptr;
    game = new GameB();
    phone = new PhoneB();
    phone->setGame(game);
    phone->play();
    delete game;
    game = nullptr;
    delete phone;
    phone = nullptr;
    return 0;
}