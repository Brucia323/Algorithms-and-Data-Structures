/* ����Ҫ��ʵ��һ��������ͳ�ƴ�ͷ���ĵ�������ĳ��Ԫ�س��ֵĴ����� */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* ϸ���ڴ˲��� */

int GetCount(LinkList L, ElemType e);

int main()
{
    ElemType e;
    LinkList L = Create();
    scanf("%d", &e);
    printf("%d\n", GetCount(L, e));
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

/* ��Ĵ��뽫��Ƕ������ */

int GetCount(LinkList L, ElemType e)
{
    LinkList p;
    p = L->next;
    int i = 0;
    while (p)
    {
        if (p->data == e)
        {
            i++;
        }
        p = p->next;
    }
    return i;
}