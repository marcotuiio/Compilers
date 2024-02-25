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

int printConstant(FILE *mips, int value) {
    int t = getTRegister();
    fprintf(mips, "\tli $t%d, %d\n", t, value);
    return t;
}

int printAddition(FILE *mips, int leftType, int leftReg, int rightType, int rightReg) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\tadd $t%d, $%c%d, $%c%d\n", t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printSubtraction(FILE *mips, int leftType, int leftReg, int rightType, int rightReg) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\tsub $t%d, $%c%d, $%c%d\n", t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printMultiplication(FILE *mips, int leftType, int leftReg, int rightType, int rightReg) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\tmul $t%d, $%c%d, $%c%d\n", t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printDivision(FILE *mips, int leftType, int leftReg, int rightType, int rightReg) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    fprintf(mips, "\tdiv $%c%d, $%c%d\n", l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    int t = getTRegister();
    fprintf(mips, "\tmflo $t%d\n", t);
    return t;
}

int printRemainder(FILE *mips, int leftType, int leftReg, int rightType, int rightReg) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    fprintf(mips, "\tdiv $%c%d, $%c%d\n", l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    int t = getTRegister();
    fprintf(mips, "\tmfhi $t%d\n", t);
    return t;
}

int printAssignment(FILE *mips, int rightType, int rightReg) {
    char r = rightType == 0 ? 't' : 's';
    int s = getSRegister();
    fprintf(mips, "\tmove $s%d, $%c%d\n", s, r, rightReg);
    if (rightType == 0) tRegister[rightReg] = 0;
    return s;
}

void printAssignmentToReg(FILE *mips, int rightType, int rightReg, int leftReg) {
    char r = rightType == 0 ? 't' : 's';
    fprintf(mips, "\tmove $s%d, $%c%d\n", leftReg, r, rightReg);
    if (rightType == 0) tRegister[rightReg] = 0;
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

void printInteger(FILE *mips, int regType, int RegNumber) {
    char r = regType == 0 ? 't' : 's';
    fprintf(mips, "\tmove $a0, $%c%d\n", r, RegNumber);
    fprintf(mips, "\tli $v0, 1\n");
    fprintf(mips, "\tsyscall\n");
    if (regType == 0) tRegister[RegNumber] = 0;
}

void printString(FILE *mips, char *value) {
    int stringID = rand() % 100;
    fprintf(mips, "\t.data\n");
    fprintf(mips, "\t\tstring%d: .asciiz \"%s\"\n", stringID, value);
    fprintf(mips, "\t.text\n");
    fprintf(mips, "\tla $a0, string%d\n", stringID);
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
