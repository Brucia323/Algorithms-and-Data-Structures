/*大家上完这周的课，对二叉树一定有了自己的理解！最近小Z遇到了一颗奇怪的二叉树，想请求大家的帮助！

这颗二叉树由N个互不相同的正整数组成，它有一个很重要的特性，就是每个节点的值一定会小于它左右孩子节点的值！

比如像下面这样：

6a99f68a-6578-46e0-9232-fbf0adf3691f.jpg

现在小Z得到了一串这种二叉树的中序序列，但不知道怎么把这棵树还原出来，请大家帮帮他吧！*/
#include<iostream>
using namespace std;
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
void Create(BiTree &T);
/*---------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>

#define MAXN ((int)1e5 + 7)
#define ll long long int
#define INF (0x7f7f7f7f)
#define fori(lef, rig) for (int i = lef; i <= rig; i++)
#define forj(lef, rig) for (int j = lef; j <= rig; j++)
#define fork(lef, rig) for (int k = lef; k <= rig; k++)
#define QAQ (0)

using namespace std;

#define show(x...)                             \
    do                                         \
    {                                          \
        cout << "\033[31;1m " << #x << " -> "; \
        err(x);                                \
    } while (0)

void err()
{
    cout << "\033[39;0m" << endl;
}
template <typename T, typename... A>
void err(T a, A... x)
{
    cout << a << ' ';
    err(x...);
}

namespace FastIO
{

    char print_f[105];
    void read() {}
    void print() { putchar('\n'); }

    template <typename T, typename... T2>
    inline void read(T &x, T2 &... oth)
    {
        x = 0;
        char ch = getchar();
        ll f = 1;
        while (!isdigit(ch))
        {
            if (ch == '-')
                f *= -1;
            ch = getchar();
        }
        while (isdigit(ch))
        {
            x = x * 10 + ch - 48;
            ch = getchar();
        }
        x *= f;
        read(oth...);
    }
    template <typename T, typename... T2>
    inline void print(T x, T2... oth)
    {
        ll p3 = -1;
        if (x < 0)
            putchar('-'), x = -x;
        do
        {
            print_f[++p3] = x % 10 + 48;
        } while (x /= 10);
        while (p3 >= 0)
            putchar(print_f[p3--]);
        putchar(' ');
        print(oth...);
    }
} // namespace FastIO
using FastIO::print;
using FastIO::read;

int n, m, Q, K, a[MAXN];

struct Node
{
    Node *lef, *rig;
    int val;
    Node(int _val = 0) : lef(0), rig(0), val(_val) {}
} * root;

void build(Node *&now, int lef, int rig)
{
    if (lef > rig)
        return;
    int mid_id = lef;
    for (int i = lef; i <= rig; i++) //暴力找最小当根节点
        if (a[mid_id] > a[i])
            mid_id = i;
    now = new Node(a[mid_id]);
    if (lef >= rig)
        return;

    build(now->lef, lef, mid_id - 1);
    build(now->rig, mid_id + 1, rig);
}

void bfs()
{
    queue<Node *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        auto no = q.front();
        q.pop();
        if (flag++)
            printf(" ");
        printf("%d", no->val);
        if (no->lef)
            q.push(no->lef);
        if (no->rig)
            q.push(no->rig);
    }
}

int main()
{
#ifdef debug
    freopen("test", "r", stdin);
    clock_t stime = clock();
#endif
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    build(root, 1, n);
    bfs();

#ifdef debug
    clock_t etime = clock();
    printf("rum time: %lf 秒\n", (double)(etime - stime) / CLOCKS_PER_SEC);
#endif
    return 0;
}