#include "raylib.h"
#include "player.h"
#include "bot.h"

Vector2 world_size = {300.0f, 300.0f};

int main(){
    InitWindow(800,600, "Path finding");
    SetTargetFPS(60);

    Player player(world_size.x/2,world_size.y/2);

    Bot bot(200,200);

    Camera2D camera = {0};
    camera.target = {player.position.x, player.position.y};
    camera.offset = {400,300};
    camera.zoom = 2.0f;

    while (!WindowShouldClose()){

        if (IsKeyDown(KEY_A) && player.position.x > 0) player.Move(-5,0);
        if (IsKeyDown(KEY_D) && player.position.x+10 < world_size.x) player.Move(5,0);
        if (IsKeyDown(KEY_W) && player.position.y > 0) player.Move(0,-5);
        if (IsKeyDown(KEY_S) && player.position.y+10 < world_size.y) player.Move(0,5);

        camera.target = {player.position.x, player.position.y};

        //start drawing to the screen
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //draw to the WORLD NOT SCREEN
        BeginMode2D(camera);

        //bot behaviour
        bot.SimpleFollow(player.position.x,player.position.y,1.0f);

        //draw teh world border
        DrawRectangleLines(0,0,world_size.x,world_size.y,RED);

        //draw the world tiles
        for (int x = 0; x < world_size.x; x+=50){
            DrawLine(x,0,x,world_size.y,LIGHTGRAY);
        }
        for (int y = 0; y < world_size.y; y+=50){
            DrawLine(0,y,world_size.x,y,LIGHTGRAY);
        }


        DrawRectangle(player.position.x, player.position.y,10,10,BLUE);

        bot.Draw();

        EndMode2D();
        //UI GETS PUT HERE

        EndDrawing();
        //No more drawing
    }

    CloseWindow();
    return 0;
}