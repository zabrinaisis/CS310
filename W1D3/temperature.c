#include <stdio.h>

int main() {
    char typ;
    char *fah = "F";
    char *cel = "C";
    printf("To convert Fahrenheit to Celcius, type F.\n");
    printf("To convert Celcius to Fahrenheit, type C.\n");
    printf("Choice = ");
    scanf("%c", &typ);

    if (typ == *fah) {
        int tmp;
        printf("Enter Fahrenheit temperature: ");
        scanf("%d", &tmp);
        tmp = tmp - 32;
        printf("The temperature in Celcius is %d.\n", tmp);
    }
    if (typ == *cel) {
        int tmp;
        printf("Enter Celcius temperature: ");
        scanf("%d", &tmp);
        tmp = tmp + 32;
        printf("The temperature in Fahrenheit is %d.\n", tmp);
    }
}
