#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define activemaxlen 100
string filename; //文件名
//内容单链表
typedef struct Content
{
    char text[81]; //文本
    struct Content *next;
} Contentnode, *Contentlist;
//活区单链表
typedef struct Livearea
{
    int line;            //行号
    Contentlist content; //内容
    struct Livearea *next;
} Liveareanode, *Livearealist;
//初始化
void Initialization()
{
    ofstream file, outputfile;
    cout << "请输入文件名：";
    cin >> filename;
    if (filename != "")
    {
        file.open(filename + ".txt"); //打开文件
        file.close();                 //关闭文件
    }
    else
    {
        cout << "文件名不能为空" << endl;
        system("pause");
        Initialization();
    }
}
//活区初始化
void Initialization(Livearealist &l)
{
    l = new Liveareanode;
    l->next = NULL;
}
//内容初始化
void Initialization(Contentlist &c)
{
    c = new Contentnode;
    c->next = NULL;
}
//插入
void Insert(Contentlist &c,char text[])
{
    Contentlist c1 = c, node;
    while (c1->next)
    {
        c1 = c1->next;
    }
    node = new Contentnode;
    strcpy(node->text, text);
    node->next = c1->next;
    c1->next = node;
}
void Insert(Livearealist &l)
{
    int line, count, i = 0;
    string text;
    char text1[81];
    Livearealist l1, node;
    cin >> line >> text;
    //行号在活区范围内
    if (line > 0 && line < activemaxlen)
    {
        l1 = l;
        //查找第i个结点
        for (int i = 0; l1->next && i < line; i++)
        {
            l1 = l1->next;
        }
        node = new Liveareanode;
        node->line = line + 1;
        Initialization(node->content);
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str()); //分割字符串
            Insert(node->content,text1);
        }
        node->next = l1->next;
        l1->next = node;
    }
}
int main(void)
{
    char cmd;
    Initialization();
    Livearealist l;
    Initialization(l);
    cin >> cmd;
    switch (cmd)
    {
    case 'i':
        Insert(l);
        break;

    default:
        break;
    }
}
