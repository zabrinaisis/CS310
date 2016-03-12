#include <stdio.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("Hello\n");
        _exit(0);           // The child will keep running without this.
    }
    if (fork() == 0) {
        printf("World\n");
        _exit(0);
    }
}

// The parent process does nothing in this program, so there will be an extra
//   prompt in the place of this parent process.
// The different children will run at different times, not always in order.
