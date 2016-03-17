#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 80
#define MAXARG 20
#define WHITE " \n\t"

void tokenize(char* cmd, char* argv[]) {
    int i = 0;
    char* tok = strtok(cmd, WHITE);
    argv[i++] = tok;
    while (i < MAXARG && tok != NULL) {
        argv[i++] = tok = strtok(NULL, WHITE); 
    } 
}

// don't wait for it to finish (run in the background)
int background(char* argv[]) {
    int id = fork();
    if (id == 0) {
        execv(argv[0], argv);
        _exit(1); // if we get here execv failed
    } else if (id < 0) {
        fprintf(stderr, "fork failed\n");
        perror("background");
    }
    return id;
}

int main() {
    char cmd[MAXLINE+1];
    char* argv[MAXARG+1];
    char* got;

    while (1) {
        printf("mysh ready$ ");
        got = fgets(cmd, MAXLINE, stdin);
        if (got == NULL) { // user pressed ^D
            printf("\n");
            exit(0); 
        }
        tokenize(cmd, argv);
        background(argv);
    }
}

