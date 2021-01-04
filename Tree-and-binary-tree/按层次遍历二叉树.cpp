/*以字符串的形式定义一棵二叉树的先序序列，若字符是‘#’, 表示该二叉树是空树，否则该字符是相应结点的数据元素。读入相应先序序列，建立二叉树，然后按层次遍历该二叉树并输出结点数据。*/
#include <iostream>
#include <queue>
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
void LevelOrderTraverse(BiTree &T)
{
    if (T == NULL)
        return;
    queue<BiTree> Q;
    Q.push(T);
    while (!Q.empty())
    {
        T=Q.front();
        Q.pop();
        cout << T->data;
        if (T->lchild)
            Q.push(T->lchild);
        if (T->rchild)
            Q.push(T->rchild);
    }
}
int main(void)
{
    BiTree T;
    CreateBiTree(T);
    LevelOrderTraverse(T);
    cout << endl;
}