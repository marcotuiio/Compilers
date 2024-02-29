// #include <stdio.h>

// void main() {
//     int x = 5;
//     int preIncrementResult, postIncrementResult;
//     // Post-increment: Use the original value and then increment
//     postIncrementResult = x++;
//     printf("Post-increment result: %d\n", postIncrementResult); // Prints 5

//     // Pre-increment: Increment first and then use the updated value
//     preIncrementResult = ++x;
//     printf("Pre-increment result: %d\n", preIncrementResult); // Prints 7
// }

// int main() {
//     int a = 7;
//     printf("hello world %d this is fun\n", a);
//     return 0;
// }

// int main() {
//     int a;
//     printf("Informe a: ");
//     scanf("%d", &a);
//     while (a < 14) {
//         printf("a = %d\n", a);
//         a = a + 1;
//     }
    // printf("Digite um valor para a: ");
    // scanf("%d", &a);

    // b = a * 2;
    // printf("Valor lido de a = %d\n", a);
    // printf("Valor de b = %d\n", b);
    // int b = 40;
    // int c;
    // c = a + b * 2;
    // // printf("valor %d\n", c);
    // // return 0;
    // if (a < b && a < 4) {
    //     printf("a menor que b E a < 4\n");
    // } else {
    //     printf("a maior que b OU a >= 4\n");
    // }
//     return 0;
// }

// TEST: relational expressions
// int main() {
//     int a = 5;
//     int b = 10;

//     printf("Testing relational expressions...\n");

//     // Test less than
//     if (a < b) {
//         printf("Test 1 passed: a is less than b\n");
//     } else {
//         printf("Test 1 failed: a is not less than b\n");
//     }

//     // Test greater than
//     if (b > a) {
//         printf("Test 2 passed: b is greater than a\n");
//     } else {
//         printf("Test 2 failed: b is not greater than a\n");
//     }

//     // Test less than or equal to
//     if (a <= b) {
//         printf("Test 3 passed: a is less than or equal to b\n");
//     } else {
//         printf("Test 3 failed: a is not less than or equal to b\n");
//     }

//     // Test greater than or equal to
//     if (b >= a) {
//         printf("Test 4 passed: b is greater than or equal to a\n");
//     } else {
//         printf("Test 4 failed: b is not greater than or equal to a\n");
//     }

//     // Test equality
//     if (a == a) {
//         printf("Test 5 passed: a is equal to a\n");
//     } else {
//         printf("Test 5 failed: a is not equal to a\n");
//     }

//     // Test inequality
//     if (a != b) {
//         printf("Test 6 passed: a is not equal to b\n");
//     } else {
//         printf("Test 6 failed: a is equal to b\n");
//     }

//     return 0;
// }

// TEST: Logical and/or
// int main() {
//     int a = 5;
//     int b = 10;
//     int c = 15;

//     printf("Testing logical expressions...\n");

//     if (a < b && b < c) {
//         printf("Test 1 passed: a is less than b AND b is less than c\n");
//     } else {
//         printf("Test 1 failed: a is not less than b OR b is not less than c\n");
//     }

//     if (a > b || a < c) {
//         printf("Test 2 passed: a is greater than b OR a is less than c\n");
//     } else {
//         printf("Test 2 failed: a is not greater than b AND a is not less than c\n");
//     }

//     return 0;
// }

// TEST Assign, ADD_Assign and SUB_Assign
// int main() {
//     int a = 5;
//     int b = 10;

//     printf("Testing assignment expressions...\n");

//     // Test assignment
//     a = b;
//     if (a == b) {
//         printf("Test 1 passed: a is equal to b after assignment\n");
//     } else {
//         printf("Test 1 failed: a is not equal to b after assignment\n");
//     }

//     // Test add assignment
//     a += b;
//     if (a == 2*b) {
//         printf("Test 2 passed: a is equal to 2*b after add assignment\n");
//     } else {
//         printf("Test 2 failed: a is not equal to 2*b after add assignment\n");
//     }

//     // Test subtract assignment
//     a -= b;
//     if (a == b) {
//         printf("Test 3 passed: a is equal to b after subtract assignment\n");
//     } else {
//         printf("Test 3 failed: a is not equal to b after subtract assignment\n");
//     }

//     return 0;
// }

// TEST: defines
#define max 10
int sla = 666;
int array[max];
int main() {
    int i;
    i = max * 2;
    array[9] = 69;
    printf("array [9] = %d\n", array[9]);
    // printf("max = %d\n", max);
    // printf("i = %d\n", i);
    // printf("sla = %d\n", sla);
    return 0;
}

// TESTE Bitwise
// int main() {
//     // a = 5(00000101), b = 9(00001001)
//     int a = 5, b = 9;
 
//     // The result is 00000001
//     printf("a = %d\n", a);
//     printf("b = %d\n", b);
//     printf("a&b = %d\n", a & b);
 
//     // The result is 00001101
//     printf("a|b = %d\n", a | b);
 
//     // The result is 00001100
//     printf("a^b = %d\n", a ^ b);
 
//     // The result is 11111010
//     printf("~a = %d\n", a = ~a);
 
//     // The result is 00010010
//     printf("b<<1 = %d\n", b << 1);
 
//     // The result is 00000100
//     printf("b>>1 = %d\n", b >> 1);
 
//     return 0;
// }

// TESTE loops
// int main() {
//     int a = 0;
//     while (a < 10) {
//         printf("while a = %d\n", a);
//         a = a + 1;
//     }
//     a = 0;
//     do {
//         printf("do-while a = %d\n", a);
//         a = a + 1;
//     } while (a < 10);
//     for (a = 10; a > 0; a--) {
//         printf("for a = %d\n", a);
//     }
//     return 0;
// }