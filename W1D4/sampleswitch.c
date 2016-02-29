#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Need filename!\n");
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    char c;
    unsigned int s = 0;
    unsigned int t = 0;
    unsigned int n = 0;
    unsigned int f = 0;
    while ((c = getc(file)) != EOF) {
        switch (c) {
            case ' ':
                s++;
                break;
            case '\t':
                t++;
                break;
            case '\n':
                n++;
                break;
            case '\f':
                f++;
                break;

        }
    }
    printf("Spaces: %u\n", s);
    printf("Tabs: %u\n", t);
    printf("New Lines: %u\n", n);
    printf("Form Feeds: %u\n", f);

}
