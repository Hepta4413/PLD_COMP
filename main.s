	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $64, %rsp
	movq $97,	-24(%rbp)
	movq -24(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movq $102,	-32(%rbp)
	movq -32(%rbp),	%rax
	movq %rax,	-16(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-40(%rbp)
	movl -16(%rbp),	%edi
	call putchar
	movq %rax,	-56(%rbp)
	leave
	ret

