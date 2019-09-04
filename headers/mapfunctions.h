#ifndef MAPFUNCTIONS_H
#define MAPFUNCTIONS_H
#include "characters.h"

void convertMatToSprite(hero play, int y, int x, int lvl);

void drawMap(hero player, int lvl);

void transition(hero &player, int &level, int &changemap);

#endif // MAPFUNCTIONS_H
