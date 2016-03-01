#include <stdio.h>

int recSum(int c, int a[]) {
    if (c == 0) {
        return 0;
    } else {
        return ((a[c-1]) + recSum((c-1), a));
    }
}

int main() {
    int length = 5;
    int array[] = {1, 2, 3, 4, 5};
    printf("%d\n", recSum(length, array));
}

// Originally tried to introduce a local variable.
//  This is a bad idea unless it is to be reset with each iteration.
// Also, the final return requires a number because it's needed to add.
// Could have been done with an index variable that terminates the problem
//  when the length defined and the index are equal.
