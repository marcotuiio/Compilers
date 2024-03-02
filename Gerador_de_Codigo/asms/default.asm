.text
.globl main
	addi $t0, $zero, 10
	la $t0, c1
	lw $t0, 0($t0)
	sub $t1, $zero, $t0
	la $t0, c1
	lw $t0, 0($t0)
	addi $t1, $zero, 2
	sllv $t2, $t0, $t1
	la $t0, c2
	lw $t0, 0($t0)
	la $t2, c3
	lw $t2, 0($t2)
	la $t3, c3
	lw $t3, 0($t3)
	mul $t4, $t2, $t3
	srlv $t2, $t0, $t4
	addi $t0, $zero, 0
	addi $t0, $zero, 11
	la $t0, c2
	lw $t0, 0($t0)
	la $t2, c3
	lw $t2, 0($t2)
	add $t3, $t0, $t2
	.data
		v: .space 120
	.text
	la $s0, v
	addi $t0, $zero, 1
	addi $t0, $zero, 0
	la $t0, TRUE
	lw $t0, 0($t0)
	la $t2, FALSE
	lw $t2, 0($t2)
	addi $t3, $zero, 1
	beq $t3, $t0, t_logical_or_17_28
	beq $t3, $t2, t_logical_or_17_28
	addi $t3, $zero, 0
	t_logical_or_17_28:
	addi $t0, $zero, 0
	beq $t0, $t3, false_ternary_17
	true_ternary_17:
	la $t0, TRUE
	lw $t0, 0($t0)
	j end_ternary_17
	false_ternary_17:
	la $t2, FALSE
	lw $t2, 0($t2)
	end_ternary_17:
	la $t0, SERA_VERDADE
	lw $t0, 0($t0)
	.data
		vetor: .space 4
	.text
	la $s1, vetor

f:
	#laoding params = 0
	la $t0, c4
	lw $t0, 0($t0)
	sll $t2, $t0, 2
	add $t2, $t2, $s0
	la $t3, c1
	lw $t3, 0($t3)
	lw $t5, 0($t0)
	sgt $t0, $t3, $t5
	la $t3, c2
	lw $t3, 0($t3)
	la $t5, NULL
	lw $t5, 0($t5)
	addi $t6, $zero, 0
	beq $t6, $t5, false_ternary_11
	true_ternary_11:
	j end_ternary_11
	false_ternary_11:
	la $t5, c3
	lw $t5, 0($t5)
	end_ternary_11:
	lw $t6, 0($t0)
	addi $t0, $zero, 0
	add $v0, $zero, $s-1
	jr $ra
	jr $ra

g:
	#laoding params = 0
	addi $t6, $zero, 1
	add $t7, $s-1, $t6
	add $s2, $zero, $t7
	addi $t6, $zero, 666
	srlv $t7, $s-1, $t6
	.data
		string_1518930144: .asciiz ""
	.text
	la $a0, string_1518930144
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t7
	addi $v0, $zero, 1
	syscall
	.data
		string_383: .asciiz ""
	.text
	la $a0, string_383
	addi $v0, $zero, 4
	syscall
	addi $t7, $zero, 0
	beq $t7, $s-1, false_ternary_24
	true_ternary_24:
	addi $t7, $zero, 666
	addi $t8, $zero, 11
	slt $t9, $s-1, $s-1
	j end_ternary_24
	false_ternary_24:
	end_ternary_24:
	add $s3, $zero, $s-1
	addi $t-1, $zero, 1
	addi $t-1, $zero, 1
	sllv $t-1, $t-1, $t-1
	sll $t-1, $t-1, 2
	add $t-1, $t-1, $s1
	add $v0, $zero, $s-1
	jr $ra
	jr $ra

main:
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
	jal g
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
	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $t2, 8($sp)
	lw $t3, 12($sp)
	lw $t4, 16($sp)
	lw $t5, 20($sp)
	lw $t6, 24($sp)
	lw $t7, 28($sp)
	lw $t8, 32($sp)
	lw $t9, 36($sp)
	addi $sp, $sp, 40
	add $t-1, $zero, $v0
	add $s4, $zero, $t-1
	addi $t-1, $zero, 65
	add $s5, $zero, $s-1
	add $s6, $zero, $s-1
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
	jal f
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
	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $t2, 8($sp)
	lw $t3, 12($sp)
	lw $t4, 16($sp)
	lw $t5, 20($sp)
	lw $t6, 24($sp)
	lw $t7, 28($sp)
	lw $t8, 32($sp)
	lw $t9, 36($sp)
	addi $sp, $sp, 40
	add $t-1, $zero, $v0
	add $s7, $zero, $t-1
	add $s-1, $zero, $s-1
	addi $t-1, $zero, 0
	add $s-1, $zero, $s-1
	la $t-1, NULL
	lw $t-1, 0($t-1)
	add $s-1, $zero, $s-1
	addi $t-1, $zero, 666
	add $s-1, $zero, $s-1
	j for_teste_32
	for_corpo_32:
	j while_teste_34
	while_corpo_34:
	addi $t-1, $zero, 0
	sle $t-1, $s-1, $s-1
	addi $t-1, $zero, 0
	beq $t-1, $t-1, else_linha_43
	add $s-1, $zero, $s-1
	addi $t-1, $zero, 666
	div $s-1, $t-1
	mflo $t-1
	la $t-1, CALL_ELEVEN
	lw $t-1, 0($t-1)
	j exit_if_-1
	else_linha_43:
	while_corpo_43:
	add $t-1, $zero, $s-1
	addi $s-1, $s-1, 1
	while_teste_43:
	addi $t-1, $zero, 1
	beq $t-1, $s0, while_corpo_43
	exit_if_-1:
	while_teste_34:
	addi $t-1, $zero, 1
	beq $t-1, $s-1, while_corpo_34
	add $t-1, $zero, $s-1
	addi $s-1, $s-1, 1
	for_teste_32:
	addi $t-1, $zero, 1
	beq $t-1, $s-1, for_corpo_32
	add $t-1, $s-1, $s-1
	add $v0, $zero, $t-1

	addi $v0, $zero, 10
	syscall

# BLOCO DE DEFINES NO FIM DO ARQUIVO
.data
	c1: .word 10
	c2: .word -10
	c3: .word 40
	c4: .word -10
	NULL: .word 0
	CALL_ELEVEN: .word 11
	TRUE: .word 1
	FALSE: .word 0
	SERA_VERDADE: .word 1
# END BLOCO DEFINES