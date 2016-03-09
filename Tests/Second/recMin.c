#include <stdio.h>
#include <limits.h>

int recMin (int a[], int l, int min) {
    if (l == 0) {                   // technically did this wrong (l<0)
        return min;
    } else {
        if (a[l-1] < min) {
            return recMin(a, l-1, a[l-1]);  // forgot return
        } else {
            return recMin(a, l-1, min);     // forgot return
        }
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 20, 4, 1, 3};
    printf("%d\n", recMin(array, 5, INT_MAX));
}
