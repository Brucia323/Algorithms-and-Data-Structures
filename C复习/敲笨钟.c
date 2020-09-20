/*微博上有个自称“大笨钟V”的家伙，每天敲钟催促码农们爱惜身体早点睡觉。为了增加敲钟的趣味性，还会糟改几句古诗词。其糟改的方法为：去网上搜寻压“ong”韵的古诗词，把句尾的三个字换成“敲笨钟”。例如唐代诗人李贺有名句曰：“寻章摘句老雕虫，晓月当帘挂玉弓”，其中“虫”（chong）和“弓”（gong）都压了“ong”韵。于是这句诗就被糟改为“寻章摘句老雕虫，晓月当帘敲笨钟”。

现在给你一大堆古诗词句，要求你写个程序自动将压“ong”韵的句子糟改成“敲笨钟”。*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    int N, i, j, len, flag1, flag2, count, pos;
    scanf("%d", &N);
    getchar();
    char a[101];
    for (int i = 0; i < N; i++)
    {
        len = 0;
        flag1 = 0;
        flag2 = 0;
        count = 0;
        gets(a);
        len = strlen(a);
        for (j = 0; j < len; j++)
        {
            if (a[j] == ',' && a[j - 1] == 'g' && a[j - 2] == 'n' && a[j - 3] == 'o')
                flag1 = 1;
            if (a[j] == '.' && a[j - 1] == 'g' && a[j - 2] == 'n' && a[j - 3] == 'o')
                flag2 = 1;
        }
        if (flag1 == 1 && flag2 == 1)
        {
            for (j = len - 1; j >= 0; j--)
            {
                if (a[j] == ' ')
                    count++;
                if (count == 3)
                {
                    pos = j;
                    break;
                }
            }
            for (j = 0; j < pos; j++)
                printf("%c", a[j]);
            printf(" qiao ben zhong.\n");
        }
        else
            printf("Skipped\n");
    }
}