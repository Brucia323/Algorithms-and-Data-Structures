#include <iostream>
using namespace std;
int number = 0;
int state[7] = {-1, -1, -1, -1, -1, -1, -1};
typedef struct QNode
{
    int Number;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void InitQueue(LinkQueue &q)
{
    q.front = q.rear = new QNode;
    q.front->next = NULL;
}

void EnQueue(LinkQueue &q)
{
    QueuePtr p = new QNode;
    p->Number = ++number;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;
}

void GetHead(LinkQueue q, int vip)
{
    int i;
    if (q.front != q.rear)
    {
        if (vip == 0)
        {
            for (i = 1; i <= 4; i++)
            {
                if (state[i] == -1)
                {
                    break;
                }
            }
            if (i <= 4)
            {
                cout << "请" << q.front->next->Number << "号到" << i << "号窗口办理业务" << endl;
            }
            else
            {
                cout << "普通窗口暂无空闲" << endl;
            }
        }
        else
        {
            for (i = 5; i <= 6; i++)
            {
                if (state[i] == -1)
                {
                    break;
                }
            }
            if (i <= 6)
            {
                cout << "请" << q.front->next->Number << "号到" << i << "号窗口办理业务" << endl;
            }
            else
            {
                cout << "VIP窗口暂无空闲" << endl;
            }
        }
    }
    else
    {
        cout << "无人排队" << endl;
    }
}

void DeQueue(LinkQueue &q, int window)
{
    if (state[window] != -1)
    {
        cout << "当前窗口正在办理业务" << endl;
        return;
    }
    if (q.front == q.rear)
    {
        state[window] = 0;
        cout << "开始办理业务" << endl;
        return;
    }
    QueuePtr p = q.front->next;
    state[window] = p->Number;
    q.front->next = p->next;
    if (q.rear == p)
    {
        q.rear = q.front;
    }
    delete p;
    cout << "开始办理业务" << endl;
}
void DeQueue(LinkQueue &q)
{
    if (q.front == q.rear)
    {
        return;
    }
    QueuePtr p = q.front->next;
    cout << "已跳过" << p->Number << "号" << endl;
    q.front->next = p->next;
    if (q.rear == p)
    {
        q.rear = q.front;
    }
    delete p;
}

void Window(int e)
{
    if (e == -1)
    {
        cout << "该窗口空闲" << endl;
    }
    else if (e == 0)
    {
        cout << "该窗口正在办理业务，但顾客没有取号" << endl;
    }
    else
    {
        cout << e << "号正在办理业务" << endl;
    }
}
void Window()
{
    for (int i = 1; i < 7; i++)
    {
        if (state[i] == -1)
        {
            cout << i << "号窗口空闲" << endl;
        }
        else if (state[i] == 0)
        {
            cout << i << "号窗口有未取号顾客正在办理业务" << endl;
        }
        else
        {
            cout << state[i] << "号顾客正在" << i << "号窗口办理业务" << endl;
        }
    }
}

void Queuing(LinkQueue q)
{
    int count = 0;
    QueuePtr p = q.front->next;
    while (p)
    {
        count++;
        p = p->next;
    }
    cout << "当前共" << count << "人等待" << endl;
}

void Finish(int e)
{
    state[e] = -1;
    cout << e << "号窗口办理结束" << endl;
}
int main(void)
{
    LinkQueue q, vipq;
    InitQueue(q);
    InitQueue(vipq);
    while (1)
    {
        int option;
        cout << "1.排队取号" << endl;
        cout << "2.叫号" << endl;
        cout << "3.办理业务" << endl;
        cout << "4.窗口状态" << endl;
        cout << "5.排队状态" << endl;
        cout << "6.办理结束" << endl;
        // cout << "7.跳过一号" << endl;
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
            switch (option)
            {
            case 1:
                GetHead(q, 0);
                break;
            case 2:
                GetHead(vipq, 1);
                break;
            default:
                break;
            }
            system("pause");
            break;
        case 3:
            cout << "1.普通窗口1" << endl;
            cout << "2.普通窗口2" << endl;
            cout << "3.普通窗口3" << endl;
            cout << "4.普通窗口4" << endl;
            cout << "5.VIP窗口1" << endl;
            cout << "6.VIP窗口2" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                DeQueue(q, option);
                break;
            case 5:
            case 6:
                DeQueue(vipq, option);
                break;
            default:
                break;
            }
            system("pause");
            break;
        case 4:
            cout << "1.普通窗口1" << endl;
            cout << "2.普通窗口2" << endl;
            cout << "3.普通窗口3" << endl;
            cout << "4.普通窗口4" << endl;
            cout << "5.VIP窗口1" << endl;
            cout << "6.VIP窗口2" << endl;
            cin >> option;
            Window(state[option]);
            // Window();
            system("pause");
            break;
        case 5:
            cout << "1.普通客户队列" << endl;
            cout << "2.VIP客户队列" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                Queuing(q);
                break;
            case 2:
                Queuing(vipq);
                break;
            default:
                break;
            }
            system("pause");
            break;
        case 6:
            cout << "1.普通窗口1" << endl;
            cout << "2.普通窗口2" << endl;
            cout << "3.普通窗口3" << endl;
            cout << "4.普通窗口4" << endl;
            cout << "5.VIP窗口1" << endl;
            cout << "6.VIP窗口2" << endl;
            cin >> option;
            Finish(option);
            system("pause");
            break;
        // case 7:
        //     cout << "1.普通客户队列" << endl;
        //     cout << "2.VIP客户队列" << endl;
        //     cin >> option;
        //     switch (option)
        //     {
        //     case 1:
        //         DeQueue(q);
        //         break;
        //     case 2:
        //         DeQueue(vipq);
        //         break;
        //     default:
        //         break;
        //     }
        //     system("pause");
        //     break;
        default:
            break;
        }
    }
}