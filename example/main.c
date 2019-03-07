#include "syscall.h"

int main() {
    // And now you can code in C
    char* filename = "/bin/bash";
    char* argv[] = {0};
    char* envp[] = {0};

    int errno = execve(filename, argv, envp);

    #include "syscall.c"
    return errno;
}
