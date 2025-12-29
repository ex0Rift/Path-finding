#include "bot.h"
#include "raylib.h"
#include <vector>

Bot::Bot(float x, float y, Vector2 world_dim_tiles , std::vector<std::vector<int>> invalid_sectors){
    position = {x,y};

    tile_map.resize(world_dim_tiles.y, std::vector<int>(world_dim_tiles.x, 0));

    for (int i = 0; i < invalid_sectors.size(); i++){
        tile_map[invalid_sectors[i][0]][invalid_sectors[i][1]] = 1;
    }

    
}

void Bot::Draw(){
    DrawRectangle(position.x,position.y,10,10,GREEN);
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