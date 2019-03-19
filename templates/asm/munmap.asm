push	ebp
mov	ebp, esp

mov	eax, 0x5b	; sys_munmap
mov	ebx, [ebp+8]	; void *addr
mov	ecx, [ebp+0xc]	; size_t length
int	0x80		; syscall

mov	esp, ebp
pop	ebp
ret
