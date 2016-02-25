#include <stdio.h>

int factorial(int n) {
    int ans = 1;
    while (n > 1) {
        ans = ans * n;
        n = n - 1;
    }
    return ans;
}

int main () {
    int n;
    printf("Please enter value of n: ");
    scanf("%d", &n);
    if (n >= 0) {
        printf("factorial(%d) = ", n);
        printf("%d\n", factorial(n));
    } else {
        printf("The factorial of a negative number is undefined.\n");
    }
}
