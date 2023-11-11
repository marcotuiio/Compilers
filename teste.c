#include <stdio.h>  

#define c1 10
#define c2 -c1
#define c3 c1 << 2
#define c4 c2 >> c3*c3
int main() {
    printf("c3 %d\n", c3);
    printf("c4 %d\n", c4);
    return 0;
}