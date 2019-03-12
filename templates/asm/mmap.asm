push ebp           ; Save stack-frame base pointer
mov ebp, esp       ; Set location of the stack

mov eax, 0x5a      ; sys_read
lea ebx, [ebp+8]   ; mmap_arg_struct *
int 0x80           ; syscall

mov esp, ebp       ; Restore stack pointer
pop ebp            ; Restore calling function frame
ret

