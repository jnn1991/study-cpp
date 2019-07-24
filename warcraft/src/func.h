#pragma once
#ifndef __func_h__
#define __func_h__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using std::string;

enum Color{
    RED,
    BLUE,
    NOTSET
};

enum WarriorType
{
    DRAGON_TYPE,
    NINJA_TYPE,
    ICEMAN_TYPE,
    LION_TYPE,
    WOLF_TYPE
};

inline string toString(Color color)
{
    return (color==RED)? string("red"):string("blue");
}

inline string toString(WarriorType type)
{
    switch(type)
    {
    case DRAGON_TYPE:return "dragon";
    case NINJA_TYPE: return "nija";
    case ICEMAN_TYPE: return "iceman";
    case LION_TYPE: return "lion";
    case WOLF_TYPE: return "wolf";
    default:
        return string();
    }
}

#endif
