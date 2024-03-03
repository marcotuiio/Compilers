# Gerado por: Gerador de Código do Marco Tulio 202100560105
.text
#.globl main

	addi $t0, $zero, 100
	.data
		a: .space 400
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

	#loading 0 params
	.data
		string_34: .asciiz "\n\n"
	.text
	la $a0, string_34
	addi $v0, $zero, 4
	syscall
	.data
		string_35: .asciiz "                 "
	.text
	la $a0, string_35
	addi $v0, $zero, 4
	syscall
	.data
		string_36: .asciiz "#######\n"
	.text
	la $a0, string_36
	addi $v0, $zero, 4
	syscall
	.data
		string_37: .asciiz "             "
	.text
	la $a0, string_37
	addi $v0, $zero, 4
	syscall
	.data
		string_38: .asciiz "###############\n"
	.text
	la $a0, string_38
	addi $v0, $zero, 4
	syscall
	.data
		string_39: .asciiz "          "
	.text
	la $a0, string_39
	addi $v0, $zero, 4
	syscall
	.data
		string_40: .asciiz "#####################\n"
	.text
	la $a0, string_40
	addi $v0, $zero, 4
	syscall
	.data
		string_41: .asciiz "         "
	.text
	la $a0, string_41
	addi $v0, $zero, 4
	syscall
	.data
		string_42: .asciiz "#######################\n"
	.text
	la $a0, string_42
	addi $v0, $zero, 4
	syscall
	.data
		string_43: .asciiz "        "
	.text
	la $a0, string_43
	addi $v0, $zero, 4
	syscall
	.data
		string_44: .asciiz "#########################\n"
	.text
	la $a0, string_44
	addi $v0, $zero, 4
	syscall
	.data
		string_45: .asciiz "       "
	.text
	la $a0, string_45
	addi $v0, $zero, 4
	syscall
	.data
		string_46: .asciiz "###########################\n"
	.text
	la $a0, string_46
	addi $v0, $zero, 4
	syscall
	.data
		string_47: .asciiz "       "
	.text
	la $a0, string_47
	addi $v0, $zero, 4
	syscall
	.data
		string_48: .asciiz "###########################\n"
	.text
	la $a0, string_48
	addi $v0, $zero, 4
	syscall
	.data
		string_49: .asciiz "       "
	.text
	la $a0, string_49
	addi $v0, $zero, 4
	syscall
	.data
		string_50: .asciiz "########"
	.text
	la $a0, string_50
	addi $v0, $zero, 4
	syscall
	.data
		string_51: .asciiz "   "
	.text
	la $a0, string_51
	addi $v0, $zero, 4
	syscall
	.data
		string_52: .asciiz "#####"
	.text
	la $a0, string_52
	addi $v0, $zero, 4
	syscall
	.data
		string_53: .asciiz "   "
	.text
	la $a0, string_53
	addi $v0, $zero, 4
	syscall
	.data
		string_54: .asciiz "########\n"
	.text
	la $a0, string_54
	addi $v0, $zero, 4
	syscall
	.data
		string_55: .asciiz "       "
	.text
	la $a0, string_55
	addi $v0, $zero, 4
	syscall
	.data
		string_56: .asciiz "######"
	.text
	la $a0, string_56
	addi $v0, $zero, 4
	syscall
	.data
		string_57: .asciiz "      "
	.text
	la $a0, string_57
	addi $v0, $zero, 4
	syscall
	.data
		string_58: .asciiz "###"
	.text
	la $a0, string_58
	addi $v0, $zero, 4
	syscall
	.data
		string_59: .asciiz "       "
	.text
	la $a0, string_59
	addi $v0, $zero, 4
	syscall
	.data
		string_60: .asciiz "#####\n"
	.text
	la $a0, string_60
	addi $v0, $zero, 4
	syscall
	.data
		string_61: .asciiz "        "
	.text
	la $a0, string_61
	addi $v0, $zero, 4
	syscall
	.data
		string_62: .asciiz "####"
	.text
	la $a0, string_62
	addi $v0, $zero, 4
	syscall
	.data
		string_63: .asciiz "       "
	.text
	la $a0, string_63
	addi $v0, $zero, 4
	syscall
	.data
		string_64: .asciiz "###"
	.text
	la $a0, string_64
	addi $v0, $zero, 4
	syscall
	.data
		string_65: .asciiz "       "
	.text
	la $a0, string_65
	addi $v0, $zero, 4
	syscall
	.data
		string_66: .asciiz "####\n"
	.text
	la $a0, string_66
	addi $v0, $zero, 4
	syscall
	.data
		string_67: .asciiz "        "
	.text
	la $a0, string_67
	addi $v0, $zero, 4
	syscall
	.data
		string_68: .asciiz "####"
	.text
	la $a0, string_68
	addi $v0, $zero, 4
	syscall
	.data
		string_69: .asciiz "      "
	.text
	la $a0, string_69
	addi $v0, $zero, 4
	syscall
	.data
		string_70: .asciiz "#####"
	.text
	la $a0, string_70
	addi $v0, $zero, 4
	syscall
	.data
		string_71: .asciiz "      "
	.text
	la $a0, string_71
	addi $v0, $zero, 4
	syscall
	.data
		string_72: .asciiz "####\n"
	.text
	la $a0, string_72
	addi $v0, $zero, 4
	syscall
	.data
		string_73: .asciiz "         "
	.text
	la $a0, string_73
	addi $v0, $zero, 4
	syscall
	.data
		string_74: .asciiz "##########"
	.text
	la $a0, string_74
	addi $v0, $zero, 4
	syscall
	.data
		string_75: .asciiz "   "
	.text
	la $a0, string_75
	addi $v0, $zero, 4
	syscall
	.data
		string_76: .asciiz "##########\n"
	.text
	la $a0, string_76
	addi $v0, $zero, 4
	syscall
	.data
		string_77: .asciiz "          "
	.text
	la $a0, string_77
	addi $v0, $zero, 4
	syscall
	.data
		string_78: .asciiz "#########"
	.text
	la $a0, string_78
	addi $v0, $zero, 4
	syscall
	.data
		string_79: .asciiz "   "
	.text
	la $a0, string_79
	addi $v0, $zero, 4
	syscall
	.data
		string_80: .asciiz "#########\n"
	.text
	la $a0, string_80
	addi $v0, $zero, 4
	syscall
	.data
		string_81: .asciiz "            "
	.text
	la $a0, string_81
	addi $v0, $zero, 4
	syscall
	.data
		string_82: .asciiz "#################\n"
	.text
	la $a0, string_82
	addi $v0, $zero, 4
	syscall
	.data
		string_83: .asciiz "             "
	.text
	la $a0, string_83
	addi $v0, $zero, 4
	syscall
	.data
		string_84: .asciiz "###############\n"
	.text
	la $a0, string_84
	addi $v0, $zero, 4
	syscall
	.data
		string_85: .asciiz "  "
	.text
	la $a0, string_85
	addi $v0, $zero, 4
	syscall
	.data
		string_86: .asciiz "###        "
	.text
	la $a0, string_86
	addi $v0, $zero, 4
	syscall
	.data
		string_87: .asciiz "####"
	.text
	la $a0, string_87
	addi $v0, $zero, 4
	syscall
	.data
		string_88: .asciiz " "
	.text
	la $a0, string_88
	addi $v0, $zero, 4
	syscall
	.data
		string_89: .asciiz "#"
	.text
	la $a0, string_89
	addi $v0, $zero, 4
	syscall
	.data
		string_90: .asciiz " "
	.text
	la $a0, string_90
	addi $v0, $zero, 4
	syscall
	.data
		string_91: .asciiz "#"
	.text
	la $a0, string_91
	addi $v0, $zero, 4
	syscall
	.data
		string_92: .asciiz " "
	.text
	la $a0, string_92
	addi $v0, $zero, 4
	syscall
	.data
		string_93: .asciiz "#"
	.text
	la $a0, string_93
	addi $v0, $zero, 4
	syscall
	.data
		string_94: .asciiz " "
	.text
	la $a0, string_94
	addi $v0, $zero, 4
	syscall
	.data
		string_95: .asciiz "####"
	.text
	la $a0, string_95
	addi $v0, $zero, 4
	syscall
	.data
		string_96: .asciiz "       "
	.text
	la $a0, string_96
	addi $v0, $zero, 4
	syscall
	.data
		string_97: .asciiz "###\n"
	.text
	la $a0, string_97
	addi $v0, $zero, 4
	syscall
	.data
		string_98: .asciiz " "
	.text
	la $a0, string_98
	addi $v0, $zero, 4
	syscall
	.data
		string_99: .asciiz "#####"
	.text
	la $a0, string_99
	addi $v0, $zero, 4
	syscall
	.data
		string_100: .asciiz "        "
	.text
	la $a0, string_100
	addi $v0, $zero, 4
	syscall
	.data
		string_101: .asciiz "#############"
	.text
	la $a0, string_101
	addi $v0, $zero, 4
	syscall
	.data
		string_102: .asciiz "       "
	.text
	la $a0, string_102
	addi $v0, $zero, 4
	syscall
	.data
		string_103: .asciiz "#####\n"
	.text
	la $a0, string_103
	addi $v0, $zero, 4
	syscall
	.data
		string_104: .asciiz "  "
	.text
	la $a0, string_104
	addi $v0, $zero, 4
	syscall
	.data
		string_105: .asciiz "#######"
	.text
	la $a0, string_105
	addi $v0, $zero, 4
	syscall
	.data
		string_106: .asciiz "      "
	.text
	la $a0, string_106
	addi $v0, $zero, 4
	syscall
	.data
		string_107: .asciiz "###########"
	.text
	la $a0, string_107
	addi $v0, $zero, 4
	syscall
	.data
		string_108: .asciiz "     "
	.text
	la $a0, string_108
	addi $v0, $zero, 4
	syscall
	.data
		string_109: .asciiz "########\n"
	.text
	la $a0, string_109
	addi $v0, $zero, 4
	syscall
	.data
		string_110: .asciiz "##############"
	.text
	la $a0, string_110
	addi $v0, $zero, 4
	syscall
	.data
		string_111: .asciiz "    "
	.text
	la $a0, string_111
	addi $v0, $zero, 4
	syscall
	.data
		string_112: .asciiz "#####"
	.text
	la $a0, string_112
	addi $v0, $zero, 4
	syscall
	.data
		string_113: .asciiz "    "
	.text
	la $a0, string_113
	addi $v0, $zero, 4
	syscall
	.data
		string_114: .asciiz "##############\n"
	.text
	la $a0, string_114
	addi $v0, $zero, 4
	syscall
	.data
		string_115: .asciiz "####################"
	.text
	la $a0, string_115
	addi $v0, $zero, 4
	syscall
	.data
		string_116: .asciiz "   "
	.text
	la $a0, string_116
	addi $v0, $zero, 4
	syscall
	.data
		string_117: .asciiz "##################\n"
	.text
	la $a0, string_117
	addi $v0, $zero, 4
	syscall
	.data
		string_118: .asciiz " "
	.text
	la $a0, string_118
	addi $v0, $zero, 4
	syscall
	.data
		string_119: .asciiz "###"
	.text
	la $a0, string_119
	addi $v0, $zero, 4
	syscall
	.data
		string_120: .asciiz "      "
	.text
	la $a0, string_120
	addi $v0, $zero, 4
	syscall
	.data
		string_121: .asciiz "###############"
	.text
	la $a0, string_121
	addi $v0, $zero, 4
	syscall
	.data
		string_122: .asciiz " "
	.text
	la $a0, string_122
	addi $v0, $zero, 4
	syscall
	.data
		string_123: .asciiz "######\n"
	.text
	la $a0, string_123
	addi $v0, $zero, 4
	syscall
	.data
		string_124: .asciiz "           "
	.text
	la $a0, string_124
	addi $v0, $zero, 4
	syscall
	.data
		string_125: .asciiz "####"
	.text
	la $a0, string_125
	addi $v0, $zero, 4
	syscall
	.data
		string_126: .asciiz " "
	.text
	la $a0, string_126
	addi $v0, $zero, 4
	syscall
	.data
		string_127: .asciiz "###############\n"
	.text
	la $a0, string_127
	addi $v0, $zero, 4
	syscall
	.data
		string_128: .asciiz "  "
	.text
	la $a0, string_128
	addi $v0, $zero, 4
	syscall
	.data
		string_129: .asciiz "##################"
	.text
	la $a0, string_129
	addi $v0, $zero, 4
	syscall
	.data
		string_130: .asciiz " "
	.text
	la $a0, string_130
	addi $v0, $zero, 4
	syscall
	.data
		string_131: .asciiz "###################\n"
	.text
	la $a0, string_131
	addi $v0, $zero, 4
	syscall
	.data
		string_132: .asciiz "  "
	.text
	la $a0, string_132
	addi $v0, $zero, 4
	syscall
	.data
		string_133: .asciiz "##############"
	.text
	la $a0, string_133
	addi $v0, $zero, 4
	syscall
	.data
		string_134: .asciiz "           "
	.text
	la $a0, string_134
	addi $v0, $zero, 4
	syscall
	.data
		string_135: .asciiz "##############\n"
	.text
	la $a0, string_135
	addi $v0, $zero, 4
	syscall
	.data
		string_136: .asciiz "   "
	.text
	la $a0, string_136
	addi $v0, $zero, 4
	syscall
	.data
		string_137: .asciiz "#######"
	.text
	la $a0, string_137
	addi $v0, $zero, 4
	syscall
	.data
		string_138: .asciiz "                      "
	.text
	la $a0, string_138
	addi $v0, $zero, 4
	syscall
	.data
		string_139: .asciiz "########\n"
	.text
	la $a0, string_139
	addi $v0, $zero, 4
	syscall
	.data
		string_140: .asciiz "     "
	.text
	la $a0, string_140
	addi $v0, $zero, 4
	syscall
	.data
		string_141: .asciiz "####"
	.text
	la $a0, string_141
	addi $v0, $zero, 4
	syscall
	.data
		string_142: .asciiz "                         "
	.text
	la $a0, string_142
	addi $v0, $zero, 4
	syscall
	.data
		string_143: .asciiz "#####\n"
	.text
	la $a0, string_143
	addi $v0, $zero, 4
	syscall
	.data
		string_144: .asciiz "\n\nFATAL ERROR: O codigo assembly gerado possui ao menos um Erro.\n"
	.text
	la $a0, string_144
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

	#loading 0 params
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	add $s0, $zero, $t0
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	add $s1, $zero, $t0
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	add $s2, $zero, $t0
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	add $s3, $zero, $t0
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	add $s4, $zero, $t0
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	add $s5, $zero, $t0
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
	add $s6, $zero, $t0
	addi $t0, $zero, 1
	add $a0, $zero, $t0 # function param i
	jal GenValue
	add $t0, $zero, $v0
