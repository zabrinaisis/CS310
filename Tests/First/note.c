#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please include a file name to write to.\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "w");
    char c;
    while ((c = getchar()) != EOF) {
        putc(c, file);
    }
    fclose(file);
    return 0;
}

// Worked first time without a problem!
