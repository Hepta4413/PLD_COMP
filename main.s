	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $97,	-16(%rbp)
	movl -16(%rbp),	%edi
	call putchar
	leave
	ret

