// Counts the words of stdin.
// Buffer of 1024.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *buf = (char*) calloc(1024, sizeof(char));
    fgets(buf, 1023, stdin);
    char *tok = strtok(buf, " \n\t\f\r");
    int words = 0;
    if (tok != NULL) {
        words = 1;
        while (tok = strtok(NULL, " \n\t\f\r")) {
            words++;
        }
    }
    printf("Words: %d\n", words);
}
