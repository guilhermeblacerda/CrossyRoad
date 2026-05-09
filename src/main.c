#include "raylib.h"

typedef struct {
    Vector2 pos;
    int tamanho;
} Player;

int main() {

    // Configuração da janela
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Crossy Road Clone");

    // Player
    Player player;

    player.pos = (Vector2){400, 300};
    player.tamanho = 40;

    // FPS
    SetTargetFPS(60);

    // Loop principal
    while (!WindowShouldClose()) {

        // Desenho
        BeginDrawing();

        ClearBackground(DARKGREEN);

        // Player
        DrawRectangle(
            player.pos.x,
            player.pos.y,
            player.tamanho,
            player.tamanho,
            YELLOW
        );

        EndDrawing();
    }

    // Fechar janela
    CloseWindow();

    return 0;
}