#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "headers/mappack.h"

HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);

struct hero {
    short x;
    short y;
    short alive;
    short hp;
    short mp;
};

void convertMatToSprite(char mat[2][30][30], hero play, int y, int x, int lvl){
    if(lvl == 0){
        if (y == play.y && x == play.x){
            //character (@)
            SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            std::cout << "@";
            SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
        } else if(mat[lvl][y][x] == 'R'){
            // █
            std::cout << char(219);
        } else if (mat[lvl][y][x] == 'r'){
            // ▓
            std::cout << char(178);
        } else if (mat[lvl][y][x] == '1'){
            // ║
            std::cout << char(186);
        } else if (mat[lvl][y][x] == '2'){
            // ╚
            std::cout << char(200);
        } else if (mat[lvl][y][x] == '3'){
            // ╝
            std::cout << char(188);
        } else if (mat[lvl][y][x] == '4'){
            // ╗
            std::cout << char(187);
        } else if (mat[lvl][y][x] == '5'){
            // ╔
            std::cout << char(201);
        } else if (mat[lvl][y][x] == '6'){
            // ═
            std::cout << char(205);
        } else if (mat[lvl][y][x] == 'e'){
            // ▒
            std::cout << char(177);
        } else if (mat[lvl][y][x] == 's'){
            std::cout << "|";
        } else {
            std::cout << mat[lvl][y][x];
        }
    } else if (lvl == 1){
        if (y == play.y && x == play.x){
            //character (@)
            SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            std::cout << "@";
            SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
        } else if(mat[lvl][y][x] == 'R'){
            // █
            std::cout << char(219);
        } else if (mat[lvl][y][x] == 'r'){
            // ▓
            std::cout << char(178);
        } else if (mat[lvl][y][x] == 'e'){
            // ▒
            std::cout << char(177);
        } else {
            std::cout << mat[lvl][y][x];
        }
    }
}

void drawMap(hero player, char mat[2][30][30], int lvl){
    for(int y = 0; y < 30; y++){
        for(int x = 0; x < 30; x++){
            convertMatToSprite(mat, player, y, x, lvl);
        }
        std::cout << "\n";
    }
}

void movement(hero &player, char matcollision[2][30][30], char mat[2][30][30], int lvl){
    char key = _getch();
    switch(key){
        case 'w':
            if(matcollision[lvl][ player.y - 1][ player.x] != 'O'){
                player.y--;
                SetConsoleCursorPosition(hando, {player.x, static_cast<short>(player.y + 1)});
                convertMatToSprite(mat, player, player.y + 1, player.x, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(mat, player, player.y, player.x, lvl);
            }
        break;
        case 'a':
            if(matcollision[lvl][ player.y][ player.x - 1] != 'O'){
                player.x--;
                SetConsoleCursorPosition(hando, {static_cast<short>(player.x + 1), player.y});
                convertMatToSprite(mat, player, player.y, player.x + 1, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(mat, player, player.y, player.x, lvl);
            }
        break;
        case 's':
            if(matcollision[lvl][ player.y + 1][ player.x] != 'O'){
                player.y++;
                SetConsoleCursorPosition(hando, {player.x, static_cast<short>(player.y - 1)});
                convertMatToSprite(mat, player, player.y - 1, player.x, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(mat, player, player.y, player.x, lvl);
            }
        break;
        case 'd':
            if(matcollision[lvl][ player.y][ player.x + 1] != 'O'){
                player.x++;
                SetConsoleCursorPosition(hando, {static_cast<short>(player.x - 1), player.y});
                convertMatToSprite(mat, player, player.y, player.x - 1, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(mat, player, player.y , player.x, lvl);
            }
        break;
    }
}

void drawMenu(short hp, short mp, std::string name){
    HANDLE hando = GetStdHandle((STD_OUTPUT_HANDLE));
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
            } else if ((y > 0 && y < 5) && (x == 0 || x == 29)){
                std::cout << char(186);
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    short temp = 15 - name.length()/2;
    SetConsoleCursorPosition(hando, {temp, 31});
    std::cout << name;
    SetConsoleCursorPosition(hando, {3, 33});
    SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_RED);
    std::cout << "HP: " << hp;
    SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    SetConsoleCursorPosition(hando, {3, 34});
    std::cout << "MP: " << mp;
    SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
    SetConsoleCursorPosition(hando, {0, 0});
}

void transition(hero &player, char mapscoll[2][30][30], int &level, int &changemap){
    if(mapscoll[level][player.y][player.x] == '1'){
        level--;
        changemap = 1;
        player.x = 14;
        player.y = 2;
    } else if (mapscoll[level][player.y][player.x] == '2'){
        level++;
        changemap = 1;
        player.x = 14;
        player.y = 27;
    }
}

int main(){
    int level = 0, changemap = 1;
    hero player = {14, 1, 1, 100, 100};
    std::string playerName = "                ";
    while(playerName.length() > 15){
        std::cout << "Type your name: ";
        getline(std::cin, playerName);
    }
    SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
    {CONSOLE_CURSOR_INFO cur;
    GetConsoleCursorInfo(hando, &cur);
    cur.bVisible = false;
    SetConsoleCursorInfo(hando, &cur);}
    while(true){
        system("CLS");
        drawMap(player, maps, level);
        drawMenu(player.hp, player.mp, playerName);
        changemap = 0;
        while(changemap == 0){
            movement(player, mapsCollision, maps, level);
            transition(player, mapsCollision, level, changemap);
        }
    }
    return 0;
}
