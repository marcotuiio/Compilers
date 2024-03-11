#include "asm.h"

int sRegister[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int tRegister[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char *definesDeclarations = NULL;
char *globalAssigns = NULL;

int getSRegister() {
    for (int i = 0; i < 8; i++) {
        if (sRegister[i] == 0) {
            sRegister[i] = 1;
            return i;
        }
    }
    printf("\n######### No free $s register found #########\n\n");
    exit(-1);
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

void printStart() {
    printf("# Gerado por: Gerador de Codigo do Marco Tulio 202100560105\n");
    // printf("# file: %s\n", fileName);
    printf(".text\n");
    printf(".globl main\n\n");
}

int printConstant(int value) {
    int t = getTRegister();
    printf("\taddi $t%d, $zero, %d\n", t, value);
    return t;
}

int printArithmeticsOps(int leftType, int leftReg, int rightType, int rightReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\t%s $t%d, $%c%d, $%c%d\n", op, t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printDivisionOps(int leftType, int leftReg, int rightType, int rightReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    printf("\tdiv $%c%d, $%c%d\n", l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    int t = getTRegister();
    printf("\t%s $t%d\n", op, t);
    return t;
}

int printPreIncrements(int leftType, int leftReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    printf("\t%s $%c%d, $%c%d, 1\n", op, l, leftReg, l, leftReg);  // the return value will be on the already incremented register
    if (leftType == 0) tRegister[leftReg] = 0;
    return leftReg;
}

int printPostIncrements(int leftType, int leftReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\tadd $t%d, $zero, $%c%d\n", t, l, leftReg);           // first store the original value
    printf("\t%s $%c%d, $%c%d, 1\n", op, l, leftReg, l, leftReg);  // then increment and return the original value
    return t;
}

int printAssignment(int rightType, int rightReg) {
    char r = rightType == 0 ? 't' : 's';
    int s = getSRegister();
    printf("\tadd $s%d, $zero, $%c%d\n", s, r, rightReg);
    if (rightType == 0) tRegister[rightReg] = 0;
    return s;
}

void printAssignmentToReg(int rightType, int rightReg, int leftReg) {
    char r = rightType == 0 ? 't' : 's';
    printf("\tadd $s%d, $zero, $%c%d\n", leftReg, r, rightReg);
    if (rightType == 0) tRegister[rightReg] = 0;
}

int printAssignAddress(int leftType, int leftReg, char *name) {
    if (leftReg == -1) leftReg = getSRegister();
    printf("\t.data\n");
    printf("\t\t%s: .word 0\n", name);
    printf("\t.text\n");
    printf("\tla $s%d, %s\n", leftReg, name);
    return leftReg;
}

void printStoreInAddress(int leftType, int leftReg, int rightType, int rightReg) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    printf("\tsw $%c%d, 0($%c%d)\n", r, rightReg, l, leftReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
}

int printDeclareString(char *name, char *value) {
    printf("\t.data\n");
    printf("\t\t%s: .asciiz \"%s\"\n", name, value);
    printf("\t.text\n");
    int s = getSRegister();
    printf("\tla $s%d, %s\n", s, name);
    return s;
}

int printUnaryPlusMinus(int leftType, int leftReg, char *op) {
    char r = leftType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\t%s $t%d, $zero, $%c%d\n", op, t, r, leftReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    return t;
}

int printBitwiseNot(int leftType, int leftReg) {
    char r = leftType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\tnot $t%d, $%c%d\n", t, r, leftReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    return t;
}

int printBitwiseOps(int leftType, int leftReg, int rightType, int rightReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\t%s $t%d, $%c%d, $%c%d\n", op, t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printLogicalNot(int leftType, int leftReg) {
    char r = leftType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\taddi $t%d, $zero, 1\n", t);
    printf("\tslt $t%d, $%c%d, $zero\n", t, r, leftReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    return t;
}

int printRelationalOps(int leftType, int leftReg, int rightType, int rightReg, char *op) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\t%s $t%d, $%c%d, $%c%d\n", op, t, l, leftReg, r, rightReg);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printLogicalAnd(int leftType, int leftReg, int rightType, int rightReg, int labelID) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\taddi $t%d, $zero, 0\n", t);
    printf("\tbeq $t%d, $%c%d, %s%d\n", t, l, leftReg, "f_logical_and_", labelID);
    printf("\tbeq $t%d, $%c%d, %s%d\n", t, r, rightReg, "f_logical_and_", labelID);
    printf("\taddi $t%d, $zero, 1\n", t);
    printf("\t%s%d:\n", "f_logical_and_", labelID);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

int printLogicalOr(int leftType, int leftReg, int rightType, int rightReg, int labelID) {
    char l = leftType == 0 ? 't' : 's';
    char r = rightType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\taddi $t%d, $zero, 1\n", t);
    printf("\tbeq $t%d, $%c%d, %s%d\n", t, l, leftReg, "t_logical_or_", labelID);
    printf("\tbeq $t%d, $%c%d, %s%d\n", t, r, rightReg, "t_logical_or_", labelID);
    printf("\taddi $t%d, $zero, 0\n", t);
    printf("\t%s%d:\n", "t_logical_or_", labelID);
    if (leftType == 0) tRegister[leftReg] = 0;
    if (rightType == 0) tRegister[rightReg] = 0;
    return t;
}

void printIf(int conditionType, int conditionReg, int labelID) {
    char c = conditionType == 0 ? 't' : 's';
    // int t = getTRegister();
    // printf("\taddi $t%d, $zero, 0\n", t);
    // printf("\tbeq $t%d, $%c%d, else_%d\n", t, c, conditionReg, labelID);
    printf("\tbeqz $%c%d, else_%d\n", c, conditionReg, labelID);
    if (conditionType == 0) tRegister[conditionReg] = 0;
    // tRegister[t] = 0;
}

void printWhile(int conditionType, int conditionReg, int labelID) {
    char c = conditionType == 0 ? 't' : 's';
    int t = getTRegister();
    // printf("\taddi $t%d, $zero, 1\n", t);
    // printf("\tbeq $t%d, $%c%d, while_corpo_%d\n", t, c, conditionReg, labelID);
    printf("\tbnez $%c%d, while_corpo_%d\n", c, conditionReg, labelID);
    if (conditionType == 0) tRegister[conditionReg] = 0;
    tRegister[t] = 0;
}

void printFor(int conditionType, int conditionReg, int labelID) {
    char c = conditionType == 0 ? 't' : 's';
    int t = getTRegister();
    // printf("\taddi $t%d, $zero, 1\n", t);
    // printf("\tbeq $t%d, $%c%d, for_corpo_%d\n", t, c, conditionReg, labelID);
    printf("\tbnez $%c%d, for_corpo_%d\n", c, conditionReg, labelID);
    if (conditionType == 0) tRegister[conditionReg] = 0;
    tRegister[t] = 0;
}

void printTernary(int conditionType, int conditionReg, int labelID) {
    char c = conditionType == 0 ? 't' : 's';
    int t = getTRegister();
    printf("\taddi $t%d, $zero, 0\n", t);
    printf("\tbeq $t%d, $%c%d, false_ternary_%d\n", t, c, conditionReg, labelID);
    if (conditionType == 0) tRegister[conditionReg] = 0;
    tRegister[t] = 0;
}

void printJump(char *label, int labelID) {
    printf("\tj %s%d\n", label, labelID);
}

void printLabel(char *label, int labelId) {
    printf("\t%s%d:\n", label, labelId);
}

void printFunctions(char *name) {
    printf("\n%s:\n", name);
}

void printGlobalVariableInMemory(int size, char *name) {
    printf("\t%s: .%s 0\n", name, size == 32 ? "word" : "byte");
}

void setDefineIntVariable(char *name, int value) {
    if (!definesDeclarations)
        definesDeclarations = calloc(4096, sizeof(char));
    // freeRegister(type, regToFree);
    sprintf(definesDeclarations + strlen(definesDeclarations), "\t%s: .word %d # define\n", name, value);
    // printf("teste de global: %s\n", definesDeclarations);
}

void printDefines() {
    if (definesDeclarations) {
        printf("%s", definesDeclarations);
        free(definesDeclarations);
    }
}

// void printGlobalCharVariable(char *name, char value) {
//     printf(".data\n");
//     printf("\t%s: .byte '%c'\n", name, value);
// }

void setGlobalVarAssign(char *name, int value) {
    if (!globalAssigns)
        globalAssigns = calloc(4096, sizeof(char));

    int t1 = getTRegister();
    int t2 = getTRegister();
    sprintf(globalAssigns + strlen(globalAssigns), "\tla $t%d, %s\n", t1, name);
    sprintf(globalAssigns + strlen(globalAssigns), "\tadd $t%d, $zero, %d\n", t2, value);
    sprintf(globalAssigns + strlen(globalAssigns), "\tsw $t%d, 0($t%d)\n", t2, t1);
    tRegister[t1] = 0;
    tRegister[t2] = 0;
}

void printGlobalVarAssign() {
    if (globalAssigns) {
        printf("\t# BLOCO DE ATRIBUICOES GLOBAIS NO COMEÇO DA MAIN\n");
        printf("%s", globalAssigns);
        printf("\t# END BLOCO ATRIBUICOES GLOBAIS\n");
        free(globalAssigns);
    }
}

int printLoadIntGlobal(char *name) {
    int t1 = getTRegister();
    int t2 = getTRegister();
    // printf("t = %d\n", t);
    printf("\tla $t%d, %s\n", t1, name);
    printf("\tlw $t%d, 0($t%d)\n", t2, t1);
    tRegister[t1] = 0;
    return t2;
}

void printStoreIntGlobal(int type, int reg, char *name) {
    char r = type == 0 ? 't' : 's';
    int t1 = getTRegister();
    printf("\tla $t%d, %s\n", t1, name);
    printf("\tsw $%c%d, 0($t%d)\n", r, reg, t1);
    if (type == 0) tRegister[reg] = 0;
    tRegister[t1] = 0;
    // return t1;
}

int printDeclareArray(char *name, int size, int isGlobal) {
    if (isGlobal) {
        printf("\t%s: .space %d # global array\n", name, size * 4);
        return -1;
    }

    int s = getSRegister();
    printf("\t.data\n");
    printf("\t\t%s: .space %d # local function array\n", name, size * 4);
    printf("\t.text\n");
    return s;
}

int printAccessIndexArray(int arrayType, int arrayReg, char *name, int indexType, int indexReg, int isGlobal) {
    char index = indexType == 0 ? 't' : 's';
    char a = arrayType == 0 ? 't' : 's';
    if (!isGlobal) {
        // printf("trying to access local array %s [$ %d %d] \n", name, arrayReg, indexReg);
        int t = getTRegister();
        printf("\tla $%c%d, %s\n", a, arrayReg, name);
        printf("\tsll $t%d, $%c%d, 2\n", t, index, indexReg);
        printf("\tadd $t%d, $t%d, $%c%d\n", t, t, a, arrayReg);
        if (indexType == 0) tRegister[indexReg] = 0;
        return t;

    } else {
        // printf("trying to access global array %s \n", name);
        int t1 = getTRegister();
        int t2 = getTRegister();
        printf("\tla $t%d, %s\n", t1, name);
        printf("\tsll $t%d, $%c%d, 2\n", t2, index, indexReg);
        printf("\tadd $t%d, $t%d, $t%d\n", t2, t2, t1);
        if (indexType == 0) tRegister[indexReg] = 0;
        tRegister[t1] = 0;
        return t2;
    }
}

void printStoreIntoArray(int posic, int rightType, int rightReg) {
    char c = rightType == 0 ? 't' : 's';
    printf("\tsw $%c%d, 0($t%d)\n", c, rightReg, posic);
    if (rightType == 0) tRegister[rightReg] = 0;
    tRegister[posic] = 0;
}

int printLoadFromArray(int posic) {
    int t = getTRegister();
    printf("\tlw $t%d, 0($t%d)\n", t, posic);
    tRegister[posic] = 0;
    return t;
}

int printLoadByte(int type, int reg) {
    int t = getTRegister();
    printf("\tlb $t%d, 0($%c%d)\n", t, type == 0 ? 't' : 's', reg);
    if (type == 0) tRegister[reg] = 0;
    return t;
}

void printInteger(int regType, int RegNumber) {
    char r = regType == 0 ? 't' : 's';
    printf("\tadd $a0, $zero, $%c%d\n", r, RegNumber);
    printf("\taddi $v0, $zero, 1\n");
    printf("\tsyscall\n");
    if (regType == 0) tRegister[RegNumber] = 0;
}

void printCharacter(int regType, int RegNumber) {
    char r = regType == 0 ? 't' : 's';
    printf("\tadd $a0, $zero, $%c%d\n", r, RegNumber);
    printf("\taddi $v0, $zero, 11\n");
    printf("\tsyscall\n");
    if (regType == 0) tRegister[RegNumber] = 0;
}

void printStringVar(int type, int value) {
    char t = type == 0 ? 't' : 's';
    printf("\tmove $a0, $%c%d\n", t, value);
    printf("\taddi $v0, $zero, 4\n");
    printf("\tsyscall\n");
    if (type == 0) tRegister[value] = 0;
}

void printString(char *value, int stringID1) {
    printf("\t.data\n");
    printf("\t\tstring_%d: .asciiz \"%s\"\n", stringID1, value);
    printf("\t.text\n");
    printf("\tla $a0, string_%d\n", stringID1);
    printf("\taddi $v0, $zero, 4\n");
    printf("\tsyscall\n");
}

int printScanInt(int sReg, char *name, int isGlobal) {
    if (sReg == -1) sReg = getSRegister();
    printf("\taddi $v0, $zero, 5\n");
    printf("\tsyscall\n");
    if (isGlobal) {
        int t = getTRegister();
        printf("\tla $t%d, %s\n", t, name);
        printf("\tsw $v0, 0($t%d)\n", t);
        tRegister[t] = 0;
        return -1;
    }
    printf("\tadd $s%d, $zero, $v0\n", sReg);
    return sReg;
}

void printCallFunction(char *name) {
    printf("\tjal %s\n", name);
}

void printSetParamInRegister(int aReg, int rightType, int rightReg, char *var) {
    // printf("\t#function param\n");
    printf("\tadd $a%d, $zero, $%c%d # function param %s\n", aReg, rightType == 0 ? 't' : 's', rightReg, var);
    if (rightType == 0) tRegister[rightReg] = 0;
}

void printFunctionParams(char *name, int params) {
    if (!strcmp(name, "main")) return;
    if (params == 0) return;
    printf("\t#loading %d params\n", params);
    for (int i = 0; i < params; i++) {
        printf("\tadd $s%d, $zero, $a%d\n", i, i);
        sRegister[i] = 1;
    }
}

void printReturn() {
    printf("\tjr $ra\n");
}

void printReturnToV0(int type, int reg) {
    char r = type == 0 ? 't' : 's';
    printf("\tadd $v0, $zero, $%c%d\n", r, reg);
    if (type == 0) tRegister[reg] = 0;
}

int printLoadReturnFromV0() {
    int t = getTRegister();
    printf("\tadd $t%d, $zero, $v0\n", t);
    return t;
}

void storeGlobalsInStack(int *globals) {
    // int count = 0;
    for (int i = 0; i < 8; i++) {
        if (sRegister[i] == 1) {
            globals[i] = 1;
            // count++;
        }
    }
}

void storeInStack() {
    printf("\taddi $sp, $sp, -52\n");
    printf("\tsw $a0, 0($sp)\n");
    printf("\tsw $a1, 4($sp)\n");
    printf("\tsw $a2, 8($sp)\n");
    printf("\tsw $a3, 12($sp)\n");
    printf("\tsw $s0, 16($sp)\n");
    printf("\tsw $s1, 20($sp)\n");
    printf("\tsw $s2, 24($sp)\n");
    printf("\tsw $s3, 28($sp)\n");
    printf("\tsw $s4, 32($sp)\n");
    printf("\tsw $s5, 36($sp)\n");
    printf("\tsw $s6, 40($sp)\n");
    printf("\tsw $s7, 44($sp)\n");
    printf("\tsw $ra, 48($sp)\n\n");
}

void loadFromStack() {
    printf("\n\tlw $a0, 0($sp)\n");
    printf("\tlw $a1, 4($sp)\n");
    printf("\tlw $a2, 8($sp)\n");
    printf("\tlw $a3, 12($sp)\n");
    printf("\tlw $s0, 16($sp)\n");
    printf("\tlw $s1, 20($sp)\n");
    printf("\tlw $s2, 24($sp)\n");
    printf("\tlw $s3, 28($sp)\n");
    printf("\tlw $s4, 32($sp)\n");
    printf("\tlw $s5, 36($sp)\n");
    printf("\tlw $s6, 40($sp)\n");
    printf("\tlw $s7, 44($sp)\n");
    printf("\tlw $ra, 48($sp)\n");
    printf("\taddi $sp, $sp, 52\n\n");
}

void storeTRegisters(int *regs) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        regs[i] = tRegister[i];
        tRegister[i] = 0;
        if (tRegister[i] == 1) count++;
    }
    if (count == 0) return;
    printf("\taddi $sp, $sp, -%d\n", count * 4);
    for (int i = 0; i < 10; i++) {
        if (regs[i] == 1) {
            printf("\tsw $t%d, %d($sp)\n", i, i * 4);
        }
    }
}

void loadTRegisters(int *regs) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        tRegister[i] = regs[i];
        if (regs[i] == 1) count++;
    }
    if (count == 0) return;
    for (int i = 0; i < 10; i++) {
        if (regs[i] == 1) {
            printf("\tlw $t%d, %d($sp)\n", i, i * 4);
        }
    }
    printf("\taddi $sp, $sp, %d\n", count * 4);
}

void freeRegister(int type, int number) {
    // printf("freeing register %d %d\n", type, number);
    if (type == 0) {
        tRegister[number] = 0;
    } else {
        sRegister[number] = 0;
    }
}

void printExit() {
    printf("\n\taddi $v0, $zero, 10\n");
    printf("\tsyscall\n");
}

