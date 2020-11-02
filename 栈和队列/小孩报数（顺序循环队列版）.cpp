/* 有若干个小孩围成一圈，现从指定的第1个开始报数，报到第 w个时，该小孩出列，然后从下一个小孩开始报数，仍是报到w个出列，如此重复下去，直到所有的小孩都出列（总人数不足w个时将循环报数），求小孩出列的顺序。 算法要求：使用顺序循环队列来存储所有小孩，报数时小孩出队，未数到w时，接着入队；数到w时，输出小孩的名字，该小孩不再入队，如此直到所有小孩出队，队列为空时停止报数。 请写出顺序循环队列的所有基本操作。 说明 ：参与报数游戏的小孩人数不能超过10人。 */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 11
#define N 10

int main()
{
    ElemType *e;
    int n, i;
    SqQueue *q;
    InitQueue(q);
    scanf("%d", &n);
    while (1)
    {
        char *name = (char *)malloc(sizeof(char) * N);
        scanf("%s", name);
        if ((strcmp("-1", name) == 0) || !enQueue(q, name))
            break;
    }
    i = n - 1;
    while (!QueueEmpty(q))
    {
        deQueue(q, e);
        if (i-- > 0)
            enQueue(q, e);
        else
        {
            printf("%s\n", e);
            i = n - 1;
            free(e);
        }
    }
    DestroyQueue(q);
}

/* 请在这里填写答案 */
typedef char ElemType;
typedef struct // 顺序循环队列结点定义
{
    ElemType *name[MaxSize]; //小孩姓名
    int front, rear;         //队首和队尾指针
} SqQueue;
void InitQueue(SqQueue *&q) //初始化队列；
{
    q = (SqQueue *)malloc(sizeof(SqQueue)); //为队列分配一个最大容量为MaxSize的数组空间
    q->front = q->rear = 0;                 //头指针和尾指针置为零，队列为空
}
void DestroyQueue(SqQueue *&q) //销毁队列；
{
    free(q);
}
bool QueueEmpty(SqQueue *q) //判定队列为空时返回true; 否则返回false;
{
    if (q->front == q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool enQueue(SqQueue *&q, ElemType *e) // e 入队；成功入队返回true; 否则返回false;
{
    if ((q->rear + 1) % MaxSize == q->front)
    {
        return false; //队满
    }
    q->name[q->rear] = e; //入队
    q->rear = (q->rear + 1) % MaxSize;
    return true;
}
bool deQueue(SqQueue *&q, ElemType *&e) //出队，返回出队元素e，且成功出队返回true,否则返回false;
{
    if (q->rear == q->front)
    {
        return false; //队空
    }
    e = q->name[q->front]; //出队
    q->front = (q->front + 1) % MaxSize;
    return true;
}