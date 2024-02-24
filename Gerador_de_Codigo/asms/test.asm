.text
.globl main
main:
	addi $s0, $zero, 10
	addi $s1, $zero, 40
	addi $t0, $zero, 40
	addi $t1, $zero, 2
	mul $t2, $t0, $t1
	addi $t0, $zero, 10
	addi $t1, $zero, 80
	add $t3, $t0, $t1
	# assignment na ast
	addi $s2, $zero, 90
	.data
		string: .asciiz "valor "
	.text
	la $a0, string
	li $v0, 4
	syscall
	addi $a0, $zero, 90
	li $v0, 1
	syscall
	.data
		string: .asciiz "\n"
	.text
	la $a0, string
	li $v0, 4
	syscall
	li $v0, 10
	syscall
