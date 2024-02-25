.text
.globl main
main:
	li $t0, 5
	move $s0, $t0
	li $t0, 10
	move $s1, $t0
	.data
		string97: .asciiz "Testing assignment expressions...\n"
	.text
	la $a0, string97
	li $v0, 4
	syscall
	# assignment na ast
	move $s0, $s1
	seq $t0, $s0, $s1
	beqz $t0, else_linha_104
	.data
		string102: .asciiz "Test 1 passed: a is equal to b after assignment\n"
	.text
	la $a0, string102
	li $v0, 4
	syscall
	j exit_if_102
	else_linha_104:
	.data
		string104: .asciiz "Test 1 failed: a is not equal to b after assignment\n"
	.text
	la $a0, string104
	li $v0, 4
	syscall
	exit_if_102:
	add $t0, $s0, $s1
	move $s0, $t0
	li $t0, 2
	mul $t1, $t0, $s1
	seq $t0, $s0, $t1
	beqz $t0, else_linha_112
	.data
		string110: .asciiz "Test 2 passed: a is equal to 2*b after add assignment\n"
	.text
	la $a0, string110
	li $v0, 4
	syscall
	j exit_if_110
	else_linha_112:
	.data
		string112: .asciiz "Test 2 failed: a is not equal to 2*b after add assignment\n"
	.text
	la $a0, string112
	li $v0, 4
	syscall
	exit_if_110:
	sub $t0, $s0, $s1
	move $s0, $t0
	seq $t0, $s0, $s1
	beqz $t0, else_linha_120
	.data
		string118: .asciiz "Test 3 passed: a is equal to b after subtract assignment\n"
	.text
	la $a0, string118
	li $v0, 4
	syscall
	j exit_if_118
	else_linha_120:
	.data
		string120: .asciiz "Test 3 failed: a is not equal to b after subtract assignment\n"
	.text
	la $a0, string120
	li $v0, 4
	syscall
	exit_if_118:
	li $t0, 0
	li $v0, 10
	syscall
