	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $80, %rsp
	movq $99,	-16(%rbp)
	movq $1,	-24(%rbp)
	movq -16(%rbp),	%rax
	subq -24(%rbp),	%rax
	movq %rax,	-32(%rbp)
	movq -32(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movq $1,	-56(%rbp)
	movq -8(%rbp),	%rax
	subq -56(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-40(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-72(%rbp)
	leave
	ret

