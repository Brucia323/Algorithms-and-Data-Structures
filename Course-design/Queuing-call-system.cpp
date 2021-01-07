#include <iostream>
using namespace std;
int number = 0; //排队号码
typedef struct QNode
{
    int Number;         //号码
    struct QNode *next; //后继指针
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾指针
} LinkQueue;
//初始化
void InitQueue(LinkQueue &q)
{
    q.front = q.rear = new QNode; //生成新结点作为头结点，队头和队尾指针指向此结点
    q.front->next = NULL;         //头指针的指针域置空
}
//排队
void EnQueue(LinkQueue &q)
{
    QueuePtr p = new QNode; //为入队元素分配结点空间，用指针p指向
    p->Number = ++number;   //取号
    p->next = NULL;
    q.rear->next = p; //排队
    q.rear = p;       //修改队尾指针
}
//叫号
void GetHead(LinkQueue q)
{
    if (q.front != q.rear)
    {
        cout << q.front->next->Number << endl;
    }
    else
    {
        cout << "无人排队" << endl;
    }
}
//出队
void DeQueue(LinkQueue &q)
{
    if (q.front == q.rear)
    {
        cout << "无人排队" << endl;
        return;
    }
    QueuePtr p = q.front->next; //p指向队头元素
    q.front->next = p->next;    //修改头结点的指针域
    if (q.rear == p)
    {
        q.rear = q.front; //最后一个元素被删，队尾指针指向头结点
    }
    delete p; //释放空间
}
int main(void)
{
    LinkQueue q, vipq; //普通队列，VIP队列
    InitQueue(q);
    InitQueue(vipq);
    while (1)
    {
        int option;
        cout << "1.排队取号" << endl;
        cout << "2.叫号" << endl;
        cout << "3.办理业务" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "1.普通客户" << endl;
            cout << "2.VIP客户" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                EnQueue(q);
                break;
            case 2:
                EnQueue(vipq);
                break;
            default:
                break;
            }
            cout << "取号成功" << endl;
            system("pause");
            break;
        case 2:
            cout << "1.普通窗口" << endl;
            cout << "2.VIP窗口" << endl;
            cin >> option;
            cout << "正在叫号" << endl;
            switch (option)
            {
            case 1:
                GetHead(q);
                break;
            case 2:
                GetHead(vipq);
                break;
            default:
                break;
            }
            system("pause");
            break;
        case 3:
            cout << "1.普通窗口" << endl;
            cout << "2.VIP窗口" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                DeQueue(q);
                break;
            case 2:
                DeQueue(vipq);
                break;
            default:
                break;
            }
            cout << "正在办理业务" << endl;
            system("pause");
        default:
            break;
        }
    }
}