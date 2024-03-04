# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: asms/test.asm
.text
.globl main

	addi $t0, $zero, 10
	addi $t0, $zero, 3
	la $t0, max
	lw $t1, 0($t0)

.data
	b: .word 0
	v: .space 12 # global array
	teste: .word 0
	addi $t0, $zero, 7
	addi $t1, $zero, 3
	div $t0, $t1
	mfhi $t0
	addi $t1, $zero, 9
	add $t2, $t0, $t1
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
		string_593436368: .asciiz "params "
	.text
	la $a0, string_593436368
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	.data
		string_593436480: .asciiz " "
	.text
	la $a0, string_593436480
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
	# BLOCO DE ATRIBUICOES GLOBAIS NO COMEÇO DA MAIN
	la $t0, teste
	add $t1, $zero, 10
	sw $t1, 0($t0)
	# END BLOCO ATRIBUICOES GLOBAIS
	.data
		a: .space 40 # local function array
	.text
	addi $t0, $zero, 999
	la $t1, b
	sw $t0, 0($t1)
	la $t0, teste
	lw $t1, 0($t0)
	.data
		string_593432304: .asciiz "teste = "
	.text
	la $a0, string_593432304
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t1
	addi $v0, $zero, 1
	syscall
	.data
		string_886: .asciiz "\n"
	.text
	la $a0, string_886
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 666
	add $v0, $zero, $t0

	addi $v0, $zero, 10
	syscall

# BLOCO DE DEFINES NO FIM DO ARQUIVO
.data
	max: .word 10
# END BLOCO DEFINES