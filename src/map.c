#include "map.h"
#include "raylib.h"
#include <stdio.h>

void initMap(Map *map) {

    Image grassImg = LoadImage("assets/grass.png");
    ImageResize(&grassImg, TILE_SIZE, TILE_SIZE);
    map->grassTexture = LoadTextureFromImage(grassImg);
    UnloadImage(grassImg);

    Image roadImg = LoadImage("assets/road.png");
    ImageResize(&roadImg, 800, TILE_SIZE);
    map->roadTexture = LoadTextureFromImage(roadImg);
    UnloadImage(roadImg);

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == 3 || row == 5 ||
                row == 7 || row == 9 || row == 11) {
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
            Rectangle dest = { posX, posY, TILE_SIZE, TILE_SIZE };
            Rectangle src = { 0, 0, map->grassTexture.width, map->grassTexture.height };
            DrawTexturePro(map->grassTexture, src, dest, (Vector2){0,0}, 0, WHITE);
        }
    }

    for (int row = 0; row < ROWS; row++) {
        if (map->tiles[row][0] == 1) {
            int posY = row * TILE_SIZE;
            Rectangle src = { 0, 0, map->roadTexture.width, map->roadTexture.height };
            Rectangle dest = { 0, posY, 800, TILE_SIZE };
            DrawTexturePro(map->roadTexture, src, dest, (Vector2){0,0}, 0, WHITE);
        }
    }
}

void freeMap(Map *map) {

    UnloadTexture(map->grassTexture);
    UnloadTexture(map->roadTexture);
}