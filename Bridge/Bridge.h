#ifndef _BRIDGE_H_
#define _BRIDGE_H_

/*
*   桥接器模式
*   抽象与实现分离，使它们可以独立变化
*/
#include <iostream>

using namespace std;

//游戏抽象基类
class Game
{
public:
    Game(){}
    virtual ~Game(){}
    virtual void playGame() = 0;
};

//各种游戏的实现派生类
class GameA : public Game
{
public:
    GameA(){}
    void playGame()
    {
        printf("wnxy like play GameA\n");
    }
};

//各种游戏的实现派生类
class GameB : public Game
{
public:
    GameB(){}
    void playGame()
    {
        printf("wnxy like play GameB\n");
    }
};

//手机抽象基类
class Phone
{
public:
    Phone(){}
    virtual ~Phone(){}
    virtual void setGame(Game *iGame) = 0;
    virtual void play() = 0;
};

//具体手机的派生类
class PhoneA : public Phone
{
public:
    PhoneA()
    {
        printf("this is PhoneA\n");
    }
    void setGame(Game *iGame)
    {
        this->game = iGame;
    }
    void play()
    {
        this->game->playGame();
    }

private:
    Game *game;
};

//具体手机的派生类
class PhoneB : public Phone
{
public:
    PhoneB()
    {
        printf("this is PhoneB\n");
    }
    void setGame(Game *iGame)
    {
        this->game = iGame;
    }
    void play()
    {
        this->game->playGame();
    }

private:
    Game *game;
};

#endif