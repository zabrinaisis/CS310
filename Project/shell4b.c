#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/file.h>
#include <sys/dir.h>
#include <sys/wait.h>

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

int tofile(char* array[], char* filename, int ground[]) {   // ">" was used
    int status;
    int id = fork();
    if (id == 0) {
        int f = open(filename, (O_CREAT | O_WRONLY), 0666);
        dup2(f, 1);
        execv(array[0], array);
        _exit(0);
    } else if (id < 0) {
        fprintf(stderr, "fork failed in tofile()\n");
    }   
    if (ground[0]) {
        while (wait(&status) != id);
    }
    return id;
}

int appfile(char* array[], char* filename, int ground[]) {   // ">>" was used
    int status;
    int id = fork();
    if (id == 0) {
        int f = open(filename, (O_CREAT | O_APPEND | O_WRONLY), 0666);
        dup2(f, 1);
        execv(array[0], array);
        _exit(0);
    } else if (id < 0) {
        fprintf(stderr, "fork failed in appfile()\n");
    }
    if (ground[0]) {
        while (wait(&status) != id);
    }
    return id;
}

int fromfile(char* array[], char* filename, int ground[]) { // "<" was used
    int status;
    int id = fork();
    if (id == 0) {
        int f = open(filename, (O_RDONLY), 0666);
        dup2(f, 0);
        execv(array[0], array);
        _exit(0);
    } else if (id < 0) {
        fprintf(stderr, "fork failed in fromfile()\n");
    }   
    if (ground[0]) {
        while (wait(&status) != id);
    }
    return id;
}

int runcmd(char* argv[], int ground[]) {
    int status;
    int id = fork();
    if (id == 0) {
        execv(argv[0], argv);
        _exit(1);
    } else if (id < 0) {
        fprintf(stderr, "fork failed in runcmd()\n");
    }
    if (ground[0]) {
        while (wait(&status) != id);
    }
    return id;
}

int topipe(char* argv[], int ground[]) {
    int status;
    int pipeAB[2];
    pipe(pipeAB);
    int pid1, pid2;
    char* first[] = {argv[0],NULL};
    char* second[] = {argv [2],NULL};
    if ((pid1 = fork()) == 0) {
        close(pipeAB[0]);
        dup2(pipeAB[1], 1);
        execv(first[0], first);
        _exit(3);
    } else if (pid1 < 0) {
        fprintf(stderr, "first fork failed in topipe()\n");
    }
    if ((pid2 = fork()) == 0) {
        close(pipeAB[1]);
        dup2(pipeAB[0], 0);
        execv(second[0], second);
        _exit(4);
    } else if (pid2 < 2) {
        fprintf(stderr, "second fork failed in topipe()\n");
    }
    if (ground[0]) {
        wait(NULL);
    }
    return pid2;
}

int main() {
    char cmd[MAXBUF + 1];
    char* argv[MAXBUF + 1];
    char* got;
    int length;
    int ground[] = {1};
    char* array[MAXARG];
    int i, c;

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
        for (i = 0; i < length; i++) {
            if (cmd[i] == '&') {
                ground[0] = 0;
                strtok(cmd, "&");
            }
        }
        int total = tokenize(cmd, argv);
        if (total > MAXARG) {
            fprintf(stderr, "too many commands\n");
            exit(2);
        }
        for (i = 0; i < total; i++) {
            array[i] = argv[i];
            if ((c = strcmp(argv[i], ">>")) == 0) {
                array[i] = NULL;
                appfile(array, argv[total - 1], ground);
                break;
            } else if (*argv[i] == '>') {
                array[i] = NULL;
                tofile(array, argv[total - 1], ground);
                break;
            } else if (*argv[i] == '<') {
                array[i] = NULL;
                fromfile(array, argv[total - 1], ground);
                break;
            } else if (*argv[i] == '|') {
                topipe(argv, ground);
                break;
            } else if (i == (total - 1)) {
                runcmd(argv, ground);
            }
        }
    }
}
