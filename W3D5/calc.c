#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    int pipeAB[2];
    int pipeBA[2];
    pipe(pipeAB);
    pipe(pipeBA);

    char buf[50];
    int num1, num2, ans;
    int child = fork();

    if (child == 0) {
        close(pipeAB[1]);           // B can only read from this pipe
        close(pipeBA[0]);           // B can only write to this pipe
        
        // make incoming pipe stdin
        dup2(pipeAB[0], 0);         // B's stdin now comes from incoming pipe
        close(pipeAB[0]);           // close incoming pipe (alternate opening now)

        // make outgoing pipe stdout
        dup2(pipeBA[1], 1);         // B's stdout now goes to outgoing pipe
        close(pipeBA[1]);           // close outgoing pipe (alternate opening now)

        printf("In Child");
        read(0, &buf, 6);

        char* tok = strtok(buf, " ");
        printf("tok is %c\n", *tok);
        num1 = atoi(&tok[0]);
        printf("num1 is %d\n", num1);
        tok = strtok(NULL, " ");
        printf("tok is %c\n", *tok);
        tok = strtok(NULL, " ");
        printf("tok is %c\n", *tok);
        num2 = atoi(&tok[3]);
        printf("num2 is %d\n", num2);
        ans = num1 + num2;
        printf("ans is %d\n", ans);

        write(1, &buf, ans);
        
        close(1); // close stdout, sends EOF signal along pipeBC
        close(0);
        _exit(0);
    }

    
    // A is parent process
    close(pipeAB[0]); // A can only write into this pipe
    close(pipeBA[1]); // A can only read from this pipe

    // if A writes to 2 (stderr) it actually writes to stdout
    dup2(1, 2); // duplicate stdout so both 1 and 2 are now stdout

    // make incoming pipe stdin
    dup2(pipeBA[0], 0); // A's stdin now comes from incoming pipe
    close(pipeBA[0]); // close incoming pipe (alternate opening now)

    // make outgoing pipe stdout
    dup2(pipeAB[1], 1); // A's stdout now goes to outgoing pipe
    close(pipeAB[1]); // close outgoing pipe (alternate opening now)

    char* out = "4 + 8";
    int in = 0;
    write(1, &out, 6);
    read(0, &in, 1);
    fprintf(stderr, "Wrote: %s Calculated: %d\n", out, in); // write to stdout!!!

    // close the pipe will cause children to quit
    close(pipeAB[1]); // this causes B to read 0
    close(pipeBA[0]); // A no longer wants to read
}

// NEEDS TO HAVE THE PARENT READ A WHOLE STRING INPUT AND CHILD TOKENIZES.
