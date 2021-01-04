/* 本题要求实现一个函数，返回带头结点的单链表中奇数的个数。 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */

int OddNumber(LinkList L);
int main()
{
    LinkList L, p;
    ElemType e;
    L = Create();
    printf("Odd number is %d.\n", OddNumber(L));
    return 0;
}
/* 你的代码将被嵌在这里 */
int OddNumber(LinkList L)
{
    LinkList p;
    int i = 0;
    p = L->next;
    while (p)
    {
        if(p->data%2!=0)
        {
            i++;
        }
        else if(p->data==1)
        {
            i++;
        }
        p = p->next;
    }
    return i;
}