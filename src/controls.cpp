#include <conio.h>
#include "mappack.h"
#include "mapfunctions.h"
#include "characters.h"
#include "menufunctions.h"
#include "interactions.h"

int movement(hero &player, int lvl){
    char key = static_cast<char>(_getch());
    switch(key){
        case 'w':
        case 'W':
            if(mapsCollision[lvl][ player.y - 1][ player.x] != 'O'){
                player.y--;
                SetConsoleCursorPosition(hando, {player.x, static_cast<short>(player.y + 1)});
                convertMatToSprite(player, player.y + 1, player.x, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(player, player.y, player.x, lvl);
            }
        break;
        case 'a':
        case 'A':
            if(mapsCollision[lvl][ player.y][ player.x - 1] != 'O'){
                player.x--;
                SetConsoleCursorPosition(hando, {static_cast<short>(player.x + 1), player.y});
                convertMatToSprite(player, player.y, player.x + 1, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(player, player.y, player.x, lvl);
            }
        break;
        case 's':
        case 'S':
            if(mapsCollision[lvl][ player.y + 1][ player.x] != 'O'){
                player.y++;
                SetConsoleCursorPosition(hando, {player.x, static_cast<short>(player.y - 1)});
                convertMatToSprite(player, player.y - 1, player.x, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(player, player.y, player.x, lvl);
            }
        break;
        case 'd':
        case 'D':
            if(mapsCollision[lvl][ player.y][ player.x + 1] != 'O'){
                player.x++;
                SetConsoleCursorPosition(hando, {static_cast<short>(player.x - 1), player.y});
                convertMatToSprite(player, player.y, player.x - 1, lvl);
                SetConsoleCursorPosition(hando, {player.x, player.y});
                convertMatToSprite(player, player.y , player.x, lvl);
            }
        break;
        case 'e':
        case 'E':
            interact(player, lvl);
        break;
        case 'q':
        case 'Q':
            return 0;
    }
    return 1;
}
