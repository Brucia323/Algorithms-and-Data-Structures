#include <iostream>
using namespace std;
typedef struct
{
    int key; //主关键字
} ElemType;
typedef struct
{
    ElemType *R; //表基址
    int length;  //表长
} SSTable;
//构造一个空的顺序表ST
void InitList(SSTable &ST, int n)
{
    ST.R = new ElemType[n]; //为顺序表分配一个大小为100的数组空间
    ST.length = n;
}
//创建顺序表
void CreateList(SSTable &ST)
{
    int key;
    for (int i = 0; i < ST.length; i++)
    {
        cin >> key;
        ST.R[i].key = key;
    }
}
//在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的未知，否则为0
int Search_Seq(SSTable ST, int key)
{
    int i;
    ST.R[0].key = key; //“哨兵”
    for (i = ST.length; ST.R[i].key != key; --i)
        ; //从后往前找
    return i;
}
//在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0
int Search_Bin(SSTable ST, int key)
{
    int low = 1, high = ST.length; //置查找区间初值
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == ST.R[mid].key)
            return mid; //找到待查元素
        else if (key < ST.R[mid].key)
            high = mid - 1; //继续在前一子表进行查找
        else
            low = mid + 1; //继续在后一子表进行查找
    }
    return 0; //表中不存在待查元素
}
//二叉排序树的二叉链表存储表示
typedef struct BSTNode
{
    ElemType data;                   //每个结点的数据域
    struct BSTNode *lchild, *rchild; //左右孩子指针
} BSTNode, *BSTree;
//当二叉排序树T中不存在关键字等于w.key的数据元素时，则插入该元素
void InsertBST(BSTree &T, ElemType e)
{
    BSTree S;
    //找到插入位置，递归结束
    if (!T)
    {
        S = new BSTNode;              //生成新结点*S
        S->data = e;                  //新结点*S的数据域置为e
        S->lchild = S->rchild = NULL; //新结点*S作为叶子结点
        T = S;                        //把新结点*S链接到已找到的插入位置
    }
    else if (e.key < T->data.key)
        InsertBST(T->lchild, e); //将*S插入左子树
    else if (e.key > T->data.key)
        InsertBST(T->rchild, e); //将*S插入右子树
}
//依次读入一个关键字为key的结点，将此结点插入二叉排序树T中
void CreateBST(BSTree &T, SSTable ST)
{
    T = NULL; //将二叉排序树T初始化为空树
    for (int i = 0; i < ST.length; i++)
        InsertBST(T, ST.R[i]); //将此结点插入二叉排序树T中
}
//中序遍历二叉树T的递归算法
void InOrderTraverse(BSTree T)
{
    //若二叉树非空
    if (T)
    {
        InOrderTraverse(T->lchild); //中序遍历左子树
        cout << T->data.key << " "; //访问根结点
        InOrderTraverse(T->rchild); //中序遍历右子树
    }
}
//在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素
//若查找成功，则返回指向该数据元素结点的指针，否则返回空指针
BSTree SearchBST(BSTree T, int key)
{
    if ((!T) || key == T->data.key)
        return T; //查找结束
    else if (key < T->data.key)
        return SearchBST(T->lchild, key); //在左子树中继续查找
    else
        return SearchBST(T->rchild, key); //在右子树中继续查找
}
int main(void)
{
    SSTable ST;
    BSTree T;
    int n, key;
    cout << "表长：";
    cin >> n;
    cout << "表内元素：";
    InitList(ST, n);
    CreateList(ST);
    cout << "需要查找的元素：";
    cin >> key;
    cout << "顺序查找结果：" << Search_Seq(ST, key) << endl;
    cout << "折半查找结果：" << Search_Bin(ST, key) << endl;
    CreateBST(T, ST);
    cout << "中序遍历结果：";
    InOrderTraverse(T);
    cout << endl;
    cout << "二叉排序树查找结果：" << SearchBST(T, key);
}