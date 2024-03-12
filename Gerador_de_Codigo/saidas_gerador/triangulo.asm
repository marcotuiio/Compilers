# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
.text
.globl main


.data
.text


main:
	.data
		string_1783953024: .asciiz "=== Determinar Tipo de Triangulo ===\n\n"
	.text
	la $a0, string_1783953024
	addi $v0, $zero, 4
	syscall
	.data
		string_1783953088: .asciiz "Entre com o tamanho do lado A: "
	.text
	la $a0, string_1783953088
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	.data
		string_1783953136: .asciiz "Entre com o tamanho do lado B: "
	.text
	la $a0, string_1783953136
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0
	.data
		string_1783953184: .asciiz "Entre com o tamanho do lado C: "
	.text
	la $a0, string_1783953184
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s2, $zero, $v0
	.data
		string_1783953232: .asciiz "\n"
	.text
	la $a0, string_1783953232
	addi $v0, $zero, 4
	syscall
	add $t0, $s1, $s2
	slt $t1, $s0, $t0
	add $t0, $s0, $s2
	slt $t2, $s1, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, f_logical_and_1783921520
	beq $t0, $t2, f_logical_and_1783921520
	addi $t0, $zero, 1
	f_logical_and_1783921520:
	add $t1, $s0, $s1
	slt $t2, $s2, $t1
	addi $t1, $zero, 0
	beq $t1, $t0, f_logical_and_1783927120
	beq $t1, $t2, f_logical_and_1783927120
	addi $t1, $zero, 1
	f_logical_and_1783927120:
	beqz $t1, else_1783946288
	seq $t0, $s0, $s1
	seq $t1, $s1, $s2
	addi $t2, $zero, 0
	beq $t2, $t0, f_logical_and_1783933776
	beq $t2, $t1, f_logical_and_1783933776
	addi $t2, $zero, 1
	f_logical_and_1783933776:
	beqz $t2, else_1783945904
	.data
		string_1783960560: .asciiz "Triangulo Equilatero."
	.text
	la $a0, string_1783960560
	addi $v0, $zero, 4
	syscall
	j exit_if_1783934832
	else_1783945904:
	seq $t0, $s0, $s1
	seq $t1, $s0, $s2
	addi $t2, $zero, 1
	beq $t2, $t0, t_logical_or_1783940752
	beq $t2, $t1, t_logical_or_1783940752
	addi $t2, $zero, 0
	t_logical_or_1783940752:
	seq $t0, $s2, $s1
	addi $t1, $zero, 1
	beq $t1, $t2, t_logical_or_1783944464
	beq $t1, $t0, t_logical_or_1783944464
	addi $t1, $zero, 0
	t_logical_or_1783944464:
	beqz $t1, else_1783945776
	.data
		string_1783963936: .asciiz "Triangulo Isosceles."
	.text
	la $a0, string_1783963936
	addi $v0, $zero, 4
	syscall
	j exit_if_1783945520
	else_1783945776:
	.data
		string_1783963968: .asciiz "Triangulo Escaleno."
	.text
	la $a0, string_1783963968
	addi $v0, $zero, 4
	syscall
	exit_if_1783945520:
	exit_if_1783934832:
	j exit_if_1783946032
	else_1783946288:
	.data
		string_1783964000: .asciiz "Nao eh Triangulo!!!\n"
	.text
	la $a0, string_1783964000
	addi $v0, $zero, 4
	syscall
	exit_if_1783946032:
	addi $t0, $zero, 0
	add $v0, $zero, $t0

	addi $v0, $zero, 10
	syscall
