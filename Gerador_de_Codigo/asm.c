#include "asm.h"

int sRegister[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int getSRegister() {
    for (int i = 0; i < 8; i++) {
        if (sRegister[i] == 0) {
            sRegister[i] = 1;
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
    fprintf(mips, "\taddi $t0, $zero, %d\n", left);
    fprintf(mips, "\taddi $t1, $zero, %d\n", right);
    fprintf(mips, "\tadd $t0, $t0, $t1\n");
}

void printSubtraction(FILE *mips, int left, int right) {
    fprintf(mips, "\taddi $t0, $zero, %d\n", left);
    fprintf(mips, "\taddi $t1, $zero, %d\n", right);
    fprintf(mips, "\tsub $t0, $t0, $t1\n");
}

void printMultiplication(FILE *mips, int left, int right) {
    fprintf(mips, "\taddi $t0, $zero, %d\n", left);
    fprintf(mips, "\taddi $t1, $zero, %d\n", right);
    fprintf(mips, "\tmul $t0, $t0, $t1\n");
}

void printDivision(FILE *mips, int left, int right) {
    fprintf(mips, "\taddi $t0, $zero, %d\n", left);
    fprintf(mips, "\taddi $t1, $zero, %d\n", right);
    fprintf(mips, "\tdiv $t0, $t1\n");
    fprintf(mips, "\tmflo $t0\n");
}

void printRemainder(FILE *mips, int left, int right) {
    fprintf(mips, "\taddi $t0, $zero, %d\n", left);
    fprintf(mips, "\taddi $t1, $zero, %d\n", right);
    fprintf(mips, "\tdiv $t0, $t1\n");
    fprintf(mips, "\tmfhi $t0\n");
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
    fprintf(mips, "\taddi $sp, $sp, -4\n");
    fprintf(mips, "\tsw $t0, 0($sp)\n");
}

void loadFromStack(FILE *mips) {
    fprintf(mips, "\tlw $t0, 0($sp)\n");
    fprintf(mips, "\taddi $sp, $sp, 4\n");
}

void printEnd(FILE *mips) {
    fprintf(mips, "\tli $v0, 10\n");
    fprintf(mips, "\tsyscall\n");
}


