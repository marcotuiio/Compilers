.text
.globl main
main:
	.data
		string4: .asciiz "Digite um valor para a: "
	.text
	la $a0, string4
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s0, $v0
	li $t0, 2
	mul $t1, $s0, $t0
	move $s1, $t1
	.data
		string8: .asciiz "Valor lido de a = "
	.text
	la $a0, string8
	li $v0, 4
	syscall
	move $a0, $s0
	li $v0, 1
	syscall
	.data
		string83: .asciiz "\n"
	.text
	la $a0, string83
	li $v0, 4
	syscall
	.data
		string9: .asciiz "Valor de b = "
	.text
	la $a0, string9
	li $v0, 4
	syscall
	move $a0, $s1
	li $v0, 1
	syscall
	.data
		string86: .asciiz "\n"
	.text
	la $a0, string86
	li $v0, 4
	syscall
	li $t0, 0
	li $v0, 10
	syscall
