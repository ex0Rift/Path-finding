#include "player.h"

Player::Player(float x ,float y){
    position = {x,y};
    prevposition = {x,y};
    speed = 3;
    size = 10;
}

void Player::Move(float amountX, float amountY){
    position.x += amountX;
    position.y += amountY;
}