/* ����Ҫ��ʵ��ɾ��������ĵ�i��Ԫ�ؽ�㣬ɾ���ɹ�����1�����򷵻�0�� */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* ϸ���ڴ˲��� */
void print(LinkList L);
int delete_link(LinkList L, int i);

int main()
{

    LinkList L = Create();
    int position;
    int flag;
    scanf("%d", &position);
    flag = delete_link(L, position);
    if (flag)
    {
        print(L);
    }
    else
    {
        printf("Wrong Position for Deletion");
    }
    return 0;
}
void print(LinkList L)
{
    LinkList p;
    p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

/* ����������д�� */
int delete_link(LinkList L, int i)
{
    LinkList p, q;
    p = L;
    int j = 0;
    while ((p->next) && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || (j > i - 1))
    {
        return 0;
    }
    q = p->next;
    p->next = q->next;
    return 1;
}