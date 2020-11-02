/* 链队列入队出队操作。 */
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char QElemType;
typedef int Status;
typedef char SElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e);
Status DeQueue(LinkQueue &Q, QElemType &e);

int main()
{
    LinkQueue Q;
    int n, m, i;
    char c;
    InitQueue(Q);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> c;
        EnQueue(Q, c);
    }
    for (i = 0; i < n; i++)
    {
        DeQueue(Q, c);
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> c;
        EnQueue(Q, c);
    }
    for (i = 0; i < m; i++)
    {
        DeQueue(Q, c);
        cout << c << " ";
    }
    return 0;
}
/* 请在这里填写答案 */
Status EnQueue(LinkQueue &Q, QElemType e) //插入元素e为Q的新的队尾元素
{
    Q.rear->data = e;
    Q.rear++;
}
Status DeQueue(LinkQueue &Q, QElemType &e) //删除Q的队头元素，用e返回其值
{
    e = Q.front->data;
    Q.front++;
    return e;
}