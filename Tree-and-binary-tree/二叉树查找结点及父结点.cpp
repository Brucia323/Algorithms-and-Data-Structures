//不完全可用
/*编写程序在二叉树中查找给定结点及父结点。二叉树结点的数据域值不等于0的整数。*/
#include <iostream>
using namespace std;
typedef struct BiTNode
{
    int data;                        //结点数据域
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;
void CreateBiTree(BiTree &T)
{ //按先序输入二叉树中结点的值，创建二叉链表表示的二叉树T
    int i;
    cin >> i;
    if (i == 0)
        T = NULL; //递归结束，建空树
    else
    {
        T = new BiTNode;         //生成根节点
        T->data = i;             //根节点数据域置为i
        CreateBiTree(T->lchild); //递归创建左子树
        CreateBiTree(T->rchild); //递归创建右子树
    }
}
void Parent(BiTree T, int e)
{
    if (T == NULL)
        return; //树空，停止递归
    if (T->data == e)
        cout << "0" << endl; //无父节点
    else if (T->lchild != NULL && T->lchild->data == e)
        cout << T->data << endl; //父节点
    else if (T->rchild != NULL && T->rchild->data == e)
        cout << T->data << endl; //父节点
    else
    {
        Parent(T->lchild, e);
        Parent(T->rchild, e);
    }
}
int main(void)
{
    BiTree T;
    CreateBiTree(T);
    int m;
    cin >> m; //查询个数
    int k;
    while (m--)
    {
        cin >> k; //要查找的结点的数据值
        Parent(T, k);
    }
}
/*----------------------------------------------------------*/
/*#include <iostream>
using namespace std;
typedef struct BiNode
{
    int data;
    struct BiNode *rchild, *lchild;
} BNode, *BiTree;
int flag = 0;
BiTree createNode()
{
    BiTree p = new BNode;
    p->rchild = p->lchild = NULL;
    return p;
}
void createBiTree(BiTree &T)
{
    int c;
    cin >> c;
    if (c == 0)
        T = NULL;
    else
    {
        T = new BNode;
        T->data = c;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}
void Find_Father(BiTree &T, int data)
{
    if (T == NULL)
        return;
    if (T->lchild != NULL)
    {
        if (T->lchild->data == data)
        {
            cout << T->data << endl;
            ;
            flag = 1;
        }
    }
    if (T->rchild != NULL)
    {
        if (T->rchild->data == data)
        {
            cout << T->data << endl;
            ;
            flag = 1;
        }
    }
    Find_Father(T->lchild, data);
    Find_Father(T->rchild, data);
}
void findfather(BiTree &T, int data)
{
    flag = 0;
    Find_Father(T, data);
    if (flag == 0)
    {
        cout << "0" << endl;
    }
}
int main()
{

    BiTree p = createNode();
    createBiTree(p);
    int m;
    int n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        findfather(p, n);
    }
    return 0;
}*/