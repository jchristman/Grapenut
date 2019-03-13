push ebp           ; Save stack-frame base pointer
mov ebp, esp       ; Set location of the stack
push edi
push esi

mov edi, [ebp+8]   ; dest
mov esi, [ebp+12]  ; src
mov ecx, [ebp+16]  ; number of bytes to move
rep movsb

pop esi
pop edi
mov esp, ebp       ; Restore stack pointer
pop ebp            ; Restore calling function frame
ret
