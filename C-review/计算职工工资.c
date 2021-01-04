/*给定N个职员的信息，包括姓名、基本工资、浮动工资和支出，要求编写程序顺序输出每位职员的姓名和实发工资（实发工资=基本工资+浮动工资-支出）。*/
#include <stdio.h>

struct information
{
    char name[11];       //姓名
    double basic;        //基本工资
    double variable;     //浮动工资
    double expenditures; //支出
    double Payroll;      //实发工资
} information[1000];

int main(void)
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %lf %lf %lf", information[i].name, &information[i].basic, &information[i].variable, &information[i].expenditures);
        information[i].Payroll = information[i].basic + information[i].variable - information[i].expenditures;
    }
    for (i = 0; i < n; i++)
        printf("%s %.2lf\n", information[i].name, information[i].Payroll);
}