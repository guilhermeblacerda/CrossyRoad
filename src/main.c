#include "game.h"
#include "raylib.h"

int main() {

    Game game;

    InitWindow(800, 600, "Crossy Road");

    InitGame(&game);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        UpdateGame(&game);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawGame(&game);
        EndDrawing();
    }

    FreeGame(&game);

    CloseWindow();

    return 0;
}