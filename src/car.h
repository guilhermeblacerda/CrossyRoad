#ifndef CAR_H
#define CAR_H

#include "raylib.h"

typedef struct Car {
    int x;
    int y;
    int width;
    int height;
    float speed;
    struct Car *next;
} Car;

Car* createCar(int x, int y, float speed);
void updateCar(Car *car);
void drawCar(Car *car);
void destroyCar(Car *car);

#endif