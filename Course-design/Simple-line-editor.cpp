#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define activemaxlen 100
#define x 20
string inputfilename, outputfilename; //文件名
int count = 0;
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
//活区初始化
void Inilivearea(Livearealist &l)
{
    l = new Liveareanode;
    l->next = NULL;
}
//内容初始化
void Inicontent(Contentlist &c)
{
    c = new Contentnode;
    c->next = NULL;
}
//内容插入
void Insert(Contentlist &c, char text[])
{
    Contentlist c1 = c, node;
    for (c1 = c; c1->next; c1 = c1->next)
        ;
    node = new Contentnode;
    strcpy(node->text, text);
    node->next = c1->next;
    c1->next = node;
}
//初始化
void Initialization(Livearealist &l)
{
    char buffer[320], text1[81];
    string text;
    fstream inputfile, outputfile;
    cout << "请输入“输入文件”文件名：（若无，则用空格表示）";
    cin >> inputfilename;
    cout << "请输入“输出文件”文件名：";
    cin >> outputfilename;
    if (inputfilename != outputfilename)
    {
        if (inputfilename == " ")
        {
            outputfile.open(outputfilename + ".txt"); //打开文件
            outputfile.close();                       //关闭文件
        }
        else
        {
            inputfile.open(inputfilename + ".txt", ios::_Nocreate); //打开文件
            Livearealist l1, node;
            l1 = l;
            for (int i = 0; i < activemaxlen - x; i++)
            {
                node = new Liveareanode;
                node->line = i + 1;
                Inicontent(node->content);
                inputfile.getline(buffer, 320);
                count++;
                text = (string)buffer;
                for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
                {
                    strcpy(text1, text.substr(j, k).c_str()); //分割字符串
                    Insert(node->content, text1);
                }
                node->next = l1->next;
                l1->next = node;
                l1 = l1->next;
                if (inputfile.eof())
                {
                    break;
                }
            }
            inputfile.close();                        //关闭文件
            outputfile.open(outputfilename + ".txt"); //打开文件
            outputfile.close();                       //关闭文件
        }
    }
    else
    {
        cout << "输入和输出文件名不能相同" << endl;
        system("pause");
        Initialization(l);
    }
}
//插入
void Insert(Livearealist &l)
{
    int line;
    string text;
    char text1[81];
    Livearealist l1, node;
    cin >> line >> text;
    //行号在活区范围内
    if (line >= 0 && line < activemaxlen)
    {
        l1 = l;
        //查找第i个结点
        for (int i = 0; l1->next && i < line; i++, l1 = l1->next)
            ;
        node = new Liveareanode;
        node->line = line + 1;
        Inicontent(node->content);
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str()); //分割字符串
            Insert(node->content, text1);
        }
        node->next = l1->next;
        l1->next = node;
        l1 = l1->next;
        //修改后续行号
        for (l1 = l1->next; l1->next; l1 = l1->next, l1->line = l1->line + 1)
            ;
    }
    else if (line == 0)
    {
        l1 = l;
    }
}
//删除
void Delete(Livearealist &l)
{
    int line1, line2 = 0;
    char space;
    Livearealist l1, l2, node1, node2;
    cin >> line1 >> space;
    //判断格式
    if (space == ' ')
    {
        cin >> line2;
    }
    if (line2 == 0)
    {
        l1 = l;
        for (int i = 0; l1->next && i < line1 - 1; i++, l1 = l1->next)
            ;
        node1 = l1->next;
        l1->next = node1->next;
        delete node1;
    }
    else
    {
        l1 = l;
        for (int i = 0; l1->next && i < line1 - 1; i++, l1 = l1->next)
            ;
        l2 = l1;
        for (int i = line1; l2->next && i < line2; i++, l2 = l2->next)
            ;
        for (node1 = l1->next; node1 != l2; node1 = node2)
        {
            node2 = node1->next;
            delete node1;
        }
        l1->next = l2->next;
        delete l2;
    }
    //修改行号
    for (l1 = l1->next; l1; l1 = l1->next)
    {
        l1->line = ++line1;
    }
}
//活区切换
void Switch(Livearealist &l)
{
    fstream inputfile, outputfile;
    Livearealist l1, node;
    l1 = l;
    outputfile.open(outputfilename + ".txt", ios::app);
    if (outputfile.is_open())
    {
        while (l1)
        {
            while (l1->content)
            {
                outputfile << l1->content->text;
                l1->content = l1->content->next;
            }
            outputfile << endl;
            node = l1;
            l1 = l1->next;
            delete node;
        }
    }
    outputfile.close();
    if (inputfilename != " ")
    {
        char buffer[320], text1[81];
        string text;
        inputfile.open(inputfilename + ".txt", ios::_Nocreate); //打开文件
        Livearealist l1, node;
        l1 = l;
        for (int i = 0; i < activemaxlen - x; i++)
        {
            node = new Liveareanode;
            node->line = i + 1;
            Inicontent(node->content);
            inputfile.getline(buffer, 320);
            text = (string)buffer;
            for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
            {
                strcpy(text1, text.substr(j, k).c_str()); //分割字符串
                Insert(node->content, text1);
            }
            node->next = l1->next;
            l1->next = node;
            l1 = l1->next;
        }
        inputfile.close(); //关闭文件
    }
}
int main(void)
{
    char cmd;
    Livearealist l;
    Inilivearea(l);
    Initialization(l);
    while (1)
    {
        cin >> cmd;
        switch (cmd)
        {
        case 'i':
            Insert(l);
            break;
        case 'd':
            Delete(l);
            break;
        case 'n':
            Switch(l);
            break;
        default:
            break;
        }
    }
}
