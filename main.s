	.globl	main

a:
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movq $97,	-16(%rbp)
	movl -16(%rbp),	%edi
	call putchar
	movq %rax,	-8(%rbp)
	movq $0,	-24(%rbp)
	movq -24(%rbp),	%rax
	leave
	ret
	leave
	ret

main:
	pushq %rbp
	movq %rsp, %rbp
	subq $208, %rsp
	movq $1,	-16(%rbp)
	movq $0,	-32(%rbp)
	movq -16(%rbp),	%rax
	cmp -32(%rbp),	%rax
	jne labelsinon10x8347c0
	movq $0,	-24(%rbp)
	jmp labelalors10x8347c0
labelsinon10x8347c0:
	movq $1,	-40(%rbp)
	movq -40(%rbp),	%rax
	cmp -32(%rbp),	%rax
	jne labelsinon20x8347c0
	movq $0,	-24(%rbp)
	jmp labelalors20x8347c0
labelsinon20x8347c0:
	movq $1,	-24(%rbp)
labelalors20x8347c0:
labelalors10x8347c0:
	movq -24(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movq $97,	-48(%rbp)
	movq -48(%rbp),	%rax
	addq -8(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-56(%rbp)
	movq $0,	-72(%rbp)
	movq $0,	-88(%rbp)
	movq -72(%rbp),	%rax
	cmp -88(%rbp),	%rax
	jne labelsinon10x834c20
	movq $0,	-80(%rbp)
	jmp labelalors10x834c20
labelsinon10x834c20:
	call a
	movq %rax,	-96(%rbp)
	movq -96(%rbp),	%rax
	cmp -88(%rbp),	%rax
	jne labelsinon20x834c20
	movq $0,	-80(%rbp)
	jmp labelalors20x834c20
labelsinon20x834c20:
	movq $1,	-80(%rbp)
labelalors20x834c20:
labelalors10x834c20:
	movq -80(%rbp),	%rax
	addq -8(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-104(%rbp)
	movq $1,	-120(%rbp)
	movq $0,	-136(%rbp)
	movq -120(%rbp),	%rax
	cmp -136(%rbp),	%rax
	jne labelsinon10x834f10
	movq $0,	-128(%rbp)
	jmp labelalors10x834f10
labelsinon10x834f10:
	movq $0,	-144(%rbp)
	movq -144(%rbp),	%rax
	cmp -136(%rbp),	%rax
	jne labelsinon20x834f10
	movq $0,	-128(%rbp)
	jmp labelalors20x834f10
labelsinon20x834f10:
	movq $1,	-128(%rbp)
labelalors20x834f10:
labelalors10x834f10:
	movq -128(%rbp),	%rax
	addq -8(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-152(%rbp)
	movq $0,	-88(%rbp)
	movq $0,	-184(%rbp)
	movq -88(%rbp),	%rax
	cmp -184(%rbp),	%rax
	jne labelsinon10x8351e0
	movq $0,	-176(%rbp)
	jmp labelalors10x8351e0
labelsinon10x8351e0:
	movq $1,	-192(%rbp)
	movq -192(%rbp),	%rax
	cmp -184(%rbp),	%rax
	jne labelsinon20x8351e0
	movq $0,	-176(%rbp)
	jmp labelalors20x8351e0
labelsinon20x8351e0:
	movq $1,	-176(%rbp)
labelalors20x8351e0:
labelalors10x8351e0:
	movq -176(%rbp),	%rax
	addq -8(%rbp),	%rax
	movq %rax,	-8(%rbp)
	movl -8(%rbp),	%edi
	call putchar
	movq %rax,	-200(%rbp)
	leave
	ret

