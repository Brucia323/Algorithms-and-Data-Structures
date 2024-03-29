# 算法数据结构  

 ---- 图  
实验目的：  
1．熟悉图的存储结构；  
2．熟悉图的创建操作；  
3．熟悉图的遍历操作。  
实验内容：  
1．理解并实现无向图邻接矩阵的创建，理解并实现无向图邻接矩阵方式存储的广度优先遍历的算法，转换成程序并上机实现；

```c++
//用两个数组分别存储顶点表和邻接矩阵
#define MaxInt 32767                     //表示极大值，即∞
#define MVNum 100                        //最大顶点数
typedef char VerTexType;               //假设顶点的数据类型为字符型
typedef int ArcType;                   //假设边的权值类型为整型
typedef struct{
  VerTexType vexs[MVNum];              //顶点表
  ArcType arcs[MVNum][MVNum];        //邻接矩阵
  int vexnum,arcnum;                  //图的当前点数和边数
}AMGraph;
```

2．理解并实现无向图邻接表的创建的算法，理解并实现无向图的深度优先遍历的算法；转换成程序并上机实现，并按要求撰写实验报告；

```c++
#define MVNum 100                         //最大顶点数
typedef struct ArcNode{                  //边结点
    int adjvex;                            //该边所指向的顶点的位置
     OtherInfo info;                                     //和边相关的信息
    struct ArcNode * nextarc;           //指向下一条边的指针
}ArcNode;
typedef struct VNode{
    VerTexType data;                     //顶点信息
    ArcNode * firstarc;                 //指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum];                //AdjList表示邻接表类型
typedef struct{
    AdjList vertices;                   //邻接表
    int vexnum, arcnum;                //图的当前顶点数和边数
}ALGraph;
```

3．单源点最短路径问题(选做)  
（1）.问题描述  
7 个城市 A、B、C、D、E、F、G 的公路网如图 113 所示。弧上的数字表示该段公路的
长度。问有一批货物要从城市 A 运到城市 G 应走哪条路最短?输出最短路径及其长度
是否还有其他最短路径?若有,如何求出其他的最短路径?  
（2）实现提示  
本问题的实质是求单源点的最短路径问题,可采用迪杰斯特拉( Dijkstra)提出的按路
径长度递增的次序产生最短路径的算法

4、多源点最短路径问题(选做)  
（1）、问题描述  
给定 4 个城市之间的交通图如图 11-4 所示,图中弧上的数字表示城市之间的道路长
度。现在要在 4 个城市之间选择一个城市建造一个物流配送中心。问这个物流配送中心
应建在哪个城市才能使离物流配送中心最远的城市到物流配送中心的路程最短。  
（2）、实现提示  
该问题的实质是从 4 个城市中选出一个城市,使得其他 3 个城市到达该城市的最短；
距离的最大值最小,求解该问题首先要求出每个城市到其他各个城市的最短距离,然后,
再求出每个城市到其他各个城市的最短距离的最大值,最大值最小的城市即为要选择的
城市。显然,该问题的关键就是“所有顶点对之间的最短路径问题”。

实验要求：  
1、 程序要添加适当的注释，程序的书写要采用缩进格式。  
2、 程序要具在一定的健壮性，即当输入数据非法时，程序也能适当地做出反应，如插入删除时指定的位置不对等等。  
3、程序要做到界面友好，在程序运行时用户可以根据相应的提示信息进行操作。  
4．在体会中描述如下内容：  
（1）图示按照你的测试数据建立的邻接表、邻接矩阵示意图。  
（2）本次实验过程的体会，实现了几个程序，各个程序的名字是什么？是否自己独立完成？最大的困难是什么？自己准备如何解决这个困难？  
5.上传实验报告到网络平台，实验报告命名为：实验 6+班级+学号姓名.doc。如实验新 xxx1701+070814101 薛力.docx，报告命名格式严格遵守！！
