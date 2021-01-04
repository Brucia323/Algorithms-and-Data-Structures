//不可用
/* 二叉树是一种普通的数据结构。给出一棵无限的二叉树，节点被标识为一对整数，构造如下：
    （1）树根被标识为整数对（1,1）。
    （2）如果一个节点被标识为（a，b），那么其左子树树根被标识为（a+b，b），其右子树树根被标识为（a，a+b）。
    给出上述二叉树的某个节点标识（a，b），假定从树根到这一给定的节点是沿着最短的路径走，你能给出多少次要向左子树走，多少次要向右子树走？*/
#include <iostream>
using namespace std;
typedef struct BiTNode
{
    int x, y;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
void Create(BiTree &T, int a, int b)
{
    T = new BiTNode;
    T->x = a;
    T->y = b;
    Create(T->lchild, a + b, b);
    Create(T->rchild, a, a + b);
}
void Search(BiTree T, int i, int j, int l, int r)
{
    if (T->x != i || T->y != j)
    {
        Search(T->lchild, i, j, l++, r);
        Search(T->rchild, i, j, l, r++);
    }
    return;
}
int main(void)
{
    BiTree T;
    int a = 1, b = 1;
    Create(T, a, b);
    int n;
    cin >> n;
    int i, j, l, r, flag = 0;
    while (n--)
    {
        cin >> i >> j;
        l = r = 0;
        Search(T, i, j, l, r);
        flag++;
        cout << "Scenario #" << i << ":" << endl;
        cout << i << " " << j << endl;
    }
}


/*---------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n, x, y, p = 1, l, r;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &x, &y);
        l = r = 0; //l表示要经过左子树的数量，r表示要经过右子树的数量
        while (x != 1 || y != 1)
        {
            if (x > y)
            {
                if (y == 1)
                    l += x - 1, x = 1; //当y为1时，x就只要走x-1步就能变成1了，记住要把x赋为1（跳出的条件所需）
                else
                    l += x / y, x %= y; //当两个数都不为1时，将其的商加入l中，x的值需要改变成x%y的余数
            }
            else if (x < y)
            {
                if (x == 1)
                    r += y - 1, y = 1; //同上
                else
                    r += y / x, y %= x; //同上
            }
        }
        printf("Scenario #%d:\n%d %d\n\n", p++, l, r);
    }
    return 0;
}