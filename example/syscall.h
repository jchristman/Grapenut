#define STDIN 0
#define STDOUT 1
#define STDERR 2

// File flags
#define O_RDONLY    0000
#define O_WRONLY    0001
#define O_RDWR      0002
#define O_CREAT     0100

#define NULL 0
extern int close(unsigned int fd);
extern void exit(int errno);
extern int read(int fd, char* buf, int count);
extern int open(char* filename, int flags, int mode);
extern int execve(char* filename, char* argv[], char* envp[]);
extern int write(int fd, char* buf, int count);
