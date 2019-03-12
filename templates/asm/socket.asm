push ebp           ; Save stack-frame base pointer
mov ebp, esp       ; Set location of the stack

mov eax, 0x66      ; sys_socketcall
mov ebx, 0x1       ; sys_socket
lea ecx, [ebp+8]  ; address of parameter array
int 0x80

mov esp, ebp       ; Restore stack pointer
pop ebp            ; Restore calling function frame
ret
