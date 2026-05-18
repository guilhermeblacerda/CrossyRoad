#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "car.h"

#define ROWS 100
#define COLS 20

typedef struct {
    Player player;
    Car *carList;
    int map[ROWS][COLS];
    int score;
    int gameOver;
} Game;

void InitGame(Game *game);
void UpdateGame(Game *game);
void DrawGame(Game *game);
void ResetGame(Game *game);
void FreeGame(Game *game);

#endif