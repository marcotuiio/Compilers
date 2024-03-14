# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
.text
.globl main


.data
	sla2: .word 56 # define
	sla1: .word -10 # define
.text


main:
	.data
		c: .asciiz "DDominar o mundo\n"
	.text
	la $s0, c
	.data
		string_1066562784: .asciiz "FUNCIONAAAAA "
	.text
	la $a0, string_1066562784
	addi $v0, $zero, 4
	syscall
	move $a0, $s0
	addi $v0, $zero, 4
	syscall
	.data
		string_55271: .asciiz "\n"
	.text
	la $a0, string_55271
	addi $v0, $zero, 4
	syscall
	.data
		c2: .asciiz "E depois novamente "
	.text
	la $s1, c2
	.data
		string_1066456064: .asciiz "E depois novamente "
	.text
	la $a0, string_1066456064
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 1
	add $t1, $s0, $t0
	.data
		string_1066560832: .asciiz "PORRA "
	.text
	la $a0, string_1066560832
	addi $v0, $zero, 4
	syscall
	move $a0, $t1
	addi $v0, $zero, 4
	syscall
	.data
		string_52352: .asciiz "\n"
	.text
	la $a0, string_52352
	addi $v0, $zero, 4
	syscall
	j while_teste_1066443872
	while_corpo_1066443872:
	lb $t0, 0($s0)
	.data
		string_1066560128: .asciiz ""
	.text
	la $a0, string_1066560128
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 11
	syscall
	.data
		string_46469: .asciiz " "
	.text
	la $a0, string_46469
	addi $v0, $zero, 4
	syscall
	add $t0, $zero, $s0
	addi $s0, $s0, 1
	while_teste_1066443872:
	lb $t1, 0($s0)
	addi $t2, $zero, 0
	sne $t3, $t1, $t2
	bnez $t3, while_corpo_1066443872
	addi $t1, $zero, 1
	add $v0, $zero, $t1

	addi $v0, $zero, 10
	syscall
