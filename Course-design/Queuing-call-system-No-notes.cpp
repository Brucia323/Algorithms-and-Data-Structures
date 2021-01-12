#include <iostream>
using namespace std;
int number = 0;                              
int state[7] = {-1, -1, -1, -1, -1, -1, -1}; 
typedef struct QNode
{
    int data;           
    struct QNode *next; 
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front; 
    QueuePtr rear;  
} LinkQueue;

void Initialization(LinkQueue &q)
{
    q.front = q.rear = new QNode; 
    q.front->next = NULL;         
}

void qpush(LinkQueue &q, int e)
{
    QueuePtr p = new QNode; 
    p->data = e;
    p->next = NULL;
    q.rear->next = p; 
    q.rear = p;       
}

int qempty(LinkQueue q)
{
    if (q.front == q.rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void qpop(LinkQueue &q)
{
    if (qempty(q))
    {
        return;
    }
    QueuePtr p = q.front->next;
    q.front->next = p->next;
    if (q.rear == p)
    {
        q.rear = q.front;
    }
    delete p;
}

int qsize(LinkQueue q)
{
    int count = 0;
    QueuePtr p = q.front->next;
    while (!qempty(q))
    {
        count++;
        p = p->next;
    }
    return count;
}

int qfront(LinkQueue q)
{
    if (!qempty(q))
    {
        return q.front->next->data;
    }
}

void Lineup(LinkQueue &q)
{
    number = number + 1; 
    qpush(q, number);
}

void Call(LinkQueue q, int vip)
{
    int i;
    if (!qempty(q))
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
                cout << "请" << qfront(q) << "号到" << i << "号窗口办理业务" << endl;
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
                cout << "请" << qfront(q) << "号到" << i << "号窗口办理业务" << endl;
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

void Conduct_business(LinkQueue &q, int window)
{
    if (state[window] != -1)
    {
        cout << "当前窗口正在办理业务" << endl;
        return;
    }
    if (qempty(q))
    {
        state[window] = 0; 
        cout << "开始办理业务" << endl;
        return;
    }
    state[window] = qfront(q); 
    qpop(q);
    cout << "开始办理业务" << endl;
}

void Skip(LinkQueue &q)
{
    if (qempty(q))
    {
        return;
    }
    cout << "已跳过" << qfront(q) << "号" << endl;
    qpop(q);
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
    cout << "当前共" << qsize(q) << "人等待" << endl;
}

void Finish(int e)
{
    state[e] = -1;
    cout << e << "号窗口办理结束" << endl;
}
int main(void)
{
    LinkQueue q, vipq; 
    Initialization(q);
    Initialization(vipq);
    while (1)
    {
        int option;
        cout << "1.排队取号" << endl;
        cout << "2.叫号" << endl;
        cout << "3.办理业务" << endl;
        cout << "4.窗口状态" << endl;
        cout << "5.排队状态" << endl;
        cout << "6.办理结束" << endl;
        cout << "7.跳过一号" << endl;
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
                Lineup(q);
                break;
            case 2:
                Lineup(vipq);
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
                Call(q, 0);
                break;
            case 2:
                Call(vipq, 1);
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
                Conduct_business(q, option);
                break;
            case 5:
            case 6:
                Conduct_business(vipq, option);
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
        case 7:
            cout << "1.普通客户队列" << endl;
            cout << "2.VIP客户队列" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                Skip(q);
                break;
            case 2:
                Skip(vipq);
                break;
            default:
                break;
            }
            system("pause");
            break;
        default:
            break;
        }
    }
}