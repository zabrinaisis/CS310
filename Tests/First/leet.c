#include <stdio.h>

int main () {
    char c;
    while ((c = getchar()) != EOF) {
        switch(c) {
            case 'e':
                c = '3';
                break;
            case 'a':
                c = '4';
                break;
            case 'o':
                c = 'O';
                break;
            case 'l':
                c = '1';
                break;
            case 't':
                c = '7';
                break;
        }
        printf("%c", c);
    }
}

// Worked the first time without changes!
