
__asm__ volatile ("jmp end");

__asm__ volatile (
"execve:"
"push ebp\n"
"mov ebp, esp\n"
"\n"
"mov eax, 0xb\n"
"mov ebx, [ebp+8]\n"
"mov ecx, [ebp+12]\n"
"mov edx, [ebp+16]\n"
"int 0x80\n"
"\n"
"mov esp, ebp\n"
"pop ebp\n"
"ret\n"
"\n"
);

__asm__ volatile ("end:");
