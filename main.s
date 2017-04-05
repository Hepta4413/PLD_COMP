	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
movq $1,	%0
movq 0(%rbp),	%rax
movq -8(%rbp),	%rax
movq %r10,	(%rax)
	leave
	ret

