/*做作业的时候，邻座的小盆友问你：“五乘以七等于多少？”你应该不失礼貌地围笑着告诉他：“五十三。”本题就要求你，对任何一对给定的正整数，倒着输出它们的乘积。*/
#include <stdio.h>
int main(void)
{
    int a, b, c, d, e = 0;
    scanf("%d%d", &a, &b);
    c = a * b;
    while (c != 0)
    {
        d = c % 10;
        e = e * 10 + d;
        c /= 10;
    }
    printf("%d", e);
}