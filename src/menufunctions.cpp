#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "characters.h"


void drawMenu(hero player, std::string name, short textX = 0, short textY = 0, std::string text = ""){
    std::cout << "\n";
    for(int y = 0; y < 6; y++){
        for(int x = 0; x < 30; x++){
            if(y == 0 && x == 0){
                std::cout << char(201);
            } else if (x == 29 && y == 0){
                std::cout << char(187);
            } else if (x == 0 && y == 5){
                std::cout << char(200);
            } else if (x == 29 && y == 5){
                std::cout << char(188);
            } else if ((x > 0 && x < 29) && (y == 0 || y == 5)){
                std::cout << char(205);
            } else if ((y > 0 && y < 5) && (x == 0 || x == 29) && name == player.name){
                std::cout << char(186);
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    SetConsoleCursorPosition(hando, {static_cast<short>(15 - name.length()/2), 31});
    std::cout << name;
    SetConsoleCursorPosition(hando, {textX, textY});
    std::cout << text;
    SetConsoleCursorPosition(hando, {0, 0});
};

void interactMenu(hero &player, std::string title, std::string content, short x, short y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 30});
    drawMenu(player, title, x, y, content);
    _getch();
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 30});
    drawMenu(player, player.name);
};
