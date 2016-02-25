#include <stdio.h>

int main (int argc, char *argv[]) {
    int count = 0;
    int i;
    for (i = 1; i < argc; i++) {
        char *j = argv[i];
        while (*j) {
            count++;
            j++;
        }   
    }
    printf("The number of decimal digits is: %d.\n", count);
}
