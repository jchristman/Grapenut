push 	ebp		; Save old bp
mov 	ebp, esp	; Set stack location
push	edi		; Save old edi

mov	edi, [ebp+8]	; Move param info edi
xor	ecx, ecx	; Zeroize counter
not	ecx		; Maximize counter
xor	al, al		; Zero byte for comparison
repne	scasb		; Scan string repeating
sub	edi, [ebp+8]	; Calculate distance
mov	eax, edi	; Set retval
dec	eax		; Subtract one (don't count \0)

pop	edi		; Restore edi
mov	esp, ebp	; Restore stack frame
pop	ebp
ret
