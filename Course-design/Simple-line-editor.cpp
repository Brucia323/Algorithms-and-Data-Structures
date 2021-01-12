#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define activemaxlen 100
#define x 95
string inputfilename, outputfilename; //�ļ���
int count1;
//���ݵ�����
typedef struct Content
{
    char text[81]; //�ı�
    struct Content *next;
} Contentnode, *Contentlist;
//����������
typedef struct Livearea
{
    int line;            //�к�
    Contentlist content; //����
    struct Livearea *next;
} Liveareanode, *Livearealist;
//���ݳ�ʼ��
void Inicontent(Contentlist &c)
{
    c = new Contentnode;
    c->next = NULL;
}
//������ʼ��
void Inilivearea(Livearealist &l)
{
    l = new Liveareanode;
    l->line = 0;
    Inicontent(l->content);
    l->next = NULL;
}
//���ݲ���
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
//���������ļ�
void Createcache()
{
    fstream cachefile, inputfile;
    cachefile.open("cache.txt", ios::trunc);
    inputfile.open((string)inputfilename + ".txt");
    char buffer[320];
    while (!inputfile.eof())
    {
        inputfile.getline(buffer, 320);
        cachefile << buffer << endl;
    }
    inputfile.close();
    cachefile.close();
    system("pause");
}
//�޸Ļ����ļ�
void Modifycache()
{
    fstream cachefile, _cachefile;
    char buffer[320];
    cachefile.open("cache.txt");
    _cachefile.open("_cache.txt");
    for (int i = 0; i < activemaxlen - x; i++)
    {
        cachefile.getline(buffer, 320);
    }
    while (!cachefile.eof())
    {
        cachefile.getline(buffer, 320);
        _cachefile << buffer << endl;
    }
    cachefile.close();
    cachefile.open("cache.txt", ios::trunc);
    while (!_cachefile.eof())
    {
        _cachefile.getline(buffer, 320);
        cachefile << buffer << endl;
    }
    cachefile.close();
    _cachefile.close();
    remove("_cache.txt");
}
//��ȡ����
void Read(Livearealist &l)
{
    fstream cachefile;
    count1 = 0;
    char buffer[320], text1[81];
    string text;
    cachefile.open("cache.txt"); //���ļ�
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
            strcpy(text1, text.substr(j, k).c_str()); //�ָ��ַ���
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
    cachefile.close(); //�ر��ļ�
    Modifycache();
}
//��ʼ��
void Initialization(Livearealist &l)
{
    cout << "�����롰�����ļ����ļ�����";
    getline(cin, inputfilename);
    cout << "�����롰����ļ����ļ�����";
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
        cout << "���������ļ���������ͬ" << endl;
        getchar();
        Initialization(l);
    }
}
//����
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
        node->content = node->content->next;
        while (node->content)
        {
            outputfile << node->content->text;
            node->content = node->content->next;
            outputfile << endl;
        }
        l1->next = node->next;
        delete node;
        for (l1 = l1->next; l1; l1->line = l1->line - 1, l1 = l1->next)
            ;
        count1--;
    }
    //�к��ڻ�����Χ��
    if (line >= 0 && line < activemaxlen)
    {
        count1++;
        l1 = l;
        //���ҵ�i�����
        for (int i = 0; l1->next && i < line; i++, l1 = l1->next)
            ;
        node = new Liveareanode;
        node->line = l1->line + 1;
        Inicontent(node->content);
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str()); //�ָ��ַ���
            Insert(node->content, text1);
        }
        node->next = l1->next;
        l1->next = node;
        l1 = l1->next;
        //�޸ĺ����к�
        for (l1 = l1->next; l1; l1->line = l1->line + 1, l1 = l1->next)
            ;
    }
    else
    {
        cout << "�������" << endl;
        return;
    }
}
//ɾ��
void Delete(Livearealist &l)
{
    int line1, line2 = 0;
    // char space;
    Livearealist l1, l2, node1, node2;
    cin >> line1;
    //�жϸ�ʽ
    if (getchar() == ' ')
    {
        cin >> line2;
    }
    if (line1 <= 0 || line2 < 0 || line1 >= activemaxlen || line2 >= activemaxlen)
    {
        cout << "�������" << endl;
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
    //�޸��к�
    if (l1->next)
    {
        for (l1->next->line = l1->line + 1, l1 = l1->next; l1->next; l1 = l1->next)
        {
            l1->next->line = l1->line + 1;
        }
    }
}
//�����л�
void Switch(Livearealist &l)
{
    fstream outputfile;
    Livearealist l1, node;
    l1 = l;
    outputfile.open((string)outputfilename + ".txt", ios::app); //׷�Ӵ�
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
            outputfile << endl;
            l1->next = node->next;
            delete node;
        }
    }
    outputfile.close(); //�ر�
    if (inputfilename != "")
    {
        Read(l);
    }
}
//������ʾ
void Display(Livearealist l)
{
    string text;
    Livearealist node = l;
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
        cout << "��һҳ[Y/N]? ";
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
        cout << "����ָ��" << endl;
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
            cout << "���������������������" << endl;
            break;
        }
    }
}