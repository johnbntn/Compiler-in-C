	global	main
	extern	printf
	section	.text
LC0:	db	"%d",10,0
printint:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 16
	mov	[rbp-4], edi
	mov	eax, [rbp-4]
	mov	esi, eax
	lea	rdi, [rel LC0]
	mov	eax, 0
	call	printf
	nop
	leave
	ret

main:
	push	rbp
	mov	rbp, rsp
	mov	r8, 12
	mov	r9, 3
	imul	r9, r8
	mov	rdi, r9
	call	printint
	mov	r8, 18
	mov	r9, 2
	mov	r10, 4
	imul	r10, r9
	sub	r8, r10
	mov	rdi, r8
	call	printint
	mov	r8, 1
	mov	r9, 2
	add	r9, r8
	mov	r8, 9
	add	r8, r9
	mov	r9, 5
	mov	r10, 2
	mov	rax, r9
	cqo
	idiv	r10
	mov	r9, rax
	sub	r8, r9
	mov	r9, 3
	mov	r10, 5
	imul	r10, r9
	add	r10, r8
	mov	rdi, r10
	call	printint
	mov	eax, 0
	pop	rbp
	ret
