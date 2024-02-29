.text
.globl main
main:
	.data
		string8: .asciiz "=== Determinar Tipo de Triangulo ===\n\n"
	.text
	la $a0, string8
	addi $v0, $zero, 4
	syscall
	.data
		string9: .asciiz "Entre com o tamanho do lado A: "
	.text
	la $a0, string9
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s0, $zero, $v0
	.data
		string11: .asciiz "Entre com o tamanho do lado B: "
	.text
	la $a0, string11
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0
	.data
		string13: .asciiz "Entre com o tamanho do lado C: "
	.text
	la $a0, string13
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 5
	syscall
	add $s2, $zero, $v0
	.data
		string16: .asciiz "\n"
	.text
	la $a0, string16
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
	beq $t0, $t1, else_linha_38
	seq $t0, $s0, $s1
	seq $t1, $s1, $s2
	addi $t2, $zero, 0
	beq $t2, $t0, f_logical_and_20_18
	beq $t2, $t1, f_logical_and_20_18
	addi $t2, $zero, 1
	f_logical_and_20_18:
	addi $t0, $zero, 0
	beq $t0, $t2, else_linha_26
	.data
		string22: .asciiz "Triangulo Equilatero."
	.text
	la $a0, string22
	addi $v0, $zero, 4
	syscall
	j exit_if_22
	else_linha_26:
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
	beq $t0, $t1, else_linha_32
	.data
		string28: .asciiz "Triangulo Isosceles."
	.text
	la $a0, string28
	addi $v0, $zero, 4
	syscall
	j exit_if_28
	else_linha_32:
	.data
		string32: .asciiz "Triangulo Escaleno."
	.text
	la $a0, string32
	addi $v0, $zero, 4
	syscall
	exit_if_28:
	exit_if_22:
	j exit_if_20
	else_linha_38:
	.data
		string38: .asciiz "Nao eh Triangulo!!!\n"
	.text
	la $a0, string38
	addi $v0, $zero, 4
	syscall
	exit_if_20:
	addi $t0, $zero, 0
	addi $v0, $zero, 10
	syscall
