
__asm__ volatile ("jmp end");

__asm__ volatile (
"socket:"
"push ebp\n"
"mov ebp, esp\n"
"\n"
"mov eax, 0x66\n"
"mov ebx, 0x1\n"
"lea ecx, [ebp+8]\n"
"int 0x80\n"
"\n"
"mov esp, ebp\n"
"pop ebp\n"
"ret\n"
);

__asm__ volatile (
"close:"
"push ebp\n"
"mov ebp, esp\n"
"\n"
"mov eax, 0x6\n"
"mov ebx, [ebp+8]\n"
"int 0x80\n"
"\n"
"mov esp, ebp\n"
"pop ebp\n"
"ret\n"
);

__asm__ volatile (
"mmap:"
"push ebp\n"
"mov ebp, esp\n"
"\n"
"mov eax, 0x5a\n"
"lea ebx, [ebp+8]\n"
"int 0x80\n"
"\n"
"mov esp, ebp\n"
"pop ebp\n"
"ret\n"
"\n"
);

__asm__ volatile (
"connect:"
"push ebp\n"
"mov ebp, esp\n"
"\n"
"mov eax, 0x66\n"
"mov ebx, 0x3\n"
"lea ecx, [ebp+8]\n"
"int 0x80\n"
"\n"
"mov esp, ebp\n"
"pop ebp\n"
"ret\n"
);

__asm__ volatile (
"exit:"
"push ebp\n"
"mov ebp, esp\n"
"\n"
"mov eax, 0x1\n"
"mov ebx, [ebp+8]\n"
"int 0x80\n"
"\n"
"mov esp, ebp\n"
"pop ebp\n"
"ret\n"
);

__asm__ volatile (
"write:"
"push ebp\n"
"mov ebp, esp\n"
"\n"
"mov eax, 0x4\n"
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
