push ebp           ; Save stack-frame base pointer
mov ebp, esp       ; Set location of the stack

mov eax, 0x6       ; sys_close
mov ebx, [ebp+8]   ; int fd
int 0x80           ; syscall

mov esp, ebp       ; Restore stack pointer
pop ebp            ; Restore calling function frame
ret
