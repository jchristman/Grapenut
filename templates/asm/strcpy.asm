push 	ebp		; Save old bp
mov 	ebp, esp	; Set stack location

push	esi		; Save old esi
push	edi		; Save old edi

mov	edi, [ebp+0xc]	; Move param 1 to esi

xor	ecx, ecx	; Zeroize counter
not	ecx		; Maximize counter
xor	al, al		; Zero byte for comparison
repne	scasb		; Scan string repeating
sub	edi, [ebp+0xc]	; Calculate distance

mov	ecx, edi	; Set counter for move (including the NULL)
mov	edi, [ebp+8]	; Dest
mov	esi, [ebp+0xc]	; Source

cld			; Clear DF (forward)
rep	movsb		; Move byte from esi to edi repeating until ecx is 0

mov	eax, [ebp+8]	; Return nest string

pop	edi		; Restore edi
pop	esi		; Restore esi

mov	esp, ebp	; Restore stack frame
pop	ebp
ret
