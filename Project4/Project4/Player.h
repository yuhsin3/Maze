#ifndef PLAYER_H
#define PLAYER_H

#include "Maze.h"


class Player {
private:
    int x, y;        
    Maze* maze;      
public:
    Player();        
    void setPosition(int newX, int newY); 
    int getX();      
    int getY();      
    void bindMaze(Maze* m); 
    bool move(char direction); 
};

#endif

