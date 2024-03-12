# Gerado por: Gerador de Codigo do Marco Tulio 202100560105
.text
.globl main


.data
	v10: .word 0
	v01: .word 0
	v20: .word 0
	v11: .word 0
	v02: .word 0
	v21: .word 0
	a: .space 400 # global array
	v12: .word 0
	v03: .word 0
	v22: .word 0
	v13: .word 0
	v04: .word 0
	v23: .word 0
	v14: .word 0
	v05: .word 0
	v24: .word 0
	v15: .word 0
	v06: .word 0
	v25: .word 0
	v16: .word 0
	v07: .word 0
	v17: .word 0
	v08: .word 0
	v18: .word 0
	v09: .word 0
	v19: .word 0
.text


GenValue:
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

	#loading 1 params
	add $s0, $zero, $a0
	add $v0, $zero, $s0

	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $s0, 16($sp)
	lw $s1, 20($sp)
	lw $s2, 24($sp)
	lw $s3, 28($sp)
	lw $s4, 32($sp)
	lw $s5, 36($sp)
	lw $s6, 40($sp)
	lw $s7, 44($sp)
	lw $ra, 48($sp)
	addi $sp, $sp, 52

	jr $ra

	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $s0, 16($sp)
	lw $s1, 20($sp)
	lw $s2, 24($sp)
	lw $s3, 28($sp)
	lw $s4, 32($sp)
	lw $s5, 36($sp)
	lw $s6, 40($sp)
	lw $s7, 44($sp)
	lw $ra, 48($sp)
	addi $sp, $sp, 52

	jr $ra

Panic:
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

	.data
		string_119168176: .asciiz "\n\n"
	.text
	la $a0, string_119168176
	addi $v0, $zero, 4
	syscall
	.data
		string_119168016: .asciiz "                 "
	.text
	la $a0, string_119168016
	addi $v0, $zero, 4
	syscall
	.data
		string_119167856: .asciiz "#######\n"
	.text
	la $a0, string_119167856
	addi $v0, $zero, 4
	syscall
	.data
		string_119167696: .asciiz "             "
	.text
	la $a0, string_119167696
	addi $v0, $zero, 4
	syscall
	.data
		string_119167536: .asciiz "###############\n"
	.text
	la $a0, string_119167536
	addi $v0, $zero, 4
	syscall
	.data
		string_119167376: .asciiz "          "
	.text
	la $a0, string_119167376
	addi $v0, $zero, 4
	syscall
	.data
		string_119167216: .asciiz "#####################\n"
	.text
	la $a0, string_119167216
	addi $v0, $zero, 4
	syscall
	.data
		string_119167040: .asciiz "         "
	.text
	la $a0, string_119167040
	addi $v0, $zero, 4
	syscall
	.data
		string_119166880: .asciiz "#######################\n"
	.text
	la $a0, string_119166880
	addi $v0, $zero, 4
	syscall
	.data
		string_119166704: .asciiz "        "
	.text
	la $a0, string_119166704
	addi $v0, $zero, 4
	syscall
	.data
		string_119166544: .asciiz "#########################\n"
	.text
	la $a0, string_119166544
	addi $v0, $zero, 4
	syscall
	.data
		string_119166368: .asciiz "       "
	.text
	la $a0, string_119166368
	addi $v0, $zero, 4
	syscall
	.data
		string_119166208: .asciiz "###########################\n"
	.text
	la $a0, string_119166208
	addi $v0, $zero, 4
	syscall
	.data
		string_119166032: .asciiz "       "
	.text
	la $a0, string_119166032
	addi $v0, $zero, 4
	syscall
	.data
		string_119165872: .asciiz "###########################\n"
	.text
	la $a0, string_119165872
	addi $v0, $zero, 4
	syscall
	.data
		string_119165696: .asciiz "       "
	.text
	la $a0, string_119165696
	addi $v0, $zero, 4
	syscall
	.data
		string_119165536: .asciiz "########"
	.text
	la $a0, string_119165536
	addi $v0, $zero, 4
	syscall
	.data
		string_119165376: .asciiz "   "
	.text
	la $a0, string_119165376
	addi $v0, $zero, 4
	syscall
	.data
		string_119165216: .asciiz "#####"
	.text
	la $a0, string_119165216
	addi $v0, $zero, 4
	syscall
	.data
		string_119165056: .asciiz "   "
	.text
	la $a0, string_119165056
	addi $v0, $zero, 4
	syscall
	.data
		string_119164896: .asciiz "########\n"
	.text
	la $a0, string_119164896
	addi $v0, $zero, 4
	syscall
	.data
		string_119164736: .asciiz "       "
	.text
	la $a0, string_119164736
	addi $v0, $zero, 4
	syscall
	.data
		string_119164576: .asciiz "######"
	.text
	la $a0, string_119164576
	addi $v0, $zero, 4
	syscall
	.data
		string_119164416: .asciiz "      "
	.text
	la $a0, string_119164416
	addi $v0, $zero, 4
	syscall
	.data
		string_119164256: .asciiz "###"
	.text
	la $a0, string_119164256
	addi $v0, $zero, 4
	syscall
	.data
		string_119164096: .asciiz "       "
	.text
	la $a0, string_119164096
	addi $v0, $zero, 4
	syscall
	.data
		string_119163936: .asciiz "#####\n"
	.text
	la $a0, string_119163936
	addi $v0, $zero, 4
	syscall
	.data
		string_119153744: .asciiz "        "
	.text
	la $a0, string_119153744
	addi $v0, $zero, 4
	syscall
	.data
		string_119153584: .asciiz "####"
	.text
	la $a0, string_119153584
	addi $v0, $zero, 4
	syscall
	.data
		string_119153424: .asciiz "       "
	.text
	la $a0, string_119153424
	addi $v0, $zero, 4
	syscall
	.data
		string_119153264: .asciiz "###"
	.text
	la $a0, string_119153264
	addi $v0, $zero, 4
	syscall
	.data
		string_119153104: .asciiz "       "
	.text
	la $a0, string_119153104
	addi $v0, $zero, 4
	syscall
	.data
		string_119152944: .asciiz "####\n"
	.text
	la $a0, string_119152944
	addi $v0, $zero, 4
	syscall
	.data
		string_119152784: .asciiz "        "
	.text
	la $a0, string_119152784
	addi $v0, $zero, 4
	syscall
	.data
		string_119152624: .asciiz "####"
	.text
	la $a0, string_119152624
	addi $v0, $zero, 4
	syscall
	.data
		string_119152464: .asciiz "      "
	.text
	la $a0, string_119152464
	addi $v0, $zero, 4
	syscall
	.data
		string_119152304: .asciiz "#####"
	.text
	la $a0, string_119152304
	addi $v0, $zero, 4
	syscall
	.data
		string_119152144: .asciiz "      "
	.text
	la $a0, string_119152144
	addi $v0, $zero, 4
	syscall
	.data
		string_119151984: .asciiz "####\n"
	.text
	la $a0, string_119151984
	addi $v0, $zero, 4
	syscall
	.data
		string_119151824: .asciiz "         "
	.text
	la $a0, string_119151824
	addi $v0, $zero, 4
	syscall
	.data
		string_119151664: .asciiz "##########"
	.text
	la $a0, string_119151664
	addi $v0, $zero, 4
	syscall
	.data
		string_119151504: .asciiz "   "
	.text
	la $a0, string_119151504
	addi $v0, $zero, 4
	syscall
	.data
		string_119151344: .asciiz "##########\n"
	.text
	la $a0, string_119151344
	addi $v0, $zero, 4
	syscall
	.data
		string_119151184: .asciiz "          "
	.text
	la $a0, string_119151184
	addi $v0, $zero, 4
	syscall
	.data
		string_119151024: .asciiz "#########"
	.text
	la $a0, string_119151024
	addi $v0, $zero, 4
	syscall
	.data
		string_119150864: .asciiz "   "
	.text
	la $a0, string_119150864
	addi $v0, $zero, 4
	syscall
	.data
		string_119150704: .asciiz "#########\n"
	.text
	la $a0, string_119150704
	addi $v0, $zero, 4
	syscall
	.data
		string_119150544: .asciiz "            "
	.text
	la $a0, string_119150544
	addi $v0, $zero, 4
	syscall
	.data
		string_119150384: .asciiz "#################\n"
	.text
	la $a0, string_119150384
	addi $v0, $zero, 4
	syscall
	.data
		string_119150224: .asciiz "             "
	.text
	la $a0, string_119150224
	addi $v0, $zero, 4
	syscall
	.data
		string_119150064: .asciiz "###############\n"
	.text
	la $a0, string_119150064
	addi $v0, $zero, 4
	syscall
	.data
		string_119149904: .asciiz "  "
	.text
	la $a0, string_119149904
	addi $v0, $zero, 4
	syscall
	.data
		string_119149744: .asciiz "###        "
	.text
	la $a0, string_119149744
	addi $v0, $zero, 4
	syscall
	.data
		string_119149584: .asciiz "####"
	.text
	la $a0, string_119149584
	addi $v0, $zero, 4
	syscall
	.data
		string_119149424: .asciiz " "
	.text
	la $a0, string_119149424
	addi $v0, $zero, 4
	syscall
	.data
		string_119149264: .asciiz "#"
	.text
	la $a0, string_119149264
	addi $v0, $zero, 4
	syscall
	.data
		string_119149104: .asciiz " "
	.text
	la $a0, string_119149104
	addi $v0, $zero, 4
	syscall
	.data
		string_119148944: .asciiz "#"
	.text
	la $a0, string_119148944
	addi $v0, $zero, 4
	syscall
	.data
		string_119148784: .asciiz " "
	.text
	la $a0, string_119148784
	addi $v0, $zero, 4
	syscall
	.data
		string_119148624: .asciiz "#"
	.text
	la $a0, string_119148624
	addi $v0, $zero, 4
	syscall
	.data
		string_119163808: .asciiz " "
	.text
	la $a0, string_119163808
	addi $v0, $zero, 4
	syscall
	.data
		string_119163648: .asciiz "####"
	.text
	la $a0, string_119163648
	addi $v0, $zero, 4
	syscall
	.data
		string_119163488: .asciiz "       "
	.text
	la $a0, string_119163488
	addi $v0, $zero, 4
	syscall
	.data
		string_119163328: .asciiz "###\n"
	.text
	la $a0, string_119163328
	addi $v0, $zero, 4
	syscall
	.data
		string_119163168: .asciiz " "
	.text
	la $a0, string_119163168
	addi $v0, $zero, 4
	syscall
	.data
		string_119163008: .asciiz "#####"
	.text
	la $a0, string_119163008
	addi $v0, $zero, 4
	syscall
	.data
		string_119162848: .asciiz "        "
	.text
	la $a0, string_119162848
	addi $v0, $zero, 4
	syscall
	.data
		string_119162688: .asciiz "#############"
	.text
	la $a0, string_119162688
	addi $v0, $zero, 4
	syscall
	.data
		string_119162528: .asciiz "       "
	.text
	la $a0, string_119162528
	addi $v0, $zero, 4
	syscall
	.data
		string_119162368: .asciiz "#####\n"
	.text
	la $a0, string_119162368
	addi $v0, $zero, 4
	syscall
	.data
		string_119162208: .asciiz "  "
	.text
	la $a0, string_119162208
	addi $v0, $zero, 4
	syscall
	.data
		string_119162048: .asciiz "#######"
	.text
	la $a0, string_119162048
	addi $v0, $zero, 4
	syscall
	.data
		string_119161888: .asciiz "      "
	.text
	la $a0, string_119161888
	addi $v0, $zero, 4
	syscall
	.data
		string_119161728: .asciiz "###########"
	.text
	la $a0, string_119161728
	addi $v0, $zero, 4
	syscall
	.data
		string_119161568: .asciiz "     "
	.text
	la $a0, string_119161568
	addi $v0, $zero, 4
	syscall
	.data
		string_119161408: .asciiz "########\n"
	.text
	la $a0, string_119161408
	addi $v0, $zero, 4
	syscall
	.data
		string_119161248: .asciiz "##############"
	.text
	la $a0, string_119161248
	addi $v0, $zero, 4
	syscall
	.data
		string_119161088: .asciiz "    "
	.text
	la $a0, string_119161088
	addi $v0, $zero, 4
	syscall
	.data
		string_119160928: .asciiz "#####"
	.text
	la $a0, string_119160928
	addi $v0, $zero, 4
	syscall
	.data
		string_119160768: .asciiz "    "
	.text
	la $a0, string_119160768
	addi $v0, $zero, 4
	syscall
	.data
		string_119160608: .asciiz "##############\n"
	.text
	la $a0, string_119160608
	addi $v0, $zero, 4
	syscall
	.data
		string_119160448: .asciiz "####################"
	.text
	la $a0, string_119160448
	addi $v0, $zero, 4
	syscall
	.data
		string_119160288: .asciiz "   "
	.text
	la $a0, string_119160288
	addi $v0, $zero, 4
	syscall
	.data
		string_119160128: .asciiz "##################\n"
	.text
	la $a0, string_119160128
	addi $v0, $zero, 4
	syscall
	.data
		string_119159968: .asciiz " "
	.text
	la $a0, string_119159968
	addi $v0, $zero, 4
	syscall
	.data
		string_119159808: .asciiz "###"
	.text
	la $a0, string_119159808
	addi $v0, $zero, 4
	syscall
	.data
		string_119159648: .asciiz "      "
	.text
	la $a0, string_119159648
	addi $v0, $zero, 4
	syscall
	.data
		string_119159488: .asciiz "###############"
	.text
	la $a0, string_119159488
	addi $v0, $zero, 4
	syscall
	.data
		string_119159328: .asciiz " "
	.text
	la $a0, string_119159328
	addi $v0, $zero, 4
	syscall
	.data
		string_119159168: .asciiz "######\n"
	.text
	la $a0, string_119159168
	addi $v0, $zero, 4
	syscall
	.data
		string_119159008: .asciiz "           "
	.text
	la $a0, string_119159008
	addi $v0, $zero, 4
	syscall
	.data
		string_119158848: .asciiz "####"
	.text
	la $a0, string_119158848
	addi $v0, $zero, 4
	syscall
	.data
		string_119158688: .asciiz " "
	.text
	la $a0, string_119158688
	addi $v0, $zero, 4
	syscall
	.data
		string_119158528: .asciiz "###############\n"
	.text
	la $a0, string_119158528
	addi $v0, $zero, 4
	syscall
	.data
		string_119158368: .asciiz "  "
	.text
	la $a0, string_119158368
	addi $v0, $zero, 4
	syscall
	.data
		string_119158208: .asciiz "##################"
	.text
	la $a0, string_119158208
	addi $v0, $zero, 4
	syscall
	.data
		string_119158048: .asciiz " "
	.text
	la $a0, string_119158048
	addi $v0, $zero, 4
	syscall
	.data
		string_119157888: .asciiz "###################\n"
	.text
	la $a0, string_119157888
	addi $v0, $zero, 4
	syscall
	.data
		string_119157728: .asciiz "  "
	.text
	la $a0, string_119157728
	addi $v0, $zero, 4
	syscall
	.data
		string_119157568: .asciiz "##############"
	.text
	la $a0, string_119157568
	addi $v0, $zero, 4
	syscall
	.data
		string_119157408: .asciiz "           "
	.text
	la $a0, string_119157408
	addi $v0, $zero, 4
	syscall
	.data
		string_119157248: .asciiz "##############\n"
	.text
	la $a0, string_119157248
	addi $v0, $zero, 4
	syscall
	.data
		string_119157088: .asciiz "   "
	.text
	la $a0, string_119157088
	addi $v0, $zero, 4
	syscall
	.data
		string_119156928: .asciiz "#######"
	.text
	la $a0, string_119156928
	addi $v0, $zero, 4
	syscall
	.data
		string_119156768: .asciiz "                      "
	.text
	la $a0, string_119156768
	addi $v0, $zero, 4
	syscall
	.data
		string_119156592: .asciiz "########\n"
	.text
	la $a0, string_119156592
	addi $v0, $zero, 4
	syscall
	.data
		string_119156432: .asciiz "     "
	.text
	la $a0, string_119156432
	addi $v0, $zero, 4
	syscall
	.data
		string_119156272: .asciiz "####"
	.text
	la $a0, string_119156272
	addi $v0, $zero, 4
	syscall
	.data
		string_119156112: .asciiz "                         "
	.text
	la $a0, string_119156112
	addi $v0, $zero, 4
	syscall
	.data
		string_119155936: .asciiz "#####\n"
	.text
	la $a0, string_119155936
	addi $v0, $zero, 4
	syscall
	.data
		string_119155776: .asciiz "\n\nFATAL ERROR: O codigo assembly gerado possui ao menos um Erro.\n"
	.text
	la $a0, string_119155776
	addi $v0, $zero, 4
	syscall
	addi $t0, $zero, 666
	# exit with status 666
	addi $v0, $zero, 10
	syscall

	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $s0, 16($sp)
	lw $s1, 20($sp)
	lw $s2, 24($sp)
	lw $s3, 28($sp)
	lw $s4, 32($sp)
	lw $s5, 36($sp)
	lw $s6, 40($sp)
	lw $s7, 44($sp)
	lw $ra, 48($sp)
	addi $sp, $sp, 52

	jr $ra

PopulateArray:
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

	la $t0, v01
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v01
	sw $t0, 0($t1)
	la $t0, v02
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v02
	sw $t0, 0($t1)
	la $t0, v03
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v03
	sw $t0, 0($t1)
	la $t0, v04
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v04
	sw $t0, 0($t1)
	la $t0, v05
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v05
	sw $t0, 0($t1)
	la $t0, v06
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v06
	sw $t0, 0($t1)
	la $t0, v07
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v07
	sw $t0, 0($t1)
	la $t0, v08
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v08
	sw $t0, 0($t1)
	la $t0, v09
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v09
	sw $t0, 0($t1)
	la $t0, v10
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v10
	sw $t0, 0($t1)
	la $t0, v11
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v11
	sw $t0, 0($t1)
	la $t0, v12
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v12
	sw $t0, 0($t1)
	la $t0, v13
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v13
	sw $t0, 0($t1)
	la $t0, v14
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v14
	sw $t0, 0($t1)
	la $t0, v15
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v15
	sw $t0, 0($t1)
	la $t0, v16
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v16
	sw $t0, 0($t1)
	la $t0, v17
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v17
	sw $t0, 0($t1)
	la $t0, v18
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v18
	sw $t0, 0($t1)
	la $t0, v19
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v19
	sw $t0, 0($t1)
	la $t0, v20
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v20
	sw $t0, 0($t1)
	la $t0, v21
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v21
	sw $t0, 0($t1)
	la $t0, v22
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v22
	sw $t0, 0($t1)
	la $t0, v23
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v23
	sw $t0, 0($t1)
	la $t0, v24
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v24
	sw $t0, 0($t1)
	la $t0, v25
	lw $t1, 0($t0)
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	la $t1, v25
	sw $t0, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 0
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 0
	addi $t1, $zero, 2
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 3
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 4
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 5
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 6
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 7
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 8
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 0
	addi $t1, $zero, 9
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 1
	srlv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 2
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 3
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 4
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 5
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 6
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 7
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 8
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 5
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 9
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 1
	srlv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 2
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 3
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 4
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 5
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 6
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 7
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 8
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 10
	addi $t1, $zero, 1
	sllv $t2, $t0, $t1
	addi $t0, $zero, 9
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 1
	srlv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 2
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 3
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 4
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 5
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 6
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 7
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 8
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 60
	addi $t1, $zero, 1
	srlv $t2, $t0, $t1
	addi $t0, $zero, 9
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 40
	addi $t1, $zero, 10
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 1
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 2
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 3
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 4
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 5
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 6
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 7
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 8
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 40
	addi $t1, $zero, 9
	addi $t2, $zero, 10
	div $t1, $t2
	mfhi $t1
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 0
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 1
	srlv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 2
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 3
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 4
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 5
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 6
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 7
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 8
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 186
	addi $t1, $zero, 55
	and $t2, $t0, $t1
	addi $t0, $zero, 9
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 0
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 1
	srlv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 1
	addi $t1, $zero, 1
	sllv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 6
	addi $t1, $zero, 1
	srlv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 1
	sllv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 1
	sllv $t3, $t0, $t1
	add $t0, $t2, $t3
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 3
	addi $t1, $zero, 1
	sllv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 3
	addi $t1, $zero, 1
	sllv $t3, $t0, $t1
	add $t0, $t2, $t3
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 2
	sllv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 48
	addi $t1, $zero, 12
	or $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 2
	sllv $t3, $t0, $t1
	add $t0, $t2, $t3
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 0
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 2
	addi $t1, $zero, 1
	srlv $t3, $t0, $t1
	add $t0, $t2, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 2
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 3
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 4
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 5
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 6
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 7
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 8
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 173
	addi $t1, $zero, 235
	xor $t2, $t0, $t1
	addi $t0, $zero, 9
	add $t1, $t2, $t0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	sllv $t2, $t1, $t4
	sub $t1, $t0, $t2
	addi $t0, $zero, 0
	add $t2, $t1, $t0
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	sllv $t2, $t1, $t4
	sub $t1, $t0, $t2
	addi $t0, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t0, $t2
	add $t0, $t1, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	sllv $t2, $t1, $t4
	sub $t1, $t0, $t2
	addi $t0, $zero, 1
	addi $t2, $zero, 1
	sllv $t3, $t0, $t2
	add $t0, $t1, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	sllv $t2, $t1, $t4
	sub $t1, $t0, $t2
	addi $t0, $zero, 6
	addi $t2, $zero, 1
	srlv $t3, $t0, $t2
	add $t0, $t1, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	sub $t1, $t0, $t3
	addi $t0, $zero, 2
	addi $t2, $zero, 1
	sllv $t3, $t0, $t2
	add $t0, $t1, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	sub $t1, $t0, $t3
	addi $t0, $zero, 2
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	sllv $t2, $t0, $t4
	add $t0, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	sub $t1, $t0, $t3
	addi $t0, $zero, 3
	addi $t2, $zero, 1
	sllv $t3, $t0, $t2
	add $t0, $t1, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	sub $t1, $t0, $t3
	addi $t0, $zero, 3
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	sllv $t2, $t0, $t4
	add $t0, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	sub $t1, $t0, $t3
	addi $t0, $zero, 2
	addi $t2, $zero, 2
	sllv $t3, $t0, $t2
	add $t0, $t1, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	sub $t1, $t0, $t3
	addi $t0, $zero, 2
	addi $t2, $zero, 2
	sllv $t3, $t0, $t2
	add $t0, $t1, $t3
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 0
	add $t2, $t0, $t1
	la $t0, a
	sll $t1, $t2, 2
	add $t1, $t1, $t0
	la $t0, v01
	lw $t2, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v03
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v05
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v07
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v09
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v11
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v13
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v15
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v17
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v19
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v21
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v23
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t2, $t3
	la $t2, v25
	lw $t3, 0($t2)
	add $t2, $t0, $t3
	sw $t2, 0($t1)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 1
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 6
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 2
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	sllv $t2, $t1, $t4
	add $t1, $t0, $t2
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	add $t1, $t0, $t3
	addi $t0, $zero, 2
	addi $t2, $zero, 2
	addi $t3, $zero, 2
	addi $t4, $zero, 1
	srlv $t5, $t3, $t4
	srlv $t3, $t2, $t5
	srlv $t2, $t0, $t3
	add $t0, $t1, $t2
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 3
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 3
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	add $t1, $t0, $t3
	addi $t0, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t0, $t2
	add $t0, $t1, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 2
	addi $t2, $zero, 2
	sllv $t3, $t1, $t2
	add $t1, $t0, $t3
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)
	addi $t0, $zero, 91
	sub $t1, $zero, $t0
	not $t0, $t1
	addi $t1, $zero, 2
	addi $t2, $zero, 2
	sllv $t3, $t1, $t2
	add $t1, $t0, $t3
	addi $t0, $zero, 2
	addi $t2, $zero, 1
	srlv $t3, $t0, $t2
	add $t0, $t1, $t3
	la $t1, a
	sll $t2, $t0, 2
	add $t2, $t2, $t1
	la $t0, v01
	lw $t1, 0($t0)
	la $t0, v02
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v03
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v04
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v05
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v06
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v07
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v08
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v09
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v10
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v11
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v12
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v13
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v14
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v15
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v16
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v17
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v18
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v19
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v20
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v21
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v22
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v23
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	la $t0, v24
	lw $t3, 0($t0)
	add $t0, $t1, $t3
	la $t1, v25
	lw $t3, 0($t1)
	add $t1, $t0, $t3
	sw $t1, 0($t2)

	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $s0, 16($sp)
	lw $s1, 20($sp)
	lw $s2, 24($sp)
	lw $s3, 28($sp)
	lw $s4, 32($sp)
	lw $s5, 36($sp)
	lw $s6, 40($sp)
	lw $s7, 44($sp)
	lw $ra, 48($sp)
	addi $sp, $sp, 52

	jr $ra

ASSERT:
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

	#loading 2 params
	add $s0, $zero, $a0
	add $s1, $zero, $a1
	sub $t0, $s1, $s0
	beqz $t0, else_113398304
	jal Panic
	add $t0, $zero, $v0
	j exit_if_113398304
	else_113398304:
	exit_if_113398304:

	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $s0, 16($sp)
	lw $s1, 20($sp)
	lw $s2, 24($sp)
	lw $s3, 28($sp)
	lw $s4, 32($sp)
	lw $s5, 36($sp)
	lw $s6, 40($sp)
	lw $s7, 44($sp)
	lw $ra, 48($sp)
	addi $sp, $sp, 52

	jr $ra

main:
	addi $t0, $zero, 0
	add $s0, $zero, $t0
	j for_teste_113201936
	for_corpo_113201936:
	la $t0, a
	sll $t1, $s0, 2
	add $t1, $t1, $t0
	addi $t0, $zero, 0
	sw $t0, 0($t1)
	add $t0, $zero, $s0
	addi $s0, $s0, 1
	for_teste_113201936:
	addi $t1, $zero, 100
	slt $t2, $s0, $t1
	bnez $t2, for_corpo_113201936
	jal PopulateArray
	add $t1, $zero, $v0
	addi $t2, $zero, 0
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $s0, $zero, $t2
	j for_teste_113202128
	for_corpo_113202128:
	la $t2, a
	sll $t3, $s0, 2
	add $t3, $t3, $t2
	lw $t2, 0($t3)
	add $a1, $zero, $t2 # function param v1
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	addi $t3, $zero, 1
	add $a0, $zero, $t3 # function param i
	jal GenValue
	add $t3, $zero, $v0
	add $t4, $t2, $t3
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t4, $t3, $t2
	addi $t2, $zero, 1
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $t3, $t4, $t2
	add $a0, $zero, $t3 # function param v2
	jal ASSERT
	add $t2, $zero, $v0
	addi $t3, $zero, 1
	add $a0, $zero, $t3 # function param i
	jal GenValue
	add $t3, $zero, $v0
	add $t4, $s0, $t3
	add $s0, $zero, $t4
	for_teste_113202128:
	addi $t3, $zero, 100
	add $a0, $zero, $t3 # function param i
	jal GenValue
	add $t3, $zero, $v0
	slt $t4, $s0, $t3
	bnez $t4, for_corpo_113202128
	.data
		string_113203472: .asciiz "O codigo assembly gerado funcionou como o esperado."
	.text
	la $a0, string_113203472
	addi $v0, $zero, 4
	syscall
	addi $t3, $zero, 666
	add $v0, $zero, $t3

	addi $v0, $zero, 10
	syscall
