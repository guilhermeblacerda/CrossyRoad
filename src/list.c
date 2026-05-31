#include "list.h"
#include "raylib.h"
#include <stdlib.h>

void addCar(Car **head, Car *newCar) {

    if (newCar == NULL) return;

    newCar->next = *head;
    *head = newCar;
}

void drawCars(Car *head) {

    Car *current = head;

    while (current != NULL) {

        drawCar(current);
        current = current->next;
    }
}

void updateCars(Car *head) {

    Car *current = head;

    while (current != NULL) {

        updateCar(current);
        current = current->next;
    }
}

void removeOffscreenCars(Car **head) {

    Car *current = *head;
    Car *prev = NULL;

    while (current != NULL) {

        int out = current->x > GetScreenWidth() + 100 || current->x < -100;

        if (out) {

            Car *toDelete = current;

            if (prev == NULL) {
                *head = current->next;
                current = *head;
            } else {
                prev->next = current->next;
                current = prev->next;
            }

            free(toDelete);

        } else {
            prev = current;
            current = current->next;
        }
    }
}

void freeCars(Car **head) {

    Car *current = *head;

    while (current != NULL) {

        Car *temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
}