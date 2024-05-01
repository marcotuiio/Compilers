# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: testes_semantico/teste_50.c
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

	addi $t0, $zero, 1
	la $t1, c4
	lw $t2, 0($t1)
	mul $t1, $t0, $t2
	la $t0, v
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, c1
	lw $t1, 0($t0)
	lw $t0, 0($t-1)
	sgt $t3, $t1, $t0
	la $t0, c2
	lw $t1, 0($t0)
	la $t0, NULL
	lw $t4, 0($t0)
	addi $t0, $zero, 0
	beq $t0, $t4, false_ternary_11
	true_ternary_11:
	j end_ternary_11
	false_ternary_11:
	la $t0, c3
	lw $t4, 0($t0)
	end_ternary_11:
	lw $t0, 0($t-1)
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

	addi $t0, $zero, 1
	add $t1, $s-1, $t0
	add $s0, $zero, $t1
	addi $t0, $zero, 666
	srlv $t1, $s-1, $t0
	.data
		string_384620752: .asciiz ""
	.text
	la $a0, string_384620752
	addi $v0, $zero, 4
	syscall
	move $a0, $t1
	addi $v0, $zero, 4
	syscall
	.data
		string_55271: .asciiz ""
	.text
	la $a0, string_55271
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 0
	beq $t0, $s0, false_ternary_24
	true_ternary_24:
	addi $t0, $zero, 666
	addi $t1, $zero, 11
	slt $t2, $s-1, $s-1
	j end_ternary_24
	false_ternary_24:
	end_ternary_24:
	.data
		v: .word 0
	.text
	la $s0, v
	addi $t3, $zero, 1
	addi $t4, $zero, 1
	addi $t5, $zero, 1
	sllv $t6, $t4, $t5
	mul $t4, $t3, $t6
	la $t3, vetor
	sll $t5, $t4, 2
	add $t5, $t5, $t3
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
	addi $t1, $zero, 13
	add $s4, $zero, $t1
	addi $t1, $zero, 0
	add $s5, $zero, $s-1
	la $t2, NULL
	lw $t3, 0($t2)
	add $s6, $zero, $s-1
	addi $t2, $zero, 666
	.data
		ptr: .word 0
	.text
	la $s6, ptr
	j for_teste_384625840
	for_corpo_384625840:
	j while_teste_384626176
	while_corpo_384626176:
	addi $t4, $zero, 0
	sle $t5, $s6, $s-1
	beqz $t5, else_384627232
	.data
		ptr: .word 0
	.text
	la $s6, ptr
	addi $t5, $zero, 0
	la $s2, i
	sll $t6, $t5, 2
	add $t6, $t6, $s2
	lw $t5, 0($t6)
	addi $t6, $zero, 0
	la $s2, i
	sll $t7, $t6, 2
	add $t7, $t7, $s2
	lw $t6, 0($t7)
	addi $t7, $zero, 666
	div $t6, $t7
	mflo $t6
	la $t7, CALL_ELEVEN
	lw $t8, 0($t7)
	j exit_if_384634112
	else_384627232:
	while_corpo_384627232:
	add $t7, $zero, $s6
	addi $s6, $s6, 1
	while_teste_384627232:
	bnez $s-1, while_corpo_384627232
	exit_if_384634112:
	while_teste_384626176:
	bnez $s6, while_corpo_384626176
	add $t9, $zero, $s6
	addi $s6, $s6, 1
	for_teste_384625840:
	bnez $s6, for_corpo_384625840
	addi $t-1, $zero, 0
	la $s2, i
	sll $t-1, $t-1, 2
	add $t-1, $t-1, $s2
	lw $t-1, 0($t-1)
	add $t-1, $s-1, $t-1
	add $v0, $zero, $t-1

	addi $v0, $zero, 10
	syscall
