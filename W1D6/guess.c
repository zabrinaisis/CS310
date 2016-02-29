#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please include two numbers in argument.\n");
        return 1;
    }
    srand(time(NULL));
    int argMax;
    int argMin;
    if (argv[1] > argv[2]) {
        argMax = atoi(argv[1]);         //did not cast
        argMin = atoi(argv[2]);
    } else if (argv[2] > argv[1]) {
        argMax = atoi(argv[2]);
        argMin = atoi(argv[1]);
    } else {
        printf("Need two different numbers.\n");
        return 2;
    }
    int range = argMax - argMin;
    int guess = -1;
    int count = 0;
    int r = ((rand() % argMin) + argMin);
    while (r != guess) {
        printf("Guess a number between, and including %d and %d: ", argMin, argMax);
        scanf("%d", &guess);
        count++;
    }
    printf("Success! You figured out the number in %d tries.\n", count);
}
