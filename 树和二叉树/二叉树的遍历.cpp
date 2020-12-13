/*根据输入构造二叉树，输出该二叉树的先序序列。二叉树共有N个节点，节点编号是1到N。约定1号节点是根节点。*/
#include <iostream>
using namespace std;
typedef struct BiTNode
{
    int lchild; //左孩子
    int rchild; //右孩子
} BiTNode, *BiTree;
void PreOrderTraverse(BiTNode T[], int root)
{
    if (root == 0)
        return;
    cout << root << " ";
    PreOrderTraverse(T, T[root].lchild);
    PreOrderTraverse(T, T[root].rchild);
}
int main(void)
{
    int n; //n行
    cin >> n;
    BiTNode T[n + 1]; //0下标不用
    for (int i = 1; i < n + 1; i++)
        cin >> T[i].lchild >> T[i].rchild;
    PreOrderTraverse(T, 1);
}