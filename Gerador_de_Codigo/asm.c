#include "asm.h"

int sRegister[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int tRegister[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char *globalDeclarations = NULL;

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
    fprintf(file, "# Gerado por: Gerador de Código do Marco Tulio 202100560105\n");
    fprintf(file, ".text\n");
    fprintf(file, "#.globl main\n\n");
    return file;
}

void deleteMipsFileOnError(FILE *mipsFile, char *mipsPath) {
    fclose(mipsFile);
    remove(mipsPath);
}

int printConstant(FILE *mips, int value) {
    int t = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, %d\n", t, value);
    return t;
}

int printArithmeticsOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\t%s $t%d, $%c%d, $%c%d\n", op, t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printDivisionOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    fprintf(mips, "\tdiv $%c%d, $%c%d\n", l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    int t = getTRegister();
    fprintf(mips, "\t%s $t%d\n", op, t);
    return t;
}

int printPreIncrements(FILE *mips, int leftType, int leftReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    fprintf(mips, "\t%s $%c%d, $%c%d, 1\n", op, l, leftReg, l, leftReg);  // the return value will be on the already incremented register
    return leftReg;
}

int printPostIncrements(FILE *mips, int leftType, int leftReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\tadd $t%d, $zero, $%c%d\n", t, l, leftReg);           // first store the original value
    fprintf(mips, "\t%s $%c%d, $%c%d, 1\n", op, l, leftReg, l, leftReg);  // then increment and return the original value
    return t;
}

int printAssignment(FILE *mips, int rightType, int rightReg) {
    char r = rightType == 0 ? 't' : 's';
    int s = getSRegister();
    fprintf(mips, "\tadd $s%d, $zero, $%c%d\n", s, r, rightReg);
    if (rightType == 0) tRegister[rightReg] = 0;
    return s;
}

void printAssignmentToReg(FILE *mips, int rightType, int rightReg, int leftReg) {
    char r = rightType == 0 ? 't' : 's';
    fprintf(mips, "\tadd $s%d, $zero, $%c%d\n", leftReg, r, rightReg);
    if (rightType == 0) tRegister[rightReg] = 0;
}

int printUnaryPlusMinus(FILE *mips, int leftType, int leftReg, char *op) {
    char r = leftType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\t%s $t%d, $zero, $%c%d\n", op, t, r, leftReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    return t;
}

int printBitwiseNot(FILE *mips, int leftType, int leftReg) {
    char r = leftType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\tnot $t%d, $%c%d\n", t, r, leftReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    return t;
}

int printBitwiseOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\t%s $t%d, $%c%d, $%c%d\n", op, t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    return t;
}

int printLogicalNot(FILE *mips, int leftType, int leftReg) {
    char r = leftType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, 1\n", t);
    fprintf(mips, "\tslt $t%d, $%c%d, $zero\n", t, r, leftReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    return t;
}

int printRelationalOps(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\t%s $t%d, $%c%d, $%c%d\n", op, t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printLogicalAnd(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, int labelLineID, int labelColumnID) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, 0\n", t);
    fprintf(mips, "\tbeq $t%d, $%c%d, %s%d_%d\n", t, l, leftReg, "f_logical_and_", labelLineID, labelColumnID);
    fprintf(mips, "\tbeq $t%d, $%c%d, %s%d_%d\n", t, r, rightReg, "f_logical_and_", labelLineID, labelColumnID);
    fprintf(mips, "\taddi $t%d, $zero, 1\n", t);
    fprintf(mips, "\t%s%d_%d:\n", "f_logical_and_", labelLineID, labelColumnID);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printLogicalOr(FILE *mips, int leftType, int leftReg, int rightType, int rightReg, int labelLineID, int labelColumnID) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, 1\n", t);
    fprintf(mips, "\tbeq $t%d, $%c%d, %s%d_%d\n", t, l, leftReg, "t_logical_or_", labelLineID, labelColumnID);
    fprintf(mips, "\tbeq $t%d, $%c%d, %s%d_%d\n", t, r, rightReg, "t_logical_or_", labelLineID, labelColumnID);
    fprintf(mips, "\taddi $t%d, $zero, 0\n", t);
    fprintf(mips, "\t%s%d_%d:\n", "t_logical_or_", labelLineID, labelColumnID);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

void printIf(FILE *mips, int conditionType, int conditionReg, int labelID) {
    char c = conditionType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, 0\n", t);
    fprintf(mips, "\tbeq $t%d, $%c%d, else_%d\n", t, c, conditionReg, labelID);
    if (conditionType == 0) tRegister[conditionReg] = 0;
    tRegister[t] = 0;
}

void printWhile(FILE *mips, int conditionType, int conditionReg, int labelID) {
    char c = conditionType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, 1\n", t);
    fprintf(mips, "\tbeq $t%d, $%c%d, while_corpo_%d\n", t, c, conditionReg, labelID);
    if (conditionType == 0) tRegister[conditionReg] = 0;
    tRegister[t] = 0;
}

void printFor(FILE *mips, int conditionType, int conditionReg, int labelID) {
    char c = conditionType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, 1\n", t);
    fprintf(mips, "\tbeq $t%d, $%c%d, for_corpo_%d\n", t, c, conditionReg, labelID);
    if (conditionType == 0) tRegister[conditionReg] = 0;
    tRegister[t] = 0;
}

void printTernary(FILE *mips, int conditionType, int conditionReg, int labelID) {
    char c = conditionType == 0 ? 't' : 's';
    int t = getTRegister();
    fprintf(mips, "\taddi $t%d, $zero, 0\n", t);
    fprintf(mips, "\tbeq $t%d, $%c%d, false_ternary_%d\n", t, c, conditionReg, labelID);
    if (conditionType == 0) tRegister[conditionReg] = 0;
    tRegister[t] = 0;
}

void printJump(FILE *mips, char *label, int labelID) {
    fprintf(mips, "\tj %s%d\n", label, labelID);
}

void printLabel(FILE *mips, char *label, int labelId) {
    fprintf(mips, "\t%s%d:\n", label, labelId);
}

void printFunctions(FILE *mips, char *name) {
    fprintf(mips, "\n%s:\n", name);
}

void setGlobalIntVariable(char *name, int value, int type, int regToFree) {
    if (!globalDeclarations)
        globalDeclarations = calloc(4096, sizeof(char));
    freeRegister(type, regToFree);
    sprintf(globalDeclarations + strlen(globalDeclarations), "\t%s: .word %d\n", name, value);
    // printf("teste de global: %s\n", globalDeclarations);
}

void printGlobals(FILE *mips) {
    if (globalDeclarations) {
        fprintf(mips, "\n# BLOCO DE DEFINES NO FIM DO ARQUIVO\n");
        fprintf(mips, ".data\n");
        fprintf(mips, "%s", globalDeclarations);
        fprintf(mips, "# END BLOCO DEFINES");
        free(globalDeclarations);
    }
}

// void printGlobalCharVariable(FILE *mips, char *name, char value) {
//     fprintf(mips, ".data\n");
//     fprintf(mips, "\t%s: .byte '%c'\n", name, value);
// }

int printLoadIntGlobal(FILE *mips, char *name) {
    int t = getTRegister();
    // printf("t = %d\n", t);
    fprintf(mips, "\tla $t%d, %s\n", t, name);
    fprintf(mips, "\tlw $t%d, 0($t%d)\n", t, t);
    return t;
}

int printDeclareArray(FILE *mips, char *name, int size) {
    fprintf(mips, "\t.data\n");
    fprintf(mips, "\t\t%s: .space %d\n", name, size * 4);
    fprintf(mips, "\t.text\n");
    int s;
    for (int i = 7; i >= 0; i++) {
        if (sRegister[i] == 0) {
            s = i;
            sRegister[i] = 1;
            break;
        }
    }
    // fprintf(mips, "\tla $s%d, %s\n", s, name);
    return s;
}

int printAccessIndexArray(FILE *mips, int arrayType, int arrayReg, char *name, int indexType, int indexReg) {
    int t = getTRegister();
    char index = indexType == 0 ? 't' : 's';
    char a = arrayType == 0 ? 't' : 's';
    fprintf(mips, "\tla $%c%d, %s\n", a, arrayReg, name);
    fprintf(mips, "\tsll $t%d, $%c%d, 2\n", t, index, indexReg);
    fprintf(mips, "\tadd $t%d, $t%d, $%c%d\n", t, t, a, arrayReg);
    return t;
}

void printStoreIntoArray(FILE *mips, int posic, int rightType, int rightReg) {
    char c = rightType == 0 ? 't' : 's';
    fprintf(mips, "\tsw $%c%d, 0($t%d)\n", c, rightReg, posic);
    if (rightType == 0) tRegister[rightReg] = 0;
    tRegister[posic] = 0;
}

int printLoadFromArray(FILE *mips, int posic) {
    int t = getTRegister();
    fprintf(mips, "\tlw $t%d, 0($t%d)\n", t, posic);
    tRegister[posic] = 0;
    return t;
}

void printInteger(FILE *mips, int regType, int RegNumber) {
    char r = regType == 0 ? 't' : 's';
    fprintf(mips, "\tadd $a0, $zero, $%c%d\n", r, RegNumber);
    fprintf(mips, "\taddi $v0, $zero, 1\n");
    fprintf(mips, "\tsyscall\n");
    if (regType == 0) tRegister[RegNumber] = 0;
}

void printString(FILE *mips, char *value, int stringID1) {
    fprintf(mips, "\t.data\n");
    fprintf(mips, "\t\tstring_%d: .asciiz \"%s\"\n", stringID1, value);
    fprintf(mips, "\t.text\n");
    fprintf(mips, "\tla $a0, string_%d\n", stringID1);
    fprintf(mips, "\taddi $v0, $zero, 4\n");
    fprintf(mips, "\tsyscall\n");
}

int printScanInt(FILE *mips, int sReg) {
    if (sReg == -1) sReg = getSRegister();
    fprintf(mips, "\taddi $v0, $zero, 5\n");
    fprintf(mips, "\tsyscall\n");
    fprintf(mips, "\tadd $s%d, $zero, $v0\n", sReg);
    return sReg;
}

void printCallFunction(FILE *mips, char *name) {
    fprintf(mips, "\tjal %s\n", name);
}

void printSetParamInRegister(FILE *mips, int aReg, int rightType, int rightReg, char *var) {
    // fprintf(mips, "\t#function param\n");
    fprintf(mips, "\tadd $a%d, $zero, $%c%d # function param %s\n", aReg, rightType == 0 ? 't' : 's', rightReg, var);
    if (rightType == 0) tRegister[rightReg] = 0;
}

void printFunctionParams(FILE *mips, char *name, int params) {
    if (!strcmp(name, "main")) return;
    fprintf(mips, "\t#loading %d params\n", params);
    for (int i = 0; i < params; i++) {
        fprintf(mips, "\tadd $s%d, $zero, $a%d\n", i, i);
        sRegister[i] = 1;
    }
}

void printReturn(FILE *mips) {
    fprintf(mips, "\tjr $ra\n");
}

void printReturnToV0(FILE *mips, int type, int reg) {
    char r = type == 0 ? 't' : 's';
    fprintf(mips, "\tadd $v0, $zero, $%c%d\n", r, reg);
    if (type == 0) tRegister[reg] = 0;
}

int printLoadReturnFromV0(FILE *mips) {
    int t = getTRegister();
    fprintf(mips, "\tadd $t%d, $zero, $v0\n", t);
    return t;
}

void storeGlobalsInStack(FILE *mips, int *globals) {
    // int count = 0;
    for (int i = 0; i < 8; i++) {
        if (sRegister[i] == 1) {
            globals[i] = 1;
            // count++;
        }
    }
}

void storeInStack(FILE *mips) {
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
    fprintf(mips, "\tsw $ra, 48($sp)\n\n");
}

void loadFromStack(FILE *mips) {
    fprintf(mips, "\n\tlw $a0, 0($sp)\n");
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
    fprintf(mips, "\taddi $sp, $sp, 52\n\n");
}

void storeTRegisters(FILE *mips, int *regs) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        regs[i] = tRegister[i];
        tRegister[i] = 0;
        if (tRegister[i] == 1) count++;
    }
    if (count == 0) return;
    fprintf(mips, "\taddi $sp, $sp, -%d\n", count * 4);
    for (int i = 0; i < 10; i++) {
        if (regs[i] == 1) {
            fprintf(mips, "\tsw $t%d, %d($sp)\n", i, i * 4);
        }
    }
}

void loadTRegisters(FILE *mips, int *regs) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        tRegister[i] = regs[i];
        if (regs[i] == 1) count++;
    }
    if (count == 0) return;
    for (int i = 0; i < 10; i++) {
        if (regs[i] == 1) {
            fprintf(mips, "\tlw $t%d, %d($sp)\n", i, i * 4);
        }
    }
    fprintf(mips, "\taddi $sp, $sp, %d\n", count * 4);
}

void freeRegister(int type, int number) {
    // printf("freeing register %d %d\n", type, number);
    if (type == 0) {
        tRegister[number] = 0;
    } else {
        sRegister[number] = 0;
    }
}

void printExit(FILE *mips) {
    fprintf(mips, "\n\taddi $v0, $zero, 10\n");
    fprintf(mips, "\tsyscall\n");
}

void printEnd(FILE *mips) {
    printExit(mips);
    printGlobals(mips);
    fclose(mips);
}
