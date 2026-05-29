#include "game.h"
#include "player.h"
#include "car.h"
#include "list.h"
#include "score.h"
#include "map.h"
#include "raylib.h"
#include <stdlib.h>

int lanes[] = {
    120,
    200,
    280,
    360,
    440,
    480
};

float laneSpeeds[] = {
    2.0f,
    4.0f,
    3.0f,
    5.0f,
    2.5f,
    4.5f
};

void InitGame(Game *game) {

    InitPlayer(&game->player);
    game->player.won = 0;

    game->carList = NULL;

    initMap(&game->map);

    game->score = 0;
    game->gameOver = 0;
    game->gameWon = 0;
}

void UpdateGame(Game *game) {

    if (game->gameOver) {
        if (IsKeyPressed(KEY_R)) {
            InitGame(game);
        }
        return;
    }

    UpdatePlayer(&game->player);

    if (game->player.won) {
        saveScore(game->score); 
        game->gameWon = 1;
        game->gameOver = 1;
        return;
    }

    updateCars(game->carList);
    removeOffscreenCars(&game->carList);

    checkCollisions(game);

    static int spawnTimer = 0;
    spawnTimer++;

    if (spawnTimer > 30) {
        spawnTimer = 0;

        if (GetRandomValue(0, 100) < 20) {

            int laneIndex = GetRandomValue(0, 5);

            float speed;
            int startX;

            if (laneIndex % 2 == 0) {
                startX = 0;
                speed = laneSpeeds[laneIndex];
            } else {
                startX = 800;
                speed = -laneSpeeds[laneIndex];
            }

            Car *newCar = createCar(
                startX,
                lanes[laneIndex],
                speed
            );

            addCar(&game->carList, newCar);
        }
    }

    if (game->player.y < 600) {
        game->score = (600 - game->player.y) / 40;
    } else {
        game->score = 0;
    }
}

void DrawGame(Game *game) {

    drawMap(&game->map);

    drawCars(game->carList);

    DrawPlayer(&game->player);

    DrawText(
        TextFormat("Score: %d", game->score),
        10,
        10,
        20,
        WHITE
    );

    if (game->gameOver) {

        if (game->gameWon) {
            DrawText("VOCE VENCEU!", 220, 250, 40, GREEN);
        } else {
            DrawText("GAME OVER", 250, 250, 40, RED);
        }

        DrawText("Pressione R para reiniciar", 200, 300, 20, WHITE);

        int scores[5];
        int totalScores = loadScores(scores, 5);

        if (totalScores < 0) totalScores = 0;
        if (totalScores > 5) totalScores = 5;

        DrawText("TOP SCORES:", 250, 350, 25, YELLOW);

        for (int i = 0; i < totalScores; i++) {
            DrawText(
                TextFormat("%d", scores[i]),
                320,
                390 + (i * 30),
                20,
                WHITE
            );
        }
    }
}

void FreeGame(Game *game) {

    Car *current = game->carList;

    while (current != NULL) {
        Car *temp = current;
        current = current->next;
        free(temp);
    }

    game->carList = NULL;
}

void checkCollisions(Game *game) {

    Rectangle playerRect = {
        game->player.x + 5,
        game->player.y + 5,
        game->player.tamanho - 10,
        game->player.tamanho - 10
    };

    Car *current = game->carList;

    while (current != NULL) {

        Rectangle carRect = {
            current->x,
            current->y,
            current->width,
            current->height
        };

        if (CheckCollisionRecs(playerRect, carRect)) {
            saveScore(game->score);
            game->gameOver = 1;
            return;
        }

        current = current->next;
    }
}