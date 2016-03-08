#include <stdio.h>

int main() {
    double cur[] = {115.25, 25.67, 34.00, 1.25, 8900.75};
    int i;
    printf("The amounts are:\n");
    for (i = 0; i < 5; i++) {
        printf("$%8.2f\n", cur[i]);
    }
}
