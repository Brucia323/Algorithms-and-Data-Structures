#include <iostream>
using namespace std;
#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN + 1];
    int length;
} SString;
void get_S(SString &S, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        S.ch[S.length++] = s[i];
    }
}
void get_T(SString &T, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        T.ch[T.length++] = s[i];
    }
}
//求模式串T的next函数值并存入数组next
void get_next(SString T, int next[])
{
    int i, j;
    i = 1;
    next[1] = 0;
    j = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
//利用模式串T的next函数求T在主串S中的位置
int Index_KMP(SString S, SString T, int next[])
{ //其中，T非空
    int i, j;
    i = 0;
    j = 1;
    while (i <= S.length && j <= T.length) //两个串均未比较到串尾
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        } //继续比较后继字符
        else
            j = next[j]; //模式串向右移动
    }
    if (j > T.length)
        return i - T.length; //匹配成功
    else
        return 0; //匹配失败
}
int main(void)
{
    string s;
    SString S, T;
    S.length = 0;
    T.length = 0;
    int next[9];
    cin >> s;
    get_S(S, s);
    cin >> s;
    get_T(T, s);
    get_next(T, next);
    cout << Index_KMP(S, T, next);
}