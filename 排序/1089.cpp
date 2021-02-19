#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
插入排序和归并排序
判断插入排序的方法是  找到一段有序序列结束的地方为i
从i+1开始 找到部分排序后序列和原序列值不一样的下标 
如果下标为n 则为插入排序，因为插入排序后面的序列都不会动
否则为归并排序
归并排序的原理就是进行分组 每组的数量从1开始不断*2
每组的数量为k  先sort 前n/k组  最后一组为 (a+n/k*k,a+n)
直到排序后的序列和题目给出的一样  最后再排序一趟  结束~~
*/
int a[100], b[100];
int main()
{
    int n, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    i = 0;
    while (i < n - 1 && b[i] <= b[i + 1])
    {
        i++;
    }
    for (j = i + 1; a[j] == b[j] && j < n; j++)
        ;
    if (j == n)
    {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2);
    }
    else //归并排序
    {
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        while (flag)
        {
            flag = 0;
            for (i = 0; i < n; i++)
            {
                if (a[i] != b[i])
                {
                    flag = 1;
                }
            }
            k *= 2;
            for (i = 0; i < n / k; i++)
            {
                sort(a + i * k, a + (i + 1) * k);
            }
            sort(a + n / k * k, a + n); //最后一组排序
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }
    return 0;
}