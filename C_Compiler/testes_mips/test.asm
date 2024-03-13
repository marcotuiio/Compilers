# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: testes_mips/test.c
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
	add $t0, $zero, $s1
	addi $s1, $s1, 1
	.data
		string_1117537984: .asciiz "porraaaa "
	.text
	la $a0, string_1117537984
	addi $v0, $zero, 4
	syscall
	move $a0, $s1
	addi $v0, $zero, 4
	syscall
	.data
		string_55271: .asciiz "\n"
	.text
	la $a0, string_55271
	addi $v0, $zero, 4
	syscall
	j while_teste_1117527952
	while_corpo_1117527952:
	lb $t1, 0($s1)
	.data
		string_1117537280: .asciiz ""
	.text
	la $a0, string_1117537280
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t1
	addi $v0, $zero, 11
	syscall
	.data
		string_52352: .asciiz " "
	.text
	la $a0, string_52352
	addi $v0, $zero, 4
	syscall
	add $t1, $zero, $s1
	addi $s1, $s1, 1
	while_teste_1117527952:
	lb $t2, 0($s1)
	addi $t3, $zero, 0
	sne $t4, $t2, $t3
	bnez $t4, while_corpo_1117527952
	.data
		string_1117521904: .asciiz "antes c = "
	.text
	la $a0, string_1117521904
	addi $v0, $zero, 4
	syscall
	move $a0, $s1
	addi $v0, $zero, 4
	syscall
	.data
		string_46469: .asciiz "\n"
	.text
	la $a0, string_46469
	addi $v0, $zero, 4
	syscall
	addi $s1, $s1, 1
	.data
		string_1117521296: .asciiz "depois c = "
	.text
	la $a0, string_1117521296
	addi $v0, $zero, 4
	syscall
	move $a0, $s1
	addi $v0, $zero, 4
	syscall
	.data
		string_22427: .asciiz "\n"
	.text
	la $a0, string_22427
	addi $v0, $zero, 4
	syscall
	.data
		string_1117520992: .asciiz "c2 = "
	.text
	la $a0, string_1117520992
	addi $v0, $zero, 4
	syscall
	move $a0, $s0
	addi $v0, $zero, 4
	syscall
	.data
		string_43439: .asciiz "\n"
	.text
	la $a0, string_43439
	addi $v0, $zero, 4
	syscall
	addi $t2, $zero, 0
	add $v0, $zero, $t2

	addi $v0, $zero, 10
	syscall
