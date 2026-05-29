#include "map.h"
#include "raylib.h"
#include <stdio.h>

// inicializa o mapa
void initMap(Map *map) {

    // carrega texturas
    map->grassTexture = LoadTexture("assets/grass.png");
    map->roadTexture = LoadTexture("assets/road.png");

    // verifica se carregou corretamente
    if (map->grassTexture.id == 0) {
        printf("Erro ao carregar grass.png\n");
    }

    if (map->roadTexture.id == 0) {
        printf("Erro ao carregar road.png\n");
    }

    // cria o mapa
    for (int y = 0; y < ROWS; y++) {

        for (int x = 0; x < COLS; x++) {

            // linhas de estrada
            if (
                y == 2 ||
                y == 4 ||
                y == 6 ||
                y == 8 ||
                y == 10 ||
                y == 12
            ) {

                map->tiles[y][x] = 1;
            }

            // grama
            else {

                map->tiles[y][x] = 0;
            }
        }
    }
}

// desenha o mapa
void drawMap(Map *map) {

    for (int y = 0; y < ROWS; y++) {

        for (int x = 0; x < COLS; x++) {

            int posX = x * TILE_SIZE;
            int posY = y * TILE_SIZE;

            // grama
            if (map->tiles[y][x] == 0) {

                DrawTexture(
                    map->grassTexture,
                    posX,
                    posY,
                    WHITE
                );
            }

            // estrada
            else {

                DrawTexture(
                    map->roadTexture,
                    posX,
                    posY,
                    WHITE
                );
            }
        }
    }
}

// libera memória
void freeMap(Map *map) {

    UnloadTexture(map->grassTexture);
    UnloadTexture(map->roadTexture);
}