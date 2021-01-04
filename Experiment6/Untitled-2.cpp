#include <iostream>
using namespace std;
#define MVNum 100 //最大顶点数
typedef char VerTexType;
typedef int OtherInfo;
typedef struct ArcNode
{                            //边结点
    int adjvex;              //该边所指向的顶点的位置
    OtherInfo info;          //和边相关的信息
    struct ArcNode *nextarc; //指向下一条边的指针
} ArcNode;
typedef struct VNode
{
    VerTexType data;     //顶点信息
    ArcNode *firstarc;   //指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum]; //AdjList表示邻接表类型
typedef struct
{
    AdjList vertices;   //邻接表
    int vexnum, arcnum; //图的当前顶点数和边数
} ALGraph;
//确定v在G中位置，即顶点在G.vertices中的序号
int LocateVex(ALGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].data == v)
            return i; //找到顶点位置
    return -1;
}
//采用邻接表表示法，创建无向图G
void CreateUDG(ALGraph &G)
{
    int i, j, k;
    VerTexType v1, v2;
    ArcNode *p1, *p2;
    cin >> G.vexnum >> G.arcnum; //输入总顶点数，总边数
    //输入各点，构造表头结点表
    for (i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vertices[i].data;     //输入顶点值
        G.vertices[i].firstarc = NULL; //初始化表头结点的指针域为NULL
    }
    //输入各边，构造邻接表
    for (k = 0; k < G.arcnum; ++k)
    {
        cin >> v1 >> v2;      //输入一条边依附的两个顶点
        i = LocateVex(G, v1); //确定v1在G中位置，即顶点在G.vertices中的序号
        j = LocateVex(G, v2); //确定v2在G中位置，即顶点在G.vertices中的序号
        p1 = new ArcNode;     //生成一个新的边结点*p1
        p1->adjvex = j;       //邻接点序号为j
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1; //将新结点*p1插入顶点v[i]的边表头部
        p2 = new ArcNode;            //生成另一个对称的新的边结点*p2
        p2->adjvex = i;              //邻接点序号为i
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2; //将新结点*p2插入顶点v[j]的边表头部
    }
}
bool visited[MVNum]; //访问标志数组
//图G为邻接表类型，从第V个顶点出发深度优先搜索遍历图G
void DFS_AL(ALGraph G, int v)
{
    ArcNode *p;
    int w;
    cout << G.vertices[v].data; //访问第v个顶点
    visited[v] = true;          //置访问标志数组相应分量值为true
    p = G.vertices[v].firstarc; //p指向v的边链表的第一个边结点
    while (p != NULL)
    {
        w = p->adjvex; //表示w是v的邻接点
        if (!visited[w])
            DFS_AL(G, w); //如果w未访问，则递归调用DFS_AL
        p = p->nextarc;   //p指向下一个边结点
    }
}
int main(void)
{
    ALGraph G;
    int v;
    CreateUDG(G);
    cout << "请选择起始顶点：";
    cin >> v;
    DFS_AL(G, v);
}