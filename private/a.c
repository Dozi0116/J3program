#include <stdio.h>

int main(void)
{
    int a = 10, b = 7;
    printf("割って掛ける演算子、掛けて割る演算子\n");

    // 3で割ってから、3で掛ける演算子
    a /*= 3;

    // 5で掛けてから、5で割る演算子
    b */= 5;

    printf("a = %d\nb = %d\n", a, b);
    return 0;
}
