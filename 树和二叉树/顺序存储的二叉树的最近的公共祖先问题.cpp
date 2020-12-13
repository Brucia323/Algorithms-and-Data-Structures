/*设顺序存储的二叉树中有编号为i和j的两个结点，请设计算法求出它们最近的公共祖先结点的编号和值。*/
#include <iostream>
using namespace std;
#define MAXTSIZE 1000
typedef int SqBiTree[MAXTSIZE];
SqBiTree bt = {0};
int FindFather(int i, int j)
{
    while (1)
    {
        if (i > j)
            i /= 2;
        else
            j /= 2;
        if (i == j)
            break;
    }
    return i;
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> bt[i];
    }
    int i, j;
    cin >> i >> j;
    int father;
    father = FindFather(i, j);
    if (i == j)
        cout << i << " " << bt[i];
    else if (bt[i] == 0)
        cout << "ERROR: T[" << i << "] is NULL";
    else if (bt[j] == 0)
        cout << "ERROR: T[" << j << "] is NULL";
    else
        cout << father << " " << bt[father];
}