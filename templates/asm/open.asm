push ebp           ; Save stack-frame base pointer
mov ebp, esp       ; Set location of the stack

mov eax, 0x5       ; sys_open
mov ebx, [ebp+8]   ; char* filename
mov ecx, [ebp+12]  ; int flags
mov edx, [ebp+16]  ; int mode
int 0x80           ; syscall

mov esp, ebp       ; Restore stack pointer
pop ebp            ; Restore calling function frame
ret

