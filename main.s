	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $48, %rsp
	movq $0,	-8(%rbp)
labeldebutwhile0x833980:
	movq $1,	-16(%rbp)
	movq -16(%rbp),	%rax
	cmp -8(%rbp),	%rax
	je labelfinwhile0x833980
	movq $1,	-40(%rbp)
	movq -40(%rbp),	%rax
	addq -24(%rbp),	%rax
	movq %rax,	-48(%rbp)
	movq -48(%rbp),	%rax
	movq %rax,	-24(%rbp)
	jmp labeldebutwhile0x833980
labelfinwhile0x833980:
	leave
	ret

