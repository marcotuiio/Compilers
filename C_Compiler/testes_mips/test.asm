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
	addi $t0, $zero, 1
	add $t1, $s1, $t0
	.data
		string_2003634496: .asciiz "porraaaa "
	.text
	la $a0, string_2003634496
	addi $v0, $zero, 4
	syscall
	move $a0, $t1
	addi $v0, $zero, 4
	syscall
	.data
		string_55271: .asciiz "\n"
	.text
	la $a0, string_55271
	addi $v0, $zero, 4
	syscall
	j while_teste_2003644768
	while_corpo_2003644768:
	lb $t0, 0($s1)
	.data
		string_2003635200: .asciiz ""
	.text
	la $a0, string_2003635200
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 11
	syscall
	.data
		string_52352: .asciiz " "
	.text
	la $a0, string_52352
	addi $v0, $zero, 4
	syscall
	add $t0, $zero, $s1
	addi $s1, $s1, 1
	while_teste_2003644768:
	lb $t1, 0($s1)
	addi $t2, $zero, 0
	sne $t3, $t1, $t2
	bnez $t3, while_corpo_2003644768
	.data
		string_2003650816: .asciiz "antes c = "
	.text
	la $a0, string_2003650816
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
		string_2003651424: .asciiz "depois c = "
	.text
	la $a0, string_2003651424
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
		string_2003651728: .asciiz "c2 = "
	.text
	la $a0, string_2003651728
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
	addi $t1, $zero, 0
	add $v0, $zero, $t1

	addi $v0, $zero, 10
	syscall
