.text
.globl main
	addi $t0, $zero, 100
	la $t0, MAX
	lw $t0, 0($t0)
	.data
		a: .space 400
	.text
	la $s0, a

quicksort:
	#laoding params = 2
	add $s0, $zero, $a0
	add $s1, $zero, $a1
	addi $t0, $zero, 1
	add $s2, $zero, $t0
	sle $t0, $s0, $s1
	addi $t1, $zero, 0
	beq $t1, $t0, else_linha_17
	jr $ra
	j exit_if_17
	else_linha_17:
	exit_if_17:
	addi $t0, $zero, 1
	sub $t1, $s1, $t0
	add $s3, $zero, $t1
	add $s4, $zero, $s0
	sll $t0, $s0, 2
	add $t0, $t0, $s0
	lw $t1, 0($t0)
	add $s5, $zero, $t1
	j while_teste_19
	while_corpo_19:
	while_corpo_21:
	addi $t0, $zero, 1
	add $t1, $s3, $t0
	add $s3, $zero, $t1
	while_teste_21:
	sll $t0, $s3, 2
	add $t0, $t0, $s0
	lw $t1, 0($t0)
	slt $t0, $t1, $s5
	addi $t1, $zero, 1
	beq $t1, $t0, while_corpo_21
	while_corpo_22:
	addi $t0, $zero, 1
	sub $t1, $s4, $t0
	add $s4, $zero, $t1
	while_teste_22:
	sll $t0, $s4, 2
	add $t0, $t0, $s0
	lw $t1, 0($t0)
	sgt $t0, $t1, $s5
	addi $t1, $zero, 1
	beq $t1, $t0, while_corpo_22
	sge $t0, $s3, $s4
	addi $t1, $zero, 0
	beq $t1, $t0, else_linha_-1
	addi $t0, $zero, 0
	add $s2, $zero, $t0
	j exit_if_-1
	else_linha_-1:
	sll $t0, $s3, 2
	add $t0, $t0, $s0
	lw $t1, 0($t0)
	add $s6, $zero, $t1
	sll $t0, $s3, 2
	add $t0, $t0, $s0
	sll $t1, $s4, 2
	add $t1, $t1, $s0
	lw $t2, 0($t1)
	sw $t2, 0($t0)
	sll $t0, $s4, 2
	add $t0, $t0, $s0
	sw $s6, 0($t0)
	exit_if_-1:
	while_teste_19:
	addi $t0, $zero, 1
	beq $t0, $s2, while_corpo_19
	sll $t0, $s3, 2
	add $t0, $t0, $s0
	lw $t1, 0($t0)
	add $s6, $zero, $t1
	sll $t0, $s3, 2
	add $t0, $t0, $s0
	sll $t1, $s0, 2
	add $t1, $t1, $s0
	lw $t2, 0($t1)
	sw $t2, 0($t0)
	sll $t0, $s0, 2
	add $t0, $t0, $s0
	sw $s6, 0($t0)
	#function param
	add $a1, $zero, $s1 # m
	#function param
	add $a0, $zero, $s4 # n
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
	#function param
	add $a1, $zero, $t2 # m
	#function param
	add $a0, $zero, $s0 # n
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
	addi $t2, $zero, 0
	add $s7, $zero, $t2
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
	add $s7, $zero, $v0
	while_teste_43:
	addi $t2, $zero, 0
	sle $t3, $s7, $t2
	addi $t2, $zero, 100
	sgt $t4, $s7, $t2
	addi $t2, $zero, 1
	beq $t2, $t3, t_logical_or_43_18
	beq $t2, $t4, t_logical_or_43_18
	addi $t2, $zero, 0
	t_logical_or_43_18:
	addi $t3, $zero, 1
	beq $t3, $t2, while_corpo_43
	addi $t2, $zero, 0
	add $s-1, $zero, $t2
	j for_teste_48
	for_corpo_48:
	addi $t2, $zero, 1
	add $t3, $s-1, $t2
	.data
		string_78638848: .asciiz "Entre com o valor da posicao "
	.text
	la $a0, string_78638848
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t3
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
	add $s-1, $zero, $v0
	sll $t2, $s-1, 2
	add $t2, $t2, $s0
	sw $s-1, 0($t2)
	add $t2, $zero, $s-1
	addi $s-1, $s-1, 1
	for_teste_48:
	slt $t3, $s-1, $s7
	addi $t4, $zero, 1
	beq $t4, $t3, for_corpo_48
	addi $t3, $zero, 0
	#function param
	add $a1, $zero, $t3 # m
	addi $t3, $zero, 1
	sub $t4, $s7, $t3
	#function param
	add $a0, $zero, $t4 # n
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
	lw $t1, 4($sp)
	lw $t2, 8($sp)
	addi $sp, $sp, 12
	add $t3, $zero, $v0
	addi $t4, $zero, 0
	add $s-1, $zero, $t4
	j for_teste_55
	for_corpo_55:
	sll $t4, $s-1, 2
	add $t4, $t4, $s0
	lw $t5, 0($t4)
	.data
		string_78641664: .asciiz ""
	.text
	la $a0, string_78641664
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t5
	addi $v0, $zero, 1
	syscall
	.data
		string_886: .asciiz " "
	.text
	la $a0, string_886
	addi $v0, $zero, 4
	syscall
	add $t4, $zero, $s-1
	addi $s-1, $s-1, 1
	for_teste_55:
	slt $t5, $s-1, $s7
	addi $t6, $zero, 1
	beq $t6, $t5, for_corpo_55
	.data
		string_59: .asciiz "\n"
	.text
	la $a0, string_59
	addi $v0, $zero, 4
	syscall
	addi $t5, $zero, 0
	add $v0, $zero, $t5

	addi $v0, $zero, 10
	syscall

# BLOCO DE DEFINES NO FIM DO ARQUIVO
.data
	MAX: .word 100
# END BLOCO DEFINES