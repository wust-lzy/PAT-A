#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
字符串处理
柳神的方法太妙了，用两个指针 i,j记录前后 统计相同字符串的个数
统计完之后直接跳到j的位置  for的妙用
*/
int main()
{
    int n;
    string d;
    cin >> d >> n;
    for (int cnt = 1; cnt < n;cnt++)
    {
        int j;
        string t;
        for (int i = 0; i < d.length();i=j)
        {
            j = i;
            while (d[j]==d[i])
            {
                j++;
            }
            t +=d[i]+to_string(j - i);
        }
        d = t;
    }
    cout << d;
    return 0;
}