.text
.globl main
main:
	li $t0, 10
	move $s0, $t0
	li $t0, 40
	move $s1, $t0
	li $t0, 2
	mul $t1, $s1, $t0
	# assignment na ast
	move $s2, $t1
	add $t0, $s1, $s2
	slt $t1, $s0, $t0
	beqz $t1, else_linha_12
	.data
		string10: .asciiz "a menor b+c\n"
	.text
	la $a0, string10
	li $v0, 4
	syscall
	j exit_if_10
	else_linha_12:
	.data
		string12: .asciiz "a maior b+c\n"
	.text
	la $a0, string12
	li $v0, 4
	syscall
	exit_if_10:
	li $t0, 0
	li $v0, 10
	syscall
