#include "player.h"
#include "raylib.h"
#include <stdio.h>

const int TAM_BLOCO = 40;

void InitPlayer(Player *player) {
    player->tamanho = TAM_BLOCO;
    player->won = 0;
    player->x = (GetScreenWidth() / 2) - (player->tamanho / 2);
    player->y = GetScreenHeight() - TAM_BLOCO;
    player->texture = LoadTexture("assets/player.png");


    if (player->texture.id == 0) {
        printf("Erro ao carregar textura\n");
    }
}
void UpdatePlayer(Player *player) {

    if (!player->won) {

        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
            player->y -= TAM_BLOCO;
            if (player->y <= 0) {
                player->won = 1;
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
    Rectangle src = {0, 0, player->texture.width, player->texture.height};
    Rectangle dest = {player->x - 40, player->y - 40, player->tamanho + 80, player->tamanho + 80};
    DrawTexturePro(player->texture, src, dest, (Vector2){0, 0}, 0, WHITE);
}

void FreePlayer(Player *player) {
    UnloadTexture(player->texture);
}