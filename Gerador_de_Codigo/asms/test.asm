# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: asms/test.asm
.text
.globl main


.data
.text

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
	beq $t1, $t0, else_292945680
	add $t0, $s1, $s0
	add $v0, $zero, $t0

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
	j exit_if_292945680
	else_292945680:
	exit_if_292945680:
	slt $t0, $s1, $s0
	addi $t1, $zero, 0
	beq $t1, $t0, else_292943120
	sub $t0, $s0, $s1
	add $v0, $zero, $t0

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
	j exit_if_292943120
	else_292943120:
	exit_if_292943120:

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
	add $a1, $zero, $s0 # function param a
	add $a0, $zero, $s1 # function param b
	jal segredo
	add $t0, $zero, $v0
	add $s2, $zero, $t0
	.data
		string_292822288: .asciiz "hello world (a "
	.text
	la $a0, string_292822288
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	.data
		string_292822144: .asciiz ") this is fun (b "
	.text
	la $a0, string_292822144
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	addi $t0, $zero, 6
	.data
		string_292822032: .asciiz ") "
	.text
	la $a0, string_292822032
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 1
	syscall
	addi $t0, $zero, 7
	.data
		string_292821920: .asciiz " "
	.text
	la $a0, string_292821920
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 1
	syscall
	.data
		string_292821808: .asciiz " "
	.text
	la $a0, string_292821808
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s2
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
