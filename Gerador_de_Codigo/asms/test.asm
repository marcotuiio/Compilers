.text
.globl main
main:
	addi $t0, $zero, 5
	add $s0, $zero, $t0
	addi $t0, $zero, 10
	add $s1, $zero, $t0
	sgt $t0, $s0, $s1
	addi $t1, $zero, 0
	beq $t1, $t0, false_ternary_229
	true_ternary_229:
	addi $t0, $zero, 1
	add $t1, $s0, $t0
	j end_ternary_229
	false_ternary_229:
	addi $t0, $zero, 1
	sub $t2, $s1, $t0
	end_ternary_229:
	add $s2, $zero, $t2
	.data
		string230: .asciiz "c = "
	.text
	la $a0, string230
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s2
	addi $v0, $zero, 1
	syscall
	.data
		string383: .asciiz "\n"
	.text
	la $a0, string383
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 0

	addi $v0, $zero, 10
	syscall
