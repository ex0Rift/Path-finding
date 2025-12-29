#pragma once
#include "raylib.h"
#include <vector>

class Bot{
public:
    Vector2 position;

    std::vector<std::vector<int>> tile_map;

    Bot(float x, float y, Vector2 world_dim_tiles , std::vector<std::vector<int>> invalid_sectors);

    void Draw();
    void SimpleFollow(float goalX, float goalY, float speed);
};