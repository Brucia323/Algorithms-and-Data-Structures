/*����һ�÷ǿն������������������Ϊ������0�����������д��������ö������е�k�����һ������ֵ���������������0��*/
#include <iostream>
#include <queue>
using namespace std;
int k = 0;
typedef struct BiTNode
{
    int data;                        //���������
    struct BiTNode *lchild, *rchild; //���Һ���ָ��
} BiTNode, *BiTree;
void CreateBiTree(BiTree &T)
{ //���������
    int i;
    cin >> i;
    if (i == 0)
        T = NULL; //��������0,��ʾ�ö������ǿ���
    else
    {
        T = new BiTNode;
        T->data = i; //��������
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
struct node
{
    BiTree T;
    int c;
};
void Get_layers(BiTree T, int F[])
{
    if (T == NULL)
        return;
    queue<node> Q;
    node now;
    now.T = T;
    now.c = 0;
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (now.T->data)
            F[now.c] = now.T->data;
        node next;
        next.c = now.c + 1;
        if (now.T->lchild)
        {
            next.T = now.T->lchild;
            Q.push(next);
        }
        if (now.T->rchild)
        {
            next.T = now.T->rchild;
            Q.push(next);
        }
    }
}
int main(void)
{
    BiTree T;
    int F[1000] = {0};
    CreateBiTree(T);
    Get_layers(T, F);
    cin >> k;
    cout << F[k] << endl;
}
/*-------------------------------------------------------*/
/*#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int k[1005] = {0};
int l = 0;
int f = 0;
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
int CreateTree(BiTree &T)
{
    int x;
    cin >> x;
    if (x == 0)
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = x;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
    return 1;
}
struct node
{
    BiTree T;
    int c;
};
int LevelOrderTraverse(BiTree T)
{
    queue<node> q;
    node now;
    now.T = T;
    now.c = 0;
    if (T != NULL)
        q.push(now);
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (now.T->data)
            k[now.c] = now.T->data;
        node next;
        next.c = now.c + 1;
        next.T = now.T->lchild;
        if (now.T->lchild)
            q.push(next);
        next.T = now.T->rchild;
        if (now.T->rchild)
            q.push(next);
    }
}
int main()
{
    BiTree T;
    T = new BiTNode;
    CreateTree(T);
    LevelOrderTraverse(T);
    int m;
    cin >> m;
    cout << k[m] << endl;
    return 0;
}*/