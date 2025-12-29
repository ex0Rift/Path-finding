#pragma once
#include "raylib.h"

class Bot{
public:
    Vector2 position;

    Bot(float x, float y);

    void Draw();
    void SimpleFollow(float goalX, float goalY, float speed);
};