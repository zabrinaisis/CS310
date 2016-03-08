#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int total = 0;
    int i;
    const char s1[] = "This is a string";
    const char s2[] = "T";
    int arrayLength = (int)(sizeof(s1))/(sizeof(s1[0])); 
    for (i = 0; i < arrayLength; i++) {
        if (s1[i] == s2[i]) {
            total++;
        }
    }

    printf("Length of matching: %d\n", total);
}
