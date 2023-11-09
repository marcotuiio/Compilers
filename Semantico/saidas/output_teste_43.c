Achei p 275 1 = 0
casting
Achei i 275 0 = 0
Achei i 275 0 = 0
Achei c 276 0 = 0
warning:5:20: 'int*'/'char*' type mismatch in conditional expression
    p = (char)(i?&i:&c);
                   ^
castando left 276 0
castando right 276 1

error:semantic:5:7: incompatible types when assigning to type 'int*' from type 'char'
    p = (char)(i?&i:&c);
      ^