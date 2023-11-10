warning:1:14: right shift count >= width of type
#define c1 1 >> 32
             ^
warning:2:14: left shift count >= width of type
#define c2 1 << 33
             ^
error:semantic:2:27: variable 'c2' already declared, previous declaration in line 2 column 9
#define c2 1 << 33
                          ^