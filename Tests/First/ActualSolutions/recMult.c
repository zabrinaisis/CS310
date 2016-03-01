#include <stdio.h>

void recMult(int c, int n) {
    if (c == 0) {
        return;
    } else {
        recMult(c-1, n);
        printf("%d * %d = %d\n", n, c, n*c);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Need a multiplier.");
        return 1;
    }
    int n = atoi(argv[1]);
    recMult(5, n);
}
