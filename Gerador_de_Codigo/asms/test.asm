.text
.globl main

test:
	#laoding params = 2
	add $s0, $zero, $a0
	add $s1, $zero, $a1
	addi $t0, $zero, 987
	add $s2, $zero, $t0
	add $t0, $zero, $s2
	addi $s2, $s2, 1
	.data
		string_800780912: .asciiz "bucetoncios laringicus "
	.text
	la $a0, string_800780912
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t0
	addi $v0, $zero, 1
	syscall
	.data
		string_800780800: .asciiz " a = "
	.text
	la $a0, string_800780800
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	.data
		string_800780688: .asciiz " b = "
	.text
	la $a0, string_800780688
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s0
	addi $v0, $zero, 1
	syscall
	.data
		string_383: .asciiz "\n"
	.text
	la $a0, string_383
	addi $v0, $zero, 4
	syscall
	jr $ra

main:
	addi $t0, $zero, 7
	add $s3, $zero, $t0
	#function param
	add $a1, $zero, $s3 # fish
	addi $t0, $zero, 5
	#function param
	add $a0, $zero, $t0 # ball
	addi $sp, $sp, -52
	sw $a0, 0($sp)
	sw $a1, 4($sp)
	sw $a2, 8($sp)
	sw $a3, 12($sp)
	sw $s0, 16($sp)
	sw $s1, 20($sp)
	sw $s2, 24($sp)
	sw $s3, 28($sp)
	sw $s4, 32($sp)
	sw $s5, 36($sp)
	sw $s6, 40($sp)
	sw $s7, 44($sp)
	sw $ra, 48($sp)
	jal test
	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $s0, 16($sp)
	lw $s1, 20($sp)
	lw $s2, 24($sp)
	lw $s3, 28($sp)
	lw $s4, 32($sp)
	lw $s5, 36($sp)
	lw $s6, 40($sp)
	lw $s7, 44($sp)
	lw $ra, 48($sp)
	addi $sp, $sp, 52
	.data
		string_800780288: .asciiz "hello world "
	.text
	la $a0, string_800780288
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s3
	addi $v0, $zero, 1
	syscall
	addi $t0, $zero, 5
	add $t1, $s3, $t0
	.data
		string_800780080: .asciiz " this is fun "
	.text
	la $a0, string_800780080
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t1
	addi $v0, $zero, 1
	syscall
	addi $t0, $zero, 2
	sub $t1, $s3, $t0
	.data
		string_800779904: .asciiz " "
	.text
	la $a0, string_800779904
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t1
	addi $v0, $zero, 1
	syscall
	.data
		string_886: .asciiz "\n"
	.text
	la $a0, string_886
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 0

	addi $v0, $zero, 10
	syscall
