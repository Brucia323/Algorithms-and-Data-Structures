/* 本题要求实现一个函数，要求返回顺序表的最大值，空表返回0。题目保证顺序表中所有元素都为正整数。 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
void InitList(SqList &L); /*细节在此不表*/
int GetMax(SqList L);

int main()
{
    SqList L;
    InitList(L);
    int p;
    p = GetMax(L);
    if (p)
        printf("The max of SequenceList L is %d.\n", p);
    else
        printf("The SequenceList is null.\n");
    return 0;
}

/* 请在这里填写答案 */
int GetMax(SqList L)
{
    if (L.length == 0)
    {
        return 0;
    }
    int i, max = L.elem[0];
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] > max)
        {
            max = L.elem[i];
        }
    }
    return max;
}