.text
.globl main
main:
	addi $t0, $zero, 99
	add $s0, $zero, $t0
	addi $t0, $zero, 1
	add $s0, $zero, $t0
	j for_teste_148
	for_corpo_148:
	.data
		string149: .asciiz ""
	.text
	la $a0, string149
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	.data
		string383: .asciiz " "
	.text
	la $a0, string383
	addi $v0, $zero, 4
	syscall
	addi $s0, $s0, 1
	for_teste_148:
	addi $t0, $zero, 10
	sle $t1, $s0, $t0
	addi $t0, $zero, 1
	beq $t0, $t1, for_corpo_148
	.data
		string151: .asciiz "\n"
	.text
	la $a0, string151
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 0
	addi $v0, $zero, 10
	syscall
