/* 本题要求实现一个函数，要求返回顺序表中指定元素值的个数，空表返回0。题目保证顺序表中所有元素都为整数。 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
void InitList(SqList &L); /*细节在此不表*/
int GetCount(SqList L, ElemType e);

int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    scanf("%d", &e);
    printf("The number of %d is %d.\n", e, GetCount(L, e));
    return 0;
}

/* 请在这里填写答案 */
int GetCount(SqList L, ElemType e)
{
    if (L.length == 0)
    {
        return 0;
    }
    int i, j = 0;
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            j++;
        }
    }
    return j;
}