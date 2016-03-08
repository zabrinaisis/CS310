#include <stdio.h>

int main() {
    int a[3][4];
    int *p = &a[0][0];
    int i, j;
    for (i = 0; i < 12; i++) {
        p[i] = i + 1;
        printf("%d ", p[i]);
    }
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}
