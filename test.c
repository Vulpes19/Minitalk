#include <stdio.h>

int main()
{
    int i;
    char c = '11';

    i = 7;
    while (i >= 0)
    {
        putchar((c & (1 << i)) ? '1' : '0');
        i--;
    }
    return 0;
}