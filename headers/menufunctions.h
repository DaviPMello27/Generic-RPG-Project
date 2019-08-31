#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H
#include <windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include "headers/characters.h"

void drawMenu(hero, std::string, short = 0, short = 0, std::string = "");

void interactMenu(hero &player, std::string, std::string, short, short);

#endif // MENUFUNCTIONS_H
