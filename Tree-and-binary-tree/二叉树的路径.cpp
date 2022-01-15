//������
/* ��������һ����ͨ�����ݽṹ������һ�����޵Ķ��������ڵ㱻��ʶΪһ���������������£�
    ��1����������ʶΪ�����ԣ�1,1����
    ��2�����һ���ڵ㱻��ʶΪ��a��b������ô����������������ʶΪ��a+b��b��������������������ʶΪ��a��a+b����
    ����������������ĳ���ڵ��ʶ��a��b�����ٶ�����������һ�����Ľڵ���������̵�·���ߣ����ܸ������ٴ�Ҫ���������ߣ����ٴ�Ҫ���������ߣ�*/
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
        l = r = 0; //l��ʾҪ������������������r��ʾҪ����������������
        while (x != 1 || y != 1)
        {
            if (x > y)
            {
                if (y == 1)
                    l += x - 1, x = 1; //��yΪ1ʱ��x��ֻҪ��x-1�����ܱ��1�ˣ���סҪ��x��Ϊ1���������������裩
                else
                    l += x / y, x %= y; //������������Ϊ1ʱ��������̼���l�У�x��ֵ��Ҫ�ı��x%y������
            }
            else if (x < y)
            {
                if (x == 1)
                    r += y - 1, y = 1; //ͬ��
                else
                    r += y / x, y %= x; //ͬ��
            }
        }
        printf("Scenario #%d:\n%d %d\n\n", p++, l, r);
    }
    return 0;
}