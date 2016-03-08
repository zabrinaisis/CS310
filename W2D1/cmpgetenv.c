#include <stdio.h>
#include <string.h>

extern char** environ;

const char* getenv(const char* key) {
    const char* val = NULL;
    int i;
    for (i = 0; environ[i] != '\0'; i++) {
        char *s = environ[i];
        char *eq = strchr(s, '=');
        int distance = eq -s;
        if (strncmp(key, s, distance) == 0) {
            return (eq + 1);
        }
    }
    return NULL;
}

int main() {
    printf("%s\n", getenv("HOME"));
    printf("%s\n", getenv("TERM"));
}

