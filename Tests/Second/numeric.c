#include <stdio.h>

typedef union {
    char cval;
    short sval;
    int ival;
    float fval;
    double dval;
} Numeric;

Numeric reduce(Numeric a[], int len, void(*op)(Numeric*, const Numeric*)) {
    Numeric res;                       // not a pointer!
    res.dval = 0;                     // not required
    int i;
    for (i = 0; i < len; i++) {
        op(&res, &a[i]);
    }
    return res;
}

void intPlus(Numeric* a, const Numeric* b) {
    a[0].ival += b[0].ival;
}

int main() {
    Numeric array[5];
    int i;
    for (i = 0; i < 5; i++) {
        array[i].ival = i + 1;
    }
    if (reduce(array, 5, &intPlus).ival == 15) {
        printf("Hooray\n");
    }
}
