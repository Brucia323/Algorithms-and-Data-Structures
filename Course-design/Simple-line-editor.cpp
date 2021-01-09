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
    char text[80]; //文本
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
        file.open(filename + ".txt");
        file.close();
    }
    else
    {
        cout << "输入和输出文件名不能相同" << endl;
        system("pause");
        Initialization();
    }
}
void Initialization(Livearealist &l)
{
    l = new Liveareanode;
    l->next = NULL;
}
void Initialization(Contentlist &c)
{
    c = new Contentnode;
    c->next = NULL;
}
//插入
void Insert(Livearealist &l)
{
    int line, count, i = 0;
    string text;
    char text1[80], text2[80], text3[80], text4[80];
    Livearealist l2, node;
    cin >> line >> text;
    if (line > 0 && line < activemaxlen)
    {
        l2 = l;
        for (int i = 0; l2->next && i < line; i++)
        {
            l2 = l2->next;
        }
        node = new Liveareanode;
        node->line = line + 1;
        Initialization(node->content);
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str());
            Insert(node->content, text1);
        }
        node->next = l2->next;
        l2->next = node;
    }
}
void Insert(Contentlist &c, char text[])
{
    Contentlist c2 = c, node;
    while (c2->next)
    {
        c2 = c2->next;
    }
    node = new Contentnode;
    strcpy(node->text, text);
    node->next = c2->next;
    c2->next = node;
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
