#include <iostream>
#include <queue>
using namespace std;
//用两个数组分别存储顶点表和邻接矩阵
#define MaxInt 32767     //表示极大值，即∞
#define MVNum 100        //最大顶点数
typedef char VerTexType; //假设顶点的数据类型为字符型
typedef int ArcType;     //假设边的权值类型为整型
typedef struct
{
    VerTexType vexs[MVNum];     //顶点表
    ArcType arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum, arcnum;         //图的当前点数和边数
} AMGraph;
//确定v在G中的位置，即顶点数组的下标
int LocateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
        if (G.vexs[i] == v)
            return i; //找到顶点位置
    return -1;
}
//采用邻接矩阵表示法，创建无向网G
void CreateUDN(AMGraph &G)
{
    int i, j, k;
    ArcType w;                   //边的权值
    VerTexType v1, v2;           //顶点
    cin >> G.vexnum >> G.arcnum; //输入总顶点数，总边数
    //依次输入点的信息
    for (i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i];
    //初始化邻接矩阵，边的权值均置为极大值MaxInt
    for (i = 0; i < G.vexnum; ++i)
        for (j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;
    //构造邻接矩阵
    for (k = 0; k < G.arcnum; ++k)
    {
        cin >> v1 >> v2 >> w;        //输入一条边依附的顶点及权值
        i = LocateVex(G, v1);        //确定v1在G中的位置，即顶点数组的下标
        j = LocateVex(G, v2);        //确定v2在G中的位置，即顶点数组的下标
        G.arcs[i][j] = w;            //边<v1,v2>的权值置为w
        G.arcs[j][i] = G.arcs[i][j]; //置<v1,v2>的对称边<v2,v1>的权值为w
    }
}
bool visited[MVNum]; //访问标志数组
//图G为邻接矩阵类型，从第v个顶点出发广度优先搜索遍历图G
void BFS_AM(AMGraph G, int v)
{
    int w, u;
    cout << G.vexs[v]; //访问第v个顶点
    visited[v] = true; //置访问标志数组相应分量值为true
    queue<int> q;      //定义辅助队列q
    q.push(v);         //v进队
    //队列非空
    while (!q.empty())
    {
        u = q.front(); //读取队头元素
        q.pop();       //队头元素出队
        //依次邻接矩阵u所在的行
        for (w = 0; w < G.vexnum; w++)
            //G.arcs[u][w] != MaxInt表示w是u的邻接点，如果w未访问，则入队
            if ((G.arcs[u][w] != MaxInt) && (!visited[w]))
            {
                cout << G.vexs[w]; //访问w
                visited[w] = true; //置访问标志数组相应分量值为true
                q.push(w);         //w进队
            }
    }
}
int main(void)
{
    AMGraph G;
    int v;
    CreateUDN(G);
    cout << "请选择起始顶点：";
    cin >> v;
    BFS_AM(G, v);
}