// Counts the characters from user input.
// Buffer is 1024.

#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

int main() {
    char buf[BUFSIZE];
    fgets(buf, BUFSIZE - 1, stdin);
    printf("Characters read : %d\n", (int)strlen(buf));
}
