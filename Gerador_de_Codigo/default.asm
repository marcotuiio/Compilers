# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: default.asm
.text
.globl main

	addi $t0, $zero, 10
	la $t0, c1
	lw $t1, 0($t0)
	sub $t0, $zero, $t1
	la $t0, c1
	lw $t1, 0($t0)
	addi $t0, $zero, 2
	sllv $t2, $t1, $t0
	la $t0, c2
	lw $t1, 0($t0)
	la $t0, c3
	lw $t2, 0($t0)
	la $t0, c3
	lw $t3, 0($t0)
	mul $t0, $t2, $t3
	srlv $t2, $t1, $t0
	addi $t0, $zero, 0
	addi $t0, $zero, 11
	la $t0, c2
	lw $t1, 0($t0)
	la $t0, c3
	lw $t2, 0($t0)
	add $t0, $t1, $t2
	addi $t0, $zero, 1
	addi $t0, $zero, 0
	la $t0, TRUE
	lw $t1, 0($t0)
	la $t0, FALSE
	lw $t2, 0($t0)
	addi $t0, $zero, 1
	beq $t0, $t1, t_logical_or_17_28
	beq $t0, $t2, t_logical_or_17_28
	addi $t0, $zero, 0
	t_logical_or_17_28:
	addi $t1, $zero, 0
	beq $t1, $t0, false_ternary_17
	true_ternary_17:
	la $t0, TRUE
	lw $t1, 0($t0)
	j end_ternary_17
	false_ternary_17:
	la $t0, FALSE
	lw $t2, 0($t0)
	end_ternary_17:
	la $t0, SERA_VERDADE
	lw $t1, 0($t0)

.data
	c1: .word 10 # define
	c2: .word -10 # define
	c3: .word 40 # define
	c4: .word -10 # define
	NULL: .word 0 # define
	CALL_ELEVEN: .word 11 # define
	TRUE: .word 1 # define
	FALSE: .word 0 # define
	SERA_VERDADE: .word 1 # define
	v: .space 120 # global array
	vetor: .space 4 # global array
.text

f:
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

	#loading 0 params
	la $t0, v
	lw $t1, 0($t0)
	la $t0, c4
	lw $t2, 0($t0)
	la $t0, v
	sll $t3, $t2, 2
	add $t3, $t3, $t0
	la $t0, c1
	lw $t2, 0($t0)
	la $t0, v
	lw $t4, 0($t0)
	lw $t0, 0($t4)
	sgt $t4, $t2, $t0
	la $t0, c2
	lw $t2, 0($t0)
	la $t0, NULL
	lw $t5, 0($t0)
	addi $t0, $zero, 0
	beq $t0, $t5, false_ternary_11
	true_ternary_11:
	la $t0, v
	lw $t5, 0($t0)
	j end_ternary_11
	false_ternary_11:
	la $t0, c3
	lw $t6, 0($t0)
	end_ternary_11:
	lw $t0, 0($t5)
	addi $t0, $zero, 0
	add $v0, $zero, $s-1

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

g:
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

	#loading 0 params
	addi $t0, $zero, 1
	add $t1, $s-1, $t0
	add $s0, $zero, $t1
	addi $t0, $zero, 666
	srlv $t1, $s-1, $t0
	.data
		string_1827953296: .asciiz ""
	.text
	la $a0, string_1827953296
	addi $v0, $zero, 4
	syscall
	.data
		string_383: .asciiz ""
	.text
	la $a0, string_383
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 0
	beq $t0, $s0, false_ternary_24
	true_ternary_24:
	addi $t0, $zero, 666
	addi $t2, $zero, 11
	slt $t3, $s-1, $s-1
	j end_ternary_24
	false_ternary_24:
	end_ternary_24:
	add $s0, $zero, $s-1
	la $t4, vetor
	lw $t5, 0($t4)
	addi $t4, $zero, 1
	addi $t6, $zero, 1
	sllv $t7, $t4, $t6
	la $t4, vetor
	sll $t6, $t7, 2
	add $t6, $t6, $t4
	add $v0, $zero, $s-1

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
	jal g
	add $t0, $zero, $v0
	add $s0, $zero, $t0
	addi $t0, $zero, 65
	add $s1, $zero, $s-1
	add $s2, $zero, $s-1
	jal f
	add $t1, $zero, $v0
	add $s3, $zero, $t1
	add $s4, $zero, $s-1
	addi $t1, $zero, 0
	add $s5, $zero, $s-1
	la $t2, NULL
	lw $t3, 0($t2)
	add $s6, $zero, $s-1
	addi $t2, $zero, 666
	add $s6, $zero, $s-1
	j for_teste_32
	for_corpo_32:
	j while_teste_34
	while_corpo_34:
	addi $t4, $zero, 0
	sle $t5, $s6, $s-1
	addi $t6, $zero, 0
	beq $t6, $t5, else_1827947072
	add $s6, $zero, $s-1
	addi $t5, $zero, 666
	div $s-1, $t5
	mflo $t5
	la $t6, CALL_ELEVEN
	lw $t7, 0($t6)
	j exit_if_1827940192
	else_1827947072:
	while_corpo_43:
	add $t6, $zero, $s6
	addi $s6, $s6, 1
	while_teste_43:
	la $t8, v
	lw $t9, 0($t8)
	addi $t8, $zero, 1
	beq $t8, $t9, while_corpo_43
	exit_if_1827940192:
	while_teste_34:
	addi $t8, $zero, 1
	beq $t8, $s6, while_corpo_34
	add $t8, $zero, $s6
	addi $s6, $s6, 1
	for_teste_32:
	addi $t9, $zero, 1
	beq $t9, $s6, for_corpo_32
	add $t9, $s-1, $s-1
	add $v0, $zero, $t9

	addi $v0, $zero, 10
	syscall
