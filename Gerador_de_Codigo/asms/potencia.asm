.text
.globl main

potencia:
	#laoding params = 2
	add $s0, $zero, $a0
	add $s1, $zero, $a1
	addi $t0, $zero, 0
	seq $t1, $s0, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, else_linha_5
	addi $t0, $zero, 1
	add $v0, $zero, $t0
	jr $ra
	j exit_if_3
	else_linha_5:
	#function param
	add $a1, $zero, $s1 # base
	addi $t0, $zero, 1
	sub $t1, $s0, $t0
	#function param
	add $a0, $zero, $t1 # expoente
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
	exit_if_3:
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
	add $s2, $zero, $v0
	.data
		string_13: .asciiz "Digite o expoente: "
	.text
	la $a0, string_13
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s3, $zero, $v0
	#function param
	add $a1, $zero, $s2 # base
	#function param
	add $a0, $zero, $s3 # expoente
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
		string_480327376: .asciiz "Resultado: "
	.text
	la $a0, string_480327376
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
