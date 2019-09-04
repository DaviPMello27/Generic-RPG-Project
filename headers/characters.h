#include <windows.h>
#include <iostream>
#ifndef CHARACTERS_H
#define CHARACTERS_H
//===================HANDLE===================//
#define hando GetStdHandle(STD_OUTPUT_HANDLE)
//===================PALYER===================//
struct hero {
    short x;
    short y;
    short alive;
    std::string name;
};

#endif // CHARACTERS_H
