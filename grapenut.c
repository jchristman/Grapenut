extern void gn_exit(int errno);
extern int gn_read(int fd, char* buf, int count);
extern int gn_write(int fd, char* buf, int count);
extern int gn_open(char* filename, int flags, int mode);

// PIPES
#define STDIN 0
#define STDOUT 1
#define STDERR 2

// File flags
#define O_RDONLY    0000
#define O_WRONLY    0001
#define O_RDWR      0002
#define O_CREAT     0100        /* create if nonexistant */

int main() {
    char buf[64] = { 0 };
    char* teststring = "Hello, world";
    char* filename = "/tmp/test";
    int flags = O_RDWR | O_CREAT;
    int mode = 00777;

    int fd = gn_open(filename, flags, mode);
    gn_write(fd, teststring, 64);
    gn_exit(0);


    // This needs to be an asm instead of a goto to avoid gcc optimizing
    // out my custom functions
    __asm__ volatile ("jmp end");

    // 1    sys_exit    0x01    int error_code    -    -    -    -    kernel/exit.c:1046
    __asm__ volatile (
        "gn_exit:             \n"
            "push ebp         \n" // Save stack-frame base pointer
            "mov ebp, esp     \n" // Set location of the stack

            "mov eax, 0x1     \n" // sys_exit
            "mov ebx, [ebp+8] \n" // Load ebx with value from call
            "int 0x80         \n" // syscall

            "mov esp, ebp     \n" // Restore stack pointer
            "pop ebp          \n" // Restore calling function frame
            "ret"
    );

    // 3    sys_read    0x03    unsigned int fd    char __user *buf    size_t count    -    -    fs/read_write.c:391
    __asm__ volatile (
        "gn_read:             \n"
            "push ebp         \n" // Save stack-frame base pointer
            "mov ebp, esp     \n" // Set location of the stack

            "mov eax, 0x3     \n" // sys_read
            "mov ebx, [ebp+8] \n" // fd
            "mov ecx, [ebp+12]\n" // char* buf
            "mov edx, [ebp+16]\n" // count to read
            "int 0x80         \n" // syscall

            "mov esp, ebp     \n" // Restore stack pointer
            "pop ebp          \n" // Restore calling function frame
            "ret"
    );

    // 4    sys_write    0x04    unsigned int fd    const char __user *buf    size_t count    -    -    fs/read_write.c:408
    __asm__ volatile (
        "gn_write:            \n"
            "push ebp         \n" // Save stack-frame base pointer
            "mov ebp, esp     \n" // Set location of the stack

            "mov eax, 0x4     \n" // sys_write
            "mov ebx, [ebp+8] \n" // fd
            "mov ecx, [ebp+12]\n" // char* buf
            "mov edx, [ebp+16]\n" // count to write
            "int 0x80         \n" // syscall

            "mov esp, ebp     \n" // Restore stack pointer
            "pop ebp          \n" // Restore calling function frame
            "ret"
    );

    // 5    sys_open    0x05    const char __user *filename    int flags    int mode    -    -    fs/open.c:900
    __asm__ volatile (
        "gn_open:            \n"
            "push ebp         \n" // Save stack-frame base pointer
            "mov ebp, esp     \n" // Set location of the stack

            "mov eax, 0x5     \n" // sys_open
            "mov ebx, [ebp+8] \n" // char* filename
            "mov ecx, [ebp+12]\n" // int flags
            "mov edx, [ebp+16]\n" // int mode
            "int 0x80         \n" // syscall

            "mov esp, ebp     \n" // Restore stack pointer
            "pop ebp          \n" // Restore calling function frame
            "ret"
    );

    __asm__ volatile (
        "template:            \n"
            "push ebp         \n" // Save stack-frame base pointer
            "mov ebp, esp     \n" // Set location of the stack
            "sub esp, 0x10    \n" // Make space that you need

            // Here be dragons

            "mov esp, ebp     \n" // Restore stack pointer
            "pop ebp          \n" // Restore calling function frame
            "ret"
    );

    __asm__ volatile ("end:");
    return 0;
}
