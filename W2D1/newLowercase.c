#include <stdio.h>

int lowercase(char *s) {
    int i;
    char *c;
    for(i = 0; s[i] != '\0'; i++) {
        int convert = tolower(c);

    }
}

int main() {
    char *string;
    printf("Please write some text: ");
    scanf("%s", string);
    printf("%s", lowercase(string));
}
