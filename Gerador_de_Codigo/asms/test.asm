.text
.globl main
main:
	addi $t0, $zero, 1
	add $s0, $zero, $t0
	addi $t0, $zero, 0
	add $s1, $zero, $t0
	j while_teste_142
	while_corpo_142:
	.data
		string143: .asciiz ""
	.text
	la $a0, string143
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	.data
		string83: .asciiz "\n"
	.text
	la $a0, string83
	addi $v0, $zero, 4
	syscall
	while_teste_142:
	addi $t0, $zero, 5
	sle $t1, $s0, $t0
	addi $t0, $zero, 1
	beq $t0, $t1, while_corpo_142
	while_corpo_147:
	.data
		string148: .asciiz "Enter a number: "
	.text
	la $a0, string148
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s2, $zero, $v0
	add $t0, $s1, $s2
	add $s1, $zero, $t0
	while_teste_147:
	addi $t0, $zero, 0
	sne $t1, $s2, $t0
	addi $t0, $zero, 1
	beq $t0, $t1, while_corpo_147
	.data
		string153: .asciiz "Sum = "
	.text
	la $a0, string153
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	.data
		string86: .asciiz "\n"
	.text
	la $a0, string86
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 1
	add $s0, $zero, $t0
	j for_teste_155
	for_corpo_155:
	.data
		string156: .asciiz ""
	.text
	la $a0, string156
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	for_teste_155:
	addi $t0, $zero, 10
	sle $t1, $s0, $t0
	addi $t0, $zero, 1
	beq $t0, $t1, for_corpo_155
	.data
		string158: .asciiz "\n"
	.text
	la $a0, string158
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 0
	addi $v0, $zero, 10
	syscall
