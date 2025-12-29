#pragma once
#include "raylib.h"

class Player{
public:
    Vector2 position;
    float speed;
    float size;

    Player(float x, float y);
    void Move(float amountX , float amountY);

};