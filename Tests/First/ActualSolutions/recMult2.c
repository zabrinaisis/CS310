#include <stdio.h>
#include <stdlib.h>

void recMult(int c, int n) {
    if (c == 1) {
        printf("%d * %d = %d\n", n, c, n*c);
        return;
    }
    recMult(c-1, n);
    printf("%d * %d = %d\n", n, c, n*c);
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Need a number!\n");
        return 1;
    }
    int n = atoi(argv[1]);
    recMult(5,n);
}
