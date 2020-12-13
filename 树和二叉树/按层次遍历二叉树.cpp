/*以字符串的形式定义一棵二叉树的先序序列，若字符是‘#’, 表示该二叉树是空树，否则该字符是相应结点的数据元素。读入相应先序序列，建立二叉树，然后按层次遍历该二叉树并输出结点数据。*/
#include <iostream>
using namespace std;
typedef struct BiTNode
{
    char data;                       //结点数据域
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;
typedef struct Queue
{
    BiTree data;
    struct Queue *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;
void CreateBiTree(BiTree &T)
{ //构造二叉树
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL; //若字符是‘#’,表示该二叉树是空树
    else
    {
        T = new BiTNode;
        T->data = ch; //先序序列
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.rear->next = new QNode;
}
void EnQueue(LinkQueue &Q, BiTree &T)
{
    Q.rear = Q.rear->next;
    Q.rear->data = T;
    Q.rear->next = new QNode;
}
bool QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return false;
    else
        return true;
}
void DeQueue(LinkQueue &Q, BiTree &T)
{
    if (Q.front == Q.rear)
        return;
    T = Q.front->next->data;
    Q.front = Q.front->next;
}
void LevelOrderTraverse(BiTree &T)
{
    if (T == NULL)
        return;
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);
    while (QueueEmpty(Q))
    {
        DeQueue(Q, T);
        cout << T->data;
        if (T->lchild)
            EnQueue(Q, T->lchild);
        if (T->rchild)
            EnQueue(Q, T->rchild);
    }
}
int main(void)
{
    BiTree T;
    CreateBiTree(T);
    LevelOrderTraverse(T);
    cout << endl;
}