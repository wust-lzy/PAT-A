#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//多项式的乘法
double a[1005], b[1005], c[2010];
int main()
{
    fill(a, a + 1005, 0);
    fill(b, b + 1005, 0);
    fill(c, c + 2010, 0);
    int k, ex, cnt = 0; // 指数
    double co;//系数
    cin >> k;
    for (int i = 0; i < k;i++)
    {
        cin >> ex >> co;
        a[ex] += co;
    }
    cin >> k;
    for (int i = 0; i < k;i++)
    {
        cin >> ex >> co;
        b[ex] += co;
    }
    for (int i = 0; i < 1001;i++)
    {
        if(a[i]!=0)
        {
            for (int j = 0; j < 1001;j++)
            {
                if(b[j]!=0)
                {
                    c[i + j] += a[i] * b[j];
                }
            }
        }
    }
    for (int i = 0; i < 2005;i++)
    {
        if(c[i]!=0)
            cnt++;
    }
    cout << cnt;
    for (int i =2005; i >= 0;i--)
    {
        if(c[i]!=0)
        {
            printf(" %d %.1lf", i, c[i]);
        }
    }
    return 0;
}