#include "car.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

Car* createCar(float x, float y, float speed) {

    printf("createCar: x=%.0f y=%.0f\n", x, y);


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
    DrawRectangle((int)car->x, (int)car->y, car->width, car->height, RED);
}

void destroyCar(Car *car) {
    free(car);
}