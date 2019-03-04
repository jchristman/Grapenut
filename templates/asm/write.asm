push ebp           ; Save stack-frame base pointer
mov ebp, esp       ; Set location of the stack

mov eax, 0x4       ; sys_write
mov ebx, [ebp+8]   ; fd
mov ecx, [ebp+12]  ; char* buf
mov edx, [ebp+16]  ; count to write
int 0x80           ; syscall

mov esp, ebp       ; Restore stack pointer
pop ebp            ; Restore calling function frame
ret

