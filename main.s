	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $64, %rsp
	movq $0,	-16(%rbp)
	movq -16(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movq $0,	-24(%rbp)
labeldebutfor0x21d9a60:
	movq $1,	-32(%rbp)
	movq -32(%rbp),	%rax
	cmp -24(%rbp),	%rax
	je labelfinfor0x21d9a60
	movq $1,	-56(%rbp)
	movq -56(%rbp),	%rax
	addq -8(%rbp),	%rax
	movq %rax,	-64(%rbp)
	movq -64(%rbp),	%rax
	movq %rax,	-8(%rbp)
	jmp labeldebutfor0x21d9a60
labelfinfor0x21d9a60:
	leave
	ret

