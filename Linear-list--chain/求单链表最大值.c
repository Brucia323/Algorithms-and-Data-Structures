/* 本题要求实现一个函数，返回带头结点的单链表中最大元素的地址。 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */

LinkList MaxP(LinkList L);

int main()
{
    LinkList L, p;
    ElemType e;
    L = Create();
    p = MaxP(L);
    if (p)
        printf("%d\n", p->data);
    else
        printf("NULL");
    return 0;
}

/* 你的代码将被嵌在这里 */
LinkList MaxP(LinkList L)
{
    if (L == NULL || L->next == NULL)
    {
        return NULL;
    }
    LinkList p, q;
    p = L->next;
    q = p;
    while (p != NULL)
    {
        if (p->data > q->data)
        {
            q = p;
        }
        p = p->next;
    }
    return q;
}