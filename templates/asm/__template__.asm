push ebp           ; Save stack-frame base pointer
mov ebp, esp       ; Set location of the stack
sub esp, 0x10      ; Make space that you need

                   ; Write your shellcode here

mov esp, ebp       ; Restore stack pointer
pop ebp            ; Restore calling function frame
ret
