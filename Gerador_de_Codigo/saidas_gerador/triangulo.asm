
>>>>>>>> End Parse <<<<<<<<
AST 0x4aeb720

.data
	MAX: .word 100 # define
	AAA: .space 400 # global array
	max: .word 0
.text

nada_faz:
	addi $sp, $sp, -52
	sw $a0, 0($sp)
	sw $a1, 4($sp)
	sw $a2, 8($sp)
	sw $a3, 12($sp)
	sw $s0, 16($sp)
	sw $s1, 20($sp)
	sw $s2, 24($sp)
	sw $s3, 28($sp)
	sw $s4, 32($sp)
	sw $s5, 36($sp)
	sw $s6, 40($sp)
	sw $s7, 44($sp)
	sw $ra, 48($sp)

>>>>>>> 0x4ac70a0 0x4a91040 0x4aaf250 0x4aeb720 0x4ac7140
