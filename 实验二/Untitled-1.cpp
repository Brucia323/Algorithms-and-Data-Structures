/* 定义一个包含学生信息（学号，姓名，成绩）的的链表，使其具有如下功能：
(1)根据指定学生个数，逐个输入学生信息；
(2) 逐个显示学生表中所有学生的相关信息；
(3) 根据姓名进行查找，返回此学生的学号和成绩；
(4) 根据指定的位置可返回相应的学生信息（学号，姓名，成绩）；
(5) 给定一个学生信息，插入到表中指定的位置；
(6) 删除指定位置的学生记录；
(7) 统计表中学生个数。
 */
#include <iostream>
#include <string.h>
using namespace std;
typedef struct
{
    long no;       //学号
    char name[20]; //姓名
    int price;     //成绩
} Student;
typedef struct LNode
{
    Student data;
    struct LNode *next;
} LNode, *LinkList;
void CreateList_L(LinkList &L, int n) //C++函数调用的一种方式，必须使用C++
{
    L = new LNode;  //头结点
    L->next = NULL; //头指针
    LinkList p;
    for (int i = n; i > 0; --i)
    {
        p = new LNode;
        p->next = L->next;
        L->next = p;
    }
}
void InputList_L(LinkList L, Student e, int i)
{
    LinkList p;
    int j;
    p = L->next;
    for (j = 0; j < i; j++)
    {
        p = p->next;
    }
    p->data = e;
    p = p->next;
}
void PrintList_L(LinkList &L)
{
    LinkList p = L->next;
    while (p)
    {
        cout << p->data.no << " " << p->data.name << " " << p->data.price << endl;
        p = p->next;
    }
}
Student NameSearchList_L(LinkList L, char name[20])
{
    LinkList p;
    p = L->next;
    while (p)
    {
        if (strcmp(p->data.name, name) == 0)
        {
            return p->data;
        }
        else
            p = p->next;
    }
}
Student PositionSearchList_L(LinkList L, int position)
{
    LinkList p;
    p = L->next;
    for (int i = 1; i != position; i++)
    {
        p = p->next;
    }
    return p->data;
}
int InsertList_L(LinkList &L, int i, Student e)
{
    LinkList s, p;
    int j;
    p = L;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p && j > i)
    {
        return 0;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}
int DeleteList_L(LinkList &L, int i)
{
    LinkList p, q;
    int j;
    p = L;
    for (j = 1; p && j < i; j++)
    {
        p = p->next;
    }
    if (!(p) || j > i)
    {
        return 0;
    }
    q = p->next;
    p->next = q->next;
    delete q;
    return 1;
}
int main(void)
{
    LinkList L;
    int n;
    cout << "请输入学生个数" << endl;
    cin >> n;
    CreateList_L(L, n);
    cout << "请输入学生信息（学号 姓名 成绩）" << endl;
    Student stu;
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> stu.no >> stu.name >> stu.price;
        InputList_L(L, stu, i);
    }
    while (1)
    {
        int flag = 0;
        cout << "1.逐个显示学生表中所有学生的相关信息" << endl;
        cout << "2.根据姓名查找学生的学号和成绩" << endl;
        cout << "3.根据指定的位置显示相应的学生信息" << endl;
        cout << "4.给定一个学生信息，插入到表中指定的位置" << endl;
        cout << "5.删除指定位置的学生信息" << endl;
        cout << "6.统计表中学生个数" << endl;
        cout << "0.退出" << endl;
        cin >> flag;
        switch (flag)
        {
        case 1:
            PrintList_L(L);
            cout << "按下空格键返回";
            getchar();
            getchar();
            break;
        case 2:
            char name[20];
            cin >> name;
            stu = NameSearchList_L(L, name);
            if (stu.no)
            {
                cout << stu.no << " " << stu.price << endl;
            }
            else
            {
                cout << "未找到" << endl;
            }
            cout << "按下空格键返回";
            getchar();
            getchar();
            break;
        case 3:
            cin >> i;
            stu = PositionSearchList_L(L, i);
            if (stu.no)
            {
                cout << stu.no << " " << stu.name << " " << stu.price << endl;
            }
            else
            {
                cout << "未找到" << endl;
            }
            cout << "按下空格键返回";
            getchar();
            getchar();
            break;
        case 4:
            cin >> i;
            cin >> stu.no >> stu.name >> stu.price;
            if (InsertList_L(L, i, stu))
            {
                n++;
                cout << "插入成功" << endl;
            }
            else
            {
                cout << "插入失败" << endl;
            }
            cout << "按下空格键返回";
            getchar();
            getchar();
            break;
        case 5:
            cin >> i;
            if (DeleteList_L(L, i))
            {
                n--;
                cout << "删除成功" << endl;
            }
            else
            {
                cout << "删除失败" << endl;
            }
            cout << "按下空格键返回";
            getchar();
            getchar();
            break;
        case 6:
            cout << "共有" << n << "个学生" << endl;
            cout << "按下空格键返回";
            getchar();
            getchar();
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }
}