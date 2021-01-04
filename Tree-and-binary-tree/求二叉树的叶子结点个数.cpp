/*以二叉链表作为二叉树的存储结构，求二叉树的叶子结点个数。*/
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
void InOrderTraverse(BiTree T)
{          //中序遍历二叉树T的递归算法
    if (T) //若二叉树非空
    {
        InOrderTraverse(T->lchild); //中序遍历左子树
        cout << T->data;            //访问根节点
        InOrderTraverse(T->rchild); //中序遍历右子树
    }
}
void Count(BiTree T, int &count)
{ //计算叶子结点的个数
    if (T == NULL)
        return;
    if (T->lchild)
        Count(T->lchild, count);
    if (T->rchild)
        Count(T->rchild, count);
    if (T->lchild == NULL && T->rchild == NULL)
        count++;
}
int main(void)
{
    BiTree T;
    CreateBiTree(T);
    InOrderTraverse(T);
    cout << endl;
    int count = 0;
    Count(T, count);
    cout << count;
}