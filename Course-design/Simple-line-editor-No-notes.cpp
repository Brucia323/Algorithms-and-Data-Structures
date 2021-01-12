#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define activemaxlen 100
#define x 95
string inputfilename, outputfilename; 
int count1;

typedef struct Content
{
    char text[81]; 
    struct Content *next;
} Contentnode, *Contentlist;

typedef struct Livearea
{
    int line;            
    Contentlist content; 
    struct Livearea *next;
} Liveareanode, *Livearealist;

void Inicontent(Contentlist &c)
{
    c = new Contentnode;
    c->next = NULL;
}

void Inilivearea(Livearealist &l)
{
    l = new Liveareanode;
    l->line = 0;
    Inicontent(l->content);
    l->next = NULL;
}

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

void Createcache()
{
    fstream cachefile, inputfile;
    inputfile.open((string)inputfilename + ".txt");
    cachefile.open("cache.txt", ios::out); 
    char buffer[320];
    if (cachefile.is_open())
    {
        while (!inputfile.eof())
        {
            inputfile.getline(buffer, 320);
            cachefile << buffer;
            if (!inputfile.eof())
            {
                cachefile << endl;
            }
        }
    }
    cachefile.close();
    inputfile.close();
}

void Modifycache()
{
    fstream cachefile, _cachefile;
    char buffer[320];
    _cachefile.open("_cache.txt", ios::out);
    cachefile.open("cache.txt", ios::in);
    for (int i = 0; i < activemaxlen - x; i++)
    {
        cachefile.getline(buffer, 320);
        if (cachefile.eof())
        {
            cachefile.close();
            _cachefile.close();
            remove("_cache.txt");
            remove("cache.txt");
            return;
        }
    }
    while (!cachefile.eof())
    {
        cachefile.getline(buffer, 320);
        _cachefile << buffer;
        if (!cachefile.eof())
        {
            _cachefile << endl;
        }
    }
    cachefile.close();
    _cachefile.close();
    cachefile.open("cache.txt", ios::out);
    _cachefile.open("_cache.txt", ios::in);
    while (!_cachefile.eof())
    {
        _cachefile.getline(buffer, 320);
        cachefile << buffer;
        if (!_cachefile.eof())
        {
            cachefile << endl;
        }
    }
    cachefile.close();
    _cachefile.close();
    remove("_cache.txt");
}

void Read(Livearealist &l)
{
    fstream cachefile;
    count1 = 0;
    char buffer[320], text1[81];
    string text;
    cachefile.open("cache.txt"); 
    if (cachefile.eof())
    {
        cachefile.close();
        return;
    }
    Livearealist l1, node;
    l1 = l;
    for (int i = 0; i < activemaxlen - x; i++)
    {
        node = new Liveareanode;
        node->line = i + 1;
        Inicontent(node->content);
        cachefile.getline(buffer, 320);
        count1++;
        text = (string)buffer;
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str()); 
            Insert(node->content, text1);
        }
        node->next = l1->next;
        l1->next = node;
        l1 = l1->next;
        if (cachefile.eof())
        {
            break;
        }
    }
    cachefile.close(); 
    Modifycache();
}

void Initialization(Livearealist &l)
{
    cout << "请输入“输入文件”文件名：";
    getline(cin, inputfilename);
    cout << "请输入“输出文件”文件名：";
    cin >> outputfilename;
    if (inputfilename != outputfilename)
    {
        if (inputfilename != "")
        {
            Createcache();
            Read(l);
        }
    }
    else
    {
        cout << "输入和输出文件名不能相同" << endl;
        getchar();
        Initialization(l);
    }
}

void Insert(Livearealist &l)
{
    int line;
    string text;
    char text1[81], buffer;
    Livearealist l1, node;
    cin >> line;
    getchar();
    getline(cin, text);
    if (count1 == activemaxlen)
    {
        l1 = l;
        node = l1->next;
        fstream outputfile;
        outputfile.open((string)outputfilename + ".txt", ios::app);
        while (node->content->next)
        {
            node->content = node->content->next;
            outputfile << node->content->text;
        }
        outputfile << endl;
        outputfile.close();
        l1->next = node->next;
        delete node;
        for (l1 = l1->next; l1; l1->line = l1->line - 1, l1 = l1->next)
            ;
        count1--;
    }
    
    if (line >= 0 && line < activemaxlen)
    {
        count1++;
        l1 = l;
        
        for (int i = 0; l1->next && i < line; i++, l1 = l1->next)
            ;
        node = new Liveareanode;
        node->line = l1->line + 1;
        Inicontent(node->content);
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str()); 
            Insert(node->content, text1);
        }
        node->next = l1->next;
        l1->next = node;
        l1 = l1->next;
        
        for (l1 = l1->next; l1; l1->line = l1->line + 1, l1 = l1->next)
            ;
    }
    else
    {
        cout << "输入错误" << endl;
        return;
    }
}

void Delete(Livearealist &l)
{
    int line1, line2 = 0;
    Livearealist l1, l2, node1, node2;
    cin >> line1;
    
    if (getchar() == ' ')
    {
        cin >> line2;
    }
    if (line1 <= 0 || line2 < 0 || line1 >= activemaxlen || line2 >= activemaxlen)
    {
        cout << "输入错误" << endl;
        return;
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
        for (int i = line1; l2->next && i <= line2; i++, l2 = l2->next)
            ;
        for (node1 = l1->next; node1 != l2; node1 = node2)
        {
            node2 = node1->next;
            delete node1;
        }
        l1->next = l2->next;
        delete l2;
    }
    
    if (l1->next)
    {
        for (l1->next->line = l1->line + 1, l1 = l1->next; l1->next; l1 = l1->next)
        {
            l1->next->line = l1->line + 1;
        }
    }
}

void Switch(Livearealist &l)
{
    fstream outputfile;
    Livearealist l1, node;
    l1 = l;
    outputfile.open((string)outputfilename + ".txt", ios::app); 
    if (outputfile.is_open())
    {
        while (l1->next)
        {
            node = l1->next;
            while (node->content->next)
            {
                node->content = node->content->next;
                outputfile << node->content->text;
            }
            if (l1->next)
            {
                outputfile << endl;
            }
            l1->next = node->next;
            delete node;
        }
    }
    outputfile.close(); 
    if (inputfilename != "")
    {
        fstream cachefile;
        cachefile.open("cache.txt", ios::in);
        if (cachefile.is_open())
        {
            cachefile.close();
            Read(l);
        }
    }
}

void Display(Livearealist l)
{
    string text;
    Livearealist node; 
    char key;
    int i;
    for (i = 0; i < 20 && l; i++)
    {
        text = "";
        for (node->content = l->content->next; node->content; node->content = node->content->next)
        {
            text += node->content->text;
            if (node->content->next == NULL)
            {
                break;
            }
        }
        cout << l->line << " " << text << endl;
        l = l->next;
    }
    if (i == 20)
    {
        cout << "下一页[Y/N]? ";
        cin >> key;
        if (key == 'Y' || key == 'y')
        {
            Display(l);
        }
        else
        {
            return;
        }
    }
}
int main(void)
{
    char cmd;
    Livearealist l, l1;
    Inilivearea(l);
    Initialization(l);
    while (1)
    {
        cout << "输入指令" << endl;
        cin >> cmd;
        switch (cmd)
        {
        case 'i':
            Insert(l);
            system("pause");
            break;
        case 'd':
            Delete(l);
            system("pause");
            break;
        case 'n':
            Switch(l);
            system("pause");
            break;
        case 'p':
            l1 = l->next;
            Display(l1);
            system("pause");
            break;
        default:
            cout << "命令输入错误，请重新输入" << endl;
            break;
        }
    }
}
