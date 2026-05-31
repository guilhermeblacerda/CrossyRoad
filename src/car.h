#ifndef CAR_H
#define CAR_H

#include "raylib.h"

typedef struct Car {
    float x;
    float y;
    int width;
    int height;
    float speed;
    Texture2D texture;
    struct Car *next;
} Car;

Car* createCar(float x, float y, float speed);
void updateCar(Car *car);
void drawCar(Car *car);
void destroyCar(Car *car);

#endif