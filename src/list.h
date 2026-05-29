#ifndef LIST_H
#define LIST_H

#include "car.h"

void addCar(Car **head, Car *newCar);
void updateCars(Car *head);
void drawCars(Car *head);
void freeCars(Car **head);
void removeOffscreenCars(Car **head);

#endif