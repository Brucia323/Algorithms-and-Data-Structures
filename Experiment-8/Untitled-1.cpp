#include <iostream>
using namespace std;
int count1 = 0; //比较次数
int count2 = 0; //移动次数
typedef struct
{
    int key; //主关键字
} ElemType;
typedef struct
{
    ElemType *R; //表基址
    int length;  //表长
} SSTable;

//构造一个空的顺序表L
void InitList(SSTable &L)
{
    L.R = new ElemType[100]; //为顺序表分配一个大小为100的数组空间
    L.length = 0;            //空表长度为0
}
void ListInsert(SSTable &L, int n)
{
    if (L.length == 100)
        return;
    for (int i = 1; i < n + 1; i++, L.length++)
        cin >> L.R[i].key;
}
void ListInsert(SSTable &L1, SSTable L)
{
    for (int i = 1; i < L.length + 1; i++, L1.length++)
        L1.R[i].key = L.R[i].key;
}

//输出顺序表L
void Print(SSTable L)
{
    for (int i = 1; i < L.length + 1; i++)
        cout << L.R[i].key << " ";
}

//对顺序表L做冒泡排序
void BubbleSort(SSTable &L)
{
    int m = L.length - 1, flag = 1; //flag用来标记某一趟排序是否发生交换
    count1 = 0, count2 = 0;
    while ((m > 0) && (flag == 1))
    {
        flag = 0; //flag置为0，如果本趟排序没有发生交换，则不会执行下一趟排序
        for (int j = 1; j <= m; j++)
        {
            if (L.R[j].key > L.R[j + 1].key)
            {
                flag = 1; //flag置为1，表示本趟排序发生了交换
                //交换前后两个记录
                ElemType t = L.R[j];
                L.R[j] = L.R[j + 1];
                L.R[j + 1] = t;
                count2++;
            }
            count1++;
        }
        m--;
        Print(L);
        cout << endl;
    }
    cout << "比较了" << count1 << "次 移动了" << count2 << "次" << endl;
    cout << "这是一个稳定的排序" << endl;
}

//对顺序表L做一趟增量是dk的希尔插入排序
void ShellInsert(SSTable &L, int dk)
{
    for (int i = dk + 1; i <= L.length; i++)
    { //需将L.r[i]插入有序增量子表
        if (L.R[i].key < L.R[i - dk].key)
        {
            int j;
            L.R[0] = L.R[i]; //暂存在L.r[0]
            for (j = i - dk; j >= 0 && L.R[0].key < L.R[j].key; j -= dk)
                L.R[j + dk] = L.R[j]; //记录后移，直到找到插入位置
            L.R[j + dk] = L.R[0];     //将r[0]即原r[i]，插入到正确位置
            count2++;
        }
        count1++;
    }
}
//按增量序列dt[0..t-1]对顺序表L作t趟希尔排序
void ShellSort(SSTable &L, int dt[], int t)
{
    count1 = 0, count2 = 0;
    for (int k = 0; k < t; k++)
    {
        ShellInsert(L, dt[k]); //一趟增量为dt[t]的希尔插入排序
        Print(L);
        cout << endl;
    }
    cout << "比较了" << count1 << "次 移动了" << count2 << "次" << endl;
    cout << "这是一个不稳定的排序" << endl;
}

//假设r[s+1..m]已经是堆，将r[s..m]调整为以r[s]为根的大根堆
void HeapAdjust(SSTable &L, int s, int m)
{
    ElemType rc = L.R[s];
    //沿key较大的孩子结点向下筛选
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && L.R[j].key < L.R[j + 1].key)
            j++; //j为key较大的记录的下标
        if (rc.key >= L.R[j].key)
        {
            count2++;
            break; //rc应插入在位置s上
        }
        L.R[s] = L.R[j];
        s = j;
        count1++;
    }
    L.R[s] = rc; //插入
}
//把无序序列L.r[i..n]建成大根堆
void CreateHeap(SSTable &L)
{
    int n = L.length;
    //反复调用HeapAdjust
    for (int i = n / 2; i > 0; i--)
        HeapAdjust(L, i, n);
}
//对顺序表L进行堆排序
void HeapSort(SSTable &L)
{
    count1 = 0, count2 = 0;
    CreateHeap(L); //把无序序列L.r[1..L.lenth]建成大根堆
    for (int i = L.length; i > 1; i--)
    {
        ElemType x = L.R[1];
        L.R[1] = L.R[i];
        L.R[i] = x;
        HeapAdjust(L, 1, i - 1); //将L.r[i..i-1]重新调整为大根堆
        Print(L);
        cout << endl;
    }
    cout << "比较了" << count1 << "次 移动了" << count2 << "次" << endl;
    cout << "这是一个不稳定的排序" << endl;
}

//对顺序表L中的子表r[low..high]进行一趟排序，返回枢纽位置
int Partition(SSTable &L, int low, int high)
{
    L.R[0] = L.R[low];           //用子表的第一个记录做枢纽记录
    int pivotkey = L.R[low].key; //枢纽记录关键字保存在pivotkey中
    //从表的两端交替地向中间扫描
    while (low < high)
    {
        while (low < high && L.R[high].key >= pivotkey)
        {
            high--;
            count1++;
        }
        L.R[low] = L.R[high]; //将比枢纽记录小的记录移到低端
        count2++;
        while (low < high && L.R[low].key <= pivotkey)
        {
            low++;
            count1++;
        }
        L.R[high] = L.R[low]; //将比枢纽记录大的记录移到高端
        count2++;
    }
    L.R[low] = L.R[0]; //枢纽记录到位
    return low;        //返回枢纽位置
}
//调用前置初值：low=1;high=L.length;
//对顺序表L中的子序列L.r[low..high]做快速排序
void QSort(SSTable &L, int low, int high)
{
    //长度大于1
    if (low < high)
    {
        int pivotloc = Partition(L, low, high); //将L.r[low..high]一分为二，pivotloc是枢纽位置
        Print(L);
        cout << endl;
        QSort(L, low, pivotloc - 1);  //对左子表递归排序
        QSort(L, pivotloc + 1, high); //对右子表递归排序
    }
}
//对顺序表L做快速排序
void QuickSort(SSTable &L)
{
    count1 = 0, count2 = 0;
    QSort(L, 1, L.length);
    cout << "比较了" << count1 << "次 移动了" << count2 << "次" << endl;
    cout << "这是一个不稳定的排序" << endl;
}

int main(void)
{
    SSTable L, L1;
    int n, i;
    cout << "数据个数：";
    cin >> n;
    InitList(L);
    ListInsert(L, n);
    while (1)
    {
        InitList(L1);
        ListInsert(L1, L);
        int dt[] = {5, 3, 1}, t = 3;
        cout << "1.冒泡排序" << endl;
        cout << "2.希尔排序" << endl;
        cout << "3.堆排序" << endl;
        cout << "4.快速排序" << endl;
        cin >> i;
        switch (i)
        {
        case 1:
            BubbleSort(L1);
            break;
        case 2:
            ShellSort(L1, dt, t);
            break;
        case 3:
            HeapSort(L1);
            break;
        case 4:
            QuickSort(L1);
            break;
        default:
            i = 0;
            break;
        }
        if (i == 0)
            break;
    }
}