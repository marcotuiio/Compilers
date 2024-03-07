# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: asms/test.asm
.text
.globl main

	addi $t0, $zero, 10

.data
	c1: .word 10 # define
.text

main:
	.data
		c2: .asciiz "E depois novamente "
	.text
	la $s0, c2
	.data
		c: .asciiz "DDominar o mundo\n"
	.text
	la $s1, c
	j while_teste_346
	while_corpo_346:
	lb $t0, 0($s1)
	.data
		string_967801920: .asciiz ""
	.text
	la $a0, string_967801920
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 11
	syscall
	.data
		string_383: .asciiz " "
	.text
	la $a0, string_383
	addi $v0, $zero, 4
	syscall
	add $t0, $zero, $s1
	addi $s1, $s1, 1
	while_teste_346:
	lb $t1, 0($s1)
	addi $t2, $zero, 0
	sne $t3, $t1, $t2
	bnez $t3, while_corpo_346
	.data
		string_967799696: .asciiz "antes c = "
	.text
	la $a0, string_967799696
	addi $v0, $zero, 4
	syscall
	move $a0, $s1
	addi $v0, $zero, 4
	syscall
	.data
		string_886: .asciiz "\n"
	.text
	la $a0, string_886
	addi $v0, $zero, 4
	syscall
	addi $s1, $s1, 1
	.data
		string_967787504: .asciiz "depois c = "
	.text
	la $a0, string_967787504
	addi $v0, $zero, 4
	syscall
	move $a0, $s1
	addi $v0, $zero, 4
	syscall
	.data
		string_777: .asciiz "\n"
	.text
	la $a0, string_777
	addi $v0, $zero, 4
	syscall
	.data
		string_967787136: .asciiz "c2 = "
	.text
	la $a0, string_967787136
	addi $v0, $zero, 4
	syscall
	move $a0, $s0
	addi $v0, $zero, 4
	syscall
	.data
		string_915: .asciiz "\n"
	.text
	la $a0, string_915
	addi $v0, $zero, 4
	syscall
	addi $t1, $zero, 0
	add $v0, $zero, $t1

	addi $v0, $zero, 10
	syscall
