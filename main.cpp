#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "headers/mappack.h"
#include "headers/menufunctions.h"
#include "headers/mapfunctions.h"

int movement(hero &player, char matcollision[2][30][30], char mat[2][30][30], int lvl){
    char key = static_cast<char>(_getch());
    switch(key){
        case 'w':
        case 'W':
            if(matcollision[lvl][ player.y - 1][ player.x] != 'O'){
                player.y--;
                SetConsoleCursorPosition(hando, {player.x, static_cast<short>(player.y + 1)});
                convertMatToSprite(mat, player, player.y + 1, player.x, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(mat, player, player.y, player.x, lvl);
            }
        break;
        case 'a':
        case 'A':
            if(matcollision[lvl][ player.y][ player.x - 1] != 'O'){
                player.x--;
                SetConsoleCursorPosition(hando, {static_cast<short>(player.x + 1), player.y});
                convertMatToSprite(mat, player, player.y, player.x + 1, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(mat, player, player.y, player.x, lvl);
            }
        break;
        case 's':
        case 'S':
            if(matcollision[lvl][ player.y + 1][ player.x] != 'O'){
                player.y++;
                SetConsoleCursorPosition(hando, {player.x, static_cast<short>(player.y - 1)});
                convertMatToSprite(mat, player, player.y - 1, player.x, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(mat, player, player.y, player.x, lvl);
            }
        break;
        case 'd':
        case 'D':
            if(matcollision[lvl][ player.y][ player.x + 1] != 'O'){
                player.x++;
                SetConsoleCursorPosition(hando, {static_cast<short>(player.x - 1), player.y});
                convertMatToSprite(mat, player, player.y, player.x - 1, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(mat, player, player.y , player.x, lvl);
            }
        break;
        case 'e':
        case 'E':
            if(lvl == 0){
                switch(matcollision[lvl][player.y][player.x]){
                    case 'e':
                        interactMenu(player, "Reading", "Douglas' house.", 8, 33);
                    break;
                    case 'f':
                        interactMenu(player, "Reading", "Davi's house.", 9, 33);
                    break;
                    case 'g':
                        interactMenu(player, "Reading", "Lucao's house.", 9, 33);
                    break;
                    case 'h':
                        interactMenu(player, "Reading", "Abandoned house\n\t DO NOT ENTER", 8, 33);
                    break;
                    case 'j':
                        interactMenu(player, "Reading", "Douglas' house.", 8, 33);
                    break;
                    default:
                        interactMenu(player, "", "Nothing's here!", 8, 33);
                    break;
                }
            }
        break;
        case 'q':
        case 'Q':
            return 0;
    }
    return 1;
}

int main(){
    //----Map ID and Map Changer----//
    int level = 0, changemap = 1;
    //----Player Define----//
    hero player = {14, 2, 1, 100, 100, ""};
    while(player.name.length() > 15 || player.name == ""){
        std::cout << "Type your name: ";
        getline(std::cin, player.name);
    }
    //----Remove Cursor and Paint White----//
    SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
    {CONSOLE_CURSOR_INFO cur;
    GetConsoleCursorInfo(hando, &cur);
    cur.bVisible = false;
    SetConsoleCursorInfo(hando, &cur);}
    //=======================LOOP START=======================//
    while(true){
        //----Draw Map and Menu----//
        system("CLS");
        drawMap(player, maps, level);
        drawMenu(player, player.name);
        changemap = 0;
        while(changemap == 0){
            //----Movement and Transition Check----//
            if(movement(player, mapsCollision, maps, level) == 0){
                return 0;
            }
            transition(player, mapsCollision, level, changemap);
        }
    }
}
