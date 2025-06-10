#include "Maze.h"
#include <fstream>
#include <iostream>


Maze::Maze() : width(0), height(0), map(nullptr) {}


Maze::~Maze() {
    if (map) {
        for (int i = 0; i < height; ++i)
            delete[] map[i];
        delete[] map;
    }
}


bool Maze::loadFromFile(const char* filename) {
    std::ifstream file(filename); 
    if (!file) return false;       

    file >> height >> width;       
    file.ignore();                 

    map = new char* [height];        
    for (int i = 0; i < height; ++i) {
        map[i] = new char[width];   
        for (int j = 0; j < width; ++j) {
            file.get(map[i][j]);    
        }
        file.ignore();             
    }

    return true;
}


void Maze::display(int playerX, int playerY) {
    system("cls"); 
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == playerX && j == playerY)
                std::cout << '@'; 
            else
                std::cout << map[i][j];
        }
        std::cout << '\n';
    }
}


char Maze::getTile(int x, int y) const {
    return map[x][y];
}


int Maze::getWidth() const { return width; }


int Maze::getHeight() const { return height; }
