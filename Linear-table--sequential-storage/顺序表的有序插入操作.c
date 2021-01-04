/* 本题要求实现一个函数，要求将指定元素插入到有序表的合适位置，使得插入后仍然保持有序，若插入失败返回0；插入成功则返回1，并且顺序表的长度加1. */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
void InitList(SqList &L); /*函数的实现此处不再显示*/
int SqInsert(SqList &L, ElemType e);
int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    scanf("%d", &e);
    int result = SqInsert(L, e);
    if (result == 0)
    {
        printf("Insertion Error.The storage space is full!");
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
int SqInsert(SqList &L, ElemType e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] > e)
        {
            break;
        }
    }
    if (L.length == MAXSIZE)
    {
        return 0;
    }
    if (i == L.length)
    {
        L.elem[i] = e;
    }
    else
    {
        for (int j = L.length - 1; j >= i - 1; j--)
        {
            L.elem[j + 1] = L.elem[j];
        }
        L.elem[i - 1] = e;
    }
    ++L.length;
    return 1;
}