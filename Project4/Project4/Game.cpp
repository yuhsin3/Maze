#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
Game::Game() : timeLimit(60), filename("maze1.txt") {}

Game::Game(int difficulty) {
    const char* files[7] = {
        "maze1.txt", "maze2.txt", "maze3.txt", "maze4.txt",
        "maze5.txt", "maze6.txt", "maze7.txt"
    };

    int index;
    if (difficulty == 8) {
        srand(static_cast<unsigned>(time(0)));
        index = rand() % 7;
    }
    else if (difficulty >= 1 && difficulty <= 7) {
        index = difficulty - 1;
    }
    else {
        index = 1;
    }

    filename = files[index];
    timeLimit = 90 - index * 10;
    if (!maze.loadFromFile(filename.c_str())) {
        std::cout << "Failed to load maze file.\n";
        timeLimit = 0;
    }
}

void Game::run() {
    if (maze.getWidth() == 0 || maze.getHeight() == 0) {
        std::cout << "Maze not loaded."<<endl;
        return;
    }

    player.setPosition(1, 1);
    player.bindMaze(&maze);

    time_t start = time(0);

    while (true) {
        maze.display(player.getX(), player.getY());

        time_t now = time(0);
        int elapsed = static_cast<int>(now - start);
        int remaining = timeLimit - elapsed;

        cout << "Time left: " << remaining << " seconds"<<endl;

        if (remaining <= 0) {
            cout << "Time's up! You lose." << endl;
            break;
        }

        char input = _getch();
        if (input == 'Q' || input == 'q') break;

        player.move(input);

        if (maze.getTile(player.getX(), player.getY()) == 'E') {
            time_t end = time(0);
            int used = static_cast<int>(end - start);

            maze.display(player.getX(), player.getY());
            cout << "You escaped the maze!" << endl;
            cout << "Total time used: " << used << " seconds" << endl;

            std::ofstream log("record.txt", std::ios::app);
            if (log.is_open()) {
                log << filename << " " << used << endl;
                log.close();
            }
            else {
                std::cout << "Failed to write record." << endl;
            }

            break;
        }
    }
}
