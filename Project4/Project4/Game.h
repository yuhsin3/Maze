#ifndef GAME_H
#define GAME_H

#include "Maze.h"
#include "Player.h"
#include <string>

class Game {
private:
    Maze maze;
    Player player;
    int timeLimit;
    std::string filename; 
public:
    Game();
    Game(int difficulty);
    void run();
};

#endif
