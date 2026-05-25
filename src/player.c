#include "player.h"
#include "raylib.h"

const int TAM_BLOCO = 40;

//função para mudar o player de posição
void UpdatePlayer(Player *player){

    //subir
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        player->y -= TAM_BLOCO;
    }
    //descer
    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        player->y += TAM_BLOCO;
    }
    //esquerda
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        player->x -= TAM_BLOCO;
    }
    //direita
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        player->x += TAM_BLOCO;
    }

    //impede de sair da tela
    if (player->x < 0)
        player->x = 0;

    if (player->y < 0)
        player->y = 0;

    if (player->x > GetScreenWidth() - player->tamanho)
        player->x = GetScreenWidth() - player->tamanho;

    if (player->y > GetScreenHeight() - player->tamanho)
        player->y = GetScreenHeight() - player->tamanho;
}


//função para iniciar o player
void InitPlayer(Player *player) {
    player->tamanho = TAM_BLOCO;
    player->x = (GetScreenWidth() / 2) - (player->tamanho / 2);
    player->y = (GetScreenHeight() / 2) - (player->tamanho / 2);
}