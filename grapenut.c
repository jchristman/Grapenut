extern void gn_exit(int errno);
extern int gn_write(int fd, char* buf, int count);

int main() {
	char* buf = "Hello world";

	gn_write(1, buf, 5);
	gn_exit(213);


    // This needs to be an asm instead of a goto to avoid gcc optimizing
    // out my custom functions
    __asm__ volatile ("jmp end");

    __asm__ volatile (
		"gn_exit: 				\n"
			"push ebp 			\n"	// Save stack-frame base pointer
			"mov ebp, esp 	\n"	// Set location of the stack

			"mov eax, 0x1 		\n"	// sys_exit
			"mov ebx, [ebp+8] 	\n"	// Load ebx with value from call
			"int 0x80 			\n"	// syscall

			"mov esp, ebp 	\n"	// Restore stack pointer
			"pop ebp       	\n"	// Restore calling function frame
			"ret"
	);

	__asm__ volatile (
		"gn_write:					\n"
			"push ebp			\n" // Save stack-frame base pointer
			"mov ebp, esp		\n"	// Set location of the stack

			"mov eax, 0x4		\n" // sys_write
			"mov ebx, [ebp+8]	\n"	// fd
			"mov ecx, [ebp+12]	\n" // char* buf
			"mov edx, [ebp+16]	\n" // count to write
			"int 0x80			\n" // syscall

			"mov esp, ebp		\n"	// Restore stack pointer
			"pop ebp			\n"	// Restore calling function frame
			"ret"
	);

    __asm__ volatile (
		"template:				\n"
			"push ebp			\n" // Save stack-frame base pointer
			"mov ebp, esp		\n"	// Set location of the stack
			"sub esp, 0x10		\n"	// Make space that you need

			// Here be dragons

			"mov esp, ebp		\n"	// Restore stack pointer
			"pop ebp			\n"	// Restore calling function frame
			"ret"
	);

    __asm__ volatile ("end:");
    return 0;
}
