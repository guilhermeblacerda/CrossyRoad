#include "player.h"
#include "raylib.h"

const int TAM_BLOCO = 40;

void InitPlayer(Player *player) {

    player->tamanho = TAM_BLOCO;

    player->x = (GetScreenWidth() / 2) - (player->tamanho / 2);
    player->y = (GetScreenHeight() / 2) - (player->tamanho / 2);

    // carrega a imagem do jogador
    player->texture = LoadTexture("assets/player.png");

    if (player->texture.id == 0) {
    printf("Erro ao carregar textura\n");
}
}

void UpdatePlayer(Player *player){

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
        player->y -= TAM_BLOCO;

    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
        player->y += TAM_BLOCO;

    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
        player->x -= TAM_BLOCO;

    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
        player->x += TAM_BLOCO;

    if (player->x < 0)
        player->x = 0;

    if (player->y < 0)
        player->y = 0;

    if (player->x > GetScreenWidth() - player->tamanho)
        player->x = GetScreenWidth() - player->tamanho;

    if (player->y > GetScreenHeight() - player->tamanho)
        player->y = GetScreenHeight() - player->tamanho;
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