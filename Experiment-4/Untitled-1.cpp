#include <iostream>
using namespace std;
#define MAXSIZE 5
int main(void)
{
    int array[MAXSIZE][MAXSIZE], min[MAXSIZE], max[MAXSIZE], a[MAXSIZE], b[MAXSIZE];
    cout << "请输入一个" << MAXSIZE << "×" << MAXSIZE << "的矩阵" << endl;
    for (int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < MAXSIZE; j++)
            cin >> array[i][j]; //获取矩阵
    for (int i = 0; i < MAXSIZE; i++)
    {
        a[i] = 0;
        max[i] = array[i][0]; //最大值初始为该行第一个元素
        for (int j = 0; j < MAXSIZE; j++)
            if (array[i][j] > max[i])
            {
                max[i] = array[i][j];
                a[i] = j;
            }
    }
    for (int j = 0; j < MAXSIZE; j++)
    {
        b[j] = 0;
        min[j] = array[0][j]; //最小值初始为该列第一个元素
        for (int i = 0; i < MAXSIZE; i++)
            if (array[i][j] < min[j])
            {
                min[j] = array[i][j];
                b[j] = i;
            }
    }
    for (int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < MAXSIZE; j++)
            if (b[j] == i && a[i] == j)
                cout << max[i]; //max[i]或min[j]均可
}