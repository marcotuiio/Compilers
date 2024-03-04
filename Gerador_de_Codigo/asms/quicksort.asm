# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: asms/quicksort.asm
.text
.globl main

	addi $t0, $zero, 100
	la $t0, MAX
	lw $t1, 0($t0)

.data
	a: .space 400 # global array
	max: .word 0
.text

quicksort:
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
	addi $t0, $zero, 1
	add $s2, $zero, $t0
	sle $t0, $s0, $s1
	addi $t1, $zero, 0
	beq $t1, $t0, else_973157728

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
	j exit_if_973157728
	else_973157728:
	exit_if_973157728:
	addi $t0, $zero, 1
	sub $t1, $s1, $t0
	add $s3, $zero, $t1
	add $s4, $zero, $s0
	la $t0, a
	lw $t1, 0($t0)
	la $t0, a
	sll $t2, $s0, 2
	add $t2, $t2, $t0
	lw $t0, 0($t2)
	add $s5, $zero, $t0
	j while_teste_20
	while_corpo_20:
	while_corpo_22:
	addi $t0, $zero, 1
	add $t2, $s3, $t0
	add $s3, $zero, $t2
	while_teste_22:
	la $t0, a
	lw $t2, 0($t0)
	la $t0, a
	sll $t3, $s3, 2
	add $t3, $t3, $t0
	lw $t0, 0($t3)
	slt $t3, $t0, $s5
	addi $t0, $zero, 1
	beq $t0, $t3, while_corpo_22
	while_corpo_23:
	addi $t0, $zero, 1
	sub $t3, $s4, $t0
	add $s4, $zero, $t3
	while_teste_23:
	la $t0, a
	lw $t3, 0($t0)
	la $t0, a
	sll $t4, $s4, 2
	add $t4, $t4, $t0
	lw $t0, 0($t4)
	sgt $t4, $t0, $s5
	addi $t0, $zero, 1
	beq $t0, $t4, while_corpo_23
	sge $t0, $s3, $s4
	addi $t4, $zero, 0
	beq $t4, $t0, else_973141440
	addi $t0, $zero, 0
	add $s2, $zero, $t0
	j exit_if_973144080
	else_973141440:
	la $t0, a
	lw $t4, 0($t0)
	la $t0, a
	sll $t5, $s3, 2
	add $t5, $t5, $t0
	lw $t0, 0($t5)
	add $s6, $zero, $t0
	la $t0, a
	sll $t5, $s3, 2
	add $t5, $t5, $t0
	la $t0, a
	lw $t6, 0($t0)
	la $t0, a
	sll $t7, $s4, 2
	add $t7, $t7, $t0
	lw $t0, 0($t7)
	sw $t0, 0($t5)
	la $t0, a
	sll $t5, $s4, 2
	add $t5, $t5, $t0
	sw $s6, 0($t5)
	exit_if_973144080:
	while_teste_20:
	addi $t0, $zero, 1
	beq $t0, $s2, while_corpo_20
	la $t0, a
	lw $t5, 0($t0)
	la $t0, a
	sll $t7, $s3, 2
	add $t7, $t7, $t0
	lw $t0, 0($t7)
	add $s6, $zero, $t0
	la $t0, a
	sll $t7, $s3, 2
	add $t7, $t7, $t0
	la $t0, a
	lw $t8, 0($t0)
	la $t0, a
	sll $t9, $s0, 2
	add $t9, $t9, $t0
	lw $t0, 0($t9)
	sw $t0, 0($t7)
	la $t0, a
	sll $t7, $s0, 2
	add $t7, $t7, $t0
	sw $s6, 0($t7)
	add $a1, $zero, $s1 # function param m
	add $a0, $zero, $s4 # function param n
	jal quicksort
	add $t0, $zero, $v0
	addi $t7, $zero, 1
	add $t9, $s3, $t7
	add $a1, $zero, $t9 # function param m
	add $a0, $zero, $s0 # function param n
	jal quicksort
	add $t7, $zero, $v0

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
	la $t1, max
	sw $t0, 0($t1)
	j while_teste_45
	while_corpo_45:
	.data
		string_47: .asciiz "Entre com o tamanho do vetor (valor entre 1 e 100): "
	.text
	la $a0, string_47
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	la $t0, max
	sw $v0, 0($t0)
	while_teste_45:
	la $t0, max
	lw $t1, 0($t0)
	addi $t0, $zero, 0
	sle $t2, $t1, $t0
	la $t0, max
	lw $t1, 0($t0)
	addi $t0, $zero, 100
	sgt $t3, $t1, $t0
	addi $t0, $zero, 1
	beq $t0, $t2, t_logical_or_45_18
	beq $t0, $t3, t_logical_or_45_18
	addi $t0, $zero, 0
	t_logical_or_45_18:
	addi $t1, $zero, 1
	beq $t1, $t0, while_corpo_45
	addi $t0, $zero, 0
	add $s1, $zero, $t0
	j for_teste_50
	for_corpo_50:
	addi $t0, $zero, 1
	add $t1, $s1, $t0
	.data
		string_973000256: .asciiz "Entre com o valor da posicao "
	.text
	la $a0, string_973000256
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t1
	addi $v0, $zero, 1
	syscall
	.data
		string_383: .asciiz ": "
	.text
	la $a0, string_383
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s2, $zero, $v0
	la $t0, a
	sll $t1, $s1, 2
	add $t1, $t1, $t0
	sw $s2, 0($t1)
	add $t0, $zero, $s1
	addi $s1, $s1, 1
	for_teste_50:
	la $t1, max
	lw $t2, 0($t1)
	slt $t1, $s1, $t2
	addi $t2, $zero, 1
	beq $t2, $t1, for_corpo_50
	addi $t1, $zero, 0
	add $a1, $zero, $t1 # function param m
	la $t1, max
	lw $t2, 0($t1)
	addi $t1, $zero, 1
	sub $t3, $t2, $t1
	add $a0, $zero, $t3 # function param n
	jal quicksort
	add $t1, $zero, $v0
	addi $t2, $zero, 0
	add $s1, $zero, $t2
	j for_teste_58
	for_corpo_58:
	la $t2, a
	lw $t3, 0($t2)
	la $t2, a
	sll $t4, $s1, 2
	add $t4, $t4, $t2
	lw $t2, 0($t4)
	.data
		string_972999104: .asciiz ""
	.text
	la $a0, string_972999104
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t2
	addi $v0, $zero, 1
	syscall
	.data
		string_886: .asciiz " "
	.text
	la $a0, string_886
	addi $v0, $zero, 4
	syscall
	add $t2, $zero, $s1
	addi $s1, $s1, 1
	for_teste_58:
	la $t4, max
	lw $t5, 0($t4)
	slt $t4, $s1, $t5
	addi $t5, $zero, 1
	beq $t5, $t4, for_corpo_58
	.data
		string_62: .asciiz "\n"
	.text
	la $a0, string_62
	addi $v0, $zero, 4
	syscall
	addi $t4, $zero, 0
	add $v0, $zero, $t4

	addi $v0, $zero, 10
	syscall

# BLOCO DE DEFINES NO FIM DO ARQUIVO
.data
	MAX: .word 100
# END BLOCO DEFINES