#include "player.h"
#include "raylib.h"

const int TAM_BLOCO = 40;

void UpdatePlayer(Player *player){

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        player->y -= TAM_BLOCO;
    }

    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        player->y += TAM_BLOCO;
    }

    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        player->x -= TAM_BLOCO;
    }

    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        player->x += TAM_BLOCO;
    }

    if (player->x < 0)
        player->x = 0;

    if (player->y < 0)
        player->y = 0;

    if (player->x > GetScreenWidth() - player->tamanho)
        player->x = GetScreenWidth() - player->tamanho;

    if (player->y > GetScreenHeight() - player->tamanho)
        player->y = GetScreenHeight() - player->tamanho;
}