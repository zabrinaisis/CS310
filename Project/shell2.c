#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 80
#define MAXARG 20
#define MAXBUF 1024
#define WHITE " \n\t"

int tokenize(char* cmd, char* argv[]) {
    int i = 0;
    int count = 0;
    char* tok = strtok(cmd, WHITE);
    argv[i++] = tok;
    while (i < MAXBUF && tok != NULL) {
        argv[i++] = tok = strtok(NULL, WHITE);  //last tok will be NULL
        count++;
    } 
    return count;
}

// does not wait for it to finish (runs in the background)
int background(char* argv[], int pipetrig) {
    int id = fork();
    if (id == 0) {
        execv(argv[0], argv);
        _exit(1);                               // if we get here execv failed
    } else if (id < 0) {
        fprintf(stderr, "fork failed\n");
        perror("background");
    }
    return id;
}


int main() {
    char cmd[MAXBUF + 1];
    char* argv[MAXBUF + 1];
    char* got;
    int length;

    while (1) {
        printf("mysh ready$ ");
        got = fgets(cmd, MAXBUF, stdin);
        length = strlen(cmd);
        if (length > MAXLINE + 1) {
            if (cmd[length + 1] != '\n') {
                fprintf(stderr, "too many characters\n");
                exit(1);
            }
        }
        if (got == NULL) {                  // user pressed ^D
            printf("\n");
            exit(0); 
        }
        int total = tokenize(cmd, argv);
        if (total > MAXARG) {
            fprintf(stderr, "too many commands\n");
            exit(2);
        }
    }
}
