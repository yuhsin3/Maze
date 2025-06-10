#include "Game.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;
struct RecordEntry {
    std::string filename;
    int time;
};

void showMenu() {
    cout << "=== 迷宮遊戲 ===" << endl;
    cout << "1. 開始遊戲" << endl;
    cout << "2. 離開" << endl;
    cout << "3. 遊戲說明" << endl;
    cout << "4. 查看排行榜" << endl;
    cout << "請輸入選項: ";
}

void showDifficultyMenu() {
    cout << endl << "=== 選擇難度 ===" << endl;
    for (int i = 1; i <= 7; ++i)
        cout << i << ". 難度 " << i << endl;
    cout << "8. 隨機地圖" << endl;
    cout << "請選擇: ";
}

void showInstructions() {
    system("cls");
    cout << "=== 遊戲說明 ===" << endl << endl;
    cout << "▶ 遊戲目標：從 '@' 出發，在時間內到達 'E'" << endl << endl;
    cout << "▶ 操作方式：W/A/S/D 移動，Q 離開" << endl;
    cout << "▶ 逃脫成功會記錄所用時間" << endl << endl;
    cout << "（按任意鍵返回主選單）";
    cin.ignore();
    cin.get();
    system("cls");
}

void showLeaderboard() {
    ifstream file("record.txt");
    if (!file) {
        std::cout << "尚無通關紀錄。"<<endl;
        return;
    }

    map<string, vector<int>> recordMap;
    string filename;
    int time;

    while (file >> filename >> time) {
        recordMap[filename].push_back(time);
    }

    if (recordMap.empty()) {
        std::cout << "尚無通關紀錄。"<<endl;
        return;
    }

    // 顯示所有有紀錄的迷宮
    cout << endl << "=== 排行榜（依地圖分類） ===" << endl;
    int index = 1;
    vector<string> keys;
    for (const auto& pair : recordMap) {
        cout << index++ << ". " << pair.first << endl;
        keys.push_back(pair.first);
    }

    cout << "請輸入要查看的地圖編號（0 返回）: ";
    int choice;
    cin >> choice;

    if (choice == 0 || choice > (int)keys.size()) {
        cout << "返回主選單。" << endl;
        return;
    }

    const std::string& selectedMap = keys[choice - 1];
    const std::vector<int>& times = recordMap[selectedMap];

    cout << endl << "=== " << selectedMap << " 的紀錄 ===" << endl;
    for (int t : times) {
        cout << "- " << t << " 秒" << endl;
    }

    cout << "（按任意鍵返回主選單）";
    cin.ignore();
    cin.get();
    system("cls");
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            int difficulty;
            showDifficultyMenu();
            std::cin >> difficulty;
            Game game(difficulty);
            game.run();
        }
        else if (choice == 2) {
            cout << "遊戲結束，再見！"<<endl;
            break;
        }
        else if (choice == 3) {
            showInstructions();
        }
        else if (choice == 4) {
            std::cin.ignore();
            showLeaderboard();
        }
        else {
            cout << "無效選項，請重新輸入。"<<endl;
        }
    }

    return 0;
}
