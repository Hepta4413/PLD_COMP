	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movq $0,	-8(%rbp)
	movq $1,	-16(%rbp)
	movq -16(%rbp),	%rax
	cmp -8(%rbp),	%rax
	je labelsinon0xc2b8b0
	movq $5,	-32(%rbp)
	movq -32(%rbp),	%rax
	movq %rax,	-24(%rbp)
	jmp labelalors0xc2b8b0
labelsinon0xc2b8b0:
labelalors0xc2b8b0:
	leave
	ret

