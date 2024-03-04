# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: asms/test.asm
.text
.globl main

	addi $t0, $zero, 3
	.data
		v: .space 12
	.text

.data
.text

soma:
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
	.data
		string_604004432: .asciiz "params "
	.text
	la $a0, string_604004432
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	.data
		string_604004544: .asciiz " "
	.text
	la $a0, string_604004544
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	.data
		string_383: .asciiz "\n"
	.text
	la $a0, string_383
	addi $v0, $zero, 4
	syscall
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
	addi $t0, $zero, 0
	la $s7, v
	sll $t1, $t0, 2
	add $t1, $t1, $s7
	addi $t0, $zero, 1
	sw $t0, 0($t1)
	addi $t0, $zero, 1
	la $s7, v
	sll $t1, $t0, 2
	add $t1, $t1, $s7
	addi $t0, $zero, 2
	sw $t0, 0($t1)
	addi $t0, $zero, 2
	la $s7, v
	sll $t1, $t0, 2
	add $t1, $t1, $s7
	addi $t0, $zero, 3
	sw $t0, 0($t1)
	addi $t0, $zero, 0
	add $s0, $zero, $t0
	j for_teste_288
	for_corpo_288:
	.data
		string_604005696: .asciiz ""
	.text
	la $a0, string_604005696
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	la $s7, v
	sll $t0, $s0, 2
	add $t0, $t0, $s7
	lw $t1, 0($t0)
	add $a1, $zero, $t1 # function param a
	addi $t0, $zero, 1
	add $t1, $s0, $t0
	la $s7, v
	sll $t0, $t1, 2
	add $t0, $t0, $s7
	lw $t1, 0($t0)
	add $a0, $zero, $t1 # function param b
	jal soma
	add $t0, $zero, $v0
	.data
		string_604006240: .asciiz " soma "
	.text
	la $a0, string_604006240
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 1
	syscall
	.data
		string_886: .asciiz "\n"
	.text
	la $a0, string_886
	addi $v0, $zero, 4
	syscall
	add $t0, $zero, $s0
	addi $s0, $s0, 1
	for_teste_288:
	addi $t1, $zero, 2
	slt $t2, $s0, $t1
	addi $t1, $zero, 1
	beq $t1, $t2, for_corpo_288
	addi $t1, $zero, 666
	add $v0, $zero, $t1

	addi $v0, $zero, 10
	syscall
