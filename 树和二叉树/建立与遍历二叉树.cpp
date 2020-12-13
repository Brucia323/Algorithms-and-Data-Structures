/*以字符串的形式定义一棵二叉树的先序序列，若字符是‘#’, 表示该二叉树是空树，否则该字符是相应结点的数据元素。读入相应先序序列，建立二叉链式存储结构的二叉树，然后中序遍历该二叉树并输出结点数据。*/
#include <iostream>
using namespace std;
#define TElemType char

typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild; //左右孩子指针
} BiNode, *BiTree;
//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
void CreateBiTree(BiTree &T)
{
    TElemType ch;
    cin >> ch;
    if (ch == '#')
        T = NULL; //递归结束，建空树
    else          //递归创建二叉树
    {
        T = new BiNode;          //生成根节点
        T->data = ch;            //根节点数据域置为ch
        CreateBiTree(T->lchild); //递归创建左子树
        CreateBiTree(T->rchild); //递归创建右子树
    }                            //else
}
//中序遍历二叉树T的递归算法
void InOrderTraverse(BiTree T)
{
    if (T) //若二叉树非空
    {
        InOrderTraverse(T->lchild); //中序遍历左子树
        cout << T->data;            //访问根节点
        InOrderTraverse(T->rchild); //中序遍历右子树
    }
}
int main(void)
{
    BiTree T;
    CreateBiTree(T);
    InOrderTraverse(T);
}