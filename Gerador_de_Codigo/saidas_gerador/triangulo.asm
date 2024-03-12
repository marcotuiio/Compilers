# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
.text
.globl main


.data
.text


main:
	.data
		string_576235904: .asciiz "=== Determinar Tipo de Triangulo ===\n\n"
	.text
	la $a0, string_576235904
	addi $v0, $zero, 4
	syscall
	.data
		string_576235840: .asciiz "Entre com o tamanho do lado A: "
	.text
	la $a0, string_576235840
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	.data
		string_576235792: .asciiz "Entre com o tamanho do lado B: "
	.text
	la $a0, string_576235792
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0
	.data
		string_576235744: .asciiz "Entre com o tamanho do lado C: "
	.text
	la $a0, string_576235744
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s2, $zero, $v0
	.data
		string_576235696: .asciiz "\n"
	.text
	la $a0, string_576235696
	addi $v0, $zero, 4
	syscall
	add $t0, $s1, $s2
	slt $t1, $s0, $t0
	add $t0, $s0, $s2
	slt $t2, $s1, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, f_logical_and_576267408
	beq $t0, $t2, f_logical_and_576267408
	addi $t0, $zero, 1
	f_logical_and_576267408:
	add $t1, $s0, $s1
	slt $t2, $s2, $t1
	addi $t1, $zero, 0
	beq $t1, $t0, f_logical_and_576261808
	beq $t1, $t2, f_logical_and_576261808
	addi $t1, $zero, 1
	f_logical_and_576261808:
	beqz $t1, else_576242640
	seq $t0, $s0, $s1
	seq $t1, $s1, $s2
	addi $t2, $zero, 0
	beq $t2, $t0, f_logical_and_576255152
	beq $t2, $t1, f_logical_and_576255152
	addi $t2, $zero, 1
	f_logical_and_576255152:
	beqz $t2, else_576243024
	.data
		string_576228368: .asciiz "Triangulo Equilatero."
	.text
	la $a0, string_576228368
	addi $v0, $zero, 4
	syscall
	j exit_if_576254096
	else_576243024:
	seq $t0, $s0, $s1
	seq $t1, $s0, $s2
	addi $t2, $zero, 1
	beq $t2, $t0, t_logical_or_576248176
	beq $t2, $t1, t_logical_or_576248176
	addi $t2, $zero, 0
	t_logical_or_576248176:
	seq $t0, $s2, $s1
	addi $t1, $zero, 1
	beq $t1, $t2, t_logical_or_576244464
	beq $t1, $t0, t_logical_or_576244464
	addi $t1, $zero, 0
	t_logical_or_576244464:
	beqz $t1, else_576243152
	.data
		string_576224992: .asciiz "Triangulo Isosceles."
	.text
	la $a0, string_576224992
	addi $v0, $zero, 4
	syscall
	j exit_if_576243408
	else_576243152:
	.data
		string_576224960: .asciiz "Triangulo Escaleno."
	.text
	la $a0, string_576224960
	addi $v0, $zero, 4
	syscall
	exit_if_576243408:
	exit_if_576254096:
	j exit_if_576242896
	else_576242640:
	.data
		string_576224928: .asciiz "Nao eh Triangulo!!!\n"
	.text
	la $a0, string_576224928
	addi $v0, $zero, 4
	syscall
	exit_if_576242896:
	addi $t0, $zero, 0
	add $v0, $zero, $t0

	addi $v0, $zero, 10
	syscall
