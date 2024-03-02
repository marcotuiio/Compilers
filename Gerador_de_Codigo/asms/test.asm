.text
.globl main

soma:
	#laoding params = 2
	add $s0, $zero, $a0
	add $s1, $zero, $a1
	sgt $t0, $s1, $s0
	addi $t1, $zero, 0
	beq $t1, $t0, else_linha_26
	add $t0, $s1, $s0
	add $v0, $zero, $t0
	jr $ra
	j exit_if_26
	else_linha_26:
	exit_if_26:
	slt $t0, $s1, $s0
	addi $t1, $zero, 0
	beq $t1, $t0, else_linha_29
	sub $t0, $s0, $s1
	add $v0, $zero, $t0
	jr $ra
	j exit_if_29
	else_linha_29:
	exit_if_29:
	jr $ra

main:
	addi $t0, $zero, 3
	add $s2, $zero, $t0
	addi $t0, $zero, 2
	add $s3, $zero, $t0
	#function param
	add $a1, $zero, $s3 # a
	addi $t0, $zero, 1012
	#function param
	add $a0, $zero, $t0 # b
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
	jal soma
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
		string_1078004016: .asciiz "a e b => "
	.text
	la $a0, string_1078004016
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
