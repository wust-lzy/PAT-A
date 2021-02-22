#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
模拟因数分解
题目求最大的连续乘积因数 因此最大的因子不可能超过sqrt(n)
max_len记录最大的长度 index记录开始的下标
从2开始遍历到sqrt(n)
*/
int main()
{
    ll n;
    int max_len = 0,index=0;
    cin >> n;
    ll sqr = sqrt(n*1.0);
    for (int i = 2; i <= sqr; i++)
    {
        ll temp = 1, j = i;//temp记录乘积
        while (1)
        {
            temp *= j;
            if(n%temp!=0)
                break;
            if (j-i+1>max_len)
            {
                max_len = j - i + 1;
                index = i;
            }
            j++;
        }
    }
    if (max_len!=0)
    {
        cout << max_len << endl;
        for (int i = 0; i < max_len; i++)
        {
            cout << index + i;
            if (i!=max_len-1)
            {
                cout << "*";
            }
        }
    }
    else
    {
        cout << 1 << "\n"
             << n;
    }  
    return 0;
}