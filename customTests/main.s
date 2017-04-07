	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	leave
	ret

