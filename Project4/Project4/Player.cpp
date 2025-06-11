#include "Player.h"


Player::Player() : x(0), y(0), maze(nullptr) {}


void Player::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}


int Player::getX() { return x; }


int Player::getY() { return y; }


void Player::bindMaze(Maze* m) {
    maze = m;
}


bool Player::move(char direction) {
    if (!maze) return false; 

    int newX = x, newY = y;
    switch (direction) {
    case 'W': case 'w': newX--; break; 
    case 'S': case 's': newX++; break; 
    case 'A': case 'a': newY--; break; 
    case 'D': case 'd': newY++; break; 
    default: return false; 
    }

    
    if (newX >= 0 && newX < maze->getHeight() &&
        newY >= 0 && newY < maze->getWidth() &&
        maze->getTile(newX, newY) != '#') {
        x = newX;
        y = newY;
        return true; 
    }

    return false; 
}
