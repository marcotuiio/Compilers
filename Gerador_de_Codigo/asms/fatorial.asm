# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: asms/fatorial.asm
.text
.globl main


.data
.text

fatorial:
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

	#loading 1 params
	add $s0, $zero, $a0
	addi $t0, $zero, 0
	sle $t1, $s0, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, else_1975806448
	addi $t0, $zero, 0
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
	j exit_if_1975806448
	else_1975806448:
	exit_if_1975806448:
	addi $t0, $zero, 1
	seq $t1, $s0, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, else_1975811072
	addi $t0, $zero, 1
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
	j exit_if_1975808528
	else_1975811072:
	addi $t0, $zero, 1
	sub $t1, $s0, $t0
	add $a0, $zero, $t1 # function param n
	jal fatorial
	add $t0, $zero, $v0
	mul $t1, $s0, $t0
	add $v0, $zero, $t1

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
	exit_if_1975808528:

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
	.data
		string_23: .asciiz "Entre com um valor inteiro: "
	.text
	la $a0, string_23
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	.data
		string_1975920480: .asciiz "O fatorial de "
	.text
	la $a0, string_1975920480
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	add $a0, $zero, $s0 # function param n
	jal fatorial
	add $t0, $zero, $v0
	.data
		string_1975920688: .asciiz " eh: "
	.text
	la $a0, string_1975920688
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