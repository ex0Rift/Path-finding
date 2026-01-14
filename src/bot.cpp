#include "bot.h"
#include "raylib.h"
#include "global.h"
#include <vector>
#include <cstdio>

Bot::Bot(float x, float y, Vector2 world_dim_tiles , std::vector<std::vector<int>> invalid_sectors_t){
    position = {x,y};
    radius = 3.0f;
    world_tiles_quantity = world_dim_tiles;
    invalid_sectors = invalid_sectors_t;

    tile_map.resize(world_dim_tiles.y, std::vector<int>(world_dim_tiles.x, 0));

    for (int i = 0; i < invalid_sectors.size(); i++){
        tile_map[invalid_sectors[i][0]][invalid_sectors[i][1]] = 1;
    }   
}

Vector2 Bot::DetectSector(){
    Vector2 current_tile = {
        position.x / sector_size,
        position.y / sector_size
    };
    return current_tile;
}

bool Bot::CheckIfSectorIsInvalid(){
    Vector2 current_tile = DetectSector();
    for (const auto& i : invalid_sectors){
        if (
            static_cast<int>(current_tile.x) == i[0] &&
            static_cast<int>(current_tile.y) == i[1]
        ){
            return true;
        }
    }
    return false;
}

void Bot::Draw(){
    DrawCircle(position.x,position.y,radius,GREEN);
}

void Bot::SimpleFollow(float goalX, float goalY, float speed){
    if (goalX > position.x){
        position.x += speed;
    }else {
        position.x -= speed;
    }
    if (goalY > position.y){
        position.y += speed;
    }else {
        position.y -= speed;
    }
}

void Bot::Mimic(float movmentX, float movmentY){
    position = {position.x-movmentX, position.y-movmentY};
}

void Bot::FollowAvoidBadSectors(float goalX, float goalY, float speed){
    Vector2 position_old = position;

    if (goalX > position.x){
        position.x += speed;
    }else if (goalX < position.x) {
        position.x -= speed;
    }
    bool resultX = CheckIfSectorIsInvalid();
    if (resultX) position.x = position_old.x;

    if (goalY > position.y){
        position.y += speed;
    }else  if (goalY < position.y){
        position.y -= speed;
    }
    bool resultY = CheckIfSectorIsInvalid();
    if (resultY) {
        if (position.x == position_old.x){
            position.x += speed;
            bool resultC = CheckIfSectorIsInvalid();

        }else{
            position.y = position_old.y;
        }
    }

    

}