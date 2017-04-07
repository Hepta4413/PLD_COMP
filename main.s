	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $40, %rsp
	movq -8,4294967280(%rbp)
	call t
	movq %rax,	-16(%rbp)
	movq -16(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-32(%rbp)
	leave
	ret

t:
	pushq %rbp
	movq %rsp, %rbp
	subq $24, %rsp
	movq $1,	-16(%rbp)
	movq -16(%rbp),	%rax
	addq -8(%rbp),	%rax
	movq %rax,	-24(%rbp)
	leave
	ret

