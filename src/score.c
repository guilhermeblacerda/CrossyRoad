#include <stdio.h>
#include "score.h"

void saveScore(int score) {

    FILE *file = fopen("score.txt", "a");

    if (file == NULL) {
        return;
    }

    fprintf(file, "%d\n", score);

    fclose(file);
}

int loadScores(int scores[], int maxScores) {

    FILE *file = fopen("score.txt", "r");

    if (file == NULL) {
        return 0;
    }

    int count = 0;

    while (count < maxScores &&
           fscanf(file, "%d", &scores[count]) != EOF) {

        count++;
    }

    fclose(file);

    return count;
}