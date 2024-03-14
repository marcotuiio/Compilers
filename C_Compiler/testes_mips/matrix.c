int main() {
    int m[2][2];
    int i, j;
    int a = 666;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            m[i][j] = a;
            // printf("nao sei mas a %d e %d\n", a, m[i][j]);
            a = a + 1;
        }
    }
    // for (i = 0; i < 2; i++) {
    //     printf("%d %d\n", m[i][0], m[i][1]);
    // }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}