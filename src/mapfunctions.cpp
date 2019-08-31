#include <iostream>
#include <windows.h>
#include "characters.h"

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
    } else if(lvl == 2){
        if (y == play.y && x == play.x){
            //character (@)
            SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            std::cout << "@";
            SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
        } else if(mat[lvl][y][x] == 'W'){
            // █
            std::cout << char(219);
        } else if(mat[lvl][y][x] == 't'){
            // ▓
            std::cout << char(178);
        } else if (mat[lvl][y][x] == 's'){
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

void transition(hero &player, char mapscoll[2][30][30], int &level, int &changemap){
    switch(level){
        case 0:
            switch(mapscoll[0][player.y][player.x]){
                case '1':
                    //insert level change here;
                    changemap = 1;
                    player.x = 14;
                    player.y = 2;
                break;
                case '2':
                    level = 1;
                    changemap = 1;
                    player.x = 14;
                    player.y = 27;
                break;
                case '3':
                    level = 2;
                    changemap = 1;
                    player.x = 28;
                    player.y = 13;
                break;
            }
        break;
        case 1:
            switch(mapscoll[1][player.y][player.x]){
                case '1':
                    level = 0;
                    changemap = 1;
                    player.x = 14;
                    player.y = 2;
                break;
            }
        break;
        case 2:
            switch(mapscoll[2][player.y][player.x]){
                case '1':
                    level = 0;
                    changemap = 1;
                    player.x = 8;
                    player.y = 7;
                break;
            }
        break;
    }
}
