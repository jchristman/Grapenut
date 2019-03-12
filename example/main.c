#include "syscall.h"

#define C2PORT 9000
#define C2IP 16777343  // Because conversions are hard

int main() {
    // And now you can code in C
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

    write(socket_fd, msg, 13);

    close(socket_fd);
    #include "syscall.c"
    return errno;
}
