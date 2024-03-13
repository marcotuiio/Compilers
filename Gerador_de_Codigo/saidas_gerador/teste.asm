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
		string_78438432: .asciiz "FUNCIONAAAAA "
	.text
	la $a0, string_78438432
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
	add $t0, $zero, $s0
	addi $s0, $s0, 1
	.data
		string_78418224: .asciiz "E depois novamente "
	.text
	la $a0, string_78418224
	addi $v0, $zero, 4
	syscall
	.data
		string_78440880: .asciiz "PORRA "
	.text
	la $a0, string_78440880
	addi $v0, $zero, 4
	syscall
	move $a0, $s0
	addi $v0, $zero, 4
	syscall
	.data
		string_52352: .asciiz "\n"
	.text
	la $a0, string_52352
	addi $v0, $zero, 4
	syscall
	j while_teste_78431280
	while_corpo_78431280:
	lb $t1, 0($s0)
	.data
		string_78441824: .asciiz ""
	.text
	la $a0, string_78441824
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t1
	addi $v0, $zero, 11
	syscall
	.data
		string_46469: .asciiz " "
	.text
	la $a0, string_46469
	addi $v0, $zero, 4
	syscall
	add $t1, $zero, $s0
	addi $s0, $s0, 1
	while_teste_78431280:
	lb $t2, 0($s0)
	addi $t3, $zero, 0
	sne $t4, $t2, $t3
	bnez $t4, while_corpo_78431280
	addi $t2, $zero, 1
	add $v0, $zero, $t2

	addi $v0, $zero, 10
	syscall
