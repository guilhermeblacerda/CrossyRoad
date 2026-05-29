#include "map.h"
#include "raylib.h"
#include <stdio.h>

void initMap(Map *map) {

    map->grassTexture = LoadTexture("assets/grass.png");
    map->roadTexture = LoadTexture("assets/road.png");

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {

            if (row == 2 || row == 4 || row == 6 ||
                row == 8 || row == 10 || row == 12) {
                map->tiles[row][col] = 1;
            } else {
                map->tiles[row][col] = 0;
            }
        }
    }
}

void drawMap(Map *map) {

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {

            int posX = col * TILE_SIZE;
            int posY = row * TILE_SIZE;

            if (map->tiles[row][col] == 0) {
                DrawTexture(map->grassTexture, posX, posY, WHITE);
            } else {
                DrawTexture(map->roadTexture, posX, posY, WHITE);
            }
        }
    }
}

void freeMap(Map *map) {

    UnloadTexture(map->grassTexture);
    UnloadTexture(map->roadTexture);
}