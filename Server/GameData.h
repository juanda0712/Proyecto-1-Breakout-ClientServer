//
// Created by juanda on 9/21/21.
//

#ifndef SERVER_GAMEDATA_H
#define SERVER_GAMEDATA_H
#include <string>
#include <string.h>

using namespace std;

class GameData{
public:
    GameData();
    void setLIves(int lives);
    int getLives();
    void setTotalBlocks(int totalBlocks);
    int getTotalBlocks();
    void setBallSpeed(int ballSpeed);
    int getBallSpeed();

private:
    int lives;
    int totalBlocks;
    int ballSpeed;
};
#endif //SERVER_GAMEDATA_H
