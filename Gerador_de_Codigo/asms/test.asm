.text
.globl main

segredo:
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

	#loading 2 params
	add $s0, $zero, $a0
	add $s1, $zero, $a1
	sgt $t0, $s1, $s0
	addi $t1, $zero, 0
	beq $t1, $t0, else_854647472
	add $t0, $s1, $s0
	add $v0, $zero, $t0
	j exit_if_854647472
	else_854647472:
	exit_if_854647472:
	slt $t0, $s1, $s0
	addi $t1, $zero, 0
	beq $t1, $t0, else_854650032
	sub $t0, $s0, $s1
	add $v0, $zero, $t0
	j exit_if_854650032
	else_854650032:
	exit_if_854650032:

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

	jr $ra

main:
	addi $t0, $zero, 1000
	add $s0, $zero, $t0
	addi $t0, $zero, 999
	add $s1, $zero, $t0
	.data
		string_854761648: .asciiz "hello world (a "
	.text
	la $a0, string_854761648
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	.data
		string_854761792: .asciiz ") this is fun (b "
	.text
	la $a0, string_854761792
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	addi $t0, $zero, 6
	.data
		string_854761904: .asciiz ") "
	.text
	la $a0, string_854761904
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 1
	syscall
	addi $t0, $zero, 7
	.data
		string_854762016: .asciiz " "
	.text
	la $a0, string_854762016
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 1
	syscall
	add $a1, $zero, $s0 # function param a
	add $a0, $zero, $s1 # function param b
	jal segredo
	add $t0, $zero, $v0
	.data
		string_854762272: .asciiz " "
	.text
	la $a0, string_854762272
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
