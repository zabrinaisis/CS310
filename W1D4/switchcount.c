#include <stdio.h>

    int cspace = 0;
    int ctab = 0;
    int cnewline = 0;
    int cformfeed = 0;

int theswitch(int n) {
    switch(n) {
        case 32:
            cspace++;
            break;
        case 9:
            ctab++;
            break;
        case 13:
            cnewline++;
            break;
        case 12:
            cformfeed++;
            break;
    }
}


int main(int argc, char *argv[]) {
   
    FILE *from = fopen(argv[1], "r");
    FILE *to = fopen(argv[2], "w");
    char c;

    if (argc != 3) {
        printf("Please give two file names.\n");
        return 1;
    }

    while ((c = getc(from) != EOF)) {
        printf("%c\n", putchar(c));
        theswitch(c);               
    }
}
