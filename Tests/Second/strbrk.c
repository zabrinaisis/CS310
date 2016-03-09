#include <stdio.h>

char* strbrk(const* a, const* b) {
    int la = strln(a) + 1;
    int lb = strln(b) + 1;
    int i = 0;
    int j = 0;
    while (i < la) {
        while (j < lb) {
            if (a[i] != b[j]) {
                j++;
            } else {
                return &a[i];
            }
        }
        i++;
    }
    return NULL;
}
