#pragma once
#include "raylib.h"

class Player{
public:
    Vector2 position;

    Player(float x, float y);
    void Move(float amountX , float amountY);

};