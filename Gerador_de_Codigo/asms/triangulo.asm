# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
# file: asms/triangulo.asm
.text
.globl main


.data
.text

main:
	.data
		string_8: .asciiz "=== Determinar Tipo de Triangulo ===\n\n"
	.text
	la $a0, string_8
	addi $v0, $zero, 4
	syscall
	.data
		string_9: .asciiz "Entre com o tamanho do lado A: "
	.text
	la $a0, string_9
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	.data
		string_11: .asciiz "Entre com o tamanho do lado B: "
	.text
	la $a0, string_11
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0
	.data
		string_13: .asciiz "Entre com o tamanho do lado C: "
	.text
	la $a0, string_13
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s2, $zero, $v0
	.data
		string_16: .asciiz "\n"
	.text
	la $a0, string_16
	addi $v0, $zero, 4
	syscall
	add $t0, $s1, $s2
	slt $t1, $s0, $t0
	add $t0, $s0, $s2
	slt $t2, $s1, $t0
	addi $t0, $zero, 0
	beq $t0, $t1, f_logical_and_18_16
	beq $t0, $t2, f_logical_and_18_16
	addi $t0, $zero, 1
	f_logical_and_18_16:
	add $t1, $s0, $s1
	slt $t2, $s2, $t1
	addi $t1, $zero, 0
	beq $t1, $t0, f_logical_and_18_27
	beq $t1, $t2, f_logical_and_18_27
	addi $t1, $zero, 1
	f_logical_and_18_27:
	addi $t0, $zero, 0
	beq $t0, $t1, else_327706320
	seq $t0, $s0, $s1
	seq $t1, $s1, $s2
	addi $t2, $zero, 0
	beq $t2, $t0, f_logical_and_20_18
	beq $t2, $t1, f_logical_and_20_18
	addi $t2, $zero, 1
	f_logical_and_20_18:
	addi $t0, $zero, 0
	beq $t0, $t2, else_327704784
	.data
		string_22: .asciiz "Triangulo Equilatero."
	.text
	la $a0, string_22
	addi $v0, $zero, 4
	syscall
	j exit_if_327697008
	else_327704784:
	seq $t0, $s0, $s1
	seq $t1, $s0, $s2
	addi $t2, $zero, 1
	beq $t2, $t0, t_logical_or_26_22
	beq $t2, $t1, t_logical_or_26_22
	addi $t2, $zero, 0
	t_logical_or_26_22:
	seq $t0, $s2, $s1
	addi $t1, $zero, 1
	beq $t1, $t2, t_logical_or_26_30
	beq $t1, $t0, t_logical_or_26_30
	addi $t1, $zero, 0
	t_logical_or_26_30:
	addi $t0, $zero, 0
	beq $t0, $t1, else_327704192
	.data
		string_28: .asciiz "Triangulo Isosceles."
	.text
	la $a0, string_28
	addi $v0, $zero, 4
	syscall
	j exit_if_327702096
	else_327704192:
	.data
		string_32: .asciiz "Triangulo Escaleno."
	.text
	la $a0, string_32
	addi $v0, $zero, 4
	syscall
	exit_if_327702096:
	exit_if_327697008:
	j exit_if_327705248
	else_327706320:
	.data
		string_38: .asciiz "Nao eh Triangulo!!!\n"
	.text
	la $a0, string_38
	addi $v0, $zero, 4
	syscall
	exit_if_327705248:
	addi $t0, $zero, 0
	add $v0, $zero, $t0

	addi $v0, $zero, 10
	syscall
