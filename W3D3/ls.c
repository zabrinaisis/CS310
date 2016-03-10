#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

int ls(char* dir) {
    DIR* dp = opendir(dir);
    struct dirent* entry = readdir(dp);
    while (entry != NULL) {
        printf("%s\n", entry->d_name);
        entry = readdir(dp);
    }
    closedir(dp);
}

int main() {
    ls("..");
}
