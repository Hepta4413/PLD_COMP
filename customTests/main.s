	.globl	main

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $64, %rsp
	movq $0,	-16(%rbp)
	movq -16(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movq $97,	-40(%rbp)
	movq $98,	-48(%rbp)
	movq -40(%rbp),%rdi
	movq -48(%rbp),%rsi
	call toto
	movq %rax,	-32(%rbp)
	movq -32(%rbp),	%rax
	movq %rax,	-24(%rbp)
	movl -24(%rbp),	%edi
	call putchar
	movq %rax,	-56(%rbp)
	leave
	ret

toto:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movq  %rdi,	0(%rbp)
	movq  %rsi,	0(%rbp)
	movq $97,	-16(%rbp)
	movl -16(%rbp),	%edi
	call putchar
	movq %rax,	-8(%rbp)
	movq $121,	-24(%rbp)
	movq -24(%rbp),	%rax
	leave
	ret
	leave
	ret

