/*定义一个包含学生信息（学号，姓名，成绩）的顺序表，使其具有如下功能：
(1) 根据指定学生个数，逐个输入学生信息；
(2) 逐个显示学生表中所有学生的相关信息；
(3) 根据姓名进行查找，返回此学生的学号和成绩；
(4) 根据指定的位置可返回相应的学生信息（学号，姓名，成绩）； 
(5) 给定一个学生信息，插入到表中指定的位置； 
(6) 删除指定位置的学生记录；
(7) 统计表中学生个数。
*/
#include <stdio.h>
#include <string.h>
typedef struct
{
    char no[8];    //8位学号
    char name[20]; //姓名
    int price;     //成绩
} Student;
int main(void)
{
    int n, i;
    puts("请输入学生个数：");
    scanf("%d", &n);
    puts("请输入学生信息：");
    Student stu[10000];
    for (i = 0; i < n; i++)
        scanf("%s %s %d", stu[i].no, stu[i].name, &stu[i].price);
    while (1)
    {
        puts("1.逐个显示学生表中所有学生的相关信息");
        puts("2.根据姓名查找学生的学号和成绩");
        puts("3.查找指定位置的学生信息");
        puts("4.给定一个学生信息，插入到指定位置");
        puts("5.删除指定位置的学生记录");
        puts("6.统计表中学生个数");
        puts("7.退出");
        int s;
        scanf("%d", &s);
        char newno[8];
        char newname[20];
        int newprice;
        char name[20];
        int a;
        if (s == 7)
            break;
        switch (s)
        {
        case 1:
            for (i = 0; i < n; i++)
                printf("%s %s %d\n", stu[i].no, stu[i].name, stu[i].price); //逐个显示学生表中所有学生的相关信息
            puts("按回车键返回");
            getchar();
            getchar();
            break;
        case 2:
            for (i = 0; i < n; i++)
                if (stu[i].name == name)
                    printf("%s %d\n", stu[i].no, stu[i].price); //根据姓名查找学生的学号和成绩
            puts("按回车键返回");
            getchar();
            getchar();
            break;
        case 3:
            puts("请输入要查找的姓名：");
            scanf("%s", &newname);
            for (i = 0; i < n; i++)
                if (!(strcmp(newname, stu[i].name)))
                    printf("%s %s %d\n", stu[i].no, stu[i].name, stu[i].price); //查找指定位置的学生信息
            puts("按回车键返回");
            getchar();
            getchar();
            break;
        case 4:
            puts("请输入学生信息：");
            scanf("%s %s %d", newno, newname, &newprice);
            puts("请指定插入位置：");
            scanf("%d", &a);
            if (!(a < n && a >= 0))
            {
                puts("输入数字错误");
                break;
            }
            for (i = n; i > a; i--)
                stu[i] = stu[i - 1];
            for (int j = 0; j < 8; j++)
                stu[a].no[j] = newno[j];
            for (int j = 0; j < 20; j++)
                stu[a].name[j] = newname[j];
            stu[a].price = newprice;
            n++;
            puts("OK!\n"); //给定一个学生信息，插入到指定位置
            puts("按回车键返回");
            getchar();
            getchar();
            break;
        case 5:
            puts("请输入需要删除的学生信息：");
            scanf("%d", &a);
            if (!(a < n && a >= 0))
            {
                puts("输入数字错误");
                break;
            }
            for (i = a; i < n - 1; i++)
                stu[i] = stu[i + 1];
            n--;
            puts("OK!\n"); //删除指定位置的学生记录
            puts("按回车键返回");
            getchar();
            getchar();
            break;
        case 6:
            printf("共有%d个学生\n", n); //统计表中学生个数
            puts("按回车键返回");
            getchar();
            getchar();
            break;
        default:
            puts("输入无效，请重新输入\n");
            puts("按回车键返回");
            getchar();
            getchar();
            break;
        }
    }
}