#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct {
    int x;
    int y;
    int tamanho;
} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);

#endif