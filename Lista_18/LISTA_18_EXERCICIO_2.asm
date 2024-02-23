.data
	basePrint: .asciiz "Entre com a base: "
    expoentePrint: .asciiz "Entre com o expoente: "
    toPrint: .asciiz "Resultado: "
.text	

main:

	la $a0, basePrint
	addi $v0, $zero, 4
	syscall

    li $v0, 5
	syscall
	add $s0, $v0, $zero  # Armazenando base em $s0

    la $a0, expoentePrint
    addi $v0, $zero, 4
    syscall

    li $v0, 5
    syscall
    add $s1, $v0, $zero  # Armazenando expoente em $s1

    la $a0, toPrint
    addi $v0, $zero, 4
    syscall

    # Chamando a func que calcula a potencia
    addi $v0, $zero, 1
    jal potencia

    move $a0, $v0
    li $v0, 1
    syscall

    li $v0, 10
    syscall

potencia:
    # Guarda o valor de $ra
    addi $sp, $sp, -8
    sw $ra, 0($sp)
    sw $s1, 4($sp)

    # Caso base: expoente == 0
    beq $s1, $zero, end_potencia    

    subi $s1, $s1, 1
    jal potencia

    # Calcula a potencia    
    mul $v0, $s0, $v0

end_potencia:
    # Restaura o valor de $ra
    lw $ra, 0($sp)
    lw $s1, 4($sp)
    addi $sp, $sp, 8

    jr $ra
