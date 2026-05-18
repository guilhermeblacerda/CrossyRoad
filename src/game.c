#include "game.h"
#include "player.h"
#include "car.h"
#include <stdlib.h>

void InitGame(Game *game) {

    InitPlayer(&game->player);

    game->carList = NULL;

    initMap(game->map);

    game->score = 0;
    game->gameOver = 0;
}

void UpdateGame(Game *game) {

    if (!game->gameOver) {

        UpdatePlayer(&game->player);

        updateCars(&game->carList);

        checkCollisions(game);

        if (GetRandomValue(0, 100) < 2) {
            Car *newCar = createCar(
                0,
                (GetRandomValue(0, 9) * 40),
                3.0f
            );

            addCar(&game->carList, newCar);
        }

        game->score = (600 - game->player.y) / 40;
    }
}

void checkCollisions(Game *game) {

    Car *current = game->carList;

    Rectangle playerRect = {
        game->player.x,
        game->player.y,
        game->player.tamanho,
        game->player.tamanho
    };

    while (current != NULL) {

        Rectangle carRect = {
            current->x,
            current->y,
            40,
            40
        };

        if (CheckCollisionRecs(playerRect, carRect)) {

            game->gameOver = 1;

            saveScore(game->score);
        }

        current = current->next;
    }
}

void DrawGame(Game *game) {

    drawMap(game->map);

    drawCars(game->carList);

    DrawPlayer(&game->player);

    DrawText(TextFormat("Score: %d", game->score), 10, 10, 20, WHITE);

    if (game->gameOver) {
        DrawText("GAME OVER", 250, 250, 40, RED);
        DrawText("Pressione R para reiniciar", 200, 300, 20, WHITE);
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