#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct {

    int x;
    int y;
    int tamanho;

    Texture2D texture;

} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);
void FreePlayer(Player *player);

#endif