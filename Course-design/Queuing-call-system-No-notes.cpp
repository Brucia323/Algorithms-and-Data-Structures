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
                cout << "��" << qfront(q) << "�ŵ�" << i << "�Ŵ��ڰ���ҵ��" << endl;
            }
            else
            {
                cout << "��ͨ�������޿���" << endl;
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
                cout << "��" << qfront(q) << "�ŵ�" << i << "�Ŵ��ڰ���ҵ��" << endl;
            }
            else
            {
                cout << "VIP�������޿���" << endl;
            }
        }
    }
    else
    {
        cout << "�����Ŷ�" << endl;
    }
}

void Conduct_business(LinkQueue &q, int window)
{
    if (state[window] != -1)
    {
        cout << "��ǰ�������ڰ���ҵ��" << endl;
        return;
    }
    if (qempty(q))
    {
        state[window] = 0;
        cout << "��ʼ����ҵ��" << endl;
        return;
    }
    state[window] = qfront(q);
    qpop(q);
    cout << "��ʼ����ҵ��" << endl;
}

void Skip(LinkQueue &q)
{
    if (qempty(q))
    {
        return;
    }
    cout << "������" << qfront(q) << "��" << endl;
    qpop(q);
}

void Window(int e)
{
    if (e == -1)
    {
        cout << "�ô��ڿ���" << endl;
    }
    else if (e == 0)
    {
        cout << "�ô������ڰ���ҵ�񣬵��˿�û��ȡ��" << endl;
    }
    else
    {
        cout << e << "�����ڰ���ҵ��" << endl;
    }
}
void Window()
{
    for (int i = 1; i < 7; i++)
    {
        if (state[i] == -1)
        {
            cout << i << "�Ŵ��ڿ���" << endl;
        }
        else if (state[i] == 0)
        {
            cout << i << "�Ŵ�����δȡ�Ź˿����ڰ���ҵ��" << endl;
        }
        else
        {
            cout << state[i] << "�Ź˿�����" << i << "�Ŵ��ڰ���ҵ��" << endl;
        }
    }
}

void Queuing(LinkQueue q)
{
    cout << "��ǰ��" << qsize(q) << "�˵ȴ�" << endl;
}

void Finish(int e)
{
    state[e] = -1;
    cout << e << "�Ŵ��ڰ������" << endl;
}
int main(void)
{
    LinkQueue q, vipq;
    Initialization(q);
    Initialization(vipq);
    while (1)
    {
        int option;
        cout << "1.�Ŷ�ȡ��" << endl;
        cout << "2.�к�" << endl;
        cout << "3.����ҵ��" << endl;
        cout << "4.����״̬" << endl;
        cout << "5.�Ŷ�״̬" << endl;
        cout << "6.�������" << endl;
        cout << "7.����һ��" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "1.��ͨ�ͻ�" << endl;
            cout << "2.VIP�ͻ�" << endl;
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
            cout << "ȡ�ųɹ�" << endl;
            system("pause");
            break;
        case 2:
            cout << "1.��ͨ����" << endl;
            cout << "2.VIP����" << endl;
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
            cout << "1.��ͨ����1" << endl;
            cout << "2.��ͨ����2" << endl;
            cout << "3.��ͨ����3" << endl;
            cout << "4.��ͨ����4" << endl;
            cout << "5.VIP����1" << endl;
            cout << "6.VIP����2" << endl;
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
            cout << "1.��ͨ����1" << endl;
            cout << "2.��ͨ����2" << endl;
            cout << "3.��ͨ����3" << endl;
            cout << "4.��ͨ����4" << endl;
            cout << "5.VIP����1" << endl;
            cout << "6.VIP����2" << endl;
            cin >> option;
            Window(state[option]);
            // Window();
            system("pause");
            break;
        case 5:
            cout << "1.��ͨ�ͻ�����" << endl;
            cout << "2.VIP�ͻ�����" << endl;
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
            cout << "1.��ͨ����1" << endl;
            cout << "2.��ͨ����2" << endl;
            cout << "3.��ͨ����3" << endl;
            cout << "4.��ͨ����4" << endl;
            cout << "5.VIP����1" << endl;
            cout << "6.VIP����2" << endl;
            cin >> option;
            Finish(option);
            system("pause");
            break;
        case 7:
            cout << "1.��ͨ�ͻ�����" << endl;
            cout << "2.VIP�ͻ�����" << endl;
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