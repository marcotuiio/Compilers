.text
.globl main
main:
	addi $t0, $zero, 5
	add $s0, $zero, $t0
	add $t0, $zero, $s0
	addi $s0, $s0, 1
	add $s1, $zero, $t0
	.data
		string8: .asciiz "Post-increment result: "
	.text
	la $a0, string8
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	.data
		string383: .asciiz "\n"
	.text
	la $a0, string383
	addi $v0, $zero, 4
	syscall
	addi $s0, $s0, 1
	add $s2, $zero, $s0
	.data
		string12: .asciiz "Pre-increment result: "
	.text
	la $a0, string12
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s2
	addi $v0, $zero, 1
	syscall
	.data
		string886: .asciiz "\n"
	.text
	la $a0, string886
	addi $v0, $zero, 4
	syscall

	addi $v0, $zero, 10
	syscall
