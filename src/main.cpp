#include "raylib.h"
#include "player.h"

int main(){
    InitWindow(800,600, "Path finding");
    SetTargetFPS(60);

    Player player(100.0f,100.0f);

    while (!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}