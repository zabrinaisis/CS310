#include <stdio.h>
#include <unistd.h>

int main() {
    int pipeAB[2];
    int pipeBC[2];
    int pipeCA[2];
    pipe(pipeAB);
    pipe(pipeBC);
    pipe(pipeCA);
    int buf;
    int r = 1;

    // parent is process A
    // first child is process is B

    if (fork()  == 0) {
        close(pipeCA[0]);
        close(pipeCA[1]);
        close(pipeAB[1]);       // can only read from this pipe
        close(pipeBC[0]);       // can only write to this pipe
        while (r) {
            r = read(pipeAB[0], &buf, 1);
            if (r) {
                printf("Process B recieved: %c\n", buf);
            }
            write(pipeBC[1], &buf, r);
        }
        close(pipeAB[0]);
        close(pipeBC[1]);
        _exit(0);
    }

    if (fork()  == 0) {
        close(pipeAB[0]);
        close(pipeAB[1]);
        close(pipeBC[1]);       // can only read from this pipe
        close(pipeCA[0]);       // can only write to this pipe
        while (r) {
            r = read(pipeBC[0], &buf, 1);
            if (r) {
                printf("Process C recieved: %c\n", buf);
            }
            write(pipeCA[1], &buf, r);
        } while (r);
        close(pipeBC[0]);
        close(pipeCA[1]);
        _exit(0);
    }
    
    int out = 'A';
    int in = 0;
    close(pipeBC[0]);
    close(pipeBC[1]);
    close(pipeAB[0]);           // "A" can only write into this pipe
    close(pipeCA[1]);           // "A" can only read from this pipe
    write(pipeAB[1], &out, 1);
    read(pipeCA[0], &in, 1);
    printf("Wrote: %c, Read: %c\n", out, in);
    
    close(pipeAB[1]);           // causes B to read 0
    close(pipeCA[0]);           // causes A to not longer want to read
}
