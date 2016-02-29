#include <stdio.h>
#include <assert.h>

int sumFizzBuzz(int c, int array[]) {
    int sum = 0;
    int i;
    int x = c;
    for (i=0; i < x; i++) {             //error on test "i<c"
        if (((array[i] % 3) == 0) || ((array[i] %5) == 0)) {
            while (c>0) {               //just wrote condition as "c"
                sum = sum + array[i];
                c--;
                break;                  //omitted on test
            }
        } else {
            return 0;
        }
    }
    return sum;                         //in wrong spot on test
}

int main() {
    int a[] = {3, 5, 6, 10, 9, 12, 15};
    int b[] = {2, 5, 6, 10, 9, 11, 15};
    assert(sumFizzBuzz(7, a) == 60);
    assert(sumFizzBuzz(7, b) == 0);
    printf("The function works!!!\n");
}
