#include <stdio.h>

int main (int argc, char *argv[]) {
    int i;
    for (i = (argc-1); i > 0; i--) {
        char *j = argv[i];
        while (*j != '\0') {
            j++;
        }
        j--;
        while (*j) {
            printf("%c\n", *j);
            j--;
        }
    }
}
