#include <vector>
#include <string>
#include "raylib.h"
#include "player.h"
#include "bot.h"
#include "global.h"

int botMode = 0;
std::string botText = "Simple Follow";

std::vector<std::vector<int>> invalid_sectors  = {
    {1,1},
    {2,3},
    {4,4}
};

int main(){
    InitWindow(800,600, "Path finding");
    SetTargetFPS(60);

    Player player(world_size.x/2,world_size.y/2);

    Bot bot(200,200, {world_size.x/sector_size, world_size.y/sector_size}, invalid_sectors);

    
    camera.target = {player.position.x, player.position.y};
    camera.offset = {400,300};
    camera.zoom = 2.0f;

    while (!WindowShouldClose()){
        player.prevposition = player.position;

        if (IsKeyDown(KEY_A) && player.position.x > 0) player.Move(-player.speed,0);
        if (IsKeyDown(KEY_D) && player.position.x+10 < world_size.x) player.Move(player.speed,0);
        if (IsKeyDown(KEY_W) && player.position.y > 0) player.Move(0,-player.speed);
        if (IsKeyDown(KEY_S) && player.position.y+10 < world_size.y) player.Move(0,player.speed);

        //bot mode switcher
        if (IsKeyReleased(KEY_ONE)) botMode = 0;
        if (IsKeyReleased(KEY_TWO)) botMode = 1;
        if (IsKeyReleased(KEY_THREE)) botMode = 2;
        if (IsKeyReleased(KEY_FOUR)) botMode = 3;

        camera.target = {player.position.x, player.position.y};

        //bot behaviour
        if (botMode == 0){
            bot.SimpleFollow(player.position.x,player.position.y,1.0f);
            botText = "Simple Follow";
        } else if (botMode == 1){
            bot.FollowAvoidBadSectors(player.position.x,player.position.y,1.0f);
            botText = "Advanced Follow";
        } else if (botMode == 2){
            bot.Mimic(player.prevposition.x-player.position.x,player.prevposition.y-player.position.y);
            botText = "Mimic User";


        //start drawing to the screen
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //draw to the WORLD NOT SCREEN
        BeginMode2D(camera);

        //draw the world border
        DrawRectangleLines(0,0,world_size.x,world_size.y,RED);

        //draw the world tiles
        for (int x = 0; x < world_size.x; x+=sector_size){
            DrawLine(x,0,x,world_size.y,LIGHTGRAY);
        }
        for (int y = 0; y < world_size.y; y+=sector_size){
            DrawLine(0,y,world_size.x,y,LIGHTGRAY);
        }

        //gray out 'invalid' world tiles
        for (int i = 0; i < invalid_sectors.size(); i++){
            DrawRectangle(
                invalid_sectors[i][0]*sector_size,
                invalid_sectors[i][1]*sector_size,
                sector_size,
                sector_size,
                LIGHTGRAY
            );
        }


        //draw the player
        DrawRectangle(player.position.x, player.position.y,player.size,player.size,BLUE);

        bot.Draw();

        EndMode2D();
        //UI GETS PUT HERE
        DrawText(botText.c_str(),20,20,20,BLACK);


        EndDrawing();
        //No more drawing
    }

    CloseWindow();
    return 0;
}