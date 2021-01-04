/* 本题要求实现一个函数，求带头结点的单链表的表长。 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */

int Length(LinkList L);

int main()
{
    LinkList L = Create();
    printf("%d\n", Length(L));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Length(LinkList L)
{
    LinkList p;
    p = L->next;
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}