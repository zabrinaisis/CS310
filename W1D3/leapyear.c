#include <stdio.h>

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 0;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

int main () {
    int y;
    printf("Enter a year: ");
    scanf("%d", &y);
    int res = is_leap_year(y);

    if (res == 0) {
        printf("%d is a leap year.\n", y); 
    } else {
        printf("%d is not a leap year.\n", y);
    }
}
