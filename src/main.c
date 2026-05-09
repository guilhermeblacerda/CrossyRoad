#include "raylib.h"

int main() {
    
    //tamanhos constantes de largura e altura da janela
    const int screenWidth = 800;
    const int screenHeight = 600;

    //inicializa a janela com as dimensões já definidas
    InitWindow(screenWidth, screenHeight, "Crossy Road");

    //define as dimensões do player, no centro da tela
    int playerX = 400;
    int playerY = 300;
    int playerSize = 40;

    //60 fps por segundo
    SetTargetFPS(60);


    //jogo roda até fechar a janela ou ESC
    while (!WindowShouldClose()) {

        //W = cima
        //S = baixo
        //D = direita
        //A = esquerda
        if (IsKeyPressed(KEY_W)) playerY -= 40;
        if (IsKeyPressed(KEY_S)) playerY += 40;
        if (IsKeyPressed(KEY_A)) playerX -= 40;
        if (IsKeyPressed(KEY_D)) playerX += 40;

        //inicia o desenho
        BeginDrawing();

        //limpa a tela
        ClearBackground(DARKGREEN);
        
        //desenha o jogador
        DrawRectangle(playerX, playerY, playerSize, playerSize, YELLOW);

        //finaliza o desenho do jogador
        EndDrawing();
    }

    //finaliza o jogo