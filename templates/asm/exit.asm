push ebp            ; Save stack-frame base pointer
mov ebp, esp        ; Set location of the stack

mov eax, 0x1        ; sys_exit
mov ebx, [ebp+8]    ; Load ebx with value from call
int 0x80            ; syscall

mov esp, ebp        ; Restore stack pointer
pop ebp             ; Restore calling function frame
ret
