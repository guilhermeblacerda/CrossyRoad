#include "car.h"
#include "raylib.h"
#include <stdlib.h>

Car* createCar(float x, float y, float speed) {


    Car *newCar = (Car*)malloc(sizeof(Car));
    if (newCar == NULL){
        return NULL;
    }
    
    newCar->x = x;
    newCar->y = y;
    newCar->width = 60;
    newCar->height = 40;
    newCar->speed = speed;
    newCar->next = NULL;
    newCar->texture = LoadTexture("assets/car.png");
    return newCar;
}

void updateCar(Car *car) {

    if (car == NULL){
        return;
    }

    car->x += car->speed;
}

void drawCar(Car *car) {

    if (car == NULL){
        return;
    }
    Rectangle src = {0, 0, car->texture.width, car->texture.height};
    Rectangle dest = {car->x, car->y, car->width, car->height};
    DrawTexturePro(car->texture, src, dest, (Vector2){0, 0}, 0, WHITE);
}

void destroyCar(Car *car) {
    UnloadTexture(car->texture);
    free(car);
}