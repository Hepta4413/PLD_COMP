	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movq $1,	-16(%rbp)
	movq $1,	-24(%rbp)
	movq -24(%rbp),	%rax
	imulq -16(%rbp)
	movq %rax,	-32(%rbp)
	movq -32(%rbp),	%rax
	movq %rax,	-8(%rbp)
	leave
	ret

