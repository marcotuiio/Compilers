.text
.globl main
main:
	addi $t0, $zero, 10
	addi $t1, $zero, 666
	add $s0, $zero, $t1
	la $t1, max
	lw $t1, 0($t1)
	.data
		array: .space 40
	.text
	la $s1, array
	la $t2, max
	lw $t2, 0($t2)
	addi $t3, $zero, 2
	mul $t4, $t2, $t3
	add $s2, $zero, $t4
	addi $t2, $zero, 9
	sll $t3, $t2, 2
	add $t3, $t3, $s1
	addi $t4, $zero, 69
	sw $t4, 0($t3)
	addi $t4, $zero, 9
	sll $t5, $t4, 2
	add $t5, $t5, $s1
	.data
		string165: .asciiz "array [9] = "
	.text
	la $a0, string165
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t5
	addi $v0, $zero, 1
	syscall
	.data
		string383: .asciiz "\n"
	.text
	la $a0, string383
	addi $v0, $zero, 4
	syscall
	addi $t5, $zero, 0

	addi $v0, $zero, 10
	syscall

# BLOCO DE DEFINES NO FIM DO ARQUIVO
.data
	max: .word 10
# END BLOCO DEFINES