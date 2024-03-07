// ./gerador asms/fatorial.asm codigos_entradas/fatorial.c
// ./gerador asms/potencia.asm codigos_entradas/potencia.c
// ./gerador asms/comparacao.asm codigos_entradas/comparacao.c
// ./gerador asms/quicksort.asm codigos_entradas/quicksort.c
// ./gerador asms/triangulo.asm codigos_entradas/triangulo.c
// ./gerador asms/test.asm codigos_entradas/test.c

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

// void test(int fish, int ball) {
//     int i = 987;
//     printf("bucetoncios laringicus %d a = %d b = %d\n", i++, fish, ball);
// }

// int segredo(int a, int b) {
//     if (a > b) {
//         return a + b;
//     }
//     if (a <= b) {
//         return b - a;
//     }
// }

// int main() {
//     int a = 1000, b = 999;
//     // int zeca = 3;
//     // printf("a e b => %d\n", soma(a, 1012));
//     // test(a, b);
//     int c = segredo(a, b);
//     printf("hello world (a %d) this is fun (b %d) %d %d %d\n", a, b, 6, 7, c);
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
//     // printf("Digite um valor para a: ");
//     // scanf("%d", &a);

//     // b = a * 2;
//     // printf("Valor lido de a = %d\n", a);
//     // printf("Valor de b = %d\n", b);
//     // int b = 40;
//     // int c;
//     // c = a + b * 2;
//     // // printf("valor %d\n", c);
//     // // return 0;
//     // if (a < b && a < 4) {
//     //     printf("a menor que b E a < 4\n");
//     // } else {
//     //     printf("a maior que b OU a >= 4\n");
//     // }
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
//     int a = 50;
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
// #define max 34
// // int sla = 666;
// int array[10];
// int main() {
//     int i;
//     int v[6];
//     // i = max * 2;
//     array[9] = 69;
//     v[2] = 1;
//     i = array[9];
//     if (array[9] == array[0]) {
//         printf("bucetoncios langeicus\n");
//     } else {
//         printf("cuuu buuu\n");
//     }
//     for (i = 0; i < 10; i++) {
//         printf("v[%d] = %d\n", i, v[i]);
//         printf("array[%d] = %d\n", i, array[i]);
//     }
//     // printf("max = %d\n", max);
//     // printf("i = %d\n", i);
//     // printf("sla = %d\n", sla);
//     return 0;
// }

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
//         printf("while a = %d\n", a++);
//     }
//     a = 0;
//     do {
//         printf("do-while a = %d\n", ++a);
//         // a = a + 1;
//     } while (a < 10);
//     for (a = 10; a > 0; a--) {
//         printf("for a = %d\n", a);
//     }
//     return 0;
// }

// TEST ternary
// int main() {
//     int a = 5;
//     int b = 10;
//     int c;
//     c = (a > b) ? a+1 : b-1;
//     printf("c = %d\n", c);
//     return 0;
// }

// #define max 10
// // // int a;
// int b;

// int soma(int a, int b) {
//     printf("params %d %d\n", a, b);
//     return a + b;
// }

// // int v[3];
// // int teste = 7%3 + 9;
// // char c = 'a';

// int main() {
//     int a[max];
//     int i;
//     b = 999;
//     // printf("teste = %d\n", teste);
//     // printf("c = %c\n", c);
//     a[0] = 1;
//     a[1] = 2;
//     a[2] = 3;
//     a[3] = a[0] + a[1];
//     // v[0] = 666;
//     for (i = 0; i < 2; i++) {
//         printf("%d soma %d\n", i, soma(a[i], a[i+1]));
//     }
//     // printf("b = a(%d) + cu(%d) = %d\n", a, cu, b);
//     // printf("c local = %d\n", c);
//     return(666);
// }

// #define c1 10
// #define c2 -c1
// #define c3 c1 << 2
// #define c4 c2 >> c3* c3
// #define NULL 0
// #define CALL_ELEVEN 11
// int v[c2 + c3];

// void** f() {
//     void** v;
//     return v;
// }
// #define TRUE 1
// #define FALSE 0
// #define SERA_VERDADE (TRUE || FALSE)
// char* vetor[SERA_VERDADE];

// char g(int arg_1, char arg_2, int arg_3) {
//     char* c;
//     c = "DDominar o mundo\n";
//     printf("%s", c + 1);
//     c++;
//     printf("E depois novamente ");
//     while (*c != '\0') {
//         printf("%c", *c);
//         g(1 + 2 * 3 - 4 * 5, *c, CALL_ELEVEN + 666);
//     }
//     return *(vetor[1 << 1]);
// }

// int main() {
//     int* ptr;
//     int* i;
//     for (ptr = v; ptr; ptr++) {
//         while (*ptr) {
//             if (ptr <= 0) {
//                 *ptr = 666;
//                 *i /*Porta para o mundo invertido*/ = CALL_ELEVEN + 666;
//             } else {
//                 do {
//                     ptr++;
//                 } while (v);
//             }
//         }
//     }
//     return (*ptr + *i);
//     // return 0;
// }

// TESTE STRINGS
#define c1 10

int main() {
    // char sla = '\n';
    char *c;
    char *c2 = "E depois novamente ";
    c = "DDominar o mundo\n";

    while (*c != '\0') {
        printf("%c ", *c);
        c++;
    }

    // printf("sla = %c\n", sla);
    printf("antes c = %s\n", c);
    printf("depois c = %s\n", ++c);
    printf("c2 = %s\n", c2);

    return 0;
}

// #define CALL_ELEVEN 11

// int main() {
//     int v[5];
//     int *i;
//     int* ptr;
//     int out = 0;
//     v[0] = 1;
//     v[1] = 2;
//     v[2] = 3;
//     v[3] = 4;
//     // v[4] = 5;
//     // *ptr = 666;
//     // printf("ptr = %d\n", *ptr);
//     for (ptr = v; ptr; ptr++) {
//         while (*ptr) {
//             if (*ptr <= 0) {
//                 *ptr = 666;
//                 *i /*Porta para o mundo invertido*/ = CALL_ELEVEN + 666;
//                 printf("ptr = %d\n", *ptr);
//                 printf("i = %d\n", *i);
//             } else {
//                 do {
//                     ptr++;
//                 } while (*ptr);
//             }
//         }
//     }
//     out = (*ptr + *i);
//     printf("out = %d\n", out);
//     return 0;
// }