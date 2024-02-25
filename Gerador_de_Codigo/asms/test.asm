.text
.globl main
main:
	li $t0, 10
	move $s0, $t0
	li $t0, 40
	move $s1, $t0
	slt $t0, $s0, $s1
	beqz $t0, else_linha_12
	.data
		string10: .asciiz "b maior que a\n"
	.text
	la $a0, string10
	li $v0, 4
	syscall
	j exit_if_10
	else_linha_12:
	.data
		string12: .asciiz "a menor que b\n"
	.text
	la $a0, string12
	li $v0, 4
	syscall
	exit_if_10:
	li $t0, 0
	li $v0, 10
	syscall
