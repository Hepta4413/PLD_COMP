	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $48, %rsp
	movq $2,	-16(%rbp)
	movq -16(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movq $0,	-24(%rbp)
	movq $4,	-40(%rbp)
	movq -40(%rbp),	%rax
	cmp -8(%rbp),	%rax
	jle labelsinon0x1c3d890
	movq $1,	-48(%rbp)
	jmp labelalors0x1c3d890
labelsinon0x1c3d890:
	movq $0,	-48(%rbp)
labelalors0x1c3d890:
	movq -48(%rbp),	%rax
	cmp -24(%rbp),	%rax
	je labelsinon0x1c3dab0
	jmp labelalors0x1c3dab0
labelsinon0x1c3dab0:
labelalors0x1c3dab0:
	leave
	ret

