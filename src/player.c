#include "player.h"
#include "raylib.h"
#include <stdio.h>

const int TAM_BLOCO = 40;

void InitPlayer(Player *player) {

    player->tamanho = TAM_BLOCO;
    player->won = 0;

    player->x = (GetScreenWidth() / 2) - (player->tamanho / 2);
    player->y = GetScreenHeight() - (TAM_BLOCO * 4);

    player->texture = LoadTexture("assets/player.png");

    if (player->texture.id == 0) {
        printf("Erro ao carregar textura\n");
    }
}
void UpdatePlayer(Player *player) {

    if (!player->won) {

        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            if (player->y - TAM_BLOCO <= -80) {
                player->y -= TAM_BLOCO;
                player->won = 1;
            } else {
                player->y -= TAM_BLOCO;
            }
        }

        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
            player->y += TAM_BLOCO;

        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
            player->x -= TAM_BLOCO;

        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
            player->x += TAM_BLOCO;

        if (player->x < 0)
            player->x = 0;

        if (player->y > GetScreenHeight() - player->tamanho)
            player->y = GetScreenHeight() - player->tamanho;

        if (player->x > GetScreenWidth() - player->tamanho)
            player->x = GetScreenWidth() - player->tamanho;
    }
}
void DrawPlayer(Player *player) {

    DrawTexture(
        player->texture,
        player->x,
        player->y,
        WHITE
    );
}

void FreePlayer(Player *player) {
    UnloadTexture(player->texture);
}