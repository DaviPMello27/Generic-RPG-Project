#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "menufunctions.h"
#include "mapfunctions.h"
#include "controls.h"

int main(){
    //----Map ID and Map Changer----//
    int level = 3, changemap = 1;
    //----Player Define----//
    hero player = {18, 15, 1, "Davi"};
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
        drawMap(player, level);
        drawMenu(player, player.name);
        changemap = 0;
        while(changemap == 0){
            //----Movement and Transition Check----//
            if(movement(player, level) == 0){
                return 0;
            }
            transition(player, level, changemap);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {35, 0});
            std::cout << "x: " << player.x << ", y: " << player.y;
        }
    }
}
