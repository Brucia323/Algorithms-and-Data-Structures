/* 本题要求实现一个函数，求带头结点的单链表中元素序号。 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */

int Locate(LinkList L, ElemType e);

int main()
{
    ElemType e;
    LinkList L = Create();
    scanf("%d", &e);
    printf("%d\n", Locate(L, e));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Locate(LinkList L, ElemType e)
{
    LinkList p;
    int locate = 0;
    p = L->next;
    while (p)
    {
        locate++;
        if (p->data == e)
        {
            return locate;
        }
        p = p->next;
    }
    return 0;
}