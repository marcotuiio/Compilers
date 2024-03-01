.text
.globl main
main:
	addi $t0, $zero, 7
	add $s0, $zero, $t0
	.data
		string0_0: .asciiz "hello world "
	.text
	la $a0, string0_0
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	addi $t0, $zero, 5
	add $t1, $s0, $t0
	.data
		string17_54: .asciiz " this is fun "
	.text
	la $a0, string17_54
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t1
	addi $v0, $zero, 1
	syscall
	addi $t0, $zero, 2
	sub $t1, $s0, $t0
	.data
		string17_59: .asciiz " "
	.text
	la $a0, string17_59
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t1
	addi $v0, $zero, 1
	syscall
	.data
		string886_145: .asciiz "\n"
	.text
	la $a0, string886_145
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 0

	addi $v0, $zero, 10
	syscall
