.text
.globl main
main:
	addi $t0, $zero, 1
	add $s0, $zero, $t0
	addi $t0, $zero, 2
	add $s1, $zero, $t0
	addi $t0, $zero, 0
	add $s2, $zero, $t0
	addi $t0, $zero, 0
	add $s2, $zero, $t0
	j for_teste_6
	for_corpo_6:
	.data
		string7: .asciiz "Sucumba "
	.text
	la $a0, string7
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s2
	addi $v0, $zero, 1
	syscall
	.data
		string383: .asciiz "!\n"
	.text
	la $a0, string383
	addi $v0, $zero, 4
	syscall
	add $t0, $zero, $s2
	addi $s2, $s2, 1
	for_teste_6:
	addi $t1, $zero, 10
	slt $t2, $s2, $t1
	addi $t1, $zero, 1
	beq $t1, $t2, for_corpo_6
	addi $t1, $zero, 0
	add $s2, $zero, $t1
	j for_teste_9
	for_corpo_9:
	.data
		string10: .asciiz "Destrua "
	.text
	la $a0, string10
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s2
	addi $v0, $zero, 1
	syscall
	.data
		string886: .asciiz "!\n"
	.text
	la $a0, string886
	addi $v0, $zero, 4
	syscall
	addi $s2, $s2, 1
	for_teste_9:
	addi $t1, $zero, 10
	slt $t2, $s2, $t1
	addi $t1, $zero, 1
	beq $t1, $t2, for_corpo_9
	addi $t1, $zero, 0

	addi $v0, $zero, 10
	syscall
