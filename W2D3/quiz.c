#include <stdio.h>

void add1(int *num) {
    *num + 1;
}

void apply(int *a, int l, void (*doit)(int*)) {
    int i;
    for (i = 0; i < l; i++) {
        doit(&a[i]);                    //also, doit(a+i);
    }
}

int main() {
    int array[3] = {1, 2, 3};
    int length = 3;
    apply(array, length, add1);
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

