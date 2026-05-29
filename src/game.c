#include "game.h"
#include "player.h"
#include "car.h"
#include "list.h"
#include <stdlib.h>

int lanes[] = {
    80,
    160,
    240,
    320,
    400,
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

//inicializa o jogo
void InitGame(Game *game) {

    InitPlayer(&game->player);

    game->carList = NULL;

    initMap(game->map);

    game->score = 0;
    game->gameOver = 0;
}

void UpdateGame(Game *game) {
    //evita atualizar o jogo finalizado
    if (!game->gameOver) {
        //movimenta o jogador
        UpdatePlayer(&game->player);
        //movimenta os carros
        updateCars(game->carList);
        //remove carros fora da tela
        removeOffscreenCars(&game->carList);
        //verifica colisões
        checkCollisions(game);
         //cria novo carro
        if (GetRandomValue(0, 100) < 2) {

            int laneIndex = GetRandomValue(0, 5);

            float speed;
            int startX;

            //faixa par vai pra direita
            if (laneIndex % 2 == 0) {

                speed = laneSpeeds[laneIndex];
                startX = 0;
            }

            //faixa impar pra esquerda
            else {

                speed = laneSpeeds[laneIndex];
                startX = 800;
            }

            Car *newCar = createCar(
                startX,
                lanes[laneIndex],
                speed
            );

            addCar(&game->carList, newCar);
        }
        //atualiza o score
        game->score = (600 - game->player.y) / 40;
    }
}
//checa colisões
void checkCollisions(Game *game) {

    Car *current = game->carList;
    //desenha retangulo
    Rectangle playerRect = {
        game->player.x,
        game->player.y,
        game->player.tamanho,
        game->player.tamanho
    };
    //percorre os carros
    while (current != NULL) {

        Rectangle carRect = {
            current->x,
            current->y,
            40,
            40
        };
        //se houver colisão, finaliza o jogo e o trava o score
        if (CheckCollisionRecs(playerRect, carRect)) {

            game->gameOver = 1;

            saveScore(game->score);
        }

        current = current->next;
    }
}
//parte visual
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
//libera a memória
void FreeGame(Game *game) {

    Car *current = game->carList;

    while (current != NULL) {
        Car *temp = current;
        current = current->next;
        free(temp);
    }

    game->carList = NULL;
}