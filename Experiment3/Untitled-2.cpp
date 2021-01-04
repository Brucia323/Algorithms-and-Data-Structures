#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef char SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;
int InitStack(SqStack &S)
{                                    //构造一个空栈S
    S.base = new SElemType[MAXSIZE]; //为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
    if (!S.base)
        return 0;          //存储分配失败
    S.top = S.base;        //top初始为base，空栈
    S.stacksize = MAXSIZE; //stacksize置为栈的最大容量MAXSIZE
    return 1;
}
int StackEmpty(SqStack S)
{ //判断栈空
    if (S.top == S.base)
        return 1; //栈空
    else
        return 0; //栈非空
}
int Push(SqStack &S, SElemType e)
{ //插入元素e为新的栈顶元素
    if (S.top - S.base == S.stacksize)
        return 0; //栈满
    *S.top++ = e; //元素e压入栈顶，栈顶指针加1
    return 1;
}
int Pop(SqStack &S, SElemType &e)
{ //删除S的栈顶元素，用e返回其值
    if (S.top == S.base)
        return 0; //栈空
    e = *--S.top; //栈顶指针减1，将栈顶元素赋给e
    return 1;
}
SElemType GetTop(SqStack S)
{                            //返回S的栈顶元素，不修改栈顶指针
    if (S.top != S.base)     //栈非空
        return *(S.top - 1); //返回栈顶元素的值，栈顶指针不变
}
int main(void)
{
    SqStack S;
    InitStack(S); //构造一个空栈S
    SElemType e;
    int i = 0, n;
    cout << "请输入n" << endl;
    cin >> n;
    cout << "请输入字符串" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> e;
        if (n % 2 != 0)
        {
            if (i < n / 2)
                Push(S, e); //插入元素e为新的栈顶元素
            else if (i > n / 2 && GetTop(S) == e)
                Pop(S, e); //删除S的栈顶元素，用e返回其值
        }
        else
        {
            if (i < n / 2)
                Push(S, e); //插入元素e为新的栈顶元素
            else if (i >= n / 2 && GetTop(S) == e)
                Pop(S, e); //删除S的栈顶元素，用e返回其值
        }
    }
    if (StackEmpty(S)) //判断栈空
        cout << "该字符串中心对称" << endl;
    else
        cout << "该字符串不是中心对称" << endl;
}