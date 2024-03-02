.text
.globl main
	addi $t0, $zero, 10
	la $t0, c1
	lw $t0, 0($t0)
	sub $t1, $zero, $t0
	la $t0, c1
	lw $t0, 0($t0)
	addi $t1, $zero, 2
	sllv $t2, $t0, $t1
	la $t0, c2
	lw $t0, 0($t0)
	la $t2, c3
	lw $t2, 0($t2)
	la $t3, c3
	lw $t3, 0($t3)
	mul $t4, $t2, $t3
	srlv $t2, $t0, $t4
	addi $t0, $zero, 0
	addi $t0, $zero, 11
	la $t0, c2
	lw $t0, 0($t0)
	la $t2, c3
	lw $t2, 0($t2)
	add $t3, $t0, $t2
	.data
		v: .space 120
	.text
	la $s0, v

f:
	#laoding params = 0
	la $t0, c4
	lw $t0, 0($t0)
	sll $t2, $t0, 2
	add $t2, $t2, $s0
	la $t3, c1
	lw $t3, 0($t3)
	lw $t5, 0($t0)
	sgt $t0, $t3, $t5
	la $t3, c2
	lw $t3, 0($t3)
	la $t5, NULL
	lw $t5, 0($t5)
	addi $t6, $zero, 0
	beq $t6, $t5, false_ternary_43
	true_ternary_43:
	j end_ternary_43
	false_ternary_43:
	la $t5, c3
	lw $t5, 0($t5)
	end_ternary_43:
	lw $t6, 0($t0)
	addi $t0, $zero, 0
	add $v0, $zero, $s-1
	jr $ra
	jr $ra

main:
	addi $t6, $zero, 2
	add $s1, $zero, $t6
	addi $t6, $zero, 4
	add $s2, $zero, $t6
	.data
		string_597922464: .asciiz "hello world "
	.text
	la $a0, string_597922464
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s1
	addi $v0, $zero, 1
	syscall
	.data
		string_597922320: .asciiz " this is fun "
	.text
	la $a0, string_597922320
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $s2
	addi $v0, $zero, 1
	syscall
	addi $t6, $zero, 6
	.data
		string_597922208: .asciiz " "
	.text
	la $a0, string_597922208
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t6
	addi $v0, $zero, 1
	syscall
	addi $t6, $zero, 7
	.data
		string_597922128: .asciiz " "
	.text
	la $a0, string_597922128
	addi $v0, $zero, 4
	syscall
	add $a0, $zero, $t6
	addi $v0, $zero, 1
	syscall
	addi $t6, $zero, 766
	.data
		string_597922080: .asciiz " "
	.text
	la $a0, string_597922080
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
	addi $t6, $zero, 0
	add $v0, $zero, $t6

	addi $v0, $zero, 10
	syscall

# BLOCO DE DEFINES NO FIM DO ARQUIVO
.data
	c1: .word 10
	c2: .word -10
	c3: .word 40
	c4: .word -10
	NULL: .word 0
	CALL_ELEVEN: .word 11
# END BLOCO DEFINES