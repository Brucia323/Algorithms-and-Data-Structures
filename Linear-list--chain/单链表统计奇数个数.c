/* ����Ҫ��ʵ��һ�����������ش�ͷ���ĵ������������ĸ����� */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* ϸ���ڴ˲��� */

int OddNumber(LinkList L);
int main()
{
    LinkList L, p;
    ElemType e;
    L = Create();
    printf("Odd number is %d.\n", OddNumber(L));
    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
int OddNumber(LinkList L)
{
    LinkList p;
    int i = 0;
    p = L->next;
    while (p)
    {
        if (p->data % 2 != 0)
        {
            i++;
        }
        else if (p->data == 1)
        {
            i++;
        }
        p = p->next;
    }
    return i;
}