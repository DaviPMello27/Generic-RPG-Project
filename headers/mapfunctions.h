#ifndef MAPFUNCTIONS_H
#define MAPFUNCTIONS_H
#include "characters.h"

void convertMatToSprite(char mat[2][30][30], hero play, int y, int x, int lvl);

void drawMap(hero player, char mat[2][30][30], int lvl);

void transition(hero &player, char mapscoll[2][30][30], int &level, int &changemap);

#endif // MAPFUNCTIONS_H
