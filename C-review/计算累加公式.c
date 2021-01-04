/*输入x，编程计算1−x^2/​3!+​​x^4/​​5!-x^6/7!+...的值，精度为0.000001*/
//测试点1答案错误
#include <stdio.h>
#include <math.h>
int main(void)
{
    int n = 0, m = 1, a = 0, b = 1, j = 1;
    double x, sum = 0, s = 1;
    scanf("%lf", &x);
    while (s >= 1e-6)
    {
        s = pow(x, n) / m;
        sum += pow(-1, a) * (pow(x, n) / m); //此处可用s
        j += 2;
        for (; b <= j; b++)
            m *= b;
        n += 2;
        a += 1;
    }
    printf("%.7lf", sum);
}