#include "asm.h"

int sRegister[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int tRegister[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int getSRegister() {
    for (int i = 0; i < 8; i++) {
        if (sRegister[i] == 0) {
            sRegister[i] = 1;
            return i;
        }
    }
    return -1;
}

int getTRegister() {
    for (int i = 0; i < 10; i++) {
        if (tRegister[i] == 0) {
            tRegister[i] = 1;
            return i;
        }
    }
    return -1;
}

FILE *createAsmFile(char *fileName) {
    char *newFileName = calloc(strlen(fileName) + 5, sizeof(char));
    newFileName = strtok(fileName, ".");
    strcat(newFileName, ".asm");
    strcat(newFileName, "\0");
    FILE *file = fopen(newFileName, "w");
    if (!file) printf("Erro ao criar arquivo .asm\n");
    // free(newFileName);
    return file;
}

void printAddition(FILE *mips, int left, int right) {
    int first = getTRegister();
    int second = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, %d\n", first, left);
    fprintf(mips, "\taddi $t%d, $zero, %d\n", second, right);
    fprintf(mips, "\tadd $t%d, $t%d, $t%d\n", getTRegister(), first, second);
    tRegister[first] = 0;
    tRegister[second] = 0;
}

void printSubtraction(FILE *mips, int left, int right) {
    int first = getTRegister();
    int second = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, %d\n", first, left);
    fprintf(mips, "\taddi $t%d, $zero, %d\n", second, right);
    fprintf(mips, "\tsub $t%d, $t%d, $t%d\n", getTRegister(), first, second);
    tRegister[first] = 0;
    tRegister[second] = 0;
}

void printMultiplication(FILE *mips, int left, int right) {
    int first = getTRegister();
    int second = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, %d\n", first, left);
    fprintf(mips, "\taddi $t%d, $zero, %d\n", second, right);
    fprintf(mips, "\tmul $t%d, $t%d, $t%d\n", getTRegister(), first, second);
    tRegister[first] = 0;
    tRegister[second] = 0;
}

void printDivision(FILE *mips, int left, int right) {
    int first = getTRegister();
    int second = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, %d\n", first, left);
    fprintf(mips, "\taddi $t%d, $zero, %d\n", second, right);
    fprintf(mips, "\tdiv $t%d, $t%d\n", first, second);
    tRegister[first] = 0;
    tRegister[second] = 0;
    fprintf(mips, "\tmflo $t%d\n", getTRegister());
}

void printRemainder(FILE *mips, int left, int right) {
    int first = getTRegister();
    int second = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, %d\n", first, left);
    fprintf(mips, "\taddi $t%d, $zero, %d\n", second, right);
    fprintf(mips, "\tdiv $t%d, $t%d\n", first, second);
    tRegister[first] = 0;
    tRegister[second] = 0;
    fprintf(mips, "\tmfhi $t%d\n", getTRegister());
}

void printAssignment(FILE *mips, int value) {
    fprintf(mips, "\taddi $s%d, $zero, %d\n", getSRegister(), value);
}

void printGlobalVariable(FILE *mips, char *name, int value) {
    fprintf(mips, ".data\n");
    fprintf(mips, "%s: .word %d\n", name, value);
}

void printStart(FILE *mips) {
    fprintf(mips, ".text\n");
    fprintf(mips, ".globl main\n");
    fprintf(mips, "main:\n");
}

void printFunction(FILE *mips, char *name) {
    fprintf(mips, "%s:\n", name);
}

void printInteger(FILE *mips, int value) {
    fprintf(mips, "\taddi $a0, $zero, %d\n", value);
    fprintf(mips, "\tli $v0, 1\n");
    fprintf(mips, "\tsyscall\n");
}

void printString(FILE *mips, char *value) {
    fprintf(mips, "\t.data\n");
    fprintf(mips, "\t\tstring: .asciiz \"%s\"\n", value);
    fprintf(mips, "\t.text\n");
    fprintf(mips, "\tla $a0, string\n");
    fprintf(mips, "\tli $v0, 4\n");
    fprintf(mips, "\tsyscall\n");
}

void printScanInt(FILE *mips) {
    fprintf(mips, "\tli $v0, 5\n");
    fprintf(mips, "\tsyscall\n");
    fprintf(mips, "\tmove $a0, $v0\n");
}

void printCallFunction(FILE *mips, char *name) {
    fprintf(mips, "\tjal %s\n", name);
}

void printReturn(FILE *mips) {
    fprintf(mips, "\tjr $ra\n");
}

void storeInStack(FILE *mips, int value) {
    fprintf(mips, "\taddi $sp, $sp, -52\n");
    fprintf(mips, "\tsw $a0, 0($sp)\n");
    fprintf(mips, "\tsw $a1, 4($sp)\n");
    fprintf(mips, "\tsw $a2, 8($sp)\n");
    fprintf(mips, "\tsw $a3, 12($sp)\n");
    fprintf(mips, "\tsw $s0, 16($sp)\n");
    fprintf(mips, "\tsw $s1, 20($sp)\n");
    fprintf(mips, "\tsw $s2, 24($sp)\n");
    fprintf(mips, "\tsw $s3, 28($sp)\n");
    fprintf(mips, "\tsw $s4, 32($sp)\n");
    fprintf(mips, "\tsw $s5, 36($sp)\n");
    fprintf(mips, "\tsw $s6, 40($sp)\n");
    fprintf(mips, "\tsw $s7, 44($sp)\n");
    fprintf(mips, "\tsw $ra, 48($sp)\n");
}

void loadFromStack(FILE *mips) {
    fprintf(mips, "\tlw $a0, 0($sp)\n");
    fprintf(mips, "\tlw $a1, 4($sp)\n");
    fprintf(mips, "\tlw $a2, 8($sp)\n");
    fprintf(mips, "\tlw $a3, 12($sp)\n");
    fprintf(mips, "\tlw $s0, 16($sp)\n");
    fprintf(mips, "\tlw $s1, 20($sp)\n");
    fprintf(mips, "\tlw $s2, 24($sp)\n");
    fprintf(mips, "\tlw $s3, 28($sp)\n");
    fprintf(mips, "\tlw $s4, 32($sp)\n");
    fprintf(mips, "\tlw $s5, 36($sp)\n");
    fprintf(mips, "\tlw $s6, 40($sp)\n");
    fprintf(mips, "\tlw $s7, 44($sp)\n");
    fprintf(mips, "\tlw $ra, 48($sp)\n");
    fprintf(mips, "\taddi $sp, $sp, 52\n");
}

void printEnd(FILE *mips) {
    fprintf(mips, "\tli $v0, 10\n");
    fprintf(mips, "\tsyscall\n");
}


