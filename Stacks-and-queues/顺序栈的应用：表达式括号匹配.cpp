/* 本题要求实现一个表达式括号匹配判断函数，输入参数为一个指针型字符串，字符串长度不可超100，括号有()
，[] ， {}
三种形式（输入形式例如：{[(1 + 2) * 3]} - 9）。如果匹配成功，则该函数应该返回1，匹配不成功则返回0。 */
#include <iostream>
using namespace std;

#define STACKSIZE 10
typedef char DataType;
typedef struct
{
    DataType *base;
    DataType *top;
    int stacksize;
} SqStack;
//初始化空顺序栈，细节在此不表
int InitStack(SqStack &S);

//判顺序栈空，细节在此不表
int StackEmpty(SqStack S);

//入栈，细节在此不表
int Push(SqStack &S, DataType item);

//出栈，细节在此不表
int Pop(SqStack &S, DataType &item);

//取栈顶，细节在此不表
int GetTop(SqStack S, DataType &item);

//表达式括号匹配判断函数，自定义
int matching(char *exp);

int main()
{
    char expr[100];
    //cout << "请输入表达式:";
    cin >> expr;
    char *ex = expr;
    if (matching(ex))
    {
        cout << "匹配成功";
    }
    else
    {
        cout << "匹配不成功";
    };

    return 0;
}

/* 请在这里填写答案 */
int matching(char *exp)
{                             //提示：可以使用string.h中的"strlen()"函数，帮助判断用户输入的表达式的长度
    SqStack S;                //定义一个顺序栈
    InitStack(S);             //初始化空顺序栈
    int length = strlen(exp); //获取字符串长度
    // if (*exp == '(' || *exp == '[' || *exp == '{')
    // {
    //     Push(S, *exp);
    // }
    while (length--)
    {
        if (*exp == '(' || *exp == ')' || *exp == '[' || *exp == ']' || *exp == '{' || *exp == '}')
        {
            char e = GetTop(S, e);
            if (e == '(' && *exp == ')')
            {
                Pop(S, e);
            }
            else if (e == '[' && *exp == ']')
            {
                Pop(S, e);
            }
            else if (e == '{' && *exp == '}')
            {
                Pop(S, e);
            }
            else
            {
                Push(S, *exp);
            }
            exp++;
        }
    }
    if (StackEmpty(S))
    {
        return 1; //栈空
    }
    else
    {
        return 0; //栈非空
    }
}