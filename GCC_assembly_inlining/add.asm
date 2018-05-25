section .data
	num1: equ 100
	num2: equ 50
	msd: db "sum is correct\n"

section .txt
	global _start

_start:
	mov rax,num1
	mov rbx,num2

	add rax,rbx
	cmp rax,150
	jne .exit
	jmp .rightsum

.rightsum:
	;;write syscall to print the sum
	mov rax,1
	mov rdi,1
	mov rsi,msd
	mov rdx,15
	syscall
	jmp .exit

.exit:
	mov rax,60
	mov rdi,0
	syscall

