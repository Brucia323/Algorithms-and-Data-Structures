/* 设计一个顺序栈，并利用该顺序栈将给定的十进制整整数转换为八进制并输出。 */
#include <iostream>
using namespace std;

#define STACKSIZE 10
typedef int DataType;
typedef struct
{
    DataType *base;
    DataType *top;
    int stacksize;
} SqStack;

//初始化空顺序栈
int InitStack(SqStack &S);

//判栈空
int StackEmpty(SqStack S);

//入栈
int Push(SqStack &S, DataType item);

//出栈
int Pop(SqStack &S, DataType &item);

void conversion(int N)
{ //对于任意一个非负十进制数，打印输出与其等值的八进制数
    SqStack S;
    InitStack(S); //初始化空栈S
    while (N)
    {                   //当N非零时,循环
        Push(S, N % 8); //把N与8求余得到的八进制数压入栈S
        N = N / 8;      //N更新为N与8的商
    }
    int e;
    cout << "转化的八进制数为：";
    while (!StackEmpty(S)) //当栈S非空时，循环
    {
        Pop(S, e); //弹出栈顶元素e
        cout << e; //输出e
    }
}
int main()
{
    int m, n;
    cout << "请输入十进制数:";
    cin >> m;
    conversion(m);
    return 0;
}

/* 请在这里填写答案 */
//初始化空顺序栈
int InitStack(SqStack &S)
{
    S.base = new DataType[STACKSIZE]; //为顺序栈动态分配一个最大容量为STACKSIZE的数组空间
    if (!S.base)
    {
        return 0; //存储分配失败
    }
    S.top = S.base;          //top初始为base，空栈
    S.stacksize = STACKSIZE; //stacksize置为栈的最大容量STACKSIZE
    return 1;
}
//判断栈空
int StackEmpty(SqStack S)
{
    if (S.top == S.base)
    {
        return 1; //栈空
    }
    else
    {
        return 0; //栈非空
    }
}
//入栈
int Push(SqStack &S, DataType item)
{
    if (S.top - S.base == S.stacksize)
    {
        return 0; //栈满
    }
    *S.top++ = item; //元素item压入栈顶，栈顶指针加1
    return 1;
}
//出栈
int Pop(SqStack &S, DataType &item)
{
    if (S.top == S.base)
    {
        return 0; //栈空
    }
    item = *--S.top; //栈顶指针减1，将栈顶元素赋给e
    return 1;
}