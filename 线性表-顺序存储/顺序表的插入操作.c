/* 本题要求实现一个函数，在顺序表的第i个位置插入一个新的数据元素e，插入成功后顺序表的长度加1，函数返回值为1；插入失败函数返回值为0； */
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
int ListInsert(SqList &L, int i, ElemType e);
int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    int i;
    scanf("%d%d", &i, &e);
    int result = ListInsert(L, i, e);
    if (result == 0)
    {
        printf("Insertion Error.The value of i is unlawful or the storage space is full!");
    }
    else if (result == 1)
    {
        printf("Insertion Success.The elements of the SequenceList L are:");
        for (int j = 0; j < L.length; j++)
        {
            printf(" %d", L.elem[j]);
        }
    }
    return 0;
}
/* 请在这里填写答案 */
int ListInsert(SqList &L, int i, ElemType e)
{
    if ((i < 1) || (i > L.length + 1))
    {
        return 0;
    }
    if (L.length == MAXSIZE)
    {
        return 0;
    }
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    ++L.length;
    return 1;
}