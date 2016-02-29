#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    unsigned int s = 0;
    unsigned int t = 0;
    unsigned int n = 0;
    unsigned int f = 0;
    while ((c = getchar()) != EOF) {
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
