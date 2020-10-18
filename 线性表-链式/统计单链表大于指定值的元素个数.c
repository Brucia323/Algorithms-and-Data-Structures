/* 本题要求实现一个函数，可统计带头结点的单链表中大于指定值的元素个数。 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */

int GetLarger(LinkList L, ElemType e);

int main()
{
    ElemType e;
    LinkList L = Create();
    scanf("%d", &e);
    printf("%d\n", GetLarger(L, e));
    return 0;
}
LinkList Create()
{
    LinkList L, r, p;
    ElemType e;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    r = L;
    scanf("%d", &e);
    while (e != -1)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->data = e;
        p->next = r->next;
        r->next = p;
        r = p;
        scanf("%d", &e);
    }
    return L;
}

/* 你的代码将被嵌在这里 */

int GetLarger(LinkList L, ElemType e)
{
    int i = 0;
    LinkList p;
    p = L->next;
    while (p)
    {
        if (p->data > e)
        {
            i++;
        }
        p = p->next;
    }
    return i;
}