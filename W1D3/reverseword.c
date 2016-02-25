#include <stdio.h>

int main (int argc, char *argv[]) {
    int i;
    for (i = (argc-1); i > -1; i--) {
        char *j = argv[i];
        while (*j) {
            printf("%c", *j);
            j++;
        }
        printf("\n");
    }
}
