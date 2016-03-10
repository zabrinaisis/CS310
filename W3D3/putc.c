#include <stdio.h>
#include <sys/file.h>

int putit(char c) {
    char array[5];
    int position = 0;
    if (position != 4) {
        array[position] = c;
        printf("%c\n", array[position]);
        position++;
    } else {
        flushit(array);
        position = 0;
        array[position] = c;
        printf("%c\n", array[position]);
        position++;
}

void flushit(char* array) {
    int i;
    for (i = 0; i < 5; i++) {
        array[i] = NULL;
    }
}
