#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "car.h"
#include "map.h"


typedef struct Game{
    Map map;
    Player player;
    Car *carList;
    int score;
    int gameOver;
    int gameWon;
} Game;

void InitGame(Game *game);
void UpdateGame(Game *game);
void DrawGame(Game *game);
void ResetGame(Game *game);
void FreeGame(Game *game);
void checkCollisions(Game *game);

#endif