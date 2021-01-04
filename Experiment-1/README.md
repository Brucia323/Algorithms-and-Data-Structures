算法数据结构      
                         ---- 顺序表
实验目的：
1、掌握线性表-顺序表的定义；
2、掌握线性表-顺序的基本操作，如建立、查找、插入和删除等。
实验内容：（以下两题2选1完成）
1.定义一个包含学生信息（学号，姓名，成绩）的的顺序表，使其具有如下功能：
(1) 根据指定学生个数，逐个输入学生信息；
(2) 逐个显示学生表中所有学生的相关信息；
(3) 根据姓名进行查找，返回此学生的学号和成绩；
(4) 根据指定的位置可返回相应的学生信息（学号，姓名，成绩）； 
(5) 给定一个学生信息，插入到表中指定的位置； 
(6) 删除指定位置的学生记录；
(7) 统计表中学生个数。
2．基于顺序存储结构实现两个一元多项式（稀疏）的相加和相减
实验提示： 
学生信息的定义：
typedef struct {
    char no[8];   //8位学号
    char name[20]; //姓名
    int price;     //成绩
}Student;

顺序表的存储结构如下定义
typedef  struct {
  Student  *elem;     //指向数据元素的基地址
  int  length;       //线性表的当前长度                                                           
 }SqList；

实现常用操作如下:
int  InitList_L(LinkList &L)
int ListEmpty(LinkList L)
int ClearList(LinkList & L)
int CountList(LinkList & L）
LNode *LocateELem_L (LinkList L，Elemtype e) 
int GetElem_L(LinkList L,int i,ElemType &e)
int ListInsert_L(LinkList &L,int i,ElemType e)
int ListDelete_L(LinkList &L,int i,ElemType &e)
CreateList_L(LinkList &L,int n)
同学们在实现了常用操作的基础上,再完成实验内容的各功能,其实现功能过程在何时的地方调用常用操作(如增,删,改,查).
	实验要求：
(1) 程序要添加适当的注释，程序的书写要采用缩进格式。
(2) 程序要具在一定的健壮性，即当输入数据非法时，程序也能适当地做出反应，如插入删除时指定的位置不对等等。
(3) 程序要做到界面友好，在程序运行时用户可以根据相应的提示信息进行操作。
(4) 根据实验报告模板详细书写实验报告,在实验报告中给出链表根据姓名进行查找的算法和插入算法的流程图。
(5) 上传实验报告网络教学平台-实验一。实验报告命名为：实验1+班级+学号姓名.doc。如实验1+软件工程1701+070814101薛力.docx，报告命名格式严格遵守！！

