/* 本题要求实现删除单链表的第i个元素结点，删除成功返回1，否则返回0。 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */
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

/* 请在这里填写答案 */
int delete_link(LinkList L, int i)
{
    LinkList p,q;
    p = L;
    int j = 0;
    while ((p->next)&&(j<i-1))
    {
        p = p->next;
        ++j;
    }
    if (!(p->next)||(j>i-1))
    {
        return 0;
    }
    q = p->next;
    p->next = q->next;
    return 1;
}