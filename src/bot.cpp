#include "bot.h"
#include "raylib.h"

Bot::Bot(float x, float y){
    position = {x,y};
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