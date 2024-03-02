.text
.globl main

fatorial:
	#laoding params = 1
	add $s0, $zero, $a0
	addi $t0, $zero, 0
	sle $t1, $s0, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, else_linha_8
	addi $t0, $zero, 0
	add $v0, $zero, $t0
	jr $ra
	j exit_if_8
	else_linha_8:
	exit_if_8:
	addi $t0, $zero, 1
	seq $t1, $s0, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, else_linha_16
	addi $t0, $zero, 1
	add $v0, $zero, $t0
	jr $ra
	j exit_if_12
	else_linha_16:
	addi $t0, $zero, 1
	sub $t1, $s0, $t0
	#function param
	add $a0, $zero, $t1 # n
	addi $sp, $sp, -52
	sw $a0, 0($sp)
	sw $a1, 4($sp)
	sw $a2, 8($sp)
	sw $a3, 12($sp)
	sw $s0, 16($sp)
	sw $s1, 20($sp)
	sw $s2, 24($sp)
	sw $s3, 28($sp)
	sw $s4, 32($sp)
	sw $s5, 36($sp)
	sw $s6, 40($sp)
	sw $s7, 44($sp)
	sw $ra, 48($sp)
	jal fatorial
	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $s0, 16($sp)
	lw $s1, 20($sp)
	lw $s2, 24($sp)
	lw $s3, 28($sp)
	lw $s4, 32($sp)
	lw $s5, 36($sp)
	lw $s6, 40($sp)
	lw $s7, 44($sp)
	lw $ra, 48($sp)
	addi $sp, $sp, 52
	add $t0, $zero, $v0
	mul $t1, $s0, $t0
	add $v0, $zero, $t1
	jr $ra
	exit_if_12:
	jr $ra

main:
	.data
		string_23: .asciiz "Entre com um valor inteiro: "
	.text
	la $a0, string_23
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0
	.data
		string_2001713616: .asciiz "O fatorial de "
	.text
	la $a0, string_2001713616
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	#function param
	add $a0, $zero, $s1 # n
	addi $sp, $sp, -52
	sw $a0, 0($sp)
	sw $a1, 4($sp)
	sw $a2, 8($sp)
	sw $a3, 12($sp)
	sw $s0, 16($sp)
	sw $s1, 20($sp)
	sw $s2, 24($sp)
	sw $s3, 28($sp)
	sw $s4, 32($sp)
	sw $s5, 36($sp)
	sw $s6, 40($sp)
	sw $s7, 44($sp)
	sw $ra, 48($sp)
	jal fatorial
	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $s0, 16($sp)
	lw $s1, 20($sp)
	lw $s2, 24($sp)
	lw $s3, 28($sp)
	lw $s4, 32($sp)
	lw $s5, 36($sp)
	lw $s6, 40($sp)
	lw $s7, 44($sp)
	lw $ra, 48($sp)
	addi $sp, $sp, 52
	add $t0, $zero, $v0
	.data
		string_2001713824: .asciiz " eh: "
	.text
	la $a0, string_2001713824
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 1
	syscall
	.data
		string_383: .asciiz "\n"
	.text
	la $a0, string_383
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 0
	add $v0, $zero, $t0

	addi $v0, $zero, 10
	syscall
