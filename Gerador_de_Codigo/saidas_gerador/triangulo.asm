# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
.text
.globl main


.data
.text


main:
	.data
		string_1297600768: .asciiz "=== Determinar Tipo de Triangulo ===\n\n"
	.text
	la $a0, string_1297600768
	addi $v0, $zero, 4
	syscall
	.data
		string_1297600576: .asciiz "Entre com o tamanho do lado A: "
	.text
	la $a0, string_1297600576
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	.data
		string_1297600080: .asciiz "Entre com o tamanho do lado B: "
	.text
	la $a0, string_1297600080
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0
	.data
		string_1297599584: .asciiz "Entre com o tamanho do lado C: "
	.text
	la $a0, string_1297599584
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s2, $zero, $v0
	.data
		string_1297599088: .asciiz "\n"
	.text
	la $a0, string_1297599088
	addi $v0, $zero, 4
	syscall
	add $t0, $s1, $s2
	slt $t1, $s0, $t0
	add $t0, $s0, $s2
	slt $t2, $s1, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, f_logical_and_1297589392
	beq $t0, $t2, f_logical_and_1297589392
	addi $t0, $zero, 1
	f_logical_and_1297589392:
	add $t1, $s0, $s1
	slt $t2, $s2, $t1
	addi $t1, $zero, 0
	beq $t1, $t0, f_logical_and_1297583792
	beq $t1, $t2, f_logical_and_1297583792
	addi $t1, $zero, 1
	f_logical_and_1297583792:
	beqz $t1, else_1297564624
	seq $t0, $s0, $s1
	seq $t1, $s1, $s2
	addi $t2, $zero, 0
	beq $t2, $t0, f_logical_and_1297577136
	beq $t2, $t1, f_logical_and_1297577136
	addi $t2, $zero, 1
	f_logical_and_1297577136:
	beqz $t2, else_1297565008
	.data
		string_1297576176: .asciiz "Triangulo Equilatero."
	.text
	la $a0, string_1297576176
	addi $v0, $zero, 4
	syscall
	j exit_if_1297576080
	else_1297565008:
	seq $t0, $s0, $s1
	seq $t1, $s0, $s2
	addi $t2, $zero, 1
	beq $t2, $t0, t_logical_or_1297570160
	beq $t2, $t1, t_logical_or_1297570160
	addi $t2, $zero, 0
	t_logical_or_1297570160:
	seq $t0, $s2, $s1
	addi $t1, $zero, 1
	beq $t1, $t2, t_logical_or_1297566448
	beq $t1, $t0, t_logical_or_1297566448
	addi $t1, $zero, 0
	t_logical_or_1297566448:
	beqz $t1, else_1297565136
	.data
		string_1297565488: .asciiz "Triangulo Isosceles."
	.text
	la $a0, string_1297565488
	addi $v0, $zero, 4
	syscall
	j exit_if_1297565392
	else_1297565136:
	.data
		string_1297565232: .asciiz "Triangulo Escaleno."
	.text
	la $a0, string_1297565232
	addi $v0, $zero, 4
	syscall
	exit_if_1297565392:
	exit_if_1297576080:
	j exit_if_1297564880
	else_1297564624:
	.data
		string_1297564720: .asciiz "Nao eh Triangulo!!!\n"
	.text
	la $a0, string_1297564720
	addi $v0, $zero, 4
	syscall
	exit_if_1297564880:
	addi $t0, $zero, 0
	add $v0, $zero, $t0

	addi $v0, $zero, 10
	syscall
