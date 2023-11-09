void f()
{
    char c;
    int i = 1;
    int* p;
    p = i?&i:&c;
}