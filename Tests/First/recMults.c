#include <stdio.h>

int mults(int m, int n) {
    if (n == 0) {
        return n;
    } else {
        int res = m*n;
        printf("%d * %d = %d\n", m, n, res);
        return mults(m, n-1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Need a multiplier.");
        return 1;
    }
    int m = atoi(argv[1]);
    int n = 5;
    mults(m, n);
}
