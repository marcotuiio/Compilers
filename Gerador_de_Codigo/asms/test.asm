.text
.globl main
main:
	li $t0, 5
	move $s0, $t0
	while_corpo_4:
	.data
		string5: .asciiz "a = "
	.text
	la $a0, string5
	li $v0, 4
	syscall
	move $a0, $s0
	li $v0, 1
	syscall
	.data
		string83: .asciiz "\n"
	.text
	la $a0, string83
	li $v0, 4
	syscall
	while_teste_4:
	li $t0, 10
	slt $t1, $s0, $t0
	li $t0, 1
	beq $t0, $t1, while_corpo_4
	li $t0, 0
	li $v0, 10
	syscall
