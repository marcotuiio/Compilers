.text
.globl main
	addi $t0, $zero, 100
	la $t0, MAX
	lw $t0, 0($t0)
	.data
		a: .space 400
	.text

quicksort:
	#laoding 2 params
	add $s0, $zero, $a0
	add $s1, $zero, $a1
	addi $t0, $zero, 1
	add $s2, $zero, $t0
	sle $t0, $s0, $s1
	addi $t1, $zero, 0
	beq $t1, $t0, else_798972992
	jr $ra
	j exit_if_798972992
	else_798972992:
	exit_if_798972992:
	addi $t0, $zero, 1
	sub $t1, $s1, $t0
	add $s3, $zero, $t1
	add $s4, $zero, $s0
	la $s7, a
	sll $t0, $s0, 2
	add $t0, $t0, $s7
	lw $t1, 0($t0)
	add $s5, $zero, $t1
	j while_teste_19
	while_corpo_19:
	while_corpo_21:
	addi $t0, $zero, 1
	add $t1, $s3, $t0
	add $s3, $zero, $t1
	while_teste_21:
	la $s7, a
	sll $t0, $s3, 2
	add $t0, $t0, $s7
	lw $t1, 0($t0)
	slt $t0, $t1, $s5
	addi $t1, $zero, 1
	beq $t1, $t0, while_corpo_21
	while_corpo_22:
	addi $t0, $zero, 1
	sub $t1, $s4, $t0
	add $s4, $zero, $t1
	while_teste_22:
	la $s7, a
	sll $t0, $s4, 2
	add $t0, $t0, $s7
	lw $t1, 0($t0)
	sgt $t0, $t1, $s5
	addi $t1, $zero, 1
	beq $t1, $t0, while_corpo_22
	sge $t0, $s3, $s4
	addi $t1, $zero, 0
	beq $t1, $t0, else_798989072
	addi $t0, $zero, 0
	add $s2, $zero, $t0
	j exit_if_798986432
	else_798989072:
	la $s7, a
	sll $t0, $s3, 2
	add $t0, $t0, $s7
	lw $t1, 0($t0)
	add $s6, $zero, $t1
	la $s7, a
	sll $t0, $s3, 2
	add $t0, $t0, $s7
	la $s7, a
	sll $t1, $s4, 2
	add $t1, $t1, $s7
	lw $t2, 0($t1)
	sw $t2, 0($t0)
	la $s7, a
	sll $t0, $s4, 2
	add $t0, $t0, $s7
	sw $s6, 0($t0)
	exit_if_798986432:
	while_teste_19:
	addi $t0, $zero, 1
	beq $t0, $s2, while_corpo_19
	la $s7, a
	sll $t0, $s3, 2
	add $t0, $t0, $s7
	lw $t1, 0($t0)
	add $s6, $zero, $t1
	la $s7, a
	sll $t0, $s3, 2
	add $t0, $t0, $s7
	la $s7, a
	sll $t1, $s0, 2
	add $t1, $t1, $s7
	lw $t2, 0($t1)
	sw $t2, 0($t0)
	la $s7, a
	sll $t0, $s0, 2
	add $t0, $t0, $s7
	sw $s6, 0($t0)
	add $a1, $zero, $s1 # function param m
	add $a0, $zero, $s4 # function param n

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

	jal quicksort

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
	addi $t1, $zero, 1
	add $t2, $s3, $t1
	add $a1, $zero, $t2 # function param m
	add $a0, $zero, $s0 # function param n

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

	jal quicksort

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
	addi $sp, $sp, 4
	add $t1, $zero, $v0
	jr $ra

main:
	addi $t0, $zero, 0
	add $s0, $zero, $t0
	j while_teste_43
	while_corpo_43:
	.data
		string_45: .asciiz "Entre com o tamanho do vetor (valor entre 1 e 100): "
	.text
	la $a0, string_45
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	while_teste_43:
	addi $t0, $zero, 0
	sle $t1, $s0, $t0
	addi $t0, $zero, 100
	sgt $t2, $s0, $t0
	addi $t0, $zero, 1
	beq $t0, $t1, t_logical_or_43_18
	beq $t0, $t2, t_logical_or_43_18
	addi $t0, $zero, 0
	t_logical_or_43_18:
	addi $t1, $zero, 1
	beq $t1, $t0, while_corpo_43
	addi $t0, $zero, 0
	add $s1, $zero, $t0
	j for_teste_48
	for_corpo_48:
	addi $t0, $zero, 1
	add $t1, $s1, $t0
	.data
		string_799122240: .asciiz "Entre com o valor da posicao "
	.text
	la $a0, string_799122240
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
	la $s7, a
	sll $t0, $s1, 2
	add $t0, $t0, $s7
	sw $s2, 0($t0)
	add $t0, $zero, $s1
	addi $s1, $s1, 1
	for_teste_48:
	slt $t1, $s1, $s0
	addi $t2, $zero, 1
	beq $t2, $t1, for_corpo_48
	addi $t1, $zero, 0
	add $a1, $zero, $t1 # function param m
	addi $t1, $zero, 1
	sub $t2, $s0, $t1
	add $a0, $zero, $t2 # function param n

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

	jal quicksort

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
	addi $sp, $sp, 4
	add $t1, $zero, $v0
	addi $t2, $zero, 0
	add $s1, $zero, $t2
	j for_teste_56
	for_corpo_56:
	la $s7, a
	sll $t2, $s1, 2
	add $t2, $t2, $s7
	lw $t3, 0($t2)
	.data
		string_799123488: .asciiz ""
	.text
	la $a0, string_799123488
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t3
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
	for_teste_56:
	slt $t3, $s1, $s0
	addi $t4, $zero, 1
	beq $t4, $t3, for_corpo_56
	.data
		string_60: .asciiz "\n"
	.text
	la $a0, string_60
	addi $v0, $zero, 4
	syscall
	addi $t3, $zero, 0
	add $v0, $zero, $t3

	addi $v0, $zero, 10
	syscall

# BLOCO DE DEFINES NO FIM DO ARQUIVO
.data
	MAX: .word 100
# END BLOCO DEFINES