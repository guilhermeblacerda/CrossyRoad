#ifndef MAP_H
#define MAP_H

#include "raylib.h"

#define ROWS 10
#define COLS 10
#define TILE_SIZE 40

typedef struct Map{

    int tiles[ROWS][COLS];

    Texture2D grassTexture;
    Texture2D roadTexture;

} Map;

void initMap(Map *map);
void drawMap(Map *map);
void freeMap(Map *map);

#endif