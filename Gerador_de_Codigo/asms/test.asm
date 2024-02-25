.text
.globl main
main:
	li $t0, 10
	move $s0, $t0
	li $t0, 40
	move $s1, $t0
	li $t0, 2
	mul $t1, $s1, $t0
	add $t0, $s0, $t1
	# assignment na ast
	move $s2, $t0
	.data
		string83: .asciiz "valor "
	.text
	la $a0, string83
	li $v0, 4
	syscall
	move $a0, $s2
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
