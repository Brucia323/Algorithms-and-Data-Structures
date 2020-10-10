/* 本题要求实现一个函数，要求从顺序表中查找指定元素，并返回第一个查找成功的元素在表中的位置序号，若查找失败，则返回0； */
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
int LocateElem(SqList L, ElemType e);

int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    int p;
    scanf("%d", &e);
    p = LocateElem(L, e);
    printf("The position of %d in SequenceList L is %d.", e, p);
    return 0;
}

/* 请在这里填写答案 */
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}