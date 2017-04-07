	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $96, %rsp
	movq $99,	-16(%rbp)
	movq -16(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movq $1,	-40(%rbp)
	movq -8(%rbp),	%rax
	movq %rax,	-48(%rbp)
	movq -40(%rbp),	%rax
	addq -8(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movl -48(%rbp),	%edi
	call putchar
	movq %rax,	-24(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-56(%rbp)
	movq $1,	-88(%rbp)
	movq -88(%rbp),	%rax
	addq -8(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-72(%rbp)
	leave
	ret

