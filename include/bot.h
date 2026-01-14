#pragma once
#include "raylib.h"
#include <vector>

class Bot{
private:
    Vector2 DetectSector();
    bool CheckIfSectorIsInvalid();

    Vector2 world_tiles_quantity;
    std::vector<std::vector<int>> invalid_sectors;
    
public:
    Vector2 position;
    float radius;

    std::vector<std::vector<int>> tile_map;

    Bot(float x, float y, Vector2 world_dim_tiles , std::vector<std::vector<int>> invalid_sectors_t);

    void Draw();
    void SimpleFollow(float goalX, float goalY, float speed);
    void Mimic(float movmentX, float movmentY);
    void FollowAvoidBadSectors(float goalX, float goalY, float speed);
};