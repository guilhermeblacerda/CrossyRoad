#include "list.h"

void addCar(Car **head, Car *newCar) {

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
void freeCars(Car **head) {

    Car *current = *head;

    while (current != NULL) {

        Car *temp = current;

        current = current->next;

        free(temp);
    }

    *head = NULL;
}