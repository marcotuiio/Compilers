.text
.globl main
	addi $t0, $zero, 34
	addi $t0, $zero, 10
	.data
		array: .space 40
	.text
	addi $t0, $zero, 6
	.data
		v: .space 24
	.text

main:
	addi $t0, $zero, 9
	la $s7, array
	sll $t1, $t0, 2
	add $t1, $t1, $s7
	addi $t2, $zero, 69
	sw $t2, 0($t1)
	addi $t1, $zero, 2
	la $s8, v
	sll $t2, $t1, 2
	add $t2, $t2, $s8
	addi $t3, $zero, 1
	sw $t3, 0($t2)
	addi $t2, $zero, 9
	la $s7, array
	sll $t3, $t2, 2
	add $t3, $t3, $s7
	addi $t4, $zero, 0
	la $s8, v
	sll $t5, $t4, 2
	add $t5, $t5, $s8
	lw $t6, 0($t3)
	lw $t3, 0($t5)
	seq $t5, $t6, $t3
	addi $t3, $zero, 0
	beq $t3, $t5, else_487496304
	.data
		string_204: .asciiz "bucetoncios langeicus\n"
	.text
	la $a0, string_204
	addi $v0, $zero, 4
	syscall
	j exit_if_487497184
	else_487496304:
	.data
		string_206: .asciiz "cuuu buuu\n"
	.text
	la $a0, string_206
	addi $v0, $zero, 4
	syscall
	exit_if_487497184:
	addi $t3, $zero, 9
	la $s7, array
	sll $t5, $t3, 2
	add $t5, $t5, $s7
	lw $t6, 0($t5)
	.data
		string_487489984: .asciiz "array [9] = "
	.text
	la $a0, string_487489984
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t6
	addi $v0, $zero, 1
	syscall
	.data
		string_383: .asciiz "\n"
	.text
	la $a0, string_383
	addi $v0, $zero, 4
	syscall
	addi $t5, $zero, 0
	add $v0, $zero, $t5

	addi $v0, $zero, 10
	syscall

# BLOCO DE DEFINES NO FIM DO ARQUIVO
.data
	max: .word 34
# END BLOCO DEFINES