#include <stdio.h>
float stack[] = {};
int count = 0;

int push() {
    float add;
    printf("What float would you like to add? ");
    scanf("%f", &add);
    stack[count] = add;
    count++;
}

int pop() {
    printf("%f is no longer on the stack.\n", stack[count]);
    stack[count] = 0;
    count--;
}

int main() {
    char resp1;
    char resp2;
    char *p1 = "Y";
    char *p2 = "N";
    printf("Do you have a float for the stack? (Y/N) ");
    scanf("%c", &resp1);
    if (resp1 == *p1) {
        push();
    } else if (resp1 == *p2) {
        printf("Do you want a float off the stack? (Y/N) ");
        scanf("%c", &resp2);
        if (resp2 == *p1) {
            pop();
        } else {
            printf("The stack has the following entries: ");
            int i;
            for (i = 0; i < (count-1); i++) {
                printf("%f ", stack[i]);
            }
            printf("\n");
        }
    }
}
