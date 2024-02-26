// #include <stdio.h>
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

// TEST: loops
int main() {
    int i = 1;
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}