	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	leave
	ret

