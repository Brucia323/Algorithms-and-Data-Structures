#include <iostream>
#include <queue>
using namespace std;
#define TElemType char

typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild; //左右孩子指针
} BiNode, *BiTree;

//1、输入字符序列,建立二叉链表

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

//2、按先根、中根和后根遍历二叉树(递归算法)
//3、按某种形式输出整棵二叉树

//先序遍历二叉树T的递归算法
void PreOrderTraverse(BiTree T)
{
    if (T) //若二叉树非空
    {
        cout << T->data;             //访问根节点
        PreOrderTraverse(T->lchild); //先序遍历左子树
        PreOrderTraverse(T->rchild); //先序遍历右子树
    }
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
//后序遍历二叉树T的递归算法
void PostOrderTraverse(BiTree T)
{
    if (T) //若二叉树非空
    {
        PostOrderTraverse(T->lchild); //后序遍历左子树
        PostOrderTraverse(T->rchild); //后序遍历右子树
        cout << T->data;              //访问根节点
    }
}

//4、求二又树的高度

//计算二叉树T的深度
int BiTreeDepth(BiTree T)
{
    int m, n;
    if (T == NULL)
        return 0; //如果是空树，深度为0，递归结束
    else
    {
        m = BiTreeDepth(T->lchild); //递归计算左子树的深度记为m
        n = BiTreeDepth(T->rchild); //递归计算右子树的深度记为n
        if (m > n)
            return (m + 1); //二叉树的深度为m与n的较大者加1
        else
            return (n + 1);
    }
}

//5、求二叉树的叶节点个数

//计算叶子结点的个数
void Count(BiTree T, int &count)
{
    if (T == NULL)
        return; //如果是空树，则叶子结点个数为0，递归结束
    if (T->lchild)
        Count(T->lchild, count); //非叶子结点，递归
    if (T->rchild)
        Count(T->rchild, count); //非叶子结点，递归
    if (T->lchild == NULL && T->rchild == NULL)
        count++; //叶子结点，计数
}

//6、交换二叉树的左右子树

//交换二叉树T的左右子树
void ExchangeChild(BiTree &T)
{
    if (T->lchild == NULL && T->rchild == NULL)
        return;            //无左右子树，递归结束
    if (T->lchild == NULL) //左子树为空，只有右子树
    {
        T->lchild = T->rchild;
        T->rchild = NULL;
        ExchangeChild(T->lchild);
    }
    else if (T->rchild == NULL) //右子树为空，只有左子树
    {
        T->rchild = T->lchild;
        T->lchild = NULL;
        ExchangeChild(T->rchild);
    }
    else //有左右子树
    {
        BiTree empty;      //创建空结点
        empty = T->lchild; //临时存储其中一棵子树
        T->lchild = T->rchild;
        T->rchild = empty;
        ExchangeChild(T->lchild);
        ExchangeChild(T->rchild);
    }
}

//7、实现二叉树的层次遍历（可以借用队列实现）

//层次遍历二叉树T
void LevelOrderTraverse(BiTree &T)
{
    if (T == NULL)
        return; //树空
    queue<BiTree> Q;
    Q.push(T);
    while (!Q.empty())
    {
        T = Q.front();
        Q.pop();
        cout << T->data; //输出对应结点数据
        if (T->lchild)
            Q.push(T->lchild); //左孩子入队
        if (T->rchild)
            Q.push(T->rchild); //右孩子入队
    }
}

int main(void)
{
    BiTree T, T1;
    cout << "请输入字符序列,以建立二叉链表:";
    CreateBiTree(T);
    while (1)
    {
        cout << "1.按先序序列输出整棵二叉树。" << endl;
        cout << "2.按中序序列输出整棵二叉树。" << endl;
        cout << "3.按后序序列输出整棵二叉树。" << endl;
        cout << "4.求二叉树的高度。" << endl;
        cout << "5.求二叉树的叶结点个数。" << endl;
        cout << "6.交换二叉树的左右子树。" << endl;
        cout << "7.按层次遍历输出整棵二叉树。" << endl;
        cout << "0.退出。" << endl;
        cout << "请输入想要进行的操作序号：";
        int i;
        cin >> i;
        int count = 0;
        int high = 0;
        T1 = T;
        switch (i)
        {
        case 1:
            PreOrderTraverse(T);
            break;
        case 2:
            InOrderTraverse(T);
            break;
        case 3:
            PostOrderTraverse(T);
            break;
        case 4:
            high = BiTreeDepth(T);
            cout << "二叉树的高度为" << high;
            break;
        case 5:
            Count(T, count);
            cout << "一共" << count << "个叶子结点";
            break;
        case 6:
            ExchangeChild(T);
            cout << "完成";
            break;
        case 7:
            LevelOrderTraverse(T1);
            break;
        default:
            break;
        }
        cout << endl;
        if (i == 0)
            break;
    }
}