#include "player.h"

Player::Player(float x ,float y){
    position = {x,y};
}

void Player::Move(float amountX, float amountY){
    position.x += amountX;
    position.y += amountY;
}