#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR* dir = opendir(".");
    struct stat stb;
    struct dirent* entry = readdir(dir);
    while (entry != NULL) {
        printf("%s\n", entry -> d_name);
        stat(entry -> d_name, &stb);
        if ((stb.st_mode & S_IFMT) == S_IRDIR) {

                }
    }
}
