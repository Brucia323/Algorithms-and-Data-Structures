/*本题要求计算并输出不超过n的最大的k个素数以及它们的和。*/
#include <stdio.h>
int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    int a[k], i = 0;
    for (int s = n; i < k; s--)
    {
        int flag = 0;
        if (s == 1)
            break;
        for (int u = 2; u < s; u++)
            if (s % u == 0)
                flag = 1;
        if (!flag)
            a[i++] = s;
    }
    k = i;
    int sum = 0;
    for (i = 0; i < k; i++)
        sum += a[i];
    for (i = 0; i < k - 1; i++)
        printf("%d+", a[i]);
    printf("%d=%d", a[k - 1], sum);
}