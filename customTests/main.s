	.globl	main

fonction:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	leave
	ret

	leave
	ret

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	leave
	ret

putchar:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	leave
	ret

