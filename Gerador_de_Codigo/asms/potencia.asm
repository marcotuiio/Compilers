.text
.globl main

potencia:
	#laoding 2 params
	add $s0, $zero, $a0
	add $s1, $zero, $a1
	addi $t0, $zero, 0
	seq $t1, $s0, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, else_1464039392
	addi $t0, $zero, 1
	add $v0, $zero, $t0
	jr $ra
	j exit_if_1464036592
	else_1464039392:
	add $a1, $zero, $s1 # function param base
	addi $t0, $zero, 1
	sub $t1, $s0, $t0
	add $a0, $zero, $t1 # function param expoente

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

	jal potencia

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
	mul $t1, $s1, $t0
	add $v0, $zero, $t1
	jr $ra
	exit_if_1464036592:
	jr $ra

main:
	.data
		string_11: .asciiz "Digite a base: "
	.text
	la $a0, string_11
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	.data
		string_13: .asciiz "Digite o expoente: "
	.text
	la $a0, string_13
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0
	add $a1, $zero, $s0 # function param base
	add $a0, $zero, $s1 # function param expoente

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

	jal potencia

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
	.data
		string_1464142224: .asciiz "Resultado: "
	.text
	la $a0, string_1464142224
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
