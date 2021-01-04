/*以二叉链表作为二叉树的存储结构，交换二叉树中每个结点的左孩子和右孩子。*/
#include <iostream>
using namespace std;
typedef struct BiTNode
{
    char data;                       //结点数据域
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;
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
void FrontInOrderTraverse(BiTree T)
{
    if (T)
    {
        FrontInOrderTraverse(T->lchild);
        cout << T->data;
        FrontInOrderTraverse(T->rchild);
    }
}
void AfterInOrderTraverse(BiTree T)
{
    if (T)
    {
        FrontInOrderTraverse(T->lchild);
        cout << T->data;
        FrontInOrderTraverse(T->rchild);
    }
}
void ExchangeChild(BiTree &T)
{
    if (T->lchild == NULL && T->rchild == NULL)
        return;
    if (T->lchild == NULL)
    {
        T->lchild = T->rchild;
        T->rchild = NULL;
        ExchangeChild(T->lchild);
    }
    else if (T->rchild == NULL)
    {
        T->rchild = T->lchild;
        T->lchild = NULL;
        ExchangeChild(T->rchild);
    }
    else
    {
        BiTree empty;
        empty = T->lchild;
        T->lchild = T->rchild;
        T->rchild = empty;
        ExchangeChild(T->lchild);
        ExchangeChild(T->rchild);
    }
}
int main(void)
{
    BiTree T;
    CreateBiTree(T);
    FrontInOrderTraverse(T);
    cout << endl;
    ExchangeChild(T);
    AfterInOrderTraverse(T);
}