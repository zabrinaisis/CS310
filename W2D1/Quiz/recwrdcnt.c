// Recursive word count.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int wordcount(int first, char* buf) {
    
    if (first == TRUE) {
        if (strtok(buf, " \n\r\t\f") != NULL) {
        return 1 + wordcount(FALSE, buf);
        }
    } else if (strtok(NULL, " \n\r\t\f")) {
        return 1 + wordcount(FALSE, NULL);
    } else {
        return 0;
    }
}

int main() {
    char *buf = (char*) calloc(1024, sizeof(char));
    fgets(buf, 1023, stdin);
    printf("Words: %d\n", wordcount(TRUE, buf));
}
