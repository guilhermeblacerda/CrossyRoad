#include "car.h"
#include <stdlib.h>

Car* createCar(int x, int y, float speed) {

    Car *newCar = (Car*) malloc(sizeof(Car));

    if (newCar == NULL) {
        return NULL;
    }

    newCar->x = x;
    newCar->y = y;
    newCar->width = 60;
    newCar->height = 40;
    newCar->speed = speed;
    newCar->next = NULL;

    return newCar;
}

void updateCar(Car *car) {

    car->x += car->speed;

    //carro indo pra direita (+)
    if (car->speed > 0 &&
        car->x > GetScreenWidth()) {

        car->x = -car->width;
    }

    //carro indo pra esquerda (-)
    if (car->speed < 0 &&
        car->x < -car->width) {

        car->x = GetScreenWidth();
    }
}

void drawCar(Car *car) {

    DrawRectangle(
        car->x,
        car->y,
        car->width,
        car->height,
        RED
    );
}

void destroyCar(Car *car) {

    free(car);
}