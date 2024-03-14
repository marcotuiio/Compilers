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
		string_230396752: .asciiz "\n\n"
	.text
	la $a0, string_230396752
	addi $v0, $zero, 4
	syscall
	.data
		string_230396912: .asciiz "                 "
	.text
	la $a0, string_230396912
	addi $v0, $zero, 4
	syscall
	.data
		string_230397072: .asciiz "#######\n"
	.text
	la $a0, string_230397072
	addi $v0, $zero, 4
	syscall
	.data
		string_230397232: .asciiz "             "
	.text
	la $a0, string_230397232
	addi $v0, $zero, 4
	syscall
	.data
		string_230397392: .asciiz "###############\n"
	.text
	la $a0, string_230397392
	addi $v0, $zero, 4
	syscall
	.data
		string_230397552: .asciiz "          "
	.text
	la $a0, string_230397552
	addi $v0, $zero, 4
	syscall
	.data
		string_230397712: .asciiz "#####################\n"
	.text
	la $a0, string_230397712
	addi $v0, $zero, 4
	syscall
	.data
		string_230397888: .asciiz "         "
	.text
	la $a0, string_230397888
	addi $v0, $zero, 4
	syscall
	.data
		string_230398048: .asciiz "#######################\n"
	.text
	la $a0, string_230398048
	addi $v0, $zero, 4
	syscall
	.data
		string_230398224: .asciiz "        "
	.text
	la $a0, string_230398224
	addi $v0, $zero, 4
	syscall
	.data
		string_230398384: .asciiz "#########################\n"
	.text
	la $a0, string_230398384
	addi $v0, $zero, 4
	syscall
	.data
		string_230398560: .asciiz "       "
	.text
	la $a0, string_230398560
	addi $v0, $zero, 4
	syscall
	.data
		string_230398720: .asciiz "###########################\n"
	.text
	la $a0, string_230398720
	addi $v0, $zero, 4
	syscall
	.data
		string_230398896: .asciiz "       "
	.text
	la $a0, string_230398896
	addi $v0, $zero, 4
	syscall
	.data
		string_230399056: .asciiz "###########################\n"
	.text
	la $a0, string_230399056
	addi $v0, $zero, 4
	syscall
	.data
		string_230399232: .asciiz "       "
	.text
	la $a0, string_230399232
	addi $v0, $zero, 4
	syscall
	.data
		string_230399392: .asciiz "########"
	.text
	la $a0, string_230399392
	addi $v0, $zero, 4
	syscall
	.data
		string_230399552: .asciiz "   "
	.text
	la $a0, string_230399552
	addi $v0, $zero, 4
	syscall
	.data
		string_230399712: .asciiz "#####"
	.text
	la $a0, string_230399712
	addi $v0, $zero, 4
	syscall
	.data
		string_230399872: .asciiz "   "
	.text
	la $a0, string_230399872
	addi $v0, $zero, 4
	syscall
	.data
		string_230400032: .asciiz "########\n"
	.text
	la $a0, string_230400032
	addi $v0, $zero, 4
	syscall
	.data
		string_230400192: .asciiz "       "
	.text
	la $a0, string_230400192
	addi $v0, $zero, 4
	syscall
	.data
		string_230400352: .asciiz "######"
	.text
	la $a0, string_230400352
	addi $v0, $zero, 4
	syscall
	.data
		string_230400512: .asciiz "      "
	.text
	la $a0, string_230400512
	addi $v0, $zero, 4
	syscall
	.data
		string_230400672: .asciiz "###"
	.text
	la $a0, string_230400672
	addi $v0, $zero, 4
	syscall
	.data
		string_230400832: .asciiz "       "
	.text
	la $a0, string_230400832
	addi $v0, $zero, 4
	syscall
	.data
		string_230400992: .asciiz "#####\n"
	.text
	la $a0, string_230400992
	addi $v0, $zero, 4
	syscall
	.data
		string_230411184: .asciiz "        "
	.text
	la $a0, string_230411184
	addi $v0, $zero, 4
	syscall
	.data
		string_230411344: .asciiz "####"
	.text
	la $a0, string_230411344
	addi $v0, $zero, 4
	syscall
	.data
		string_230411504: .asciiz "       "
	.text
	la $a0, string_230411504
	addi $v0, $zero, 4
	syscall
	.data
		string_230411664: .asciiz "###"
	.text
	la $a0, string_230411664
	addi $v0, $zero, 4
	syscall
	.data
		string_230411824: .asciiz "       "
	.text
	la $a0, string_230411824
	addi $v0, $zero, 4
	syscall
	.data
		string_230411984: .asciiz "####\n"
	.text
	la $a0, string_230411984
	addi $v0, $zero, 4
	syscall
	.data
		string_230412144: .asciiz "        "
	.text
	la $a0, string_230412144
	addi $v0, $zero, 4
	syscall
	.data
		string_230412304: .asciiz "####"
	.text
	la $a0, string_230412304
	addi $v0, $zero, 4
	syscall
	.data
		string_230412464: .asciiz "      "
	.text
	la $a0, string_230412464
	addi $v0, $zero, 4
	syscall
	.data
		string_230412624: .asciiz "#####"
	.text
	la $a0, string_230412624
	addi $v0, $zero, 4
	syscall
	.data
		string_230412784: .asciiz "      "
	.text
	la $a0, string_230412784
	addi $v0, $zero, 4
	syscall
	.data
		string_230412944: .asciiz "####\n"
	.text
	la $a0, string_230412944
	addi $v0, $zero, 4
	syscall
	.data
		string_230413104: .asciiz "         "
	.text
	la $a0, string_230413104
	addi $v0, $zero, 4
	syscall
	.data
		string_230413264: .asciiz "##########"
	.text
	la $a0, string_230413264
	addi $v0, $zero, 4
	syscall
	.data
		string_230413424: .asciiz "   "
	.text
	la $a0, string_230413424
	addi $v0, $zero, 4
	syscall
	.data
		string_230413584: .asciiz "##########\n"
	.text
	la $a0, string_230413584
	addi $v0, $zero, 4
	syscall
	.data
		string_230413744: .asciiz "          "
	.text
	la $a0, string_230413744
	addi $v0, $zero, 4
	syscall
	.data
		string_230413904: .asciiz "#########"
	.text
	la $a0, string_230413904
	addi $v0, $zero, 4
	syscall
	.data
		string_230414064: .asciiz "   "
	.text
	la $a0, string_230414064
	addi $v0, $zero, 4
	syscall
	.data
		string_230414224: .asciiz "#########\n"
	.text
	la $a0, string_230414224
	addi $v0, $zero, 4
	syscall
	.data
		string_230414384: .asciiz "            "
	.text
	la $a0, string_230414384
	addi $v0, $zero, 4
	syscall
	.data
		string_230414544: .asciiz "#################\n"
	.text
	la $a0, string_230414544
	addi $v0, $zero, 4
	syscall
	.data
		string_230414704: .asciiz "             "
	.text
	la $a0, string_230414704
	addi $v0, $zero, 4
	syscall
	.data
		string_230414864: .asciiz "###############\n"
	.text
	la $a0, string_230414864
	addi $v0, $zero, 4
	syscall
	.data
		string_230415024: .asciiz "  "
	.text
	la $a0, string_230415024
	addi $v0, $zero, 4
	syscall
	.data
		string_230415184: .asciiz "###        "
	.text
	la $a0, string_230415184
	addi $v0, $zero, 4
	syscall
	.data
		string_230415344: .asciiz "####"
	.text
	la $a0, string_230415344
	addi $v0, $zero, 4
	syscall
	.data
		string_230415504: .asciiz " "
	.text
	la $a0, string_230415504
	addi $v0, $zero, 4
	syscall
	.data
		string_230415664: .asciiz "#"
	.text
	la $a0, string_230415664
	addi $v0, $zero, 4
	syscall
	.data
		string_230415824: .asciiz " "
	.text
	la $a0, string_230415824
	addi $v0, $zero, 4
	syscall
	.data
		string_230415984: .asciiz "#"
	.text
	la $a0, string_230415984
	addi $v0, $zero, 4
	syscall
	.data
		string_230416144: .asciiz " "
	.text
	la $a0, string_230416144
	addi $v0, $zero, 4
	syscall
	.data
		string_230416304: .asciiz "#"
	.text
	la $a0, string_230416304
	addi $v0, $zero, 4
	syscall
	.data
		string_230401120: .asciiz " "
	.text
	la $a0, string_230401120
	addi $v0, $zero, 4
	syscall
	.data
		string_230401280: .asciiz "####"
	.text
	la $a0, string_230401280
	addi $v0, $zero, 4
	syscall
	.data
		string_230401440: .asciiz "       "
	.text
	la $a0, string_230401440
	addi $v0, $zero, 4
	syscall
	.data
		string_230401600: .asciiz "###\n"
	.text
	la $a0, string_230401600
	addi $v0, $zero, 4
	syscall
	.data
		string_230401760: .asciiz " "
	.text
	la $a0, string_230401760
	addi $v0, $zero, 4
	syscall
	.data
		string_230401920: .asciiz "#####"
	.text
	la $a0, string_230401920
	addi $v0, $zero, 4
	syscall
	.data
		string_230402080: .asciiz "        "
	.text
	la $a0, string_230402080
	addi $v0, $zero, 4
	syscall
	.data
		string_230402240: .asciiz "#############"
	.text
	la $a0, string_230402240
	addi $v0, $zero, 4
	syscall
	.data
		string_230402400: .asciiz "       "
	.text
	la $a0, string_230402400
	addi $v0, $zero, 4
	syscall
	.data
		string_230402560: .asciiz "#####\n"
	.text
	la $a0, string_230402560
	addi $v0, $zero, 4
	syscall
	.data
		string_230402720: .asciiz "  "
	.text
	la $a0, string_230402720
	addi $v0, $zero, 4
	syscall
	.data
		string_230402880: .asciiz "#######"
	.text
	la $a0, string_230402880
	addi $v0, $zero, 4
	syscall
	.data
		string_230403040: .asciiz "      "
	.text
	la $a0, string_230403040
	addi $v0, $zero, 4
	syscall
	.data
		string_230403200: .asciiz "###########"
	.text
	la $a0, string_230403200
	addi $v0, $zero, 4
	syscall
	.data
		string_230403360: .asciiz "     "
	.text
	la $a0, string_230403360
	addi $v0, $zero, 4
	syscall
	.data
		string_230403520: .asciiz "########\n"
	.text
	la $a0, string_230403520
	addi $v0, $zero, 4
	syscall
	.data
		string_230403680: .asciiz "##############"
	.text
	la $a0, string_230403680
	addi $v0, $zero, 4
	syscall
	.data
		string_230403840: .asciiz "    "
	.text
	la $a0, string_230403840
	addi $v0, $zero, 4
	syscall
	.data
		string_230404000: .asciiz "#####"
	.text
	la $a0, string_230404000
	addi $v0, $zero, 4
	syscall
	.data
		string_230404160: .asciiz "    "
	.text
	la $a0, string_230404160
	addi $v0, $zero, 4
	syscall
	.data
		string_230404320: .asciiz "##############\n"
	.text
	la $a0, string_230404320
	addi $v0, $zero, 4
	syscall
	.data
		string_230404480: .asciiz "####################"
	.text
	la $a0, string_230404480
	addi $v0, $zero, 4
	syscall
	.data
		string_230404640: .asciiz "   "
	.text
	la $a0, string_230404640
	addi $v0, $zero, 4
	syscall
	.data
		string_230404800: .asciiz "##################\n"
	.text
	la $a0, string_230404800
	addi $v0, $zero, 4
	syscall
	.data
		string_230404960: .asciiz " "
	.text
	la $a0, string_230404960
	addi $v0, $zero, 4
	syscall
	.data
		string_230405120: .asciiz "###"
	.text
	la $a0, string_230405120
	addi $v0, $zero, 4
	syscall
	.data
		string_230405280: .asciiz "      "
	.text
	la $a0, string_230405280
	addi $v0, $zero, 4
	syscall
	.data
		string_230405440: .asciiz "###############"
	.text
	la $a0, string_230405440
	addi $v0, $zero, 4
	syscall
	.data
		string_230405600: .asciiz " "
	.text
	la $a0, string_230405600
	addi $v0, $zero, 4
	syscall
	.data
		string_230405760: .asciiz "######\n"
	.text
	la $a0, string_230405760
	addi $v0, $zero, 4
	syscall
	.data
		string_230405920: .asciiz "           "
	.text
	la $a0, string_230405920
	addi $v0, $zero, 4
	syscall
	.data
		string_230406080: .asciiz "####"
	.text
	la $a0, string_230406080
	addi $v0, $zero, 4
	syscall
	.data
		string_230406240: .asciiz " "
	.text
	la $a0, string_230406240
	addi $v0, $zero, 4
	syscall
	.data
		string_230406400: .asciiz "###############\n"
	.text
	la $a0, string_230406400
	addi $v0, $zero, 4
	syscall
	.data
		string_230406560: .asciiz "  "
	.text
	la $a0, string_230406560
	addi $v0, $zero, 4
	syscall
	.data
		string_230406720: .asciiz "##################"
	.text
	la $a0, string_230406720
	addi $v0, $zero, 4
	syscall
	.data
		string_230406880: .asciiz " "
	.text
	la $a0, string_230406880
	addi $v0, $zero, 4
	syscall
	.data
		string_230407040: .asciiz "###################\n"
	.text
	la $a0, string_230407040
	addi $v0, $zero, 4
	syscall
	.data
		string_230407200: .asciiz "  "
	.text
	la $a0, string_230407200
	addi $v0, $zero, 4
	syscall
	.data
		string_230407360: .asciiz "##############"
	.text
	la $a0, string_230407360
	addi $v0, $zero, 4
	syscall
	.data
		string_230407520: .asciiz "           "
	.text
	la $a0, string_230407520
	addi $v0, $zero, 4
	syscall
	.data
		string_230407680: .asciiz "##############\n"
	.text
	la $a0, string_230407680
	addi $v0, $zero, 4
	syscall
	.data
		string_230407840: .asciiz "   "
	.text
	la $a0, string_230407840
	addi $v0, $zero, 4
	syscall
	.data
		string_230408000: .asciiz "#######"
	.text
	la $a0, string_230408000
	addi $v0, $zero, 4
	syscall
	.data
		string_230408160: .asciiz "                      "
	.text
	la $a0, string_230408160
	addi $v0, $zero, 4
	syscall
	.data
		string_230408336: .asciiz "########\n"
	.text
	la $a0, string_230408336
	addi $v0, $zero, 4
	syscall
	.data
		string_230408496: .asciiz "     "
	.text
	la $a0, string_230408496
	addi $v0, $zero, 4
	syscall
	.data
		string_230408656: .asciiz "####"
	.text
	la $a0, string_230408656
	addi $v0, $zero, 4
	syscall
	.data
		string_230408816: .asciiz "                         "
	.text
	la $a0, string_230408816
	addi $v0, $zero, 4
	syscall
	.data
		string_230408992: .asciiz "#####\n"
	.text
	la $a0, string_230408992
	addi $v0, $zero, 4
	syscall
	.data
		string_230409152: .asciiz "\n\nFATAL ERROR: O codigo assembly gerado possui ao menos um Erro.\n"
	.text
	la $a0, string_230409152
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 0
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 3
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 4
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 5
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 6
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 7
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 8
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 0
	addi $t2, $zero, 9
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 2
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 3
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 4
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 5
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 6
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 7
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 8
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 5
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 9
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 2
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 3
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 4
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 5
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 6
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 7
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 8
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 10
	addi $t2, $zero, 1
	sllv $t3, $t1, $t2
	addi $t1, $zero, 9
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 2
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 3
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 4
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 5
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 6
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 7
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 8
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 60
	addi $t2, $zero, 1
	srlv $t3, $t1, $t2
	addi $t1, $zero, 9
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 10
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 1
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 2
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 3
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 4
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 5
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 6
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 7
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 8
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 40
	addi $t2, $zero, 9
	addi $t3, $zero, 10
	div $t2, $t3
	mfhi $t2
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 0
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 2
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 3
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 4
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 5
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 6
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 7
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 8
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 186
	addi $t2, $zero, 55
	and $t3, $t1, $t2
	addi $t1, $zero, 9
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 0
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 1
	addi $t2, $zero, 1
	sllv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 6
	addi $t2, $zero, 1
	srlv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	sllv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	sllv $t4, $t1, $t2
	add $t1, $t3, $t4
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 3
	addi $t2, $zero, 1
	sllv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 3
	addi $t2, $zero, 1
	sllv $t4, $t1, $t2
	add $t1, $t3, $t4
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 2
	sllv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 48
	addi $t2, $zero, 12
	or $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 2
	sllv $t4, $t1, $t2
	add $t1, $t3, $t4
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 0
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 2
	addi $t2, $zero, 1
	srlv $t4, $t1, $t2
	add $t1, $t3, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 2
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 3
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 4
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 5
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 6
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 7
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 8
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 173
	addi $t2, $zero, 235
	xor $t3, $t1, $t2
	addi $t1, $zero, 9
	add $t2, $t3, $t1
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 2
	addi $t4, $zero, 1
	srlv $t5, $t3, $t4
	sllv $t3, $t2, $t5
	sub $t2, $t1, $t3
	addi $t1, $zero, 0
	add $t3, $t2, $t1
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 2
	addi $t4, $zero, 1
	srlv $t5, $t3, $t4
	sllv $t3, $t2, $t5
	sub $t2, $t1, $t3
	addi $t1, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t1, $t3
	add $t1, $t2, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 2
	addi $t4, $zero, 1
	srlv $t5, $t3, $t4
	sllv $t3, $t2, $t5
	sub $t2, $t1, $t3
	addi $t1, $zero, 1
	addi $t3, $zero, 1
	sllv $t4, $t1, $t3
	add $t1, $t2, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 2
	addi $t4, $zero, 1
	srlv $t5, $t3, $t4
	sllv $t3, $t2, $t5
	sub $t2, $t1, $t3
	addi $t1, $zero, 6
	addi $t3, $zero, 1
	srlv $t4, $t1, $t3
	add $t1, $t2, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	sub $t2, $t1, $t4
	addi $t1, $zero, 2
	addi $t3, $zero, 1
	sllv $t4, $t1, $t3
	add $t1, $t2, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	sub $t2, $t1, $t4
	addi $t1, $zero, 2
	addi $t3, $zero, 2
	addi $t4, $zero, 1
	srlv $t5, $t3, $t4
	sllv $t3, $t1, $t5
	add $t1, $t2, $t3
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	sub $t2, $t1, $t4
	addi $t1, $zero, 3
	addi $t3, $zero, 1
	sllv $t4, $t1, $t3
	add $t1, $t2, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	sub $t2, $t1, $t4
	addi $t1, $zero, 3
	addi $t3, $zero, 2
	addi $t4, $zero, 1
	srlv $t5, $t3, $t4
	sllv $t3, $t1, $t5
	add $t1, $t2, $t3
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	sub $t2, $t1, $t4
	addi $t1, $zero, 2
	addi $t3, $zero, 2
	sllv $t4, $t1, $t3
	add $t1, $t2, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 5
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	sub $t2, $t1, $t4
	addi $t1, $zero, 2
	addi $t3, $zero, 2
	sllv $t4, $t1, $t3
	add $t1, $t2, $t4
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 0
	add $t3, $t1, $t2
	mul $t1, $t0, $t3
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 1
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 6
	addi $t3, $zero, 1
	srlv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 2
	addi $t3, $zero, 2
	addi $t4, $zero, 1
	srlv $t5, $t3, $t4
	sllv $t3, $t2, $t5
	add $t2, $t1, $t3
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 2
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	add $t2, $t1, $t4
	addi $t1, $zero, 2
	addi $t3, $zero, 2
	addi $t4, $zero, 2
	addi $t5, $zero, 1
	srlv $t6, $t4, $t5
	srlv $t4, $t3, $t6
	srlv $t3, $t1, $t4
	add $t1, $t2, $t3
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 3
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 3
	addi $t3, $zero, 1
	sllv $t4, $t2, $t3
	add $t2, $t1, $t4
	addi $t1, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t1, $t3
	add $t1, $t2, $t4
	mul $t2, $t0, $t1
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 2
	addi $t3, $zero, 2
	sllv $t4, $t2, $t3
	add $t2, $t1, $t4
	mul $t1, $t0, $t2
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
	addi $t0, $zero, 1
	addi $t1, $zero, 91
	sub $t2, $zero, $t1
	not $t1, $t2
	addi $t2, $zero, 2
	addi $t3, $zero, 2
	sllv $t4, $t2, $t3
	add $t2, $t1, $t4
	addi $t1, $zero, 2
	addi $t3, $zero, 1
	srlv $t4, $t1, $t3
	add $t1, $t2, $t4
	mul $t2, $t0, $t1
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
	beqz $t0, else_236166624
	jal Panic
	add $t0, $zero, $v0
	j exit_if_236166624
	else_236166624:
	exit_if_236166624:

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
	j for_teste_236362992
	for_corpo_236362992:
	addi $t0, $zero, 1
	mul $t1, $t0, $s0
	la $t0, a
	sll $t2, $t1, 2
	add $t2, $t2, $t0
	addi $t0, $zero, 0
	sw $t0, 0($t2)
	add $t0, $zero, $s0
	addi $s0, $s0, 1
	for_teste_236362992:
	addi $t1, $zero, 100
	slt $t2, $s0, $t1
	bnez $t2, for_corpo_236362992
	jal PopulateArray
	add $t1, $zero, $v0
	addi $t2, $zero, 0
	add $a0, $zero, $t2 # function param i
	jal GenValue
	add $t2, $zero, $v0
	add $s0, $zero, $t2
	j for_teste_236362800
	for_corpo_236362800:
	addi $t2, $zero, 1
	mul $t3, $t2, $s0
	la $t2, a
	sll $t4, $t3, 2
	add $t4, $t4, $t2
	lw $t2, 0($t4)
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
	for_teste_236362800:
	addi $t3, $zero, 100
	add $a0, $zero, $t3 # function param i
	jal GenValue
	add $t3, $zero, $v0
	slt $t4, $s0, $t3
	bnez $t4, for_corpo_236362800
	.data
		string_236361456: .asciiz "O codigo assembly gerado funcionou como o esperado."
	.text
	la $a0, string_236361456
	addi $v0, $zero, 4
	syscall
	addi $t3, $zero, 666
	add $v0, $zero, $t3

	addi $v0, $zero, 10
	syscall
