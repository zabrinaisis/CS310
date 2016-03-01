#include <stdio.h>

int sum(int argc, char *argv[]) {
    double input;
    int i;
    for (i = 1; i < argc; i++) {
        char *j = argv[i];
        while (*j != -1) {
            input++;

        }
    }
    return input;
}

int main(int argc, char *argv[]) {
    double result = sum(argc, argv);
    printf("sum is: %f\n", result);
}
