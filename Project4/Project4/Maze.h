#ifndef MAZE_H
#define MAZE_H


class Maze {
private:
    int width, height;  
    char** map;         
public:
    Maze();             
    ~Maze();            
    bool loadFromFile(const char* filename); 
    void display(int playerX, int playerY);  
    char getTile(int x, int y) const;         
    int getWidth() const;                     
    int getHeight() const;                    
};

#endif

