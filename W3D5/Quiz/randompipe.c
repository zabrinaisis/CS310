#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>     // required for fork() and pipe()

int main() {
    srand(time(NULL));
    int num = (rand() % 25) + 1;

    int p[2];
    pipe(p);

    if (fork() == 0) {
        close(p[0]);
        num = (rand() % 25) + 1;
        int w = write(p[1], &num, sizeof(int));
        while (w > 0) {
            num = (rand() % 25) + 1;
            w = write(p[1], &num, sizeof(int));
        }
        _exit(0);
    }

    close(p[1]);
    int guess;
    int count = 1;
    int r = read(p[0], &guess, sizeof(int));
    while (guess != num && r > 0) {
        r = read(p[0], &guess, sizeof(int));
        count++;
    }

    close(p[0]);
    printf("Child took %d guess(es) to find %d.\n", count, num);
}
